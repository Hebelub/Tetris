//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_TETRISPIECEGENERATOR_H
#define TETRISEXAM_TETRISPIECEGENERATOR_H

#include <vector>
#include <random>
#include "../../GameState/TetrisPiece.h"

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
        // @returns instance of TetrisPiece
        //
        State::TetrisPiece &getRandomPiece();

    private:
        ///
        // Vector of possible tetris pieces.
        std::vector<State::TetrisPiece> m_possiblePieces;
        // A random generator.
        std::random_device m_device;
        std::mt19937 m_mt{m_device()};
    };

} // end of namespace Logic.

#endif // TETRISEXAM_TETRISPIECEGENERATOR_H
