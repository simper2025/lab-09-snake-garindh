#pragma once
#include "point.h"
#include "KeyCommand.h"
#include <windows.h>
#include <conio.h>
#include <vector>
#include <ctime>
#include <chrono>

#define key_UP 72
#define key_DOWN 80
#define key_LEFT 75
#define key_RIGHT 77
#define key_ESCAPE 27
using namespace std;

class Keyboard
{
private:

public:
	KeyCommand KeyPress(KeyCommand direction);

};