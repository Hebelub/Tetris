//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_TETRISGRIDSTATE_H
#define TETRISEXAM_TETRISGRIDSTATE_H

#include <vector>
#include "GridCellState.h"
#include <SFML/Graphics/RenderTexture.hpp>

namespace Tetris::State
{
    class TetrisGridState
    {
    public:
        explicit TetrisGridState(const sf::Vector2i &gridSize);

        [[nodiscard]] GridCellState getTileAt(const sf::Vector2i &tilePos);
        [[nodiscard]] GridCellState getTileAt(int x, int y);

        [[nodiscard]] int getGridTileWidth() const;
        [[nodiscard]] int getGridTileHeight() const;

    private:
        std::vector<std::vector<GridCellState>> m_grid;

    };
} // Tetris::State

#endif // TETRISEXAM_TETRISGRIDSTATE_H
