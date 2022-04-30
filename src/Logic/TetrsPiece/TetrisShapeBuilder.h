//
// Created by glosn on 4/27/2022.
//

#ifndef TETRISEXAM_TETRISSHAPEBUILDER_H
#define TETRISEXAM_TETRISSHAPEBUILDER_H

#include "../../GameState/TetrisShape.h"

namespace Tetris::Logic
{
    /// @brief Builds tetris pieces
    class TetrisShapeBuilder
    {
    public:
        class ClassicalPieces
        {
        public:
            // □ □ □ □
            // Color: Light blue
            static State::TetrisShape buildPieceI();

            // □ □
            // □ □
            // Color: Yellow
            static State::TetrisShape buildPieceO();

            //   □
            // □ □ □
            // Color: Orange
            static State::TetrisShape buildPieceT();

            //   □ □
            // □ □
            // Color: Green
            static State::TetrisShape buildPieceS();

            // □ □
            //   □ □
            // Color: Red
            static State::TetrisShape buildPieceZ();

            // □
            // □ □ □
            // Blue
            static State::TetrisShape buildPieceJ();

            //     □
            // □ □ □
            // Orange
            static State::TetrisShape buildPieceL();
        };
    };
} // Tetris::Logic


#endif //TETRISEXAM_TETRISSHAPEBUILDER_H
