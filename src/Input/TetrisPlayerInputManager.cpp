//
// Created by glosn on 4/27/2022.
//

#include "TetrisPlayerInputManager.h"
#include "KeyboardInput.h"

namespace Tetris::Input
{
    TetrisPlayerInputManager::TetrisPlayerInputManager()
    {
    }

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
        return false;
    }

    bool TetrisPlayerInputManager::shouldMoveLeft(float deltaTime)
    {
        return false;
    }
}
