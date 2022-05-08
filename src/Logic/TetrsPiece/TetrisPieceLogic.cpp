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

    int TetrisPieceLogic::fallToTheBottom()
    {
        return 0;
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
            // sf::Vector2i(  1,  1 ), // UpRight
            // sf::Vector2i( -1,  1 ), // UpLeft
            sf::Vector2i(  1, -2 ), // TwoDownOneRight
            sf::Vector2i( -1, -2 ), // TwoDownOneLeft
            sf::Vector2i(  2,  0 ), // TwoRight
            sf::Vector2i( -2,  0 ), // TwoLeft
        };

        std::list<sf::Vector2i> offsetDirectionsForSymmetricalPieces
        {
            sf::Vector2i(  0, -1 ), // Down
            sf::Vector2i(  0, -2 ), // TwoDown
            sf::Vector2i(  0, -3 ), // ThreeDown // THIS LINE IS A TEST
            sf::Vector2i(  1, -1 ), // DownRight
            sf::Vector2i( -1, -1 ), // DownLeft
            sf::Vector2i(  1,  0 ), // Right
            sf::Vector2i( -1,  0 ), // Left
            sf::Vector2i(  0,  1 ), // Up
            sf::Vector2i(  1,  1 ), // UpRight
            sf::Vector2i( -1,  1 ), // UpLeft
            sf::Vector2i(  2,  0 ), // TwoRight
            sf::Vector2i( -2,  0 ), // TwoLeft
            sf::Vector2i(  0,  0 ), // Origin
        };

        if (m_activePiece.useQueasyMovement()) offsetDirections = offsetDirectionsForSymmetricalPieces;
        for (const auto &offset : offsetDirections)
        {
            if (canBeAt(m_activePiece.getPosition() + offset, newRotation))
            {
                clearCoveredCells();
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
            // tile.setColor(sf::Color::White);
            cell->setTile(tile);
        }
        return true;
    }

    void TetrisPieceLogic::instantiateTiles()
    {
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

} // Tetris::Logic