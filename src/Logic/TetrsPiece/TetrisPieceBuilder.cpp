//
// Created by glosn on 4/27/2022.
//

#include "TetrisPieceBuilder.h"

namespace Tetris::Logic
{

    State::TetrisPiece TetrisPieceBuilder::ClassicalPieces::buildPieceI()
    {
        State::TetrisSingleTile tile{};
        tile.setColor(sf::Color::Red);

        State::TetrisPiece piece(tile);

        piece.addTilePieceRelativeToCenter(-1, 0);
        piece.addTilePieceRelativeToCenter( 0, 0);
        piece.addTilePieceRelativeToCenter( 1, 0);
        piece.addTilePieceRelativeToCenter( 2, 0);

        return piece;
    }

    State::TetrisPiece TetrisPieceBuilder::ClassicalPieces::buildPieceO()
    {
        State::TetrisSingleTile tile{};
        tile.setColor(sf::Color::Red);

        State::TetrisPiece piece(tile);

        piece.addTilePieceRelativeToCenter(-1, -1);
        piece.addTilePieceRelativeToCenter( 0, -1);
        piece.addTilePieceRelativeToCenter(-1,  0);
        piece.addTilePieceRelativeToCenter( 0,  0);

        return piece;
    }

    State::TetrisPiece TetrisPieceBuilder::ClassicalPieces::buildPieceT()
    {
        State::TetrisSingleTile tile{};
        tile.setColor(sf::Color::Red);

        State::TetrisPiece piece(tile);

        piece.addTilePieceRelativeToCenter( 0, -1);
        piece.addTilePieceRelativeToCenter(-1,  0);
        piece.addTilePieceRelativeToCenter( 0,  0);
        piece.addTilePieceRelativeToCenter( 1,  0);

        return piece;
    }

    State::TetrisPiece TetrisPieceBuilder::ClassicalPieces::buildPieceS()
    {
        State::TetrisSingleTile tile{};
        tile.setColor(sf::Color::Red);

        State::TetrisPiece piece(tile);

        piece.addTilePieceRelativeToCenter( 0,  1);
        piece.addTilePieceRelativeToCenter( 1,  1);
        piece.addTilePieceRelativeToCenter(-1,  0);
        piece.addTilePieceRelativeToCenter( 0,  0);

        return piece;
    }

    State::TetrisPiece TetrisPieceBuilder::ClassicalPieces::buildPieceZ()
    {
        State::TetrisSingleTile tile{};
        tile.setColor(sf::Color::Red);

        State::TetrisPiece piece(tile);

        piece.addTilePieceRelativeToCenter(-1, 1);
        piece.addTilePieceRelativeToCenter( 0, 1);
        piece.addTilePieceRelativeToCenter( 0, 0);
        piece.addTilePieceRelativeToCenter( 1, 0);

        return piece;
    }

    State::TetrisPiece TetrisPieceBuilder::ClassicalPieces::buildPieceJ()
    {
        State::TetrisSingleTile tile{};
        tile.setColor(sf::Color::Red);

        State::TetrisPiece piece(tile);

        piece.addTilePieceRelativeToCenter(-1, 1);
        piece.addTilePieceRelativeToCenter(-1, 0);
        piece.addTilePieceRelativeToCenter( 0, 0);
        piece.addTilePieceRelativeToCenter( 0, 1);

        return piece;
    }

    State::TetrisPiece TetrisPieceBuilder::ClassicalPieces::buildPieceL()
    {
        State::TetrisSingleTile tile{};
        tile.setColor(sf::Color::Red);

        State::TetrisPiece piece(tile);

        piece.addTilePieceRelativeToCenter( 1, 1);
        piece.addTilePieceRelativeToCenter(-1, 0);
        piece.addTilePieceRelativeToCenter( 0, 0);
        piece.addTilePieceRelativeToCenter( 0, 1);

        return piece;
    }
}
