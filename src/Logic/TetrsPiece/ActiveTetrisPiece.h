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

        /// @return if it successfully moved down
        bool tryFallOnce();

        /// @return if it successfully rotated
        bool tryRotateRight();
        /// @return if it successfully rotated
        bool tryRotateLeft();

        /// @brief moves the piece down until it can't anymore
        /// @return how many blocks it fell
        int fallToTheBottom();

        /// @brief instantiates solid tiles and ends life of this ActiveTetrisPiece
        bool makePieceSolid();
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
