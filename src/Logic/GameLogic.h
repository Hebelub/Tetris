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
#include <optional>

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

        bool isGameOver() const;

        void setLineClearCallback(const std::function<void(int)> &function);

    private:
        Input::TetrisPlayerInputManager m_inputManager;

        State::GameState &m_gameState;
        TetrisPieceLogic m_pieceLogic;
        GridLogic m_gridLogic{m_gameState.gameGrid};

        GameLogicTimer m_timer{};

        std::optional<std::function<void(int)>> m_lineClearCallback{std::nullopt};

    };

} // Tetris::Logic

#endif // TETRISEXAM_GAMELOGIC_H
