//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GAMELOADER_H
#define TETRISEXAM_GAMELOADER_H

#include "../GameState/TetrisGameState.h"

namespace Tetris
{
    class GameLoader
    {
    public:
        static State::TetrisGameState loadGame();
    };
}


#endif //TETRISEXAM_GAMELOADER_H
