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
        bool shouldThePieceSolidify(sf::Vector2i piecePosition, bool didTrick);

    private:
        // Variables for the shouldThePieceFall function
        float m_timeSincePieceFall{0};
        float m_timeBetweenTetrisPieceFall{0.5f};
        float m_timeBetweenTetrisPieceFallInFastMode{0.05f};
        bool m_fellFastLastIteration{false};


        // Variables for the shouldThePieceSolidify function
        int m_previousYPosition{};
        int m_fallingMovesSincePieceFell{0};
        int m_wantedFallingMovesBeforeSolidification{2};
    };

} // Tetris::Logic

#endif //TETRISEXAM_GAMELOGICTIMER_H
