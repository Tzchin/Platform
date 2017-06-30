#pragma once
#include "MovableBody.h"

class Player : public MovableBody
{
public:
	Player(Vec _pos, int _width, int _height, int _speed);
	void moveLeft();
	void moveRight();
private:

};