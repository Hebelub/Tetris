//
// Created by glosn on 4/23/2022.
//

#include "TetrisGameState.h"

namespace Tetris::State
{
    TetrisGameState::TetrisGameState()
    = default;

    TetrisPiece TetrisGameState::useNextTetris()
    {
        return m_upcomingPieces.front();
    }

    void TetrisGameState::addTetrisLast(TetrisPiece tetrisPiece)
    {
        m_upcomingPieces.push_back(tetrisPiece);
    }

    TetrisGridState TetrisGameState::getGridState() const
    {
        return m_gameGrid;
    }

}
