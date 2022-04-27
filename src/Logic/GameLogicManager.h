//
// Created by glosn on 4/24/2022.
//

#ifndef TETRISEXAM_GAMELOGICMANAGER_H
#define TETRISEXAM_GAMELOGICMANAGER_H

#include <memory>
#include "../GameState/TetrisGameState.h"
#include "../Input/TetrisPlayerInputManager.h"

namespace Tetris::Logic
{
    /// @brief Updates the logic.
    class GameLogicManager
    {
    public:
        /// @brief Updates logic.
        /// @param gameState  The current gamestate.
        /// @param deltaTime  Time elapsed since last logic update.
        void updateLogic(State::TetrisGameState &gameState, float deltaTime);

    private:
        Input::TetrisPlayerInputManager m_inputManager{Input::TetrisPlayerInputManager()};

    };

} // Tetris::Logic

#endif // TETRISEXAM_GAMELOGICMANAGER_H
