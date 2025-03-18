#include "GameRunner.h"

GameRunner::GameRunner()
{
}

GameRunner::GameRunner(float r, KeyCommand kP)
{
    repeat = r;
    keyPress = kP;
}

void GameRunner::RunGame()
{
    Keyboard k1;

    chrono::time_point<chrono::system_clock> runTime;
    chrono::time_point<chrono::system_clock> currentTime;
    runTime = std::chrono::system_clock::now();
    Sleep(300);

    point playerloc = { 0, 10 };
    KeyCommand direction;
    int length = 5;

    //Loop to start drawing and playing.
    while (k1.KeyPress(keyPress) != KeyCommand::quit) {

    direction = k1.KeyPress(keyPress);

    currentTime = chrono::system_clock::now();

    double elapsedTime = chrono::duration_cast<chrono::milliseconds>(currentTime - runTime).count();
    if (elapsedTime > repeat * 1000) {
        runTime = chrono::system_clock::now();

        //Most of your game logic goes here.

        Console::txtPlot(playerloc, 31);

        _cprintf("Length: %i", length);


    }

    Sleep(10);
    }
}


