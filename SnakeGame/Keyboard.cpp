#include "Keyboard.h"

KeyCommand Keyboard::KeyPress(KeyCommand direction)
{
    //KeyCommand direction = KeyCommand::none;

    if (_kbhit())
    {
        int keypress = _getch();
        switch (keypress)
        {
        case key_LEFT:
            direction = KeyCommand::left;
            break;

        case key_RIGHT:
            direction = KeyCommand::right;
            break;

        case key_UP:
            direction = KeyCommand::up;
            break;

        case key_DOWN:
            direction = KeyCommand::down;
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