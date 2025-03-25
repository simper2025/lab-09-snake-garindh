#pragma once
#include <windows.h>
#include <conio.h>
#include <vector>
#include <ctime>
#include <chrono>
#include "point.h"

using namespace std;


class Console
{
private:
	static void gotoxy(int x, int y);
	static void setcolor(WORD color);

public:
	static void txtPlot(point item, unsigned char Color);
};