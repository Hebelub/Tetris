//
// Created by glosn on 4/23/2022.
//

#include "TetrisPiece.h"

namespace Tetris::State
{
    /// @param tileTemplate the tile witch will be copied to create the tile
    TetrisPiece::TetrisPiece(TetrisSingleTile const& tileTemplate)
        : m_tileTemplate(tileTemplate)
    {

    }

    void TetrisPiece::addTilePieceRelativeToCenter(int xOffset, int yOffset)
    {
        m_tetrisPieces.push_back({xOffset, yOffset, m_tileTemplate});
    }

}
