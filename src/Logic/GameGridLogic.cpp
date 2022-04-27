//
// Created by glosn on 4/27/2022.
//

#include "GameGridLogic.h"
#include <vector>

namespace Tetris::Logic
{
    GameGridLogic::GameGridLogic(State::TetrisGridState &grid)
        : m_grid(grid)
    {

    }

    //
    void GameGridLogic::removeSolidHorizontalLines()
    {
        for (int row = 0; row < m_grid.getGridTileHeight(); row++)
        {
            for (int col = 0; col < m_grid.getGridTileWidth(); col++)
            {

                if (!m_grid.getTileAt(row, col).isSolid())
                {
                    break;
                }
            }
        }
    }

} // Tetris::Logic