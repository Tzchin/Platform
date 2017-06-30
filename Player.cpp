#include "Player.h"

Player::Player(Vec _pos, int _width, int _height, int _speed) : MovableBody(_pos, _width, _height)
{
	speed = _speed;
}

