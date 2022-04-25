//
// Created by glosn on 4/23/2022.
//

#include "TetrisGridState.h"
#include "TetrisPiece.h"
#include "TetrisGameState.h"

namespace Tetris::State
{

    TetrisPiece TetrisGameState::useNextTetris()
    {
        return m_upcomingPieces.front();
    }

    void TetrisGameState::addTetrisLast(TetrisPiece tetrisPiece)
    {
        m_upcomingPieces.push_back(tetrisPiece);
    }

} // Tetris::State