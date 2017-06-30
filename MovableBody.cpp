#include "MovableBody.h"
#include <ctgmath>

Vec MovableBody::getPos()
{
	return position;
}

Vec MovableBody::getTL()
{
	Vec co;
	co.x = position.x - (width / 2);
	co.y = position.y - (height / 2);
	return co;
}

Vec MovableBody::getTR()
{
	Vec co;
	co.x = position.x + (width / 2);
	co.y = position.y - (height / 2);
	return co;
}

Vec MovableBody::getBL()
{
	Vec co;
	co.x = position.x - (width / 2);
	co.y = position.y + (height / 2);
	return co;
}

Vec MovableBody::getBR()
{
	Vec co;
	co.x = position.x + (width / 2);
	co.y = position.y + (height / 2);
	return co;
}

Vec MovableBody::getTL(Vec pos)
{
	Vec co;
	co.x = pos.x - (width / 2);
	co.y = pos.y - (height / 2);
	return co;
}

Vec MovableBody::getTR(Vec pos)
{
	Vec co;
	co.x = pos.x + (width / 2);
	co.y = pos.y - (height / 2);
	return co;
}

Vec MovableBody::getBL(Vec pos)
{
	Vec co;
	co.x = pos.x - (width / 2);
	co.y = pos.y + (height / 2);
	return co;
}

Vec MovableBody::getBR(Vec pos)
{
	Vec co;
	co.x = pos.x + (width / 2);
	co.y = pos.y + (height / 2);
	return co;
}

int MovableBody::getHeight()
{
	return height;
}

int MovableBody::getWidth()
{
	return width;
}

bool MovableBody::isMoving()
{
	return moving;
}

MovableBody::MovableBody(Vec _pos, int _width, int _height) : position(_pos), width(_width), height(_height)
{
	moving = false;
	movingLeft = false;
	movingRight = false;
	inJump = false;
}

void MovableBody::updatePos() //No collision detection
{
	Vec d;
	d.x = 0;
	d.y = 0;
	if (movingLeft)
	{
		d.x += -speed;
	}
	if (movingRight)
	{
		d.x += speed;
	}

	if (d.x == 0 && d.y == 0)
	{
		moving = false;
	}
	else
	{
		moving = true;
		translate(&position, d.x, d.y);
	}

}

void MovableBody::updatePos(vector <StaticRect *> walls) //Also does collision detection
{
	Vec d;
	d.x = 0;
	d.y = 0;
	static float yVelocity = 0;
	static int time = 0;
	if (movingLeft)
	{
		d.x += -speed;
	}
	if (movingRight)
	{
		d.x += speed;
	}
	if (!inJump)
	{
		yVelocity = ceilf((1.0 / 8.0) * (time + 1)); //Hard coded constants
		d.y = yVelocity;
		time++;
/*		if (d.y > 5)
		{
			d.y = 5;
			yVelocity = 5;
		}*/
	}
	else //Calculates Jump
	{
		if (time <= 60) //Hard coded constants
		{
			yVelocity = float((1.0/8.0) * (time - 60));
			d.y = yVelocity;
			time++;
		}
		else
		{
			inJump = false;
			time = 0;
		}
	}

	if (d.x == 0 && d.y == 0)
	{
		moving = false;
	}
	else
	{
		bool collided = false;

		Vec newXPos = position; //Checks If x vector has collided
		translate(&newXPos, d.x, 0);
		bool xCollided = false;
		for (unsigned int i = 0; i < walls.size() && !xCollided; i++)
		{

			if (checkCollision(walls[i], newXPos))
			{
				xCollided = true;
				if (d.x > 0) //Moving Right
				{
					d.x = walls[i]->getTL().x - getBR(position).x;
				} 
				else if (d.x < 0) //Moving Left
				{
					d.x = walls[i]->getBR().x - getTL(position).x;
				}
			}
		}

		Vec newYPos = position; //Checks If y vector has collided
		translate(&newYPos, 0, d.y);
		bool yCollided = false;
		canJump = false;
		for (unsigned int i = 0; i < walls.size() && !yCollided; i++)
		{

			if (checkCollision(walls[i], newYPos))
			{
				yCollided = true;
				if (d.y < 0) //going up
				{
					d.y = walls[i]->getBR().y - getTL(position).y;
					yVelocity = 0;
					inJump = false;
					time = 0;
					
				}
				else if (d.y > 0) //going down
				{
					d.y = walls[i]->getTL().y - getBR(position).y;
					yVelocity = 0;
					time = 0;
					canJump = true;
				}
			}
		}
		collided = xCollided || yCollided;
		if (!collided) //Checks both
		{
			Vec newPos = position; 
			translate(&newPos, d.x, d.y);
			for (unsigned int i = 0; i < walls.size() && !collided; i++)
			{

				if (checkCollision(walls[i], newPos))
				{
					collided = true;
				}
			}
		}
		if (d.x != 0 || d.y != 0)
		{
			moving = true;
			translate(&position, d.x, d.y);
		}
		else moving = false;
	}

}

bool MovableBody::checkCollision(StaticRect * wall)
{
	return ((this->getTL().x < wall->getBR().x && this->getBR().x > wall->getTL().x) //Checks x-axis alignment
		&& (this->getTL().y < wall->getBR().y && this->getBR().y > wall->getTL().y)); //Checks y-axis alignment
}

bool MovableBody::checkCollision(StaticRect * wall, Vec pos)
{
	return ((this->getTL(pos).x < wall->getBR().x && this->getBR(pos).x > wall->getTL().x) //Checks x-axis alignment
		&& (this->getTL(pos).y < wall->getBR().y && this->getBR(pos).y > wall->getTL().y)); //Checks y-axis alignment
}

void MovableBody::translate(Vec * co, int x, int y)
{

	co->x += x;
	co->y += y;
}

bool MovableBody::onGround()
{
//	checkColli
	return false;
}

void MovableBody::moveLeft()
{
//	moving = true;
	movingLeft = true;
}

void MovableBody::stopLeft()
{
	movingLeft = false;
}

void MovableBody::jump()
{
	if(canJump)
		inJump = true;
}

void MovableBody::moveRight()
{
//	moving = true;
	movingRight = true;
}

void MovableBody::stopRight()
{
	movingRight = false;
}