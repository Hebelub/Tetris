//
// Created by glosn on 4/23/2022.
//

#include "TetrisPieceGenerator.h"
#include <random>

namespace Tetris::Logic
{
    TetrisPieceGenerator::TetrisPieceGenerator() {

    }

    Tetris::TetrisPiece TetrisPieceGenerator::GetRandomPiece()
    {
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, m_possiblePieces.size());
        return m_possiblePieces[dist(m_mt)];
    }

}