//
// Created by glosn on 4/27/2022.
//

#include "GridLogic.h"
#include <vector>

namespace Tetris::Logic
{
    GridLogic::GridLogic(State::Grid &grid)
        : m_grid(grid)
    {

    }

    void GridLogic::removeSolidHorizontalLines()
    {
        for (int row = 0; row < m_grid.height(); row++)
        {
            bool onlySolidFound = true;
            for (int col = 0; col < m_grid.width(); col++)
            {
                if (m_grid.getCellAt(row, col).getTile().getType() != State::TetrisTile::Solid)
                {
                    onlySolidFound = false;
                    break;
                }
            }

            if (onlySolidFound)
            {
                for (int col = 0; col < m_grid.width(); col++)
                {
                    m_grid.getCellAt(row, col).setEmpty();
                }
            }
        }
    }

    void GridLogic::dropPieceFromTheTop(const State::TetrisShape &tetrisPiece)
    {

    }

} // Tetris::Logic