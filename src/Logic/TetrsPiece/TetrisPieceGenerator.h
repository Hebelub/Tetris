//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_TETRISPIECEGENERATOR_H
#define TETRISEXAM_TETRISPIECEGENERATOR_H

#include <vector>
#include <random>
#include "../../GameState/TetrisShape.h"

namespace Tetris::Logic
{
    ///
    // @brief   Generates the next tetris piece. For now at random from a vector of optional pices.
    //
    class TetrisPieceGenerator
    {
    public:
        TetrisPieceGenerator();
        /// Gets a random piece.
        // @returns instance of TetrisShape
        //
        [[nodiscard]] const State::TetrisShape& getRandomPiece();

    private:
        ///
        // Vector of possible tetris pieces.
        std::vector<State::TetrisShape> m_possiblePieces;
        // A random generator.
        std::mt19937 m_mt{std::random_device{}()};
    };

} // end of namespace Logic.

#endif // TETRISEXAM_TETRISPIECEGENERATOR_H
