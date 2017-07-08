#pragma once
#include "StaticBody.h"

StaticBody::StaticBody(int _width, int _height) : width(_width), height(_height)
{

}


int StaticBody::getWidth()
{
	return width;
}

int StaticBody::getHeight()
{
	return height;
}
