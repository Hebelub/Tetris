//
// Created by glosn on 4/29/2022.
//

#include "TetrisPiece.h"

#include <utility>
#include <iostream>

namespace Tetris::State
{
    TetrisPiece::TetrisPiece(State::TetrisShape shape)
        : m_currentShape(std::move(shape))
        , m_tiles(shape.getTiles())
    {
    }

    TetrisPiece::Rotation TetrisPiece::getRotation() const
    {
        return m_rotation;
    }

    void TetrisPiece::setRotation(Rotation rotation)
    {
        m_rotation = rotation;
        auto tiles = m_currentShape.getTiles();
        for (auto &tile : tiles) {
            switch (m_rotation) {
                case Rotation::Up: break;
                case Rotation::Down:
                {
                    tile.offset.x = -tile.offset.x;
                    tile.offset.y = -tile.offset.y;
                    break;
                }
                case Rotation::Left:
                {
                    int temp = tile.offset.x;
                    tile.offset.x = -tile.offset.y;
                    tile.offset.y = temp;
                    break;
                }
                case Rotation::Right:
                {
                    int temp = tile.offset.x;
                    tile.offset.x = tile.offset.y;
                    tile.offset.y = -temp;
                    break;
                }
            }
        }
        m_tiles = tiles;
    }

    const std::vector<TetrisShape::TetrisTileRelative> &TetrisPiece::getTiles() const
    {
        return m_tiles;
    }

    void TetrisPiece::setShape(const TetrisShape &piece)
    {
        m_currentShape = piece;
    }

    sf::Vector2i TetrisPiece::getPosition() const
    {
        return m_position;
    }

    void TetrisPiece::setPosition(sf::Vector2i newPosition)
    {
        m_position = newPosition;
    }

    void TetrisPiece::addPosition(sf::Vector2i offset)
    {
        m_position += offset;
    }

} // Tetris::State