//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GRIDCELLSTATE_H
#define TETRISEXAM_GRIDCELLSTATE_H

#include <SFML/Graphics/Color.hpp>

namespace Tetris::State
{
    /// @brief Stores info about the current state of a grid cell
    // Is it empty, solid, falling? What color has it?
    class GridCellState
    {
    public:
        /// @brief Getter for m_isEmpty
        [[nodiscard]] bool isEmpty() const;
        /// @brief Getter for m-isSolid
        [[nodiscard]] bool isSolid() const;
        /// @brief Getter for m_isFalling
        [[nodiscard]] bool isFalling() const;
        /// @brief Sets the grid cell to solid.
        void setSolid(); // TODO: This should maybe be move to Logic?
        /// @brief Getter for m_color
        [[nodiscard]] sf::Color getColor() const;

    private:
        bool m_isEmpty{};
        bool m_isSolid{};
        sf::Color m_color{};
    };
} // Tetris::State

#endif // TETRISEXAM_GRIDCELLSTATE_H
