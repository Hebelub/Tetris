//
// Created by glosn on 4/24/2022.
//

#ifndef TETRISEXAM_GAMELOGIC_H
#define TETRISEXAM_GAMELOGIC_H

#include <memory>
#include "../GameState/GameState.h"
#include "../Input/TetrisPlayerInputManager.h"
#include "TetrsPiece/TetrisPieceLogic.h"
#include "TetrsPiece/TetrisPieceGenerator.h"
#include "GameLogicTimer.h"
#include "GridLogic.h"
#include "../Input/KeyboardLayout.h"

namespace Tetris::Logic
{
    /// @brief Updates the logic.
    class GameLogic
    {
    public:
        explicit GameLogic(const KeyboardLayout &layout, State::GameState &gameState);

        /// @brief Updates logic.
        /// @param deltaTime  Time elapsed since last logic update.
        void updateLogic(float deltaTime);

        void nextPiece();
        void activateNextPieceFromQueue();

        bool isGameOver();

    private:
        Input::TetrisPlayerInputManager m_inputManager;

        State::GameState &m_gameState;
        TetrisPieceLogic m_pieceLogic;
        GridLogic m_gridLogic{m_gameState.gameGrid};

        GameLogicTimer m_timer{};

        bool m_gameOver = false;

    };

} // Tetris::Logic

#endif // TETRISEXAM_GAMELOGIC_H
