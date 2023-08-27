#pragma once
#include "SDL.h"
#include "iostream"
#include "Windows.h"
#include "cmath"

#include "player.h"
#include "Raycast.h"
#include "vector"
#include "textures.h"
using std::vector;

class Game {
public:

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	//void handleKeyboard();
	void update();
	void render();
	void clean();
	void draw2D();
	void createWorld();

	bool running() { return isRunning; }

private:
	const static int worldSize = 50;
	int width = 1000;
	int height = 800;
	int gridSize = width / worldSize;
	int world[worldSize * worldSize];
	float heightMap[worldSize * worldSize];
	int resolution = 1000;
	int drawID = 1;
	float FOV = 3.1415/3;
	float moveSpeed = .1;
	bool do2D;
	bool isRunning;
	bool ghostMode = false;
	bool mouseLeftDown = false;
	bool mouseRightDown = false;
	bool mouseMiddleDown = false;
	//bool KEYS[322];
	SDL_Window* window;
	SDL_Renderer* renderer;
	Player* player = nullptr;
	Raycaster* raycaster = nullptr;
	textureMap* texture = nullptr;
};