//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_TETRISPIECE_H
#define TETRISEXAM_TETRISPIECE_H


#include "TetrisSingleTile.h"
#include <vector>

namespace Tetris::State
{
    class TetrisPiece
    {
    private:
        struct TetrisPieceRelativeToCenter
        {
            int xOffset;
            int yOffset;
            const TetrisSingleTile &tile;
        };

    public:

        explicit TetrisPiece(const TetrisSingleTile &tileTemplate);

        void addTilePieceRelativeToCenter(int xOffset, int  yOffset);


    private:
        const TetrisSingleTile &m_tileTemplate;

        std::vector<TetrisPieceRelativeToCenter> m_tetrisPieces;



    };
}


#endif //TETRISEXAM_TETRISPIECE_H
