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
            const TetrisTile &tile;
        };

    public:

        explicit TetrisPiece(const TetrisTile &tileTemplate);

        void addTilePieceRelativeToCenter(int xOffset, int  yOffset);

        [[nodiscard]] std::vector<TetrisPieceRelativeToCenter> getTiles();

    private:
        const TetrisTile &m_tileTemplate;

        std::vector<TetrisPieceRelativeToCenter> m_tetrisPieces{std::vector<TetrisPieceRelativeToCenter>()};

    };
}


#endif //TETRISEXAM_TETRISPIECE_H
