#include "Raycast.h"

int colors[4][3] = { 
	{0, 0, 0},
	{0, 255, 255},
	{255, 255, 0}, 
	{255, 0, 255} };

int textureSize = 16;

int texture[16] = {
	0, 1, 0, 1,
	1, 0, 1, 0,
	0, 1, 0, 1,
	1, 0, 1, 0 };

void Raycaster::castToScreen(SDL_Renderer* renderer, float FOV, int resolution, vector<float> playerPos, float playerDirection, float playerDirY, float playerPosY, float gridSize, int wld[], int worldSize, float heightMap[]) {
	float rayDirection = playerDirection - FOV / 2;
	float rayStep = FOV / resolution;
	float castDistance = 30 * gridSize;
	SDL_Rect drawLine;
	drawLine.x = 0;
	drawLine.y = 0;
	drawLine.w = 1000 / resolution;
	drawLine.h = 0;
	for (int ray = 0; ray < resolution; ray++) {
		vector<float> raycastReturns = raycast(playerPos, { playerPos[0] + cos(rayDirection) * castDistance, playerPos[1] + sin(rayDirection) * castDistance }, gridSize, wld, worldSize);
		distance = raycastReturns[0];
		side = raycastReturns[1];
		hitPoint[0] = playerPos[0] + cos(rayDirection) * distance * gridSize;
		hitPoint[1] = playerPos[1] + sin(rayDirection) * distance * gridSize;

		if (distance+.5 < castDistance/gridSize) {
			da = abs(playerDirection - rayDirection);
			distance *= cos(da);
			lineHeight = 800 / distance;
			float drawHeight = (lineHeight * heightMap[int(raycastReturns[2]) + int(raycastReturns[3]) * worldSize]) / (textureSize * heightMap[int(raycastReturns[2]) + int(raycastReturns[3]) * worldSize]);
			drawLine.x = (1000 / resolution) * ray;
			drawLine.y = (800 / 2 - lineHeight / 2) - (heightMap[int(raycastReturns[2]) + int(raycastReturns[3]) * worldSize]-1) * lineHeight + playerPosY * lineHeight + playerDirY;
			drawLine.h = drawHeight + 1;
			
			int wallID = wld[int(raycastReturns[2]) + int(raycastReturns[3]) * worldSize];
			if (wallID > 3) {
				wallID = 0;
			}

			int textureX = int((hitPoint[0]/gridSize) * textureSize) % textureSize;
			int textureZ = int((hitPoint[1] / gridSize) * textureSize) % textureSize;
			int texturePoint = 0;
			if (side == 1) {
				for (float y = 0; y < textureSize * heightMap[int(raycastReturns[2]) + int(raycastReturns[3]) * worldSize]; y++)
				{
					texturePoint = (textureX + int(y) * textureSize) % (textureSize * textureSize);
					SDL_SetRenderDrawColor(renderer, textureMapWall->getTexture(texturePoint, 0) * (1 - (distance / (castDistance / gridSize))), textureMapWall->getTexture(texturePoint, 1) * (1 - (distance / (castDistance / gridSize))), textureMapWall->getTexture(texturePoint, 2) * (1 - (distance / (castDistance / gridSize))), 255);
					/*if (texture[(textureX + int(y) * textureSize)%(textureSize* textureSize)]) {
						SDL_SetRenderDrawColor(renderer, textureMapWall[] * (1 - (distance / (castDistance / gridSize))), colors[wallID][1] * (1 - (distance / (castDistance / gridSize))), colors[wallID][2] * (1 - (distance / (castDistance / gridSize))), 255);

						SDL_SetRenderDrawColor(renderer, colors[wallID][0] * (1 - (distance / (castDistance / gridSize))), colors[wallID][1] * (1 - (distance / (castDistance / gridSize))), colors[wallID][2] * (1 - (distance / (castDistance / gridSize))), 255);
					}
					else {
						SDL_SetRenderDrawColor(renderer, colors[wallID][0] * (1 - (distance / (castDistance / gridSize))) * .5, colors[wallID][1] * (1 - (distance / (castDistance / gridSize))) * .5, colors[wallID][2] * (1 - (distance / (castDistance / gridSize))) * .5, 255);
					}*/
					drawLine.y = (800 / 2 - lineHeight / 2) - (heightMap[int(raycastReturns[2]) + int(raycastReturns[3]) * worldSize] - 1) * lineHeight + playerPosY * lineHeight + playerDirY + y * drawHeight;
					SDL_RenderFillRect(renderer, &drawLine);
				}
			}
			else {
				for (float y = 0; y < textureSize * heightMap[int(raycastReturns[2]) + int(raycastReturns[3]) * worldSize]; y++)
				{
					texturePoint = (textureZ + int(y) * textureSize) % (textureSize * textureSize);
					SDL_SetRenderDrawColor(renderer, .5 * textureMapWall->getTexture(texturePoint, 0) * (1 - (distance / (castDistance / gridSize))), .5 * textureMapWall->getTexture(texturePoint, 1) * (1 - (distance / (castDistance / gridSize))), .5 * textureMapWall->getTexture(texturePoint, 2) * (1 - (distance / (castDistance / gridSize))), 255);
					drawLine.y = (800 / 2 - lineHeight / 2) - (heightMap[int(raycastReturns[2]) + int(raycastReturns[3]) * worldSize] - 1) * lineHeight + playerPosY * lineHeight + playerDirY + y * drawHeight;
					SDL_RenderFillRect(renderer, &drawLine);
				}
			}
		}
		rayDirection += rayStep;
	}
}

