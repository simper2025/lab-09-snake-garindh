#include "GameRunner.h"

GameRunner::GameRunner()
{
	repeat = 0.3;
	direction = KeyCommand::none;
}

GameRunner::GameRunner(float r, KeyCommand k)
{
	repeat = r;
	direction = k;
}

void GameRunner::RunGame()
{
	Keyboard k1;
	point max = { 15,15 };
	point playerLoc = s1.GetHeadLoc();
	vector<point> tailLocs = s1.GetTailLocs();
	int length = s1.GetLength();
	int hC = s1.GetHeadColor();
	bool endGame = false;

	chrono::time_point<chrono::system_clock> runTime;
	chrono::time_point<chrono::system_clock> currentTime;
	runTime = std::chrono::system_clock::now();
	Sleep(300);


	for (int i = 0; i <= 15; i++)
	{
		for (int j = 0; j <= 15; j++)
		{
			Console::txtPlot({ i,j }, 170);
			if (i == max.x || i == 0 || j == max.y || j == 0)
			{
				Console::txtPlot({ i,j }, 34);
			}
		}
	}
	m1.Move(max, tailLocs);
	Console::txtPlot(playerLoc, 68);
	//Loop to start drawing and playing.
	while (direction != KeyCommand::quit && endGame == false)
	{

		direction = k1.KeyPress(direction);

		currentTime = chrono::system_clock::now();

		double elapsedTime = chrono::duration_cast<chrono::milliseconds>(currentTime - runTime).count();
		if (elapsedTime > repeat * 1000)
		{
			runTime = chrono::system_clock::now();
	

			//Most of your game logic goes here.
			if (!s1.CanMove(direction, max))
			{
				endGame = true;
			}
			s1.Move(direction);
			if (s1.GetHeadLoc() == m1.GetPosition())
			{
				length++;
				s1.SetLength(length);
				tailLocs = s1.GetTailLocs();
				m1.Move(max, tailLocs);
			}
		}

		Console::txtPlot({ 0,max.y + 1 }, 15);
		_cprintf("Length: %i", length);
		Sleep(10);
	}
}


