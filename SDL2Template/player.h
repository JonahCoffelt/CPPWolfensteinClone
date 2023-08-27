#pragma once
#include "iostream"
#include "vector"
using std::vector;

class Player {
public:
	void init(vector<float> pos);
	void move(vector<float> move, float turn, int wld[]);
	void moveY(float move, float turn);
	void update();
	void jump();
	void setVariables(float gridSize, int wldSize);
	float getDirection();
	float getDirY();
	float getPosY();
	vector<float> getPos();
private:
	vector<float> position;
	float positionY;
	float direction;
	float directionY;
	float gridSize;
	float wallBuffer = .3;
	float yDirBuffer = 400;
	int worldSize;
	float velocity = 0;
	float gravity = -.006;
};
