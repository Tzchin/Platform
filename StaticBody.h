#pragma once
#include "MovableBody.h"

class MovableBody;

class StaticBody
{
public:

	int getWidth();
	int getHeight();
	virtual bool checkCollision(MovableBody *obj) = 0;
	virtual bool checkCollision(MovableBody * obj, Vec pos) = 0;
	StaticBody(int _width, int _height);
	virtual Vec getTL() = 0;
	virtual Vec getBR() = 0;
	virtual void draw() = 0;

private:

protected:


	int width;
	int height;

};