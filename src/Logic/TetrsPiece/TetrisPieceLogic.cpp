//
// Created by glosn on 4/28/2022.
//

#include "TetrisPieceLogic.h"
#include "../../GameState/TetrisPiece.h"
#include <utility>
#include <vector>
#include <iostream>

namespace Tetris::Logic
{
    TetrisPieceLogic::TetrisPieceLogic(State::TetrisPiece &piece, State::Grid &grid)
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
            return true;
        }
        else
        {
            return false;
        }
    }

    bool TetrisPieceLogic::tryMoveOnceRight()
    {
        auto newPos = m_activePiece.getPosition();
        newPos.x += 1;
        if (canMoveTo(newPos))
        {
            moveTo(newPos);
            return true;
        }
        else
        {
            return false;
        }
    }

    bool TetrisPieceLogic::tryMoveOnceLeft()
    {
        auto newPos = m_activePiece.getPosition();
        newPos.x -= 1;
        if (canMoveTo(newPos))
        {
            moveTo(newPos);
            return true;
        }
        else
        {
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
        for (const auto &[offset, tile] : m_activePiece.getShape().getTiles())
        {
            m_gridState.getCellAt(
                    m_activePiece.getPosition().x + offset.x,
                    m_activePiece.getPosition().y + offset.y
            ).setTile(tile);
        }
        return true;
    }

    void TetrisPieceLogic::instantiateTiles()
    {
        for (auto cell : getCoveredCells())
        {
            cell->setTile(m_activePiece.getShape().getTiles().front().tile);
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

        for (const auto &[offset, tile] : m_activePiece.getShape().getTiles())
        {
            int x = cellsAt.x + offset.x;
            int y = cellsAt.y + offset.y;

            if(m_gridState.isInside(x, y))
                cells.push_back(&m_gridState.getCellAt(x, y));
        }

        return cells;
    }

    void TetrisPieceLogic::spawnNewPiece()
    {
        // m_activePiece.setShape();
        moveTo(
                sf::Vector2i(
                        m_gridState.width() / 2,
                        m_gridState.height()
                )
        );
    }

} // Tetris::Logic