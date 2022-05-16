//
// Created by glosn on 4/27/2022.
//

#ifndef TETRISEXAM_TETRISSHAPEBUILDER_H
#define TETRISEXAM_TETRISSHAPEBUILDER_H

#include "../../GameState/TetrisShape.h"
#include "../Random.h"

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
            // Color: Magenta
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

        // □     □
        //   □ □
        // Color: Black
        static State::TetrisShape buildPieceParenthesis();

        // □ □
        // Color: Brown
        static State::TetrisShape buildPieceBaby();

        // □ □ □
        // □ □ □
        // □ □ □
        static State::TetrisShape buildPieceBigBox();


        //     □
        //   □
        // □
        static State::TetrisShape buildPieceDiagonal();


        //   □
        // □   □
        //   □
        static State::TetrisShape buildPieceHole();

        // □   □
        // □ □ □
        static State::TetrisShape buildPieceU();

        // □ □ □
        //
        // □ □ □
        static State::TetrisShape buildPieceEquals();

        //   □
        // □ □ □
        //   □
        //   □
        static State::TetrisShape buildPieceCross();

        // □   □
        //
        // □   □
        static State::TetrisShape buildPieceHorribleBox();

        //   □   □
        // □   □
        static State::TetrisShape buildPieceZ();

        // □
        // □ □
        static State::TetrisShape buildPieceL();

        //   □
        // □   □
        static State::TetrisShape buildPieceV();

        // □   □
        static State::TetrisShape buildPieceColon();

        // □
        //     □
        static State::TetrisShape buildPieceChessHorse();

        // □   □
        //   □   □
        static State::TetrisShape buildPieceS();

        // □ □ □
        // □   □
        // □ □ □
        static State::TetrisShape buildPieceBigO();

        // □
        static State::TetrisShape buildPieceDot();


    private:
        static State::TetrisTile getNewTile(const sf::Color &color);
        static inline Random random{};
    };
} // Tetris::Logic


#endif //TETRISEXAM_TETRISSHAPEBUILDER_H
