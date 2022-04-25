#include "RunningGame/RunningGame.h"
#include "RunningGame/TetrisGameManager.h"

#include <memory>

namespace Tetris
{
    void initiateTetrisGame()
    {
        auto game = std::make_unique<Tetris::TetrisGameManager>();

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
