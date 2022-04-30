//
// Created by glosn on 4/23/2022.
//

#include <SFML/Graphics/RenderTexture.hpp>
#include "GridState.h"
#include <vector>
#include <iostream>

namespace Tetris::State
{
    GridState::GridState(const sf::Vector2i &gridSize)
    {
        m_grid = std::vector<std::vector<GridCellState>>(
                gridSize.y, std::vector<GridCellState>(
                gridSize.x,
                GridCellState{}
        ));
    }

    GridCellState GridState::getTileAt(const sf::Vector2i &tilePos)
    {
        return m_grid.at(tilePos.y).at(tilePos.x);
    }

    GridCellState GridState::getCellAt(int x, int y)
    {
        return m_grid.at(y).at(x);
    }

    size_t GridState::width() const
    {
        return m_grid.at(0).size();
    }

    size_t GridState::height() const
    {
        return m_grid.size();
    }

    bool GridState::isInside(int x, int y) const
    {
        return (x >= 0 && y >= 0 && x < width() && y < height());
    }

} // Tetris::State