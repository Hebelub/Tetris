//
// Created by glosn on 4/27/2022.
//

#ifndef TETRISEXAM_GRIDLOGIC_H
#define TETRISEXAM_GRIDLOGIC_H

#include "../GameState/Grid.h"
#include "../GameState/TetrisShape.h"

namespace Tetris::Logic
{
    /// @brief Contains basic functionality to easily manipulate the TetrisGrid
    class GridLogic
    {
    public:
        explicit GridLogic(State::Grid &grid);

        void removeSolidHorizontalLines();

    private:
        State::Grid &m_grid;

    };

} // Tetris::Logic

#endif //TETRISEXAM_GRIDLOGIC_H
