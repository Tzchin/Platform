#pragma once
#include "Vec.h"

class StaticRect
{
public:
	StaticRect(Vec _TL, Vec _BR);
	StaticRect(Vec _TL, int _width, int _height);
	int getWidth();
	int getHeight();
	Vec getTL();
	Vec getBR();

private:
	Vec TL;
	Vec TR;
	Vec BL;
	Vec BR;
	int width;
	int height;

};