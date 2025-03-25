//This is a frameword to allow you to focus on the game logic.
//Most of your code will go in three locations. 
//Function decalrations, game logic in runGame, and the function declarations.

#include <windows.h>
#include <conio.h>
#include <vector>
#include <ctime>
#include <chrono>
#include "point.h"
#include "GameRunner.h"
using namespace std;

#define key_UP 72
#define key_DOWN 80
#define key_LEFT 75
#define key_RIGHT 77
#define key_ESCAPE 27

//This is a struct (aka structure) it reduces the number of variables needed.

//keypress keeps track of what the last pressed key. It is global, but could be made local.


//Add function declarations here

void setcolor(WORD color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    return;
}


int main()
{

  /*  Uncomment the next four lines to see console color options 0-255*/
    //for (int i = 0; i < 255; i++) {
    //    setcolor(i);
    //    _cprintf("Color option: %i. Hello, world.\n", i);
    //}
   
    GameRunner game1(.3, KeyCommand::right);
	game1.RunGame();
	return 0;
}




//These are helper funcitons to capture keyboard and draw to the console.

