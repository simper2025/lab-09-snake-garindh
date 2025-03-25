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
	headLoc = { 1,10 };
	direction = { 0,0 };
	length = 5;
}

int Snake::GetLength()
{
	return length;
}

void Snake::SetLength(int l)
{
	length = l;
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
	tail.push_back(headLoc);
	headLoc = { headLoc.x + direction.x, headLoc.y + direction.y };
	Draw();
}

void Snake::Draw()
{
	Console::txtPlot(headLoc, headColor);
	if (tail.size() > length)
	{
		Console::txtPlot(tail[0], 170);
		tail.erase(tail.begin() + 0);
	}
	Console::txtPlot(tail[tail.size() - 1], bodyColor);
}

vector<point> Snake::GetTailLocs()
{
	vector<point> tLocs;
	for (int i = 0; i < tail.size(); i++)
	{
		tLocs.push_back(tail[i]);
	}
	return tLocs;
}
