//
// Created by glosn on 4/27/2022.
//

#ifndef TETRISEXAM_GAMEGRIDLOGIC_H
#define TETRISEXAM_GAMEGRIDLOGIC_H

#include "../GameState/Grid.h"
#include "../GameState/TetrisShape.h"

namespace Tetris::Logic
{
    /// @brief Contains basic functionality to easily manipulate the TetrisGrid
    class GameGridLogic
    {
    public:
        explicit GameGridLogic(State::Grid &grid);

        void removeSolidHorizontalLines();

        void dropPieceFromTheTop(const State::TetrisShape &tetrisPiece);

    private:
        State::Grid m_grid;

    };

} // Tetris::Logic

#endif //TETRISEXAM_GAMEGRIDLOGIC_H
