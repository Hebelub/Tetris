//
// Created by glosn on 4/23/2022.
//

#include "TetrisPiece.h"

namespace Tetris::State
{
    /// @param tileTemplate the tile witch will be copied to create the tile
    TetrisPiece::TetrisPiece(TetrisTile &tileTemplate)
        : m_tileTemplate(tileTemplate)
    {

    }

    void TetrisPiece::addTilePieceRelativeToCenter(int xOffset, int yOffset)
    {
        m_tetrisPieces.emplace_back(TetrisPieceRelativeToCenter{xOffset, yOffset, &m_tileTemplate});
    }

    std::vector<TetrisPiece::TetrisPieceRelativeToCenter> &TetrisPiece::getTiles()
    {
        return m_tetrisPieces;
    }

}
