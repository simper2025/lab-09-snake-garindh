#include "Keyboard.h"

KeyCommand Keyboard::KeyPress(KeyCommand direction)
{

	if (_kbhit())
	{
		int keyPress = _getch();

		switch (keyPress)
		{
		case key_A:
		case key_LEFT:
			if (direction != KeyCommand::right)
			{
				direction = KeyCommand::left;
			}
			break;

		case key_D:
		case key_RIGHT:
			if (direction != KeyCommand::left)
			{
				direction = KeyCommand::right;
			}
			break;

		case key_W:
		case key_UP:
			if (direction != KeyCommand::down)
			{
				direction = KeyCommand::up;
			}
			break;

		case key_S:
		case key_DOWN:
			if (direction != KeyCommand::up)
			{
				direction = KeyCommand::down;
			}
			break;

		case key_ESCAPE:
			direction = KeyCommand::quit;
			break;

		default:
			break;
		}

	}
	return direction;
}