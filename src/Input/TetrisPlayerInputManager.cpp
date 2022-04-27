//
// Created by glosn on 4/27/2022.
//

#include "TetrisPlayerInputManager.h"
#include "KeyboardInput.h"

namespace Tetris::Input
{
    TetrisPlayerInputManager::TetrisPlayerInputManager() = default;

    bool TetrisPlayerInputManager::shouldTurnRight(float deltaTime)
    {
        if (m_inputDevice.turnLeftIsPressed())
        {
            if (m_wasTurnRightHeldDownButtonPreviousCall)
            {
                return false;
            }
            else
            {
                m_wasTurnRightHeldDownButtonPreviousCall = true;
                return true;
            }
        }
        else
        {
            m_wasTurnRightHeldDownButtonPreviousCall = false;
            return false;
        }
    }

    bool TetrisPlayerInputManager::shouldTurnLeft(float deltaTime)
    {
        if (m_inputDevice.turnLeftIsPressed())
        {
            if (m_wasTurnLeftButtonHeldDownPreviousCall)
            {
                return false;
            }
            else
            {
                m_wasTurnLeftButtonHeldDownPreviousCall = true;
                return true;
            }
        }
        else
        {
            m_wasTurnLeftButtonHeldDownPreviousCall = false;
            return false;
        }
    }

    bool TetrisPlayerInputManager::shouldInstantFall(float deltaTime)
    {
        if (m_inputDevice.instantFallIsPressed())
        {
            if (m_wasInstantFallButtonHeldDownPreviousCall)
            {
                return false;
            }
            else
            {
                m_wasInstantFallButtonHeldDownPreviousCall = true;
                return true;
            }
        }
        else
        {
            m_wasInstantFallButtonHeldDownPreviousCall = false;
            return false;
        }
    }

    bool TetrisPlayerInputManager::shouldSpeedFall(float deltaTime)
    {
        return m_inputDevice.speedFallIsPressed();
    }

    bool TetrisPlayerInputManager::shouldMoveRight(float deltaTime)
    {
        if(m_inputDevice.moveRightIsPressed())
        {
            if (m_moveRightKeyPressedSinceLastMove)
            {
                m_timeSinceMoveRight += deltaTime;

                if (m_firstAutomaticMoveRight)
                {
                    if (m_timeSinceMoveRight > m_timeBetweenTheFirstAutomaticMoves)
                    {
                        m_firstAutomaticMoveRight = false;
                        m_timeSinceMoveRight = 0;
                        return true;
                    }
                }
                else
                {
                    if (m_timeSinceMoveRight > m_timeBetweenMovesWhenHolding)
                    {
                        m_firstAutomaticMoveRight = false;
                        m_timeSinceMoveRight = 0;
                        return true;
                    }
                }

                return false;
            }
            else
            {
                m_timeSinceMoveRight = deltaTime;
                m_moveRightKeyPressedSinceLastMove = true;
                return true;
            }
        }
        else
        {
            m_timeSinceMoveRight = 0;
            m_firstAutomaticMoveRight = true;
            m_moveRightKeyPressedSinceLastMove = false;
            return false;
        }
    }

    bool TetrisPlayerInputManager::shouldMoveLeft(float deltaTime)
    {
        if(m_inputDevice.moveLeftIsPressed())
        {
            if (m_moveLeftKeyPressedSinceLastMove)
            {
                m_timeSinceMoveLeft += deltaTime;

                if (m_firstAutomaticMoveLeft)
                {
                    if (m_timeSinceMoveLeft > m_timeBetweenTheFirstAutomaticMoves)
                    {
                        m_firstAutomaticMoveLeft = false;
                        m_timeSinceMoveLeft = 0;
                        return true;
                    }
                }
                else
                {
                    if (m_timeSinceMoveLeft > m_timeBetweenMovesWhenHolding)
                    {
                        m_firstAutomaticMoveLeft = false;
                        m_timeSinceMoveLeft = 0;
                        return true;
                    }
                }

                return false;
            }
            else
            {
                m_timeSinceMoveLeft = deltaTime;
                m_moveLeftKeyPressedSinceLastMove = true;
                return true;
            }
        }
        else
        {
            m_timeSinceMoveLeft = 0;
            m_firstAutomaticMoveLeft = true;
            m_moveLeftKeyPressedSinceLastMove = false;
            return false;
        }
    }

    bool TetrisPlayerInputManager::shouldOpenMenu(float deltaTime)
    {
        if (m_inputDevice.pauseIsPressed())
        {
            if (m_shouldOpenMenuButtonWasHeldDownPreviousCall)
            {
                return false;
            }
            else
            {
                m_shouldOpenMenuButtonWasHeldDownPreviousCall = true;
                return true;
            }
        }
        else
        {
            m_shouldOpenMenuButtonWasHeldDownPreviousCall = false;
            return false;
        }
    }

    bool TetrisPlayerInputManager::shouldHoldPiece(float deltaTime)
    {
        if (m_inputDevice.holdPieceIsPressed())
        {
            if (m_shouldHoldPieceWasHeldDownPreviousCall)
            {
                return false;
            }
            else
            {
                m_shouldHoldPieceWasHeldDownPreviousCall = true;
                return true;
            }
        }
        else
        {
            m_shouldHoldPieceWasHeldDownPreviousCall = false;
            return false;
        }
    }
}
