//
// Created by glosn on 4/28/2022.
//

#ifndef TETRISEXAM_ACTIVETETRISPIECE_H
#define TETRISEXAM_ACTIVETETRISPIECE_H

/// @brief Manages falling and rotation of piece. Also instantiation of tiles into the grid
#include <SFML/System/Vector2.hpp>
#include "../../GameState/TetrisTile.h"
#include "../../GameState/GridState.h"

namespace Tetris::Logic
{
    class ActiveTetrisPiece
    {
    public:
        explicit ActiveTetrisPiece(State::GridState &grid);

        void tryFallOnce();
        void tryFallToTheBottom();

        void tryRotateRight();
        void tryRotateLeft();

    private:
        // A value between one and four
        int m_rotation{};
        State::TetrisTile m_currentTile;
        sf::Vector2i m_currentPosition;
        State::GridState &m_gridState;


        void moveTo(sf::Vector2i newPosition);
        void canMoveTo(sf::Vector2i position);
        void getBottomCells();
        void updatePosition();
    };

} // Tetris::Logic

#endif //TETRISEXAM_ACTIVETETRISPIECE_H