vector<float> Raycaster::raycast(vector<float> position, vector<float> endPosition, int gridSize, int wld[], int worldSize) {
	//int* world = wld;

	bool cast = true;
	float ax = 0.0;
	float ay = 0.0;
	float xDir = 0.0;
	float yDir = 0.0;

	vector<vector<int>> mapPoints;

	vector<int> mapPos = { int(position[0] / gridSize), int(position[1] / gridSize) };
	float maxDistance = sqrt(pow((endPosition[0] - position[0]), 2) + pow((endPosition[1] - position[1]), 2))/gridSize;
	float theta = -1 * atan2(endPosition[1] - position[1], endPosition[0] - position[0]);
	float xScale = sqrt(1 + pow(tan(theta), 2));
	float yScale = sqrt(1 + pow(1 / tan(theta), 2));

	if (endPosition[0] > position[0]){
		xDir = 1;
		ax = gridSize - (position[0] - int(position[0] / gridSize) * gridSize);
	}
	else {
		xDir = -1;
		ax = position[0] - int(position[0] / gridSize) * gridSize;
	}
	if (endPosition[1] > position[1]) {
		yDir = 1;
		ay = gridSize - (position[1] - int(position[1] / gridSize) * gridSize);
	}
	else {
		yDir = -1;
		ay = position[1] - int(position[1] / gridSize) * gridSize;
	}

	ax /= gridSize;
	ay /= gridSize;

	float xlen = ax * xScale;
	float ylen = ay * yScale;
	
	while (cast) {
		if (mapPos[0] < 1 || mapPos[1] < 1 || mapPos[0] >= worldSize || mapPos[1] >= worldSize) {
			return {maxDistance, 0, 0, 0 };
		}
		if (xlen <= ylen) {
			if (wld[int((mapPos[0] + xDir) + mapPos[1] * worldSize)]) {
				return { xlen, 0, (mapPos[0] + xDir), float(mapPos[1]) };
			}
			else {
				mapPos[0] += xDir;
				xlen += xScale;
			}
		}
		else {
			if (wld[int(mapPos[0] + (mapPos[1] + yDir) * worldSize)]) {
				return { ylen, 1, float(mapPos[0]), float((mapPos[1] + yDir)) };
			}
			else {
				mapPos[1] += yDir;
				ylen += yScale;
			}
		}
		if (xlen >= maxDistance and ylen >= maxDistance) {
			return { maxDistance, 0, 0, 0 };
		}
	}
}