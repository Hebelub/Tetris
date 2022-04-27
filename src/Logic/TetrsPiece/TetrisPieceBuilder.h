//
// Created by glosn on 4/27/2022.
//

#ifndef TETRISEXAM_TETRISPIECEBUILDER_H
#define TETRISEXAM_TETRISPIECEBUILDER_H

#include "../../GameState/TetrisPiece.h"

namespace Tetris::Logic
{
    class TetrisPieceBuilder
    {
    public:
        enum ClassicTetrisShape
        {
            // □ □ □ □
            I,
            // □ □
            // □ □
            O,
            //   □
            // □ □ □
            T,
            //   □ □
            // □ □
            S,
            // □ □
            //   □ □
            Z,
            // □
            // □ □ □
            J,
            //     □
            // □ □ □
            L
        };

        static State::TetrisPiece buildClassicTetrisShape(ClassicTetrisShape shape);
    };
} // Tetris::Logic


#endif //TETRISEXAM_TETRISPIECEBUILDER_H
