//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_TETRISGRIDSTATE_H
#define TETRISEXAM_TETRISGRIDSTATE_H

#include <vector>
#include "GridCellState.h"

namespace Tetris::State
{
    class TetrisGridState
    {
        // TODO: Width and height might be redundant
        int m_width = 10;
        int m_height = 20;

        std::vector<std::vector<GridCellState>> grid;
    };
} // Tetris::State

#endif //TETRISEXAM_TETRISGRIDSTATE_H
