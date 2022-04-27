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

    void GameGridLogic::removeSolidHorizontalLines()
    {
        for (int row = 0; row < m_grid.getGridTileHeight(); row++)
        {
            bool onlySolidFound = true;
            for (int col = 0; col < m_grid.getGridTileWidth(); col++)
            {
                if (m_grid.getCellAt(row, col).getTile().getType() != State::TetrisSingleTile::Solid)
                {
                    onlySolidFound = false;
                    break;
                }
            }

            if (onlySolidFound)
            {
                for (int col = 0; col < m_grid.getGridTileWidth(); col++)
                {

                }
            }
        }
    }

} // Tetris::Logic