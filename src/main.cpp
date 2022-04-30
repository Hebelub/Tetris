#include "RunningGame/Game.h"
#include "RunningGame/GameManager.h"

#include <memory>

int main()
{
    Tetris::GameManager game;

    game.initiateARunningGame();
    game.runGameLoop();

    return 0;
}
