//
// Created by glosn on 4/27/2022.
//

#include "TetrisTile.h"

namespace Tetris::State
{
    TetrisTile::Type TetrisTile::getType() const
    {
        return m_type;
    }

    void TetrisTile::setType(TetrisTile::Type type)
    {
        m_type = type;
    }

    sf::Color TetrisTile::getColor() const
    {
        return m_tileColor;
    }

    void TetrisTile::setColor(sf::Color color)
    {
        m_tileColor = color;
    }

    TetrisTile::TetrisTile(TetrisTile::Type type)
        : m_type(type)
    { }

} // Tetris::State