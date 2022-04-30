//
// Created by glosn on 4/28/2022.
//

#include "TetrisPieceLogic.h"
#include "../../GameState/ActiveTetrisPiece.h"
#include <utility>
#include <vector>
#include <iostream>

namespace Tetris::Logic
{
    TetrisPieceLogic::TetrisPieceLogic(State::ActiveTetrisPiece &piece, State::GridState &grid)
        : m_activePiece(piece)
        , m_gridState(grid)
    {
        instantiateTiles();
    }

    bool TetrisPieceLogic::tryFallOnce()
    {
        std::cout << "Trying to fall once" << std::endl;
        return true;
    }

    int TetrisPieceLogic::fallToTheBottom()
    {
        return 0;
    }

    bool TetrisPieceLogic::tryRotateRight()
    {
        return true;
    }

    bool TetrisPieceLogic::tryRotateLeft()
    {
        return true;
    }

    void TetrisPieceLogic::getBottomCells()
    {

    }

    void TetrisPieceLogic::updatePosition()
    {

    }

    void TetrisPieceLogic::moveTo(sf::Vector2i newPosition)
    {

    }

    void TetrisPieceLogic::canMoveTo(sf::Vector2i position)
    {

    }

    bool TetrisPieceLogic::makePieceSolid()
    {
        for (const State::TetrisPiece::TetrisPieceRelativeToCenter &tile : m_activePiece.getPiece().getTiles())
        {
            m_gridState.getCellAt(
                    m_activePiece.getPosition().x + tile.xOffset,
                    m_activePiece.getPosition().y + tile.yOffset
            ).setTile(*(tile.tile));
        }
        return true;
    }

    void TetrisPieceLogic::instantiateTiles()
    {
        for (auto &cell : getCoveredCells())
        {
            // cell.setTile(m_currentPiece.getTiles().front().tile);
        }
    }

    void TetrisPieceLogic::removeCoveredCells()
    {
        for (State::GridCellState &cell : getCoveredCells())
        {
            cell.setEmpty();
        }
    }

    std::vector<State::GridCellState> TetrisPieceLogic::getCoveredCells()
    {
        std::vector<State::GridCellState> cells;

        for (const State::TetrisPiece::TetrisPieceRelativeToCenter &tile : m_activePiece.getPiece().getTiles())
        {
            int x = m_activePiece.getPosition().x + tile.xOffset;
            int y = m_activePiece.getPosition().y + tile.yOffset;

            if(m_gridState.isInside(x, y))
                cells.push_back(m_gridState.getCellAt(x, y));
        }

        return cells;
    }

} // Tetris::Logic