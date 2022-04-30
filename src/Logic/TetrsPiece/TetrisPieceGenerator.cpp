//
// Created by glosn on 4/23/2022.
//

#include "TetrisPieceGenerator.h"
#include "TetrisShapeBuilder.h"
#include <random>
#include <iostream>


namespace Tetris::Logic
{
    TetrisPieceGenerator::TetrisPieceGenerator()
    {
        m_possiblePieces.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceI());
        m_possiblePieces.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceO());
        m_possiblePieces.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceT());
        m_possiblePieces.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceS());
        m_possiblePieces.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceZ());
        m_possiblePieces.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceJ());
        m_possiblePieces.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceL());
    }

    const State::TetrisShape &TetrisPieceGenerator::getRandomPiece()
    {
        std::uniform_int_distribution<> dist(0, m_possiblePieces.size() - 1);
        return m_possiblePieces.at(dist(m_mt));
    }

}