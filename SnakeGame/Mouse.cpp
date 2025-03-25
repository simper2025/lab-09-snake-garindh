#include "Mouse.h"

Mouse::Mouse()
{
	position = { 1,1 };
}

Mouse::Mouse(point pos)
{
	position = pos;
}

point Mouse::GetPosition()
{
	return position;
}

void Mouse::SetPosition(point pos)
{
	position = pos;
}

void Mouse::Move(point max, vector<point> tail)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randX(1, max.x - 1);
	uniform_int_distribution<int> randY(1, max.y - 1);
	int locX = randX(gen);
	int locY = randY(gen);
	for (int i = 0; i < tail.size(); i++)
	{
		if (tail[i].x == locX && tail[i].y == locY)
		{
			Move(max, tail);
		}
	}
	position.x = locX;
	position.y = locY;
	Draw();
}

void Mouse::Draw()
{
	Console::txtPlot(position, 181);
}
