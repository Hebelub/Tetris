//
// Created by glosn on 4/24/2022.
//

#ifndef TETRISEXAM_GAMELOGIC_H
#define TETRISEXAM_GAMELOGIC_H

#include <memory>
#include "../GameState/GameState.h"
#include "TetrsPiece/TetrisPieceLogic.h"
#include "TetrsPiece/TetrisPieceGenerator.h"
#include "GameLogicTimer.h"
#include "GridLogic.h"
#include "../Input/PlayerInput.h"
#include <optional>

namespace Tetris::Logic
{

    /// @brief Updates the logic.
    class GameLogic
    {
    public:
        explicit GameLogic(Input::PlayerInput playerInput, State::GameState &gameState);

        /// @brief Updates logic.
        /// @param deltaTime  Time elapsed since last logic updateButtons.
        void updateLogic(float deltaTime);

        void nextPiece();
        void activateNextPieceFromQueue();

        [[nodiscard]] bool isGameOver() const;

        void setLineClearCallback(const std::function<void(int)> &function);

    private:
        Input::PlayerInput m_playerInput;

        State::GameState &m_gameState;
        TetrisPieceLogic m_pieceLogic;
        GridLogic m_gridLogic{m_gameState.gameGrid};

        GameLogicTimer m_timer{};

        std::optional<std::function<void(int)>> m_lineClearCallback{std::nullopt};

    };

} // Tetris::Logic

#endif // TETRISEXAM_GAMELOGIC_H
