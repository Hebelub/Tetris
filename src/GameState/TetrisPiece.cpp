//
// Created by glosn on 4/29/2022.
//

#include "TetrisPiece.h"

#include <utility>

namespace Tetris::State
{
    TetrisPiece::TetrisPiece(State::TetrisShape piece)
        : m_currentShape(std::move(piece))
    {

    }

    TetrisPiece::Rotation TetrisPiece::getRotation() const
    {
        return m_rotation;
    }

    void TetrisPiece::setRotation(Rotation rotation)
    {
        m_rotation = rotation;
    }

    TetrisShape &TetrisPiece::getShape()
    {
        return m_currentShape;
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