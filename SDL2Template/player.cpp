#include "player.h"
#include "iostream"

void Player::init(vector<float> pos) {
	position = pos;
	direction = 3.14 + 3.14/2;
}

void Player::setVariables(float gdSize, int wldSize) {
	gridSize = gdSize;
	worldSize = wldSize;
}

void Player::update() {
	positionY += velocity;
	velocity += gravity;
	if (positionY < 0) {
		velocity = 0;
		positionY = 0;
	}
}

void Player::jump() {
	if (positionY == 0) {
		velocity = .1;
	}
}

vector<float> Player::getPos() {
	return position;
}

float Player::getDirection() {
	return direction;
}

float Player::getDirY() {
	return directionY;
}

float Player::getPosY() {
	return positionY;
}


void Player::moveY(float move, float turn) {
	positionY += move;
	if ((directionY + turn < yDirBuffer) & (directionY + turn > -yDirBuffer)) {
		directionY += turn;
	}
}

void Player::move(vector<float> move, float turn, int wld[]) {
	float projectedX = position[0] + (cos(direction) * move[0] - cos(direction + 3.1415/2) * move[1]) * gridSize;
	float projectedY = position[1] + (sin(direction) * move[0] - sin(direction + 3.1415/2) * move[1]) * gridSize;

	if ((wld[int(projectedX / gridSize + wallBuffer) + int(position[1] / gridSize) * worldSize] == 0) &
		(wld[int(projectedX / gridSize - wallBuffer) + int(position[1] / gridSize) * worldSize] == 0) &
		(int(projectedX / gridSize + wallBuffer) > 0) &
		(int(projectedX / gridSize - wallBuffer) < worldSize - 1))
	{
		position[0] = projectedX;
	}
	if ((wld[int(position[0] / gridSize) + int((projectedY / gridSize) + wallBuffer) * worldSize] == 0) &
		(wld[int(position[0] / gridSize) + int((projectedY / gridSize) - wallBuffer) * worldSize] == 0) &
		(int(projectedY / gridSize + wallBuffer) > 0) &
		(int(projectedY / gridSize - wallBuffer) < worldSize - 1))
	{
		position[1] = projectedY;
	}
	direction += turn;
}