//
// Created by glosn on 4/23/2022.
//

#include <SFML/Graphics/RenderTexture.hpp>
#include "GridState.h"
#include <vector>

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

    int GridState::getGridTileWidth() const
    {
        return (int)m_grid.at(0).size();
    }

    int GridState::getGridTileHeight() const
    {
        return (int)m_grid.size();
    }


} // Tetris::State