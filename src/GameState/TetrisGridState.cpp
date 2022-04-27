//
// Created by glosn on 4/23/2022.
//

#include <SFML/Graphics/RenderTexture.hpp>
#include "TetrisGridState.h"

namespace Tetris::State
{
    TetrisGridState::TetrisGridState(const sf::Vector2i &gridSize)
    {
        m_grid = std::vector<std::vector<GridCellState>>(
                gridSize.y, std::vector<GridCellState>(
                gridSize.x,
                GridCellState{}
        ));
    }

    GridCellState TetrisGridState::getTileAt(const sf::Vector2i &tilePos)
    {
        return m_grid.at(tilePos.y).at(tilePos.x);
    }

    GridCellState TetrisGridState::getTileAt(int x, int y)
    {
        return m_grid.at(y).at(x);
    }

    int TetrisGridState::getGridTileWidth() const
    {
        return m_grid.at(0).size();
    }

    int TetrisGridState::getGridTileHeight() const
    {
        return m_grid.size();
    }


} // Tetris::State