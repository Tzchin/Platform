#include "StaticTriangle.h"

StaticTriangle::StaticTriangle(ofPoint pos, int _width, int _height) : StaticBody(_width, _height)
{
	ofPoint yCorner;
	ofPoint xCorner;
	xCorner = pos;
	xCorner.x += width;
	yCorner = pos;
	yCorner.y += height;

	poly.push_back(pos);
	poly.push_back(xCorner);
	poly.push_back(yCorner);

}

bool StaticTriangle::checkCollision(MovableBody *obj, Vec pos)
{
	return 
		((ofInsidePoly(obj->getTL(pos).x, obj->getTL(pos).y, poly)) //Checks if Corners of rect inside trig
		|| (ofInsidePoly(obj->getTR(pos).x, obj->getTR(pos).y, poly))
		|| (ofInsidePoly(obj->getBR(pos).x, obj->getBR(pos).y, poly))
		|| (ofInsidePoly(obj->getBL(pos).x, obj->getBL(pos).y, poly))

		|| (ofInRange(poly[1].x, obj->getTL(pos).x, obj->getBR(pos).x) //Checks if Corners of tri in rect
			&& ofInRange(poly[1].y, obj->getTL(pos).y, obj->getBR(pos).y))
		|| (ofInRange(poly[2].x, obj->getTL(pos).x, obj->getBR(pos).x)
			&& ofInRange(poly[2].y, obj->getTL(pos).y, obj->getBR(pos).y))
		
		
			);
}

bool StaticTriangle::checkCollision(MovableBody * obj)
{
	return false;
}

Vec StaticTriangle::getTL()
{
	Vec pos;
	pos.y = poly[1].y;
	pos.x = poly[1].x;
	return pos;
}

Vec StaticTriangle::getBR()
{
	Vec pos;
	pos.y = poly[2].y;
	pos.x = poly[2].x;
	return pos;
}

void StaticTriangle::draw()
{
	ofDrawTriangle(poly[0], poly[1], poly[2]);
}
