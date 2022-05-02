//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GRIDCELLSTATE_H
#define TETRISEXAM_GRIDCELLSTATE_H

#include <SFML/Graphics/Color.hpp>
#include <memory>
#include <optional>
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

        void setTile(const TetrisTile &tile);

        void setEmpty();

        [[nodiscard]] const TetrisTile &getTile() const;

    private:
        bool m_isSolid{};
        sf::Color m_color{};

        /// @brief equal to nullptr when it is empty
        std::optional<TetrisTile> m_containedTile{std::nullopt};
    };
} // Tetris::State

#endif // TETRISEXAM_GRIDCELLSTATE_H
