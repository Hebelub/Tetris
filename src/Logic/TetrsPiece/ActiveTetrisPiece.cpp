//
// Created by glosn on 4/28/2022.
//

#include "ActiveTetrisPiece.h"

namespace Tetris::Logic
{
    ActiveTetrisPiece::ActiveTetrisPiece(State::TetrisPiece &piece, State::GridState &grid)
        : m_currentPiece(piece)
        , m_gridState(grid)
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
        for (State::GridCellState &cell : getCoveredCells())
        {
            cell.setEmpty();
        }
    }

    std::vector<State::GridCellState> &ActiveTetrisPiece::getCoveredCells()
    {
        std::vector<State::GridCellState> cells;

        for (State::TetrisPiece::TetrisPieceRelativeToCenter &tile : m_currentPiece.getTiles())
        {
            cells.push_back(
                    m_gridState.getCellAt(
                            m_position.x + tile.xOffset,
                            m_position.y + tile.yOffset
                    ));
        }

        return cells;
    }

} // Tetris::Logic