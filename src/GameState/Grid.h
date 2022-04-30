//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GRID_H
#define TETRISEXAM_GRID_H

#include <vector>
#include "GridCellState.h"
#include <SFML/Graphics/RenderTexture.hpp>

namespace Tetris::State
{
    class Grid
    {
    public:
        explicit Grid(const sf::Vector2i &gridSize);

        [[nodiscard]] const TetrisTile &getTileAt(int x, int y) const;
        [[nodiscard]] GridCellState &getCellAt(int x, int y);
        [[nodiscard]] bool isInside(int x, int y) const;

        [[nodiscard]] int width() const;
        [[nodiscard]] int height() const;

    private:
        std::vector<std::vector<GridCellState>> m_grid;

        const TetrisTile m_outOfBoundsTile {TetrisTile::OutOfBounds};
        const TetrisTile m_overGrid {TetrisTile::OverGrid};

    };
} // Tetris::State

#endif // TETRISEXAM_GRID_H
