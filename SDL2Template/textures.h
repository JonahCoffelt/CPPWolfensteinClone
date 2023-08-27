#pragma once
#include "iostream"
#include "vector"

using std::vector;

class textureMap {
public:
	int getTexture(int pixel, int value);
private:
	int wall[16 * 16][4] = { {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {36, 58, 60, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255}, {29, 46, 48, 255} };
	int wood[16 * 16][4] = { {32, 22, 17, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {67, 51, 38, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {46, 30, 22, 255}, {46, 30, 22, 255}, {46, 30, 22, 255}, {46, 30, 22, 255}, {46, 30, 22, 255}, {46, 30, 22, 255}, {46, 30, 22, 255}, {46, 30, 22, 255}, {46, 30, 22, 255}, {46, 30, 22, 255}, {46, 30, 22, 255}, {46, 30, 22, 255}, {46, 30, 22, 255}, {46, 30, 22, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {57, 42, 30, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {32, 22, 17, 255}, {32, 22, 17, 255} };
};