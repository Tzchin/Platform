#pragma once
#include "ofMain.h"
#include "Vec.h"
#include "StaticBody.h"
//#include "ofApp.h"
#include <vector>

class StaticBody;
class StaticRect;

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
	void updatePos(vector<StaticBody*> walls);
	bool checkCollision(StaticBody * wall);
	bool checkCollision(StaticBody * wall, Vec pos);

private:

protected:
	Vec position;
	int width;
	int height;
	int speed;
    ofPoint acceleration;
    ofPoint velocity;
	void translate(Vec * co, float x, float y);	//Add Checks Later?
	bool moving;
	bool movingLeft;
	bool movingRight;
	bool inJump;
	bool canJump;
	bool onGround();
};
