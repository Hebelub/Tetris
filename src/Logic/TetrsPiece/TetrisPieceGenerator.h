//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_TETRISPIECEGENERATOR_H
#define TETRISEXAM_TETRISPIECEGENERATOR_H

#include <vector>
#include <map>
#include "../../GameState/TetrisShape.h"
#include "../Random.h"

namespace Tetris::Logic
{
    ///
    // @brief   Generates the next tetris piece. For now at random from a vector of optional pices.
    //
    class TetrisPieceGenerator
    {
    public:
        explicit TetrisPieceGenerator(int seed);
        /// Gets a random piece.
        // @returns instance of TetrisShape
        //
        [[nodiscard]] State::TetrisShape getRandomShape(State::TetrisShape::Pool pool = State::TetrisShape::Normal);

    private:
        ///
        // Vector of possible tetris pieces.
        std::map<State::TetrisShape::Pool, std::vector<State::TetrisShape>> m_possibleShapes;
        // A random generator.
        std::map<State::TetrisShape::Pool, Random> m_generators;
    };

} // end of namespace Logic.

#endif // TETRISEXAM_TETRISPIECEGENERATOR_H
