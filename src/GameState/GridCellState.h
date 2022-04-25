//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GRIDCELLSTATE_H
#define TETRISEXAM_GRIDCELLSTATE_H

#include <SFML/Graphics/Color.hpp>

namespace Tetris::State
{
    class GridCellState
    {
    public:
        [[nodiscard]] bool isEmpty() const;
        [[nodiscard]] bool isSolid() const;
        [[nodiscard]] bool isFalling() const;
        void setSolid(); // TODO: This should maybe be move to Logic?
        [[nodiscard]] sf::Color getColor() const;

    private:
        bool m_isEmpty{};
        bool m_isSolid{};
        sf::Color m_color{};
    };
} // Tetris::State


#endif //TETRISEXAM_GRIDCELLSTATE_H
