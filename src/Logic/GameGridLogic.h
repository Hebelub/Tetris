//
// Created by glosn on 4/27/2022.
//

#ifndef TETRISEXAM_GAMEGRIDLOGIC_H
#define TETRISEXAM_GAMEGRIDLOGIC_H

#include "../GameState/TetrisGridState.h"
#include "../GameState/TetrisPiece.h"

namespace Tetris::Logic
{
    /// @brief Contains basic functionality to easily manipulate the TetrisGrid
    class GameGridLogic
    {
    public:
        explicit GameGridLogic(State::TetrisGridState &grid);

        void removeSolidHorizontalLines();

        void dropPieceFromTheTop(const State::TetrisPiece &tetrisPiece);

    private:
        State::TetrisGridState m_grid;

    };

} // Tetris::Logic

#endif //TETRISEXAM_GAMEGRIDLOGIC_H
