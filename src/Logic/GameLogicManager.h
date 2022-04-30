//
// Created by glosn on 4/24/2022.
//

#ifndef TETRISEXAM_GAMELOGICMANAGER_H
#define TETRISEXAM_GAMELOGICMANAGER_H

#include <memory>
#include "../GameState/GameState.h"
#include "../Input/TetrisPlayerInputManager.h"
#include "TetrsPiece/TetrisPieceLogic.h"
#include "TetrsPiece/TetrisPieceGenerator.h"
#include "GameLogicTimer.h"

namespace Tetris::Logic
{
    /// @brief Updates the logic.
    class GameLogicManager
    {
    public:
        explicit GameLogicManager(State::GameState &gameState);

        /// @brief Updates logic.
        /// @param deltaTime  Time elapsed since last logic update.
        void updateLogic(float deltaTime);



    private:
        Input::TetrisPlayerInputManager m_inputManager{Input::TetrisPlayerInputManager()};

        State::GameState &m_gameState;
        TetrisPieceLogic m_tetrisPieceLogic;

        GameLogicTimer m_timer{};

    };

} // Tetris::Logic

#endif // TETRISEXAM_GAMELOGICMANAGER_H
