//
// Created by glosn on 4/23/2022.
//

#include "TetrisPieceGenerator.h"
#include "TetrisShapeBuilder.h"
#include <random>
#include <iostream>


namespace Tetris::Logic
{
    TetrisPieceGenerator::TetrisPieceGenerator(int seed)
        : m_mt(seed)
    {
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceI());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceO());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceT());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceS());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceZ());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceJ());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceL());

        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceI());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceO());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceT());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceS());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceZ());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceJ());
        m_possibleShapes.push_back(TetrisShapeBuilder::ClassicalPieces::buildPieceL());


        m_possibleShapes.push_back(TetrisShapeBuilder::buildPieceParenthesis());
        m_possibleShapes.push_back(TetrisShapeBuilder::buildPieceBigBox());
        m_possibleShapes.push_back(TetrisShapeBuilder::buildPieceDiagonal());
        m_possibleShapes.push_back(TetrisShapeBuilder::buildPieceHole());
        m_possibleShapes.push_back(TetrisShapeBuilder::buildPieceBaby());
        m_possibleShapes.push_back(TetrisShapeBuilder::buildPieceU());
        m_possibleShapes.push_back(TetrisShapeBuilder::buildPieceEquals());
        m_possibleShapes.push_back(TetrisShapeBuilder::buildPieceCross());
    }

    State::TetrisShape TetrisPieceGenerator::getRandomShape()
    {
        std::uniform_int_distribution<> dist(0, m_possibleShapes.size() - 1);
        int num = dist(m_mt);
        std::cout << num << std::endl;
        return m_possibleShapes.at(num);
    }

}