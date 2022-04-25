
#ifndef TETRISEXAM_GAMELOADER_H
#define TETRISEXAM_GAMELOADER_H

#include "../GameState/TetrisGameState.h"

namespace Tetris
{
    /// @brief Load info from a previous game from a json file.
    class GameLoader
    {
    public:
        /// @brief Load score, state etc from a jsonfile.
        static State::TetrisGameState loadGame();
    };
} // End namespace Tetris

#endif // TETRISEXAM_GAMELOADER_H
