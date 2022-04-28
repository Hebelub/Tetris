//
// Created by glosn on 4/27/2022.
//

#ifndef TETRISEXAM_TETRISPLAYERINPUTMANAGER_H
#define TETRISEXAM_TETRISPLAYERINPUTMANAGER_H

#include "InputType.h"
#include "KeyboardInput.h"
#include <vector>

namespace Tetris::Input
{

    // TODO: This code is very unsafe, unreadable, unorganised, unsustainable. Fix it!

    /// @brief Gives easy access to the possible game moves
    // Keeps track of witch type of input you use,
    // keyboard input or controller input etc.
    class TetrisPlayerInputManager
    {
    public:
        ///@brief Default constructor
        TetrisPlayerInputManager();

        /// @brief Attempt at generalizing 6 functions. Add deltaTime if needed.
        /// @param checkButton m_inputDevice check function
        /// @param m_variable internal bool last press variable
        /// @returns bool -> whether or not the button has been pressed.
        bool shouldButtonPressed(bool checkButton, bool &m_variable);
        /// @brief Calls shouldButtonPressed()
        bool shouldRotateRight(float deltaTime);
        /// @brief Calls shouldButtonPressed()
        bool shouldRotateLeft(float deltaTime);
        /// @brief Calls shouldButtonPressed()
        bool shouldInstantFall(float deltaTime);
        /// @brief Calls shouldButtonPressed()
        bool shouldSpeedFall(float deltaTime);
        /// @brief Calls shouldButtonPressed()
        bool shouldOpenMenu(float deltaTime);
        /// @brief Calls shouldButtonPressed()
        bool shouldHoldPiece(float deltaTime);

        ///@brief Generalizing shouldMoveRight and shouldMoveLeft
        bool shouldMoveDirection(bool checkButton, bool &m_move,
                                 bool &m_firstMove, float &m_timeSinceMove, float deltaTime);
        ///@brief Calls shouldMoveDirection for right direction.
        bool shouldMoveRight(float deltaTime);
        ///@brief Calls shouldMoveDirection for left direction.
        bool shouldMoveLeft(float deltaTime);

    private:
        // Setting this to InputType did not work, IDK why
        KeyboardInput m_inputDevice{KeyboardInput()};

        // Variables for shouldRotateRight
        bool m_wasTurnRightHeldDownButtonPreviousCall{false};

        // Variables for shouldRotateLeft
        bool m_wasTurnLeftButtonHeldDownPreviousCall{false};

        // Variables for shouldInstantFall
        bool m_wasInstantFallButtonHeldDownPreviousCall{false};

        // Variables for shouldSpeedFall

        // Variables for sideways moving
        float m_timeSinceMoveLeft{0};
        float m_timeSinceMoveRight{0};

        bool m_firstAutomaticMoveRight{true};
        bool m_firstAutomaticMoveLeft{true};

        bool m_moveLeftKeyPressedSinceLastMove{false};
        bool m_moveRightKeyPressedSinceLastMove{false};

        float m_timeBetweenMovesWhenHolding{0.15f};
        float m_timeBetweenTheFirstAutomaticMoves{0.3f};

        // Variables for shouldOpenMenu
        bool m_shouldOpenMenuButtonWasHeldDownPreviousCall{false};

        // Variables for shouldHoldPiece
        bool m_shouldHoldPieceWasHeldDownPreviousCall{false};
    };
}

#endif // TETRISEXAM_TETRISPLAYERINPUTMANAGER_H
