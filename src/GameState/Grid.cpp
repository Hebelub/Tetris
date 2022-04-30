//
// Created by glosn on 4/23/2022.
//

#include <SFML/Graphics/RenderTexture.hpp>
#include "Grid.h"
#include <vector>
#include <iostream>

namespace Tetris::State
{
    Grid::Grid(const sf::Vector2i &gridSize)
    {
        m_grid = std::vector<std::vector<GridCellState>>(
                gridSize.y, std::vector<GridCellState>(
                gridSize.x,
                GridCellState{}
        ));
    }

    GridCellState &Grid::getTileAt(const sf::Vector2i &tilePos)
    {
        return m_grid.at(tilePos.y).at(tilePos.x);
    }

    GridCellState &Grid::getCellAt(int x, int y)
    {
        return m_grid.at(y).at(x);
    }

    int Grid::width() const
    {
        return (int)m_grid.at(0).size();
    }

    int Grid::height() const
    {
        return (int)m_grid.size();
    }

    bool Grid::isInside(int x, int y) const
    {
        return (x >= 0 && y >= 0 && x < width() && y < height());
    }

} // Tetris::State