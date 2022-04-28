//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_TETRISPIECE_H
#define TETRISEXAM_TETRISPIECE_H


#include "TetrisTile.h"
#include <vector>

namespace Tetris::State
{
    class TetrisPiece
    {
    public:
        struct TetrisPieceRelativeToCenter
        {
            int xOffset;
            int yOffset;
            TetrisTile &tile;
        };

    public:

        explicit TetrisPiece(TetrisTile &tileTemplate);

        void addTilePieceRelativeToCenter(int xOffset, int  yOffset);

        std::vector<TetrisPieceRelativeToCenter> &getTiles();

    private:
        TetrisTile &m_tileTemplate;

        std::vector<TetrisPieceRelativeToCenter> m_tetrisPieces;

    };

} // Tetris::Logic


#endif //TETRISEXAM_TETRISPIECE_H
