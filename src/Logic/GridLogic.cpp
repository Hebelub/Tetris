//
// Created by glosn on 4/27/2022.
//

#include "GridLogic.h"
#include <iostream>

namespace Tetris::Logic
{
    GridLogic::GridLogic(State::Grid &grid)
        : m_grid(grid)
    { }

    void GridLogic::removeSolidHorizontalLines()
    {
        for (int y = 0; y < m_grid.height(); y++)
        {
            bool onlySolidFound = true;
            for (int x = 0; x < m_grid.width(); x++)
            {
                if (m_grid.getTileAt(x, y).getType() != State::TetrisTile::Solid)
                {
                    onlySolidFound = false;
                    break;
                }

            }

            if (onlySolidFound)
            {
                for (int x = 0; x < m_grid.width(); x++)
                {
                    m_grid.getCellAt(x, y).setEmpty();
                }
            }
        }
    }

} // Tetris::Logic