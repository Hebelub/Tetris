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
            { State::TetrisShape::Good,     Random(seed) },
            { State::TetrisShape::Normal,   Random(seed)  },
            { State::TetrisShape::Bad,      Random(seed)  },
            { State::TetrisShape::Horrible, Random(seed)  }
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
        auto randomIndex = m_generators.at(pool).getInt(0, shapeList.size());
        return shapeList.at(randomIndex);
    }

}