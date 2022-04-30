//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GAMESTATE_H
#define TETRISEXAM_GAMESTATE_H

#include <list>
#include "Grid.h"
#include "TetrisShape.h"
#include "../Logic/TetrsPiece/TetrisPieceGenerator.h"
#include "TetrisPiece.h"

namespace Tetris::State
{
    struct GameState
    {
        State::Grid gameGrid;
        State::TetrisPiece activePiece;
        std::vector<State::TetrisShape> upcomingPieces{};

        GameState(Logic::TetrisPieceGenerator& generator, int queueAmount)
            : gameGrid{sf::Vector2i{10, 20}}
            , activePiece(generator.getRandomPiece())
        {
            for(int i = 0; i < queueAmount; i++)
            {
                upcomingPieces.emplace_back();
            }
        }
    };


    ///// @brief Bundle class, storing a state of a whole tetris game.
    //// containing pieces, scores(n.i), upcoming pieces etc
    //class GameState
    //{
    //public:
    //    /// @brief Default constructor
    //    // @param how many queued pieces there should be. At least 1
    //    explicit GameState(int queuedPieces);
//
    //    TetrisShape &getNextTetris();
    //    void conveyPieces();
    //    TetrisShape &getNextTetrisAndConvey();
    //    /// @brief Does something
    //    /// @param TetrisPiece
    //    void addTetrisLast(TetrisShape &tetrisPiece);
    //    void tryRemoveTetrisLast();
    //    void popNextTetris();
//
    //    size_t queuedPieces();
//
    //    Grid &getGridState();
//
    //    TetrisPiece &getActiveTetris();
//
    //private:
    //    Logic::TetrisPieceGenerator m_pieceGenerator{};
//
    //    /// @brief list of upcoming tetris pieces.
    //    std::list<TetrisShape> m_upcomingPieces;
    //    Grid m_gameGrid{sf::Vector2i(10, 20)};
//
    //    TetrisPiece m_activeTetrisPiece{m_pieceGenerator.getRandomPiece()};
    //};

} // Tetris::State

#endif // TETRISEXAM_GAMESTATE_H
