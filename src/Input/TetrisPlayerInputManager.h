//
// Created by glosn on 4/27/2022.
//

#ifndef TETRISEXAM_TETRISPLAYERINPUTMANAGER_H
#define TETRISEXAM_TETRISPLAYERINPUTMANAGER_H


#include "../RunningGame/RunningGame.h"
#include "InputType.h"
#include "KeyboardInput.h"
#include <vector>

namespace Tetris::Input
{
    /// @brief Gives easy access to the possible game moves
    // Keeps track of witch type of input you use,
    // keyboard input or controller input etc.
    class TetrisPlayerInputManager
    {
    public:
        TetrisPlayerInputManager();

        bool shouldTurnRight(float deltaTime);
        bool shouldTurnLeft(float deltaTime);
        bool shouldInstantFall(float deltaTime);
        bool shouldSpeedFall(float deltaTime);
        bool shouldMoveRight(float deltaTime);
        bool shouldMoveLeft(float deltaTime);

    private:
        // Setting this to InputType did not work, IDK why
        KeyboardInput m_inputDevice{KeyboardInput()};


        // Variables for shouldTurnRight
        bool m_wasTurnRightHeldDownButtonPreviousCall{false};

        // Variables for shouldTurnLeft
        bool m_wasTurnLeftButtonHeldDownPreviousCall{false};

        // Variables for shouldInstantFall
        bool m_wasInstantFallButtonHeldDownPreviousCall{false};

        // Variables for shouldSpeedFall

        // Variables for sideways moving
        float m_timeSinceMoveLeft{0};
        float m_timeSinceMoveRight{0};
        bool m_firstAutomaticMove{true};
        float m_timeBetweenMovesWhenHolding{0};
        bool m_moveLeftKeyPressedSinceLastMove{false};
        bool m_moveRightKeyPressedSinceLastMove{false};


    };
}


#endif //TETRISEXAM_TETRISPLAYERINPUTMANAGER_H
