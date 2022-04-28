//
// Created by glosn on 4/24/2022.
//

#ifndef TETRISEXAM_GAMELOGICMANAGER_H
#define TETRISEXAM_GAMELOGICMANAGER_H

#include <memory>
#include "../GameState/GameState.h"
#include "../Input/TetrisPlayerInputManager.h"

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


        /// @brief Makes the TetrisPiece fall instantly to the correct spot
        void instantFall();
        /// @brief Moves the currently active TetrisPiece one space to the left
        void moveLeft();
        /// @brief Moves the currently active TetrisPiece one space to the right
        void moveRight();
        /// @brief Rotates the currently active TetrisPiece clockwise
        void rotateRight();
        /// @brief Rotates the currently active TetrisPiece counterClockwise
        void rotateLeft();
        /// @brief Takes the currently active TetrisPiece and swaps it with the currently held piece
        // if there are any, if not the next piece becomes the next piece as normal
        void holdPiece();

        void openMenu();


    };

} // Tetris::Logic

#endif // TETRISEXAM_GAMELOGICMANAGER_H
