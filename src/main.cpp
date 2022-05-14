#include "RunningGame/Application.h"
#include "Input/PlayerInput.h"

#include <memory>
#include <random>


int main()
{
    Tetris::Application game;
    game.runGameLoop();
    return 0;
}
