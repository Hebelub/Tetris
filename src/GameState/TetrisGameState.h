//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_TETRISGAMESTATE_H
#define TETRISEXAM_TETRISGAMESTATE_H

#include <list>
#include "TetrisGridState.h"
#include "TetrisPiece.h"

namespace Tetris::State
{
    class TetrisGameState
    {
    public:
        TetrisGameState();


        // TODO: The logic inside here should maybe be moved out?s
        TetrisPiece useNextTetris();
        void addTetrisLast(TetrisPiece);

    private:
        std::list<TetrisPiece> m_upcomingPieces;
        TetrisGridState *m_gameGrid{};

    };

} // Tetris::State


#endif //TETRISEXAM_TETRISGAMESTATE_H
