//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GRIDCELLSTATE_H
#define TETRISEXAM_GRIDCELLSTATE_H

#include <SFML/Graphics/Color.hpp>
#include <memory>
#include "TetrisSingleTile.h"

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

        void setTile(TetrisSingleTile *tile);

        void setEmpty();

        TetrisSingleTile &getTile();

    private:
        bool m_isSolid{};
        sf::Color m_color{};

        /// @brief equal to nullptr when it is empty
        TetrisSingleTile *m_containedTile{nullptr};
    };
} // Tetris::State

#endif // TETRISEXAM_GRIDCELLSTATE_H
