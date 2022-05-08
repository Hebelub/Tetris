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

    int GridLogic::removeSolidHorizontalLines()
    {
        int numLinesCleared = 0;
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

            // Found a full line, so clear it!
            if (onlySolidFound)
            {
                numLinesCleared++;

                // Set all tiles to empty
                for (int x = 0; x < m_grid.width(); x++)
                {
                    m_grid.getCellAt(x, y).setEmpty();
                }

                // Make all tiles above the cleared line fall down one step
                for (int i = y; i < m_grid.height() - 1; i++)
                {
                    for (int x = 0; x < m_grid.width(); x++)
                    {
                        if (m_grid.getCellAt(x, i+1).hasTile())
                            m_grid.getCellAt(x, i).setTile(m_grid.getCellAt(x, i + 1).getTile());
                        else
                            m_grid.getCellAt(x, i).setEmpty();
                    }
                }
                y--;
            }
        }
        return numLinesCleared;
    }

} // Tetris::Logic