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

    int ActiveTetrisPiece::fallToTheBottom()
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

    void ActiveTetrisPiece::moveTo(sf::Vector2i newPosition)
    {

    }

    void ActiveTetrisPiece::canMoveTo(sf::Vector2i position)
    {

    }
    
    bool ActiveTetrisPiece::makePieceSolid()
    {
        return false;
    }

    void ActiveTetrisPiece::instantiateTiles()
    {

    }

    void ActiveTetrisPiece::removeOccupiedTiles()
    {

    }

} // Tetris::Logic