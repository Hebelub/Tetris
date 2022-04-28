//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GRIDCELLSTATE_H
#define TETRISEXAM_GRIDCELLSTATE_H

#include <SFML/Graphics/Color.hpp>
#include <memory>
#include "TetrisTile.h"

namespace Tetris::State
{
    /// @brief Stores info about the current state of a grid cell
    class GridCellState
    {
    public:
        GridCellState();
        ~GridCellState();

        /// @brief Getter for !m_isEmpty
        [[nodiscard]] bool hasTile() const;

        void setTile(TetrisTile &tile);

        void setEmpty();

        TetrisTile &getTile();

    private:
        bool m_isSolid{};
        sf::Color m_color{};

        /// @brief equal to nullptr when it is empty
        TetrisTile *m_containedTile{nullptr};
    };
} // Tetris::State

#endif // TETRISEXAM_GRIDCELLSTATE_H
