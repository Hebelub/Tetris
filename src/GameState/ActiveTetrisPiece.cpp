//
// Created by glosn on 4/29/2022.
//

#include "ActiveTetrisPiece.h"

namespace Tetris::State
{
    ActiveTetrisPiece::ActiveTetrisPiece(State::TetrisPiece &piece)
        : m_currentPiece(piece)
    {

    }

    int ActiveTetrisPiece::getRotation() const
    {
        return m_rotation;
    }

    void ActiveTetrisPiece::setRotation(int rotation)
    {
        m_rotation = rotation % 4;
    }

    void ActiveTetrisPiece::addRotation(int turns)
    {
        setRotation(turns + m_rotation);
    }

    TetrisPiece &ActiveTetrisPiece::getPiece()
    {
        return m_currentPiece;
    }

    void ActiveTetrisPiece::setPiece(TetrisPiece &piece)
    {
        m_currentPiece = piece;
    }

    sf::Vector2i ActiveTetrisPiece::getPosition() const
    {
        return m_position;
    }

    void ActiveTetrisPiece::setPosition(sf::Vector2i newPosition)
    {
        m_position = newPosition;
    }

    void ActiveTetrisPiece::addPosition(sf::Vector2i offset)
    {
        m_position += offset;
    }

} // Tetris::State