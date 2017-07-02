#pragma once
#include "ofMain.h"
#include "Vec.h"
#include "StaticRect.h"
//#include "ofApp.h"
#include <vector>

class MovableBody
{
public:
	Vec getPos();
	Vec getTL();
	Vec getTR();
	Vec getBL();
	Vec getBR();
	Vec getTL(Vec pos);
	Vec getTR(Vec pos);
	Vec getBL(Vec pos);
	Vec getBR(Vec pos);
	int getHeight();
	int getWidth();
	bool isMoving();
	MovableBody(Vec _pos, int _width, int _height);
	void moveRight();
	void stopRight();
	void moveLeft();
	void stopLeft();
	void jump();
	void updatePos();
	void updatePos(vector<StaticRect*> walls);
	bool checkCollision(StaticRect * wall);
	bool checkCollision(StaticRect * wall, Vec pos);

private:

protected:
	Vec position;
	int width;
	int height;
	int speed;
    ofVec2f acceleration;
    ofVec2f velocity;
	void translate(Vec * co, float x, float y);	//Add Checks Later?
	bool moving;
	bool movingLeft;
	bool movingRight;
	bool inJump;
	bool canJump;
	bool onGround();
};
