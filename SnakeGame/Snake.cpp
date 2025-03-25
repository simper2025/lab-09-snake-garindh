#include "Snake.h"

Snake::Snake()
{
	headColor = 68;
	bodyColor = 204;
	headLoc = { 1,10 };
	direction = { 0,0 };
	length = 5;
}

Snake::Snake(int hC, int bC)
{
	headColor = hC;
	bodyColor = bC;
	headLoc = { 0,10 };
	direction = { 0,0 };
	length = 5;
}

int Snake::GetLength()
{
	return length;
}

point Snake::GetHeadLoc()
{
	return headLoc;
}

int Snake::GetHeadColor()
{
	return headColor;
}

void Snake::Move(KeyCommand keyPress)
{
	switch (keyPress)
	{
	case KeyCommand::left:
		direction = { -1, 0 };
		break;

	case KeyCommand::right:
		direction = { 1, 0 };
		break;

	case KeyCommand::up:
		direction = { 0, -1 };
		break;

	case KeyCommand::down:
		direction = { 0, 1 };
		break;

	default:
		break;
	}

	headLoc = { headLoc.x + direction.x, headLoc.y + direction.y };
	Console::txtPlot(headLoc, headColor);
}


