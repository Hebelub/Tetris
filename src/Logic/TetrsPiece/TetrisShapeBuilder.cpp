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

    State::TetrisShape TetrisShapeBuilder::buildPieceParenthesis()
    {
        State::TetrisTile tile{};
        tile.setColor(sf::Color::Black);

        State::TetrisShape shape;

        shape.addTile(-2, 1, tile);
        shape.addTile( 1, 1, tile);
        shape.addTile(-1, 0, tile);
        shape.addTile( 0, 0, tile);

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceBigBox()
    {
        State::TetrisTile tile{};
        tile.setColor(sf::Color::Green);

        State::TetrisShape shape;


        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                shape.addTile( i - 1, j - 1, tile);
            }
        }

        return shape;
    }



    State::TetrisShape TetrisShapeBuilder::buildPieceBaby()
    {
        State::TetrisTile tile{};
        tile.setColor(sf::Color(0xAA44AAFF));

        State::TetrisShape shape;

        shape.addTile(0,  0, tile);
        shape.addTile(1,  0, tile);

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceDiagonal()
    {
        State::TetrisTile tile{};
        tile.setColor(sf::Color(0xde7ba2FF));

        State::TetrisShape shape;
        shape.m_shouldHaveQueasyMovement = true;

        shape.addTile(-1, -1, tile);
        shape.addTile( 0,  0, tile);
        shape.addTile( 1,  1, tile);

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceHole() {
        State::TetrisTile tile{};
        tile.setColor(sf::Color(0x0e1b35FF));

        State::TetrisShape shape;
        shape.m_shouldHaveQueasyMovement = true;

        shape.addTile( 1,  0, tile);
        shape.addTile(-1,  0, tile);
        shape.addTile( 0,  1, tile);
        shape.addTile( 0, -1, tile);

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceU()
    {
        State::TetrisTile tile{};
        tile.setColor(sf::Color(0xE0B450FF));

        State::TetrisShape shape;

        shape.addTile( 1,  0, tile);
        shape.addTile(-1,  0, tile);
        shape.addTile( 0, -1, tile);
        shape.addTile(-1, -1, tile);
        shape.addTile( 1, -1, tile);

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceEquals()
    {
        State::TetrisTile tile{};
        tile.setColor(sf::Color(0x2FA222FF));

        State::TetrisShape shape;

        shape.addTile(-1,  1, tile);
        shape.addTile( 0,  1, tile);
        shape.addTile( 1,  1, tile);
        shape.addTile(-1, -1, tile);
        shape.addTile( 0, -1, tile);
        shape.addTile( 1, -1, tile);

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceCross()
    {
        State::TetrisTile tile{};
        tile.setColor(sf::Color(0xFF2288FF));

        State::TetrisShape shape;

        shape.addTile(  0,  1, tile);
        shape.addTile( -1,  0, tile);
        shape.addTile(  0,  0, tile);
        shape.addTile(  1,  0, tile);
        shape.addTile(  0, -1, tile);
        shape.addTile(  0, -2, tile);

        return shape;
    }
}
