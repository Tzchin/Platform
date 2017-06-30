#include "StaticRect.h"

StaticRect::StaticRect(Vec _TL, Vec _BR)
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

StaticRect::StaticRect(Vec _TL, int _width, int _height) : width(_width), height(_height)
{
	TL = _TL;
	BL.x = _TL.x;
	BL.y = _TL.y + height;
	TR.x = _TL.x + width;
	TR.y = _TL.y;
	BR.x = _TL.x + width;
	BR.y = _TL.y + height;
}

int StaticRect::getWidth()
{
	return width;
}

int StaticRect::getHeight()
{
	return height;
}

Vec StaticRect::getTL()
{
	return TL;
}

Vec StaticRect::getBR()
{
	return BR;
}
