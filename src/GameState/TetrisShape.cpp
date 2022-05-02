//
// Created by glosn on 4/23/2022.
//

#include "TetrisShape.h"

namespace Tetris::State
{
    void TetrisShape::addTile(int x, int y, TetrisTile tile)
    {
        m_tiles.push_back({ sf::Vector2i{x, y}, tile });
    }

    const std::vector<TetrisShape::TetrisTileRelative> &TetrisShape::getTiles() const
    {
        return m_tiles;
    }

}
