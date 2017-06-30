#pragma once
#include <iostream>
using namespace std;
struct Vec
{
	int x;
	int y;
};

ostream& operator<<(ostream& os, Vec& co);