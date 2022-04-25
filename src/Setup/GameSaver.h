//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GAMESAVER_H
#define TETRISEXAM_GAMESAVER_H


#include "../GameState/TetrisGameState.h"

namespace Tetris
{
    class GameSaver
    {

        Tetris::State::TetrisGameState loadGameToJson();
        void saveGameToJson(Tetris::State::TetrisGameState const &);


    };
}


#endif //TETRISEXAM_GAMESAVER_H
