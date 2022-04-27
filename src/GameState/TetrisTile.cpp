//
// Created by glosn on 4/27/2022.
//

#include "TetrisTile.h"

namespace Tetris::State
{
    TetrisTile::Type TetrisTile::getType()
    {
        return m_type;
    }

    sf::Color TetrisTile::getColor()
    {
        return m_tileColor;
    }

    void TetrisTile::setColor(sf::Color color)
    {
        m_tileColor = color;
    }

} // Tetris::State