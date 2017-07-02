#pragma once
#include <iostream>
using namespace std;
struct Vec
{
	float x;
	float y;
};

ostream& operator<<(ostream& os, Vec& co);
