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
            if (m_timeSincePieceFall > m_timeBetweenTetrisPieceFall)
            {
                m_timeSincePieceFall -= m_timeBetweenTetrisPieceFall;
                m_fellFastLastIteration = false;
                return true;
            }
        }
        else
        {
            if (m_timeSincePieceFall > m_timeBetweenTetrisPieceFallInFastMode)
            {
                if (m_fellFastLastIteration)
                {
                    m_timeSincePieceFall -= m_timeBetweenTetrisPieceFallInFastMode;
                }
                else
                {
                    m_timeSincePieceFall = 0;
                }

                m_fellFastLastIteration = true;
                return true;
            }
        }
    }

    bool GameLogicTimer::shouldThePieceSolidify(float deltaTime)
    {
        return false;
    }
} // Tetris::Logic