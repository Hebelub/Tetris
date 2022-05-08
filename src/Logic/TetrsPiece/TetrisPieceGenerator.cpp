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
        : m_generators{
            { State::TetrisShape::Good,     std::mt19937(seed) },
            { State::TetrisShape::Normal,   std::mt19937(seed) },
            { State::TetrisShape::Bad,      std::mt19937(seed) },
            { State::TetrisShape::Horrible, std::mt19937(seed) }
        }
    {
        using namespace State;

        // TODO: add usage of these and remove them from Normal
        m_possibleShapes.insert({ TetrisShape::Good, {
            TetrisShapeBuilder::buildPieceDot(),
            TetrisShapeBuilder::buildPieceBaby()
        }});

        m_possibleShapes.insert({ TetrisShape::Normal, {
            TetrisShapeBuilder::ClassicalPieces::buildPieceO(),
            TetrisShapeBuilder::ClassicalPieces::buildPieceS(),
            TetrisShapeBuilder::ClassicalPieces::buildPieceZ(),
            TetrisShapeBuilder::ClassicalPieces::buildPieceJ(),
            TetrisShapeBuilder::ClassicalPieces::buildPieceL(),
            TetrisShapeBuilder::ClassicalPieces::buildPieceI(),
            TetrisShapeBuilder::ClassicalPieces::buildPieceT(),
            TetrisShapeBuilder::buildPieceColon(),
            TetrisShapeBuilder::buildPieceL()
        }});

        m_possibleShapes.insert({ TetrisShape::Bad, {
            TetrisShapeBuilder::buildPieceV(),
            TetrisShapeBuilder::buildPieceHole(),
            TetrisShapeBuilder::buildPieceDiagonal(),
            TetrisShapeBuilder::buildPieceU(),
            TetrisShapeBuilder::buildPieceEquals(),
            TetrisShapeBuilder::buildPieceCross(),
            TetrisShapeBuilder::buildPieceChessHorse()
        }});

        m_possibleShapes.insert({ TetrisShape::Horrible, {
            TetrisShapeBuilder::buildPieceParenthesis(),
            TetrisShapeBuilder::buildPieceBigBox(),
            TetrisShapeBuilder::buildPieceHorribleBox(),
            TetrisShapeBuilder::buildPieceZ(),
            TetrisShapeBuilder::buildPieceS(),
            TetrisShapeBuilder::buildPieceBigO()
        }});
    }

    State::TetrisShape TetrisPieceGenerator::getRandomShape(State::TetrisShape::Pool pool)
    {
        auto &shapeList = m_possibleShapes.at(pool);
        std::uniform_int_distribution<> dist(0, shapeList.size() - 1);
        return shapeList.at(dist(m_generators.at(pool)));
    }

}