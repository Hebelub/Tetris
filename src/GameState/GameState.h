//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GAMESTATE_H
#define TETRISEXAM_GAMESTATE_H

#include <list>
#include "GridState.h"
#include "TetrisPiece.h"

namespace Tetris::State
{
    /// @brief Bundle class, storing a state of a whole tetris game.
    // containing pieces, scores(n.i), upcoming pieces etc
    class GameState
    {
    public:
        /// @brief Default constructor
        GameState();

        // TODO: The logic inside here should maybe be moved out?
        TetrisPiece useNextTetris();
        /// @brief Does something
        /// @param TetrisPiece
        void addTetrisLast(TetrisPiece);

        [[nodiscard]] GridState &getGridState();

    private:
        /// @brief list of upcoming tetris pieces.
        std::list<TetrisPiece> m_upcomingPieces;
        GridState m_gameGrid{sf::Vector2i(10, 20)};
    };

} // Tetris::State

#endif // TETRISEXAM_GAMESTATE_H
