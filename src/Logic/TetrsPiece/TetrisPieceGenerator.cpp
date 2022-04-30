//
// Created by glosn on 4/23/2022.
//

#include "TetrisPieceGenerator.h"
#include "TetrisShapeBuilder.h"
#include <random>


namespace Tetris::Logic
{
    TetrisPieceGenerator::TetrisPieceGenerator()
    {
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceI());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceO());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceT());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceS());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceZ());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceJ());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceL());
    }

    State::TetrisShape TetrisPieceGenerator::getRandomShape()
    {
        std::uniform_int_distribution<> dist(0, m_possibleShapes.size() - 1);
        return m_possibleShapes.at(dist(m_mt));
    }

}