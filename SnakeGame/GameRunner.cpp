#include "GameRunner.h"

GameRunner::GameRunner()
{
	repeat = 0.3;
	keyPress = KeyCommand::none;
	m1.Move();
}

GameRunner::GameRunner(float r, KeyCommand kP)
{
	repeat = r;
	keyPress = kP;
	m1.Move();
}

void GameRunner::RunGame()
{
	Keyboard k1;

	chrono::time_point<chrono::system_clock> runTime;
	chrono::time_point<chrono::system_clock> currentTime;
	runTime = std::chrono::system_clock::now();
	Sleep(300);

	point playerLoc = s1.GetHeadLoc();
	KeyCommand direction = KeyCommand::right;
	int length = s1.GetLength();

	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{

			Console::txtPlot({ i,j }, 170);
		}
	}
	m1.Move();
	Console::txtPlot(playerLoc, 164);
	//Loop to start drawing and playing.
	while (k1.KeyPress(direction) != KeyCommand::quit) {

		direction = k1.KeyPress(direction);
		currentTime = chrono::system_clock::now();

		double elapsedTime = chrono::duration_cast<chrono::milliseconds>(currentTime - runTime).count();
		if (elapsedTime > repeat * 1000) {
			runTime = chrono::system_clock::now();

			//Most of your game logic goes here.

			s1.Move(direction);

		}

		Console::txtPlot({ 0,21 }, 15);
		_cprintf("Length: %i", length);
		Sleep(10);
	}
}


