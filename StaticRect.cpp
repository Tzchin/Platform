#include "StaticRect.h"

StaticRect::StaticRect(Vec _TL, Vec _BR) : StaticBody(0,0)
{
	TL = _TL;
	BR = _BR;

	BL.x = TL.x;
	BL.y = BR.y;

	TR.x = _BR.x;
	TR.y = _TL.y;

	width = TR.x - TL.x;
	height = BL.y - TL.y;
}

StaticRect::StaticRect(Vec _TL, int _width, int _height) : StaticBody(_width, _height)
{
	TL = _TL;
	BL.x = _TL.x;
	BL.y = _TL.y + height;
	TR.x = _TL.x + width;
	TR.y = _TL.y;
	BR.x = _TL.x + width;
	BR.y = _TL.y + height;
}

void StaticRect::draw()
{
	ofDrawRectangle(TL.x, TL.y, width, height);
}

Vec StaticRect::getTL()
{
	return TL;
}

Vec StaticRect::getBR()
{
	return BR;
}

bool StaticRect::checkCollision(MovableBody * obj)
{

	return ((obj->getTL().x < this->getBR().x && obj->getBR().x > this->getTL().x) //Checks x-axis alignment
		&& (obj->getTL().y < this->getBR().y && obj->getBR().y > this->getTL().y)); //Checks y-axis alignment
}

bool StaticRect::checkCollision(MovableBody * obj, Vec pos)
{
	return ((obj->getTL(pos).x < this->getBR().x && obj->getBR(pos).x > this->getTL().x) //Checks x-axis alignment
		&& (obj->getTL(pos).y < this->getBR().y && obj->getBR(pos).y > this->getTL().y)); //Checks y-axis alignment
}
