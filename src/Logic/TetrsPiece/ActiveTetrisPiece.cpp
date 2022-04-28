//
// Created by glosn on 4/28/2022.
//

#include "ActiveTetrisPiece.h"

namespace Tetris::Logic
{
    ActiveTetrisPiece::ActiveTetrisPiece(State::GridState &grid)
        : m_gridState(grid)
    {

    }

    bool ActiveTetrisPiece::tryFallOnce()
    {

    }

<<<<<<< HEAD
    int ActiveTetrisPiece::fallToTheBottom()
=======
    bool ActiveTetrisPiece::fallToTheBottom()
>>>>>>> 8b626a86cdf76e88d194a0fb76b77ab9a0b1b038
    {

    }

    bool ActiveTetrisPiece::tryRotateRight()
    {

    }

    bool ActiveTetrisPiece::tryRotateLeft()
    {

    }

    void ActiveTetrisPiece::getBottomCells()
    {

    }

    void ActiveTetrisPiece::updatePosition()
    {

    }

    bool ActiveTetrisPiece::makePieceSolid()
    {
        return false;
    }
} // Tetris::Logic