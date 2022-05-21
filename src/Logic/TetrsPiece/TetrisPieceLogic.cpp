//
// Created by glosn on 4/28/2022.
//

#include "TetrisPieceLogic.h"
#include "../../GameState/TetrisPiece.h"
#include <utility>
#include <vector>
#include <iostream>
#include <list>

namespace Tetris::Logic
{
    TetrisPieceLogic::TetrisPieceLogic(State::TetrisPiece &piece, State::Grid &grid)
        : m_activePiece(piece)
        , m_gridState(grid)
    { }

    bool TetrisPieceLogic::tryFallOnce()
    {
        return tryMoveWithOffset(sf::Vector2i{0, -1});
    }

    bool TetrisPieceLogic::tryFallDiagonalRight()
    {
        return tryMoveWithOffset(sf::Vector2i{1, -1});
    }

    bool TetrisPieceLogic::tryFallDiagonalLeft()
    {
        return tryMoveWithOffset(sf::Vector2i{-1, -1});
    }

    bool TetrisPieceLogic::tryMoveOnceRight()
    {
        return tryMoveWithOffset(sf::Vector2i{1, 0});
    }

    bool TetrisPieceLogic::tryMoveOnceLeft()
    {
        return tryMoveWithOffset(sf::Vector2i{-1, 0});
    }

    bool TetrisPieceLogic::tryMoveWithOffset(sf::Vector2i offset)
    {
        auto newPos = m_activePiece.getPosition() + offset;
        if (canBeAt(newPos, m_activePiece.getRotation()))
        {
            moveTo(newPos);
            return true;
        }
        else
        {
            return false;
        }
    }

    bool TetrisPieceLogic::tryRotateRight()
    {
        using Rotation = State::TetrisPiece::Rotation;
        auto newRotation = m_activePiece.getRotation();

        switch(m_activePiece.getRotation())
        {
            case Rotation::Up:
                newRotation = Rotation::Right;
                break;
            case Rotation::Down:
                newRotation = Rotation::Left;
                break;
            case Rotation::Left:
                newRotation = Rotation::Up;
                break;
            case Rotation::Right:
                newRotation = Rotation::Down;
                break;
        }

        std::list<sf::Vector2i> offsetDirections
        {
            sf::Vector2i(  0,  0 ), // Origin
            sf::Vector2i(  0, -1 ), // Down
            sf::Vector2i(  1, -1 ), // DownRight
            sf::Vector2i( -1, -1 ), // DownLeft
            sf::Vector2i(  1,  0 ), // Right
            sf::Vector2i( -1,  0 ), // Left
            sf::Vector2i(  0,  1 ), // Up
            sf::Vector2i(  0, -2 ), // TwoDown
            sf::Vector2i(  1, -2 ), // TwoDownOneRight
            sf::Vector2i( -1, -2 ), // TwoDownOneLeft
            sf::Vector2i(  2,  0 ), // TwoRight
            sf::Vector2i( -2,  0 ), // TwoLeft
        };

        for (const auto &offset : offsetDirections)
        {
            if (canBeAt(m_activePiece.getPosition() + offset, newRotation))
            {
                clearActiveCells();
                m_activePiece.setPosition(m_activePiece.getPosition() + offset);
                m_activePiece.setRotation(newRotation);
                instantiateTiles();
                return true;
            }
        }

        return false;
    }

    bool TetrisPieceLogic::tryRotateLeft()
    {
        return true;
    }

    void TetrisPieceLogic::moveTo(sf::Vector2i newPosition)
    {
        clearActiveCells();

        m_activePiece.setPosition(newPosition);

        instantiateTiles();
    }

    bool TetrisPieceLogic::canBeAt(sf::Vector2i position, State::TetrisPiece::Rotation rotation)
    {
        auto currentRotation = m_activePiece.getRotation();
        m_activePiece.setRotation(rotation);
        for (const auto tile : getTilesAt(position))
        {
            const auto type = tile->getType();
            if (type == State::TetrisTile::Solid || type == State::TetrisTile::OutOfBounds)
            {
                m_activePiece.setRotation(currentRotation);
                return false;
            }
        }
        m_activePiece.setRotation(currentRotation);
        return true;
    }

    bool TetrisPieceLogic::makePieceSolid()
    {
        if (m_activePiece.getPosition().y >= m_gridState.height() - 1) return false;

        for (auto cell : getCoveredCells())
        {
            auto tile = cell->getTile();
            tile.setType(State::TetrisTile::Solid);
            cell->setTile(tile);
        }
        return true;
    }

    void TetrisPieceLogic::instantiateTiles()
    {
        auto coveredTiles = m_activePiece.getTiles();
        int i = 0;
        for (auto pos : getGhostPositions())
        {
            if (m_gridState.isInside(pos.x, pos.y))
            {
                auto &cell = m_gridState.getCellAt(pos.x, pos.y);
                auto tile = coveredTiles.at(i).tile;
                tile.setType(State::TetrisTile::GhostTile);
                cell.setTile(tile);
            }
            i++;
        }

        for (const auto &[offset, tile] : m_activePiece.getTiles())
        {
            auto cellPos = m_activePiece.getPosition() + offset;

            if (m_gridState.isInside(cellPos.x, cellPos.y))
            {
                auto &cell = m_gridState.getCellAt(cellPos.x, cellPos.y);
                cell.setTile(tile);
            }
        }
    }

    void TetrisPieceLogic::clearActiveCells()
    {
        for (auto pos : getGhostPositions())
        {
            if (m_gridState.isInside(pos.x, pos.y))
            {
                m_gridState.getCellAt(pos.x, pos.y).setEmpty();
            }
        }

        for (auto cell : getCoveredCells())
        {
            cell->setEmpty();
        }
    }

    std::vector<State::GridCellState *>  TetrisPieceLogic::getCoveredCells()
    {
        std::vector<State::GridCellState*> cells;

        for (const auto &[offset, tile] : m_activePiece.getTiles())
        {
            auto cellPos = m_activePiece.getPosition() + offset;

            if (m_gridState.isInside(cellPos.x, cellPos.y))
            {
                auto &cell = m_gridState.getCellAt(cellPos.x, cellPos.y);
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

        for (const auto &[offset, tile] : m_activePiece.getTiles())
        {
            int x = cellsAt.x + offset.x;
            int y = cellsAt.y + offset.y;

            cells.push_back(&m_gridState.getTileAt(x, y));
        }

        return cells;
    }

    std::vector<sf::Vector2i> TetrisPieceLogic::getTilePositionsAt(sf::Vector2i position)
    {
        std::vector<sf::Vector2i> positions;

        for (const auto &[offset, tile] : m_activePiece.getTiles())
        {
            int x = position.x + offset.x;
            int y = position.y + offset.y;

            positions.emplace_back(x, y);
        }

        return positions;
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

    sf::Vector2i TetrisPieceLogic::getPiecePosition()
    {
        return m_activePiece.getPosition();
    }

    std::vector<sf::Vector2i> TetrisPieceLogic::getGhostPositions()
    {
        sf::Vector2i bottomMost = m_activePiece.getPosition();

        do
        {
            bottomMost += sf::Vector2i(0, -1);
        }
        while (canBeAt(bottomMost, m_activePiece.getRotation()));

        bottomMost += sf::Vector2i(0, 1);

        return getTilePositionsAt(bottomMost);
    }

} // Tetris::Logic