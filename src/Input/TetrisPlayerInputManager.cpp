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
        return false;
    }

    bool TetrisPlayerInputManager::shouldTurnLeft(float deltaTime)
    {
        return false;
    }

    bool TetrisPlayerInputManager::shouldInstantFall(float deltaTime)
    {
        return false;
    }

    bool TetrisPlayerInputManager::shouldSpeedFall(float deltaTime)
    {
        return false;
    }

    bool TetrisPlayerInputManager::shouldMoveRight(float deltaTime)
    {
        if(m_inputDevice.moveRightIsPressed() && m_timeSinceMoveRight <= m_timeSinceMoveLeft)
        {
            if (m_moveRightKeyPressedSinceLastMove) {
                m_timeSinceMoveRight += deltaTime;

                if (m_firstAutomaticMove)
                {
                    if (m_timeSinceMoveRight > m_timeBetweenMovesWhenHolding * 2)
                    {
                        m_firstAutomaticMove = false;
                        m_timeSinceMoveRight = 0;
                        return true;
                    }
                }
                else
                {
                    if (m_timeSinceMoveRight > m_timeBetweenMovesWhenHolding)
                    {
                        m_firstAutomaticMove = false;
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
            m_firstAutomaticMove = false;
            return false;
        }
    }

    bool TetrisPlayerInputManager::shouldMoveLeft(float deltaTime)
    {
        if(m_inputDevice.moveLeftIsPressed() && m_timeSinceMoveLeft <= m_timeSinceMoveRight)
        {
            if (m_moveLeftKeyPressedSinceLastMove) {
                m_timeSinceMoveLeft += deltaTime;

                if (m_firstAutomaticMove)
                {
                    if (m_timeSinceMoveLeft > m_timeBetweenMovesWhenHolding * 2)
                    {
                        m_firstAutomaticMove = false;
                        m_timeSinceMoveRight = 0;
                        return true;
                    }
                }
                else
                {
                    if (m_timeSinceMoveLeft > m_timeBetweenMovesWhenHolding)
                    {
                        m_firstAutomaticMove = false;
                        m_timeSinceMoveRight = 0;
                        return true;
                    }
                }

                return false;
            }
            else
            {
                m_timeSinceMoveLeft = false;
                m_moveLeftKeyPressedSinceLastMove = true;
                return true;
            }
        }
        else
        {
            m_timeSinceMoveLeft = 0;
            m_firstAutomaticMove = false;
            return false;
        }
    }
}
