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
                gridSize.x, std::vector<GridCellState>(
                gridSize.y,
                GridCellState{}
        ));
    }

    const TetrisTile &Grid::getTileAt(int x, int y) const
    {
        if (isInside(x, y) && m_grid.at(x).at(y).hasTile())
            return m_grid.at(x).at(y).getTile();
        else if (x < 0 || y < 0 || x >= width())
            return m_outOfBoundsTile;
        else
            return m_overGrid;
    }

    GridCellState &Grid::getCellAt(int x, int y)
    {
        return m_grid.at(x).at(y);
    }

    int Grid::width() const
    {
        return (int)m_grid.size();
    }

    int Grid::height() const
    {
        return (int)m_grid.at(0).size();
    }

    bool Grid::isInside(int x, int y) const
    {
        return (x >= 0 && y >= 0 && x < width() && y < height());
    }

} // Tetris::State