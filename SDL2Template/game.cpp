#include "game.h"

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window Created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			std::cout << "Renderer Created" << std::endl;
		}

		isRunning = true;
		createWorld();
		player = new Player();
		raycaster = new Raycaster();
		texture = new textureMap();
		player->init({ gridSize * float(worldSize) / 2, gridSize * float(worldSize) /2 });
		player->setVariables(gridSize, worldSize);

		//texture->testTextures();
	}
	else {
		isRunning = false;
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE) {
			do2D = !do2D;
			std::cout << drawID << std::endl;
		}
		if (event.key.keysym.sym == SDLK_1) {
			drawID = 1;
			std::cout << drawID << std::endl;
		}
		if (event.key.keysym.sym == SDLK_2) {
			drawID = 2;
			std::cout << drawID << std::endl;
		}
		if (event.key.keysym.sym == SDLK_3) {
			drawID = 3;
			std::cout << drawID << std::endl;
		}
		if (event.key.keysym.sym == SDLK_g) {
			ghostMode = !ghostMode;
			std::cout << "Ghost: " << drawID << std::endl;
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (event.button.button == SDL_BUTTON_LEFT) {
			mouseLeftDown = true;
		}
		if (event.button.button == SDL_BUTTON_RIGHT) {
			mouseRightDown = true;
		}
		if (event.button.button == SDL_BUTTON_MIDDLE) {
			mouseMiddleDown = true;
		}
		break;
	case SDL_MOUSEBUTTONUP:
		if (event.button.button == SDL_BUTTON_LEFT) {
			mouseLeftDown = false;
		}
		if (event.button.button == SDL_BUTTON_RIGHT) {
			mouseRightDown = false;
		}
		if (event.button.button == SDL_BUTTON_MIDDLE) {
			mouseMiddleDown = false;
		}
		break;

	default:
		break;
	}
}

void Game::update()
{
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		player->move({0.0, 0.0}, 0.03, world);
	}
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		player->move({ 0.0, 0.0 }, -0.03, world);
	}
	if (GetKeyState(VK_UP) & 0x8000)
	{
		player->moveY(0.0, 10);
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		player->moveY(0.0, -10);
	}
	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		if (ghostMode){
			player->moveY(.10, 0.0);
		}
		else {
			player->jump();
		}
	}
	if (GetKeyState(VK_SHIFT) & 0x8000)
	{
		player->moveY(-.10, 0.0);
	}
	if (GetKeyState('W') & 0x8000)
	{
		if ((GetKeyState('A') & 0x8000) || (GetKeyState('D') & 0x8000)) {
			player->move({ moveSpeed * float(sqrt(2)/2), 0.0 }, 0.0, world);
		}
		else {
			player->move({ moveSpeed, 0.0 }, 0.0, world);
		}
	}
	if (GetKeyState('S') & 0x8000)
	{
		if ((GetKeyState('A') & 0x8000) || (GetKeyState('D') & 0x8000)) {
			player->move({ -moveSpeed * float(sqrt(2) / 2), 0.0 }, 0.0, world);
		}
		else {
			player->move({ -moveSpeed, 0.0 }, 0.0, world);
		}
	}
	if (GetKeyState('A') & 0x8000)
	{
		if ((GetKeyState('W') & 0x8000) || (GetKeyState('S') & 0x8000)) {
			player->move({ 0.0, moveSpeed * float(sqrt(2) / 2) }, 0.0, world);
		}
		else {
			player->move({ 0.0, moveSpeed }, 0.0, world);
		}
	}
	if (GetKeyState('D') & 0x8000)
	{
		if ((GetKeyState('W') & 0x8000) || (GetKeyState('S') & 0x8000)) {
			player->move({ 0.0, -moveSpeed * float(sqrt(2) / 2) }, 0.0, world);
		}
		else {
			player->move({ 0.0, -moveSpeed }, 0.0, world);
		}
	}
	if (mouseLeftDown){
		int x, y;
		SDL_GetMouseState(&x, &y);
		world[int(x / gridSize + int(y / gridSize) * worldSize)] = drawID;
	}
	if (mouseRightDown) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		world[int(x / gridSize + int(y / gridSize) * worldSize)] = 0;
	}
	if (mouseMiddleDown) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		heightMap[int(x / gridSize + int(y / gridSize) * worldSize)] = float(drawID)*2;
	}
	if (!ghostMode) {
		player->update();
	}
}

void Game::render()
{

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	
	if (do2D) {
		this->draw2D();
	}
	else {
		vector<float> playerPos = player->getPos();
		float playerDirection = player->getDirection();
		raycaster->castToScreen(renderer, FOV, resolution, playerPos, playerDirection, player->getDirY(), player->getPosY(), gridSize, world, worldSize, heightMap);
	}

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game Cleaned" << std::endl;
}

void Game::draw2D() {
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);

	SDL_Rect r;
	r.w = gridSize - 1;
	r.h = gridSize - 1;


	for (int y = 0; y < worldSize; y++) {
		for (int x = 0; x < worldSize; x++) {
			if (world[x + y * worldSize] == 0) {
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				r.x = gridSize * x;
				r.y = gridSize * y;
				SDL_RenderFillRect(renderer, &r);
			}
			else {
				SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
				r.x = gridSize * x;
				r.y = gridSize * y;
				SDL_RenderFillRect(renderer, &r);
			}
		}
	}

	vector<float> playerPos = player->getPos();
	float playerDirection = player->getDirection();

	SDL_Rect playerRect;
	playerRect.x = playerPos[0] - gridSize / 2;
	playerRect.y = playerPos[1] - gridSize / 2;
	playerRect.w = gridSize;
	playerRect.h = gridSize;
	SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
	SDL_RenderFillRect(renderer, &playerRect);
}

void Game::createWorld() {
	for (int y = 0; y < worldSize; y++) {
		for (int x = 0; x < worldSize; x++) {
			if (x == 0 || y == 0 || x == worldSize-1 || y == worldSize-1) {
				world[x + y * worldSize] = 1;
				heightMap[x + y * worldSize] = .75;
			}
			else {
				world[x + y * worldSize] = 0;
				heightMap[x + y * worldSize] = 2;
			}
		}
	}
}