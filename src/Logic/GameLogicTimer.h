//
// Created by glosn on 4/28/2022.
//

#ifndef TETRISEXAM_GAMELOGICTIMER_H
#define TETRISEXAM_GAMELOGICTIMER_H

#include "../GameState/GameState.h"

namespace Tetris::Logic
{
    // TODO: This is very dangerous code, and should have another solution to it. But it works for now!

    class GameLogicTimer
    {
    public:
        GameLogicTimer();

        bool shouldThePieceFall(float deltaTime, bool shouldFallFast);

        /// @brief Not implemented yet
        bool shouldThePieceSolidify(float deltaTime);

    private:
        // Variables for the shouldThePieceFall function
        float m_timeSincePieceFall{0};
        float m_timeBetweenTetrisPieceFall{1};
        float m_timeBetweenTetrisPieceFallInFastMode{0.25};
        bool m_fellFastLastIteration{false};
    };

} // Tetris::Logic

#endif //TETRISEXAM_GAMELOGICTIMER_H
