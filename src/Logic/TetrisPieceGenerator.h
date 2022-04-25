//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_TETRISPIECEGENERATOR_H
#define TETRISEXAM_TETRISPIECEGENERATOR_H

#include <vector>;
#include <random>
#include "../GameState/TetrisPiece.h"

namespace Tetris::Logic
{
    class TetrisPieceGenerator
    {
    public:
        TetrisPieceGenerator();

        std::vector<State::TetrisPiece> m_possiblePieces;

        State::TetrisPiece GetRandomPiece();

    private:
        std::random_device m_device;
        std::mt19937 m_mt{m_device()};
    };

}

#endif //TETRISEXAM_TETRISPIECEGENERATOR_H
