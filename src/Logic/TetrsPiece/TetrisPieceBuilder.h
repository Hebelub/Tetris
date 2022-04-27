//
// Created by glosn on 4/27/2022.
//

#ifndef TETRISEXAM_TETRISPIECEBUILDER_H
#define TETRISEXAM_TETRISPIECEBUILDER_H

#include "../../GameState/TetrisPiece.h"

namespace Tetris::Logic
{
    /// @brief Builds tetris pieces
    class TetrisPieceBuilder
    {
    public:
        class ClassicalPieces
        {
        public:
            // □ □ □ □
            // Color: Light blue
            static State::TetrisPiece buildPieceI();

            // □ □
            // □ □
            // Color: Yellow
            static State::TetrisPiece buildPieceO();

            //   □
            // □ □ □
            // Color: Orange
            static State::TetrisPiece buildPieceT();

            //   □ □
            // □ □
            // Color: Green
            static State::TetrisPiece buildPieceS();

            // □ □
            //   □ □
            // Color: Red
            static State::TetrisPiece buildPieceZ();

            // □
            // □ □ □
            // Blue
            static State::TetrisPiece buildPieceJ();

            //     □
            // □ □ □
            // Orange
            static State::TetrisPiece buildPieceL();
        };
    };
} // Tetris::Logic


#endif //TETRISEXAM_TETRISPIECEBUILDER_H
