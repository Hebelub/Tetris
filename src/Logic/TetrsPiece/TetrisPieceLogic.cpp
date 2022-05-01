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
        if (canBeAt(newPos))
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
        if (canBeAt(newPos))
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
        if (canBeAt(newPos))
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

    bool TetrisPieceLogic::canBeAt(sf::Vector2i position)
    {
        for (const auto tile : getTilesAt(position))
        {
            const auto type = tile->getType();
            if (type == State::TetrisTile::Solid || type == State::TetrisTile::OutOfBounds)
            {
                return false;
            }
        }
        return true;
    }

    bool TetrisPieceLogic::makePieceSolid()
    {
        for (auto cell : getCoveredCells())
        {
            auto tile = cell->getTile();
            tile.setType(State::TetrisTile::Solid);
            // tile.setColor(sf::Color::White);
            cell->setTile(tile);
        }
    }

    void TetrisPieceLogic::instantiateTiles()
    {
        for (const auto &[offset, tile] : m_activePiece.getShape().getTiles())
        {
            auto cellPos = m_activePiece.getPosition() + offset;

            if (m_gridState.isInside(cellPos.x, cellPos.y))
            {
                auto& cell = m_gridState.getCellAt(cellPos.x, cellPos.y);
                cell.setTile(tile);
            }
        }
    }

    void TetrisPieceLogic::clearCoveredCells()
    {
        for (auto cell : getCoveredCells())
        {
            cell->setEmpty();
        }
    }

    std::vector<State::GridCellState *>  TetrisPieceLogic::getCoveredCells()
    {
        std::vector<State::GridCellState*> cells;

        for (const auto &[offset, tile] : m_activePiece.getShape().getTiles())
        {
            auto cellPos = m_activePiece.getPosition() + offset;

            if (m_gridState.isInside(cellPos.x, cellPos.y))
            {
                auto& cell = m_gridState.getCellAt(cellPos.x, cellPos.y);
                cells.push_back(&cell);
            }
        }
        return cells;
    }

    std::vector<const State::TetrisTile *> TetrisPieceLogic::getCoveredTiles()
    {
        return getTilesAt(
                sf::Vector2i(
                        m_activePiece.getPosition().x,
                        m_activePiece.getPosition().y
                )
        );
    }

    std::vector<const State::TetrisTile *> TetrisPieceLogic::getTilesAt(sf::Vector2i cellsAt)
    {
        std::vector<const State::TetrisTile*> cells;

        for (const auto &[offset, tile] : m_activePiece.getShape().getTiles())
        {
            int x = cellsAt.x + offset.x;
            int y = cellsAt.y + offset.y;

            cells.push_back(&m_gridState.getTileAt(x, y));
        }

        return cells;
    }

    void TetrisPieceLogic::spawnNewPiece(const State::TetrisShape &shape)
    {
        m_activePiece.setShape(shape);
        m_activePiece.setRotation(State::TetrisPiece::Rotation::Up);
        m_activePiece.setPosition(
                sf::Vector2i(
                        m_gridState.width() / 2,
                        m_gridState.height()
                )
        );
        instantiateTiles();
    }

} // Tetris::Logic