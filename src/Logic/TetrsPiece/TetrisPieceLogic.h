//
// Created by glosn on 4/28/2022.
//

#ifndef TETRISEXAM_TETRISPIECELOGIC_H
#define TETRISEXAM_TETRISPIECELOGIC_H

/// @brief Manages falling and rotation of piece. Also instantiation of tiles into the grid
#include <SFML/System/Vector2.hpp>
#include "../../GameState/TetrisTile.h"
#include "../../GameState/Grid.h"
#include "../../GameState/TetrisShape.h"
#include "../../GameState/TetrisPiece.h"

namespace Tetris::Logic
{
    class TetrisPieceLogic
    {
    public:
        TetrisPieceLogic(State::TetrisPiece &piece, State::Grid &grid);

        void spawnNewPiece(const State::TetrisShape &shape);

        /// @return if it successfully moved down
        bool tryFallOnce();

        bool tryMoveOnceRight();
        bool tryMoveOnceLeft();

        /// @return if it successfully rotated
        bool tryRotateRight();
        /// @return if it successfully rotated
        bool tryRotateLeft();

        /// @brief moves the piece down until it can't anymore
        /// @return how many blocks it fell
        int fallToTheBottom();

        /// @brief instantiates solid tiles and ends life of this TetrisPieceLogic
        bool makePieceSolid();

        void instantiateTiles();

    private:
        State::TetrisPiece &m_activePiece;

        State::Grid &m_gridState;

        std::vector<State::GridCellState *> getCoveredCells();

        /// @return all the cells that the piece is currently covering
        std::vector<const State::TetrisTile *> getCoveredTiles();

        std::vector<const State::TetrisTile*> getTilesAt(sf::Vector2i cellsAt);

        void moveTo(sf::Vector2i newPosition);
        bool canBeAt(sf::Vector2i position);
        void getBottomCells();
        void updatePosition();

        void clearCoveredCells();
    };

} // Tetris::Logic

#endif //TETRISEXAM_TETRISPIECELOGIC_H
