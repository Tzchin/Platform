#pragma once
#include "StaticBody.h"
#include "ofMain.h"
#include "MovableBody.h"
#include "Vec.h"
#include <vector>

class StaticTriangle : public StaticBody
{
public:
	StaticTriangle(ofPoint pos, int _width, int _height);
	bool checkCollision(MovableBody* obj, Vec pos);
	bool checkCollision(MovableBody* obj);
	Vec getTL(); //*
	Vec getBR(); //*
	void draw();
private:

	vector <ofPoint> poly;
};