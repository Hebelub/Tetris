//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_TETRISGAMESTATE_H
#define TETRISEXAM_TETRISGAMESTATE_H

#include <list>
#include "TetrisGridState.h"
#include "TetrisPiece.h"

namespace Tetris::State
{
    /// @brief Bundle class, storing a state of a whole tetris game.
    // containing pieces, scores(n.i), upcoming pieces etc
    class TetrisGameState
    {
    public:
        /// @brief Default constructor
        TetrisGameState();

        // TODO: The logic inside here should maybe be moved out?
        TetrisPiece useNextTetris();
        /// @brief Does something
        /// @param TetrisPiece
        void addTetrisLast(TetrisPiece);

    private:
        /// @brief Vector of upcoming tetris pieces.
        std::list<TetrisPiece> m_upcomingPieces;
        TetrisGridState *m_gameGrid{};
    };

} // Tetris::State

#endif // TETRISEXAM_TETRISGAMESTATE_H
