//
// Created by glosn on 4/23/2022.
//

#include "TetrisPieceGenerator.h"
#include "TetrisPieceBuilder.h"
#include <random>


namespace Tetris::Logic
{
    TetrisPieceGenerator::TetrisPieceGenerator()
    {
        m_possiblePieces.push_back(TetrisPieceBuilder::ClassicalPieces::buildPieceI());
        m_possiblePieces.push_back(TetrisPieceBuilder::ClassicalPieces::buildPieceO());
        m_possiblePieces.push_back(TetrisPieceBuilder::ClassicalPieces::buildPieceT());
        m_possiblePieces.push_back(TetrisPieceBuilder::ClassicalPieces::buildPieceS());
        m_possiblePieces.push_back(TetrisPieceBuilder::ClassicalPieces::buildPieceZ());
        m_possiblePieces.push_back(TetrisPieceBuilder::ClassicalPieces::buildPieceJ());
        m_possiblePieces.push_back(TetrisPieceBuilder::ClassicalPieces::buildPieceL());
    }

    State::TetrisPiece TetrisPieceGenerator::GetRandomPiece()
    {
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, m_possiblePieces.size());
        return m_possiblePieces[dist(m_mt)];
    }

}