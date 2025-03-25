#pragma once
#include <iostream>
#include "KeyCommand.h"
#include <windows.h>
#include <conio.h>
#include <vector>
#include <ctime>
#include <chrono>
#include "point.h"
#include "Keyboard.h"
#include "Console.h"
#include "Mouse.h"
#include "Snake.h"
using namespace std;

#define key_UP 72
#define key_DOWN 80
#define key_LEFT 75
#define key_RIGHT 77
#define key_ESCAPE 27

class GameRunner
{
private:
	KeyCommand keyPress;
	float repeat;
	Mouse m1;
	Snake s1;
public:
	GameRunner();
	GameRunner(float repeat, KeyCommand k);

	void RunGame();
};