#include "RunningGame/Game.h"
#include "RunningGame/GameManager.h"

#include <memory>

namespace Tetris
{
    void initiateTetrisGame()
    {
        auto game = std::make_unique<Tetris::GameManager>();

        game->openGameWindow();
        game->initiateARunningGame();
        game->runGameLoop();
    }
} // end of namespace Tetris

int main()
{
    Tetris::initiateTetrisGame();

    return 0;
}
