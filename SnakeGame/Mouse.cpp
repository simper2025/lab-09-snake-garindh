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

void Mouse::Move()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> rand(1, 15);
	//uniform_int_distribution<int> randY(1, 20);
	int locX = rand(gen);
	int locY = rand(gen);

	position.x = locX;
	position.y = locY;
	Draw();
}

void Mouse::Draw()
{
	Console::txtPlot(position, 181);
}
