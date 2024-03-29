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
#include "../Resources.h"

namespace Tetris::State
{
    struct GameState
    {
        int score{0};
        int numOfSlides{0}; // Movement trick
        int numOfSolidifiedPieces{0};
        bool gameOver{false};
        const Resources &resources;
        State::Grid gameGrid;
        State::TetrisPiece activePiece;
        std::list<State::TetrisShape> upcomingPieces{};
        Logic::TetrisPieceGenerator &generator;

        GameState(const Resources& resources, Logic::TetrisPieceGenerator &generator, int queueAmount)
            : resources(resources)
            , gameGrid{sf::Vector2i{10, 20}}
            , activePiece(generator.getRandomShape())
            , generator(generator)
        {
            for(int i = 0; i < queueAmount; i++)
            {
                upcomingPieces.emplace_back(generator.getRandomShape());
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
    //    TetrisPiece m_activeTetrisPiece{m_pieceGenerator.getRandomShape()};
    //};

} // Tetris::State

#endif // TETRISEXAM_GAMESTATE_H
