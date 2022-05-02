#include "TetrisPlayerInputManager.h"
#include "KeyboardInput.h"

namespace Tetris::Input
{
    TetrisPlayerInputManager::TetrisPlayerInputManager(const KeyboardLayout &layout)
        : m_inputDevice(layout)
    {
    }

    bool TetrisPlayerInputManager::shouldButtonPressed(bool checkButton, bool &m_variable)
    {
        if (checkButton)

        {
            if (m_variable)
            {
                return false;
            }
            else
            {
                m_variable = true;
                return true;
            }
        }
        else
        {
            m_variable = false;
            return false;
        }
    } // end function

    bool TetrisPlayerInputManager::shouldRotateRight(float deltaTime)
    {
        return TetrisPlayerInputManager::shouldButtonPressed(m_inputDevice.turnRightIsPressed(),
                                                             m_wasTurnRightHeldDownButtonPreviousCall);
    }

    bool TetrisPlayerInputManager::shouldRotateLeft(float deltaTime)
    {
        return TetrisPlayerInputManager::shouldButtonPressed(m_inputDevice.turnLeftIsPressed(),
                                                             m_wasTurnLeftButtonHeldDownPreviousCall);
    }

    bool TetrisPlayerInputManager::shouldInstantFall(float deltaTime)
    {
        return TetrisPlayerInputManager::shouldButtonPressed(m_inputDevice.instantFallIsPressed(),
                                                             m_wasInstantFallButtonHeldDownPreviousCall);
    }

    bool TetrisPlayerInputManager::shouldSpeedFall(float deltaTime)
    {
        return m_inputDevice.speedFallIsPressed();
    }

    bool TetrisPlayerInputManager::shouldMoveDirection(bool checkButton, bool &m_move, bool &m_firstMove, float &m_timeSinceMove, float deltaTime)
    {
        if (checkButton)
        {
            if (m_move)
            {
                m_timeSinceMove += deltaTime;

                if (m_firstMove)
                {
                    if (m_timeSinceMove > m_timeBetweenTheFirstAutomaticMoves)
                    {

                        m_firstMove = false;
                        m_timeSinceMove = 0;
                        return true;
                    }
                }
                else
                {
                    if (m_timeSinceMove > m_timeBetweenMovesWhenHolding)
                    {
                        m_firstMove = false;
                        m_timeSinceMove = 0;
                        return true;
                    }
                }

                return false;
            }
            else
            {
                m_timeSinceMove = deltaTime;
                m_move = true;
                return true;
            }
        }
        else
        {
            m_timeSinceMove = 0;
            m_firstMove = true;
            m_move = false;
            return false;
        }
    } // end of func

    bool TetrisPlayerInputManager::shouldMoveRight(float deltaTime)
    {
        return TetrisPlayerInputManager::shouldMoveDirection(m_inputDevice.moveRightIsPressed(),
                                                             m_moveRightKeyPressedSinceLastMove, m_firstAutomaticMoveRight,
                                                             m_timeSinceMoveRight, deltaTime);
    }

    bool TetrisPlayerInputManager::shouldMoveLeft(float deltaTime)
    {
        return TetrisPlayerInputManager::shouldMoveDirection(m_inputDevice.moveLeftIsPressed(),
                                                             m_moveLeftKeyPressedSinceLastMove, m_firstAutomaticMoveLeft,
                                                             m_timeSinceMoveLeft, deltaTime);
    }

    bool TetrisPlayerInputManager::shouldOpenMenu(float deltaTime)
    {
        return TetrisPlayerInputManager::shouldButtonPressed(m_inputDevice.pauseIsPressed(),
                                                             m_shouldOpenMenuButtonWasHeldDownPreviousCall);
    }

    bool TetrisPlayerInputManager::shouldHoldPiece(float deltaTime)
    {
        return TetrisPlayerInputManager::shouldButtonPressed(m_inputDevice.holdPieceIsPressed(),
                                                             m_shouldHoldPieceWasHeldDownPreviousCall);
    }
    // end of function
} // end of namespace
