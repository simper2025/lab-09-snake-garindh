#pragma once
#include "Point.h"
#include "Console.h"
#include <random>
using namespace std;

class Mouse
{
private:
	point position;
public:
	Mouse();
	Mouse(point pos);
	point GetPosition();
	void SetPosition(point pos);
	void Move();
	void Draw();
};