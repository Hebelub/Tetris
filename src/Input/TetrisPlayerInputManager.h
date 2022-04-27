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
        KeyboardInput inputDevice{KeyboardInput()};

    };
}


#endif //TETRISEXAM_TETRISPLAYERINPUTMANAGER_H
