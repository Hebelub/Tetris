//
// Created by glosn on 4/23/2022.
//

#include "GameState.h"

// TODO FINISH IMPLEMENTATION
namespace Tetris::State
{
    GameState::GameState()
    = default;

    TetrisPiece GameState::useNextTetris()
    {
        return m_upcomingPieces.front();
    }

    void GameState::addTetrisLast(TetrisPiece tetrisPiece)
    {
        m_upcomingPieces.push_back(tetrisPiece);
    }

    TetrisGridState &GameState::getGridState()
    {
        return m_gameGrid;
    }
}
