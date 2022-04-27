//
// Created by glosn on 4/27/2022.
//

#include "TetrisSingleTile.h"

namespace Tetris::State
{
    TetrisSingleTile::Type TetrisSingleTile::getType()
    {
        return m_type;
    }

    sf::Color TetrisSingleTile::getColor()
    {
        return m_tileColor;
    }
} // Tetris::State