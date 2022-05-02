//
// Created by glosn on 4/27/2022.
//

#include "TetrisShapeBuilder.h"

namespace Tetris::Logic
{

    State::TetrisShape TetrisShapeBuilder::ClassicalPieces::buildPieceI()
    {
        State::TetrisTile tile{};
        tile.setColor(sf::Color::Cyan);

        State::TetrisShape shape;

        shape.addTile(-1, 0, tile);
        shape.addTile( 0, 0, tile);
        shape.addTile( 1, 0, tile);
        shape.addTile( 2, 0, tile);

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::ClassicalPieces::buildPieceO()
    {
        State::TetrisTile tile{};
        tile.setColor(sf::Color::Yellow);

        State::TetrisShape shape;

        shape.addTile(-1, -1, tile);
        shape.addTile( 0, -1, tile);
        shape.addTile(-1,  0, tile);
        shape.addTile( 0,  0, tile);

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::ClassicalPieces::buildPieceT()
    {
        State::TetrisTile tile{};
        tile.setColor(sf::Color::Magenta);

        State::TetrisShape shape;

        shape.addTile( 0, -1, tile);
        shape.addTile(-1,  0, tile);
        shape.addTile( 0,  0, tile);
        shape.addTile( 1,  0, tile);

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::ClassicalPieces::buildPieceS()
    {
        State::TetrisTile tile{};
        tile.setColor(sf::Color::Green);

        State::TetrisShape shape;

        shape.addTile( 0,  1, tile);
        shape.addTile( 1,  1, tile);
        shape.addTile(-1,  0, tile);
        shape.addTile( 0,  0, tile);

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::ClassicalPieces::buildPieceZ()
    {
        State::TetrisTile tile{};
        tile.setColor(sf::Color::Red);

        State::TetrisShape shape;

        shape.addTile(-1, 1, tile);
        shape.addTile( 0, 1, tile);
        shape.addTile( 0, 0, tile);
        shape.addTile( 1, 0, tile);

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::ClassicalPieces::buildPieceJ()
    {
        State::TetrisTile tile{};
        tile.setColor(sf::Color::Blue);

        State::TetrisShape shape;

        shape.addTile(-1, 1, tile);
        shape.addTile(-1, 0, tile);
        shape.addTile( 0, 0, tile);
        shape.addTile( 1, 0, tile);

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::ClassicalPieces::buildPieceL()
    {
        State::TetrisTile tile{};
        tile.setColor(sf::Color(255, 128, 32));

        State::TetrisShape shape;

        shape.addTile( 1, 1, tile);
        shape.addTile(-1, 0, tile);
        shape.addTile( 0, 0, tile);
        shape.addTile( 1, 0, tile);

        return shape;
    }
}
