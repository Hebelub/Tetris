//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GAMESTATE_H
#define TETRISEXAM_GAMESTATE_H

#include <list>
#include "GridState.h"
#include "TetrisPiece.h"
#include "../Logic/TetrsPiece/TetrisPieceGenerator.h"
#include "ActiveTetrisPiece.h"

namespace Tetris::State
{
    /// @brief Bundle class, storing a state of a whole tetris game.
    // containing pieces, scores(n.i), upcoming pieces etc
    class GameState
    {
    public:
        /// @brief Default constructor
        // @param how many queued pieces there should be. At least 1
        explicit GameState(int queuedPieces);

        TetrisPiece &getNextTetris();
        void conveyPieces();
        TetrisPiece &getNextTetrisAndConvey();
        /// @brief Does something
        /// @param TetrisPiece
        void addTetrisLast(TetrisPiece &tetrisPiece);
        void tryRemoveTetrisLast();
        void popNextTetris();

        size_t queuedPieces();

        GridState &getGridState();

        ActiveTetrisPiece &getActiveTetris();

    private:
        Logic::TetrisPieceGenerator m_pieceGenerator{};

        /// @brief list of upcoming tetris pieces.
        std::list<TetrisPiece> m_upcomingPieces;
        GridState m_gameGrid{sf::Vector2i(10, 20)};

        ActiveTetrisPiece m_activeTetrisPiece{m_pieceGenerator.getRandomPiece()};
    };

} // Tetris::State

#endif // TETRISEXAM_GAMESTATE_H
