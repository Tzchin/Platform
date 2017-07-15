#pragma once
#include "Vec.h"
#include "StaticBody.h"
#include "MovableBody.h"

class StaticBody;
class MovableBody;

class StaticRect : public StaticBody
{
public:
	StaticRect(Vec _TL, Vec _BR);
	StaticRect(Vec _TL, int _width, int _height);
	void draw();
	Vec getTL();
	Vec getBR();
	bool checkCollision(MovableBody *obj);
	bool checkCollision(MovableBody* obj, Vec pos);
	bool handleCollision(MovableBody * obj, Vec pos, ofPoint adjust);

private:
	Vec TL;
	Vec TR;
	Vec BL;
	Vec BR;


};