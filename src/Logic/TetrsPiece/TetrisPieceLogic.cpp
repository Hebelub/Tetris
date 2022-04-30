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
    { }

    bool TetrisPieceLogic::tryFallOnce()
    {
        auto newPos = m_activePiece.getPosition();
        newPos.y -= 1;
        if (canMoveTo(newPos))
        {
            moveTo(newPos);
            std::cout << m_activePiece.getPosition().y << std::endl;
            return true;
        }
        else
        {
            std::cout << m_activePiece.getPosition().y << std::endl;

            return false;
        }
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
        clearCoveredCells();

        m_activePiece.setPosition(newPosition);

        instantiateTiles();
    }

    bool TetrisPieceLogic::canMoveTo(sf::Vector2i position)
    {
        for (auto cell : getCellsWhenAt(position))
        {
            if (cell->hasTile() && cell->getTile().getType() == State::TetrisTile::Solid)
                return false;
        }
        return true;
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
        for (auto cell : getCoveredCells())
        {
            cell->setTile(*m_activePiece.getPiece().getTiles().front().tile);
        }
    }

    void TetrisPieceLogic::clearCoveredCells()
    {
        for (auto cell : getCoveredCells())
        {
            cell->setEmpty();
        }
    }

    std::vector<State::GridCellState*> TetrisPieceLogic::getCoveredCells()
    {
        return getCellsWhenAt(
                sf::Vector2i (
                    m_activePiece.getPosition().x,
                    m_activePiece.getPosition().y
                    )
                );
    }

    std::vector<State::GridCellState *> TetrisPieceLogic::getCellsWhenAt(sf::Vector2i cellsAt)
    {
        std::vector<State::GridCellState*> cells;

        for (const State::TetrisPiece::TetrisPieceRelativeToCenter &tile : m_activePiece.getPiece().getTiles())
        {
            int x = cellsAt.x + tile.xOffset;
            int y = cellsAt.y + tile.yOffset;

            if(m_gridState.isInside(x, y))
                cells.push_back(&m_gridState.getCellAt(x, y));
        }

        return cells;
    }

    void TetrisPieceLogic::spawnNewPiece()
    {
        // m_activePiece.setPiece();
        moveTo(
                sf::Vector2i(
                        m_gridState.width() / 2,
                        m_gridState.height()
                )
        );
    }

} // Tetris::Logic