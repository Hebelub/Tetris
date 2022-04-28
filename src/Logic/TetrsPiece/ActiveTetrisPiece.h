//
// Created by glosn on 4/28/2022.
//

#ifndef TETRISEXAM_ACTIVETETRISPIECE_H
#define TETRISEXAM_ACTIVETETRISPIECE_H

/// @brief Manages falling and rotation of piece. Also instantiation of tiles into the grid
#include <SFML/System/Vector2.hpp>
#include "../../GameState/TetrisTile.h"
#include "../../GameState/GridState.h"
#include "../../GameState/TetrisPiece.h"

namespace Tetris::Logic
{
    class ActiveTetrisPiece
    {
    public:
        ActiveTetrisPiece(State::TetrisPiece &piece, State::GridState &grid);


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
        State::TetrisPiece m_currentPiece;
        sf::Vector2i m_position;
        State::GridState &m_gridState;

        /// @return all the cells that the piece is currently covering
        std::vector<State::GridCellState> &getCoveredCells();

        void moveTo(sf::Vector2i newPosition);
        void canMoveTo(sf::Vector2i position);
        void getBottomCells();
        void updatePosition();

        void instantiateTiles();
        void removeCoveredCells();
    };

} // Tetris::Logic

#endif //TETRISEXAM_ACTIVETETRISPIECE_H
