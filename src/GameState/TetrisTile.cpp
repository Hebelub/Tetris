//
// Created by glosn on 4/27/2022.
//

#include "TetrisTile.h"

namespace Tetris::State
{
    TetrisTile::TetrisTile(const sf::IntRect &intRect, TetrisTile::Type type)
        : m_type(type)
        , m_intRect(intRect)
    {
    }


    TetrisTile::TetrisTile(Type type)
        : m_type(type)
    {
    }


    TetrisTile::Type TetrisTile::getType() const
    {
        return m_type;
    }

    void TetrisTile::setType(TetrisTile::Type type)
    {
        m_type = type;
    }

    void TetrisTile::setColor(sf::Color color)
    {
        m_tileColor = color;
    }

    const sf::IntRect &TetrisTile::getSpriteRect() const
    {
        return m_intRect;
    }

    const sf::Color &TetrisTile::getColor() const
    {
        return m_tileColor;
    }

} // Tetris::State