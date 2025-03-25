#pragma once
#include <vector>
#include "Point.h"
#include "KeyCommand.h"
#include "Console.h";
using namespace std;

class Snake
{
private:
	int headColor;
	int bodyColor;
	int length;
	point headLoc;
	vector<point> tail;
	point direction;
public:
	Snake();
	Snake(int hC, int bC);

	int GetLength();
	point GetHeadLoc();
	int GetHeadColor();
	void Move(KeyCommand kP);
};