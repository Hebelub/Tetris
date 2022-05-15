//
// Created by glosn on 4/27/2022.
//

#include "TetrisShapeBuilder.h"
#include "../../RunningGame/Application.h"
#include <SFML/Graphics.hpp>

namespace Tetris::Logic
{

    State::TetrisShape TetrisShapeBuilder::ClassicalPieces::buildPieceI()
    {
        State::TetrisShape shape;
        auto color = sf::Color::Cyan;

        shape.addTile(-1, 0, getNewTile(color));
        shape.addTile( 0, 0, getNewTile(color));
        shape.addTile( 1, 0, getNewTile(color));
        shape.addTile( 2, 0, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::ClassicalPieces::buildPieceO()
    {

        State::TetrisShape shape;
        auto color = sf::Color::Yellow;

        shape.addTile(-1, -1, getNewTile(sf::Color::Yellow));
        shape.addTile( 0, -1, getNewTile(sf::Color::Yellow));
        shape.addTile(-1,  0, getNewTile(sf::Color::Yellow));
        shape.addTile( 0,  0, getNewTile(sf::Color::Yellow));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::ClassicalPieces::buildPieceT()
    {
        auto color = sf::Color::Magenta;

        State::TetrisShape shape;

        shape.addTile( 0, -1, getNewTile(color));
        shape.addTile(-1,  0, getNewTile(color));
        shape.addTile( 0,  0, getNewTile(color));
        shape.addTile( 1,  0, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::ClassicalPieces::buildPieceS()
    {
        auto color = sf::Color::Green;

        State::TetrisShape shape;

        shape.addTile( 0,  1, getNewTile(color));
        shape.addTile( 1,  1, getNewTile(color));
        shape.addTile(-1,  0, getNewTile(color));
        shape.addTile( 0,  0, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::ClassicalPieces::buildPieceZ()
    {
        auto color = sf::Color::Red;

        State::TetrisShape shape;

        shape.addTile(-1, 1, getNewTile(color));
        shape.addTile( 0, 1, getNewTile(color));
        shape.addTile( 0, 0, getNewTile(color));
        shape.addTile( 1, 0, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::ClassicalPieces::buildPieceJ()
    {
        auto color = sf::Color::Blue;

        State::TetrisShape shape;

        shape.addTile(-1, 1, getNewTile(color));
        shape.addTile(-1, 0, getNewTile(color));
        shape.addTile( 0, 0, getNewTile(color));
        shape.addTile( 1, 0, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::ClassicalPieces::buildPieceL()
    {
        auto color = sf::Color(255, 128, 32);

        State::TetrisShape shape;

        shape.addTile( 1, 1, getNewTile(color));
        shape.addTile(-1, 0, getNewTile(color));
        shape.addTile( 0, 0, getNewTile(color));
        shape.addTile( 1, 0, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceParenthesis()
    {
        auto color = sf::Color::Black;

        State::TetrisShape shape;

        shape.addTile(-2, 1, getNewTile(color));
        shape.addTile( 1, 1, getNewTile(color));
        shape.addTile(-1, 0, getNewTile(color));
        shape.addTile( 0, 0, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceBigBox()
    {
        auto color = sf::Color::Green;

        State::TetrisShape shape;


        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                shape.addTile( i - 1, j - 1, getNewTile(color));
            }
        }

        return shape;
    }



    State::TetrisShape TetrisShapeBuilder::buildPieceBaby()
    {
        auto color = sf::Color(0xAA44AAFF);

        State::TetrisShape shape;

        shape.addTile(0,  0, getNewTile(color));
        shape.addTile(1,  0, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceDiagonal()
    {
        auto color = sf::Color(0xde7ba2FF);

        State::TetrisShape shape;
        shape.m_shouldHaveQueasyMovement = true;

        shape.addTile(-1, -1, getNewTile(color));
        shape.addTile( 0,  0, getNewTile(color));
        shape.addTile( 1,  1, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceHole()
    {
        auto color = sf::Color(0x0e1b35FF);

        State::TetrisShape shape;
        shape.m_shouldHaveQueasyMovement = true;

        shape.addTile( 1,  0, getNewTile(color));
        shape.addTile(-1,  0, getNewTile(color));
        shape.addTile( 0,  1, getNewTile(color));
        shape.addTile( 0, -1, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceU()
    {
        auto color = sf::Color(0xE0B450FF);

        State::TetrisShape shape;

        shape.addTile( 1,  0, getNewTile(color));
        shape.addTile(-1,  0, getNewTile(color));
        shape.addTile( 0, -1, getNewTile(color));
        shape.addTile(-1, -1, getNewTile(color));
        shape.addTile( 1, -1, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceEquals()
    {
        auto color = sf::Color(0x2FA222FF);

        State::TetrisShape shape;

        shape.addTile(-1,  1, getNewTile(color));
        shape.addTile( 0,  1, getNewTile(color));
        shape.addTile( 1,  1, getNewTile(color));
        shape.addTile(-1, -1, getNewTile(color));
        shape.addTile( 0, -1, getNewTile(color));
        shape.addTile( 1, -1, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceCross()
    {
        auto color = sf::Color(0xFF2288FF);

        State::TetrisShape shape;

        shape.addTile(  0,  1, getNewTile(color));
        shape.addTile( -1,  0, getNewTile(color));
        shape.addTile(  0,  0, getNewTile(color));
        shape.addTile(  1,  0, getNewTile(color));
        shape.addTile(  0, -1, getNewTile(color));
        shape.addTile(  0, -2, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceHorribleBox()
    {
        auto color = sf::Color(0x259734FF);

        State::TetrisShape shape;
        shape.m_shouldHaveQueasyMovement = true;

        shape.addTile(  1,  1, getNewTile(color));
        shape.addTile( -1, -1, getNewTile(color));
        shape.addTile(  1, -1, getNewTile(color));
        shape.addTile( -1,  1, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceZ()
    {
        auto color = sf::Color(0xabcd33FF);

        State::TetrisShape shape;

        shape.addTile( -2,  0, getNewTile(color));
        shape.addTile( -1,  1, getNewTile(color));
        shape.addTile(  0,  0, getNewTile(color));
        shape.addTile(  1,  1, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceL()
    {
        auto color = sf::Color(0x33A155FF);

        State::TetrisShape shape;

        shape.addTile(  0,  1, getNewTile(color));
        shape.addTile(  1,  1, getNewTile(color));
        shape.addTile(  1,  0, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceV()
    {
        auto color = sf::Color(0x33A155FF);

        State::TetrisShape shape;

        shape.addTile( -1, -1, getNewTile(color));
        shape.addTile(  0,  0, getNewTile(color));
        shape.addTile(  1, -1, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceColon()
    {
        auto color = sf::Color(0x127A11FF);

        State::TetrisShape shape;

        shape.addTile(  0,  0, getNewTile(color));
        shape.addTile(  2,  0, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceChessHorse()
    {
        auto color = sf::Color(0xAF3F9FFF);

        State::TetrisShape shape;

        shape.addTile( -1,  0, getNewTile(color));
        shape.addTile(  1, -1, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceS()
    {
        auto color = sf::Color(0x127A11FF);

        State::TetrisShape shape;

        shape.addTile( -1,  1, getNewTile(color));
        shape.addTile(  0,  0, getNewTile(color));
        shape.addTile(  1,  1, getNewTile(color));
        shape.addTile(  2,  0, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceBigO()
    {
        auto color = sf::Color(0x44F449FF);

        State::TetrisShape shape;
        shape.m_shouldHaveQueasyMovement = true;

        shape.addTile( 1,  0, getNewTile(color));
        shape.addTile(-1,  0, getNewTile(color));
        shape.addTile( 0,  1, getNewTile(color));
        shape.addTile( 0, -1, getNewTile(color));
        shape.addTile( 1,  1, getNewTile(color));
        shape.addTile(-1, -1, getNewTile(color));
        shape.addTile(-1,  1, getNewTile(color));
        shape.addTile( 1, -1, getNewTile(color));

        return shape;
    }

    State::TetrisShape TetrisShapeBuilder::buildPieceDot()
    {
        auto color = sf::Color(0x44F449FF);

        State::TetrisShape shape;
        shape.m_shouldHaveQueasyMovement = true;

        shape.addTile( 0,  0, getNewTile(color));

        return shape;
    }

    State::TetrisTile TetrisShapeBuilder::getNewTile(const sf::Color &color)
    {
        int tileIndex = 0;
        if (random.getInt(0, 100) <= 32)
            tileIndex = random.getInt(1, 8);

        State::TetrisTile tile{sf::IntRect{tileIndex * 32, 0, 32, 32}, State::TetrisTile::Active};
        tile.setColor(color);
        return tile;
    }
}
