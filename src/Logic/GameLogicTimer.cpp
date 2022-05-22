//
// Created by glosn on 4/28/2022.
//

#include "GameLogicTimer.h"

namespace Tetris::Logic
{
    GameLogicTimer::GameLogicTimer() = default;

    bool GameLogicTimer::shouldThePieceFall(float deltaTime, bool shouldFallFast)
    {
        m_timeSincePieceFall += deltaTime;

        if (!shouldFallFast)
        {
            m_fellFastLastIteration = false;
            if (m_timeSincePieceFall > m_timeBetweenTetrisPieceFall)
            {
                m_timeSincePieceFall -= m_timeBetweenTetrisPieceFall;
                return true;
            }
            return false;
        }
        else
        {
            if (m_timeSincePieceFall > m_timeBetweenTetrisPieceFallInFastMode)
            {
                if (m_fellFastLastIteration)
                    m_timeSincePieceFall -= m_timeBetweenTetrisPieceFallInFastMode;
                else
                    m_timeSincePieceFall = 0;

                m_fellFastLastIteration = true;
                return true;
            }
            m_fellFastLastIteration = false;
            return false;
        }
    }

    bool GameLogicTimer::shouldThePieceSolidify(sf::Vector2i piecePosition, bool didTrick)
    {
        m_fallingMovesSincePieceFell -= didTrick; // This is a quickfix...

        if (piecePosition.y != m_previousYPosition)
            m_fallingMovesSincePieceFell = 0;
        else
            m_fallingMovesSincePieceFell += 1;

        m_previousYPosition = piecePosition.y;
        return m_fallingMovesSincePieceFell >= m_wantedFallingMovesBeforeSolidification;
    }

} // Tetris::Logic