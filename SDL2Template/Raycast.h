#pragma once
#include "iostream"
#include "cmath"
#include "vector"
#include "SDL.h"
#include "textures.h"
using std::vector;

class Raycaster {
public: 
    vector<float> raycast(vector<float> position, vector<float> endPosition, int gridSize, int wld[], int worldSize);
    void castToScreen(SDL_Renderer* renderer, float FOV, int resolution, vector<float> playerPos, float playerDirection, float playerDirY, float playerPosY, float gridSize, int wld[], int worldSize, float heightMap[]);

private:
	float distance;
	float hitPoint[2] = { 0, 0 };
	float lineHeight;
	float da;
	bool side;
	textureMap* textureMapWall = new textureMap();
};
