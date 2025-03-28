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
	void SetLength(int l);
	point GetHeadLoc();
	int GetHeadColor();
	bool CanMove(KeyCommand kP, point max);
	void Move(KeyCommand kP);
	void Draw();
	vector<point> GetTailLocs();
};