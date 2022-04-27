//
// Created by glosn on 4/24/2022.
//

#include <iostream>
#include "GameLogicManager.h"

namespace Tetris::Logic
{
    GameLogicManager::GameLogicManager(State::TetrisGameState &gameState)
        : m_gameState(gameState)
    { }

    // TODO: The gameState should maybe be a member reference instead?
    void GameLogicManager::updateLogic(float deltaTime)
    {
        if (m_inputManager.shouldMoveLeft(deltaTime))
            std::cout << "MoveLeft" << std::endl;
        if (m_inputManager.shouldMoveRight(deltaTime))
            std::cout << "MoveRight" << std::endl;
        if (m_inputManager.shouldTurnRight(deltaTime))
            std::cout << "TurnRight" << std::endl;
        if (m_inputManager.shouldTurnLeft(deltaTime))
            std::cout << "TurnLeft" << std::endl;
        if (m_inputManager.shouldSpeedFall(deltaTime))
            std::cout << "FallFast" << std::endl;
        if (m_inputManager.shouldInstantFall(deltaTime))
            std::cout << "InstantFall" << std::endl;
        if (m_inputManager.shouldHoldPiece(deltaTime))
            std::cout << "HoldPiece" << std::endl;
        if (m_inputManager.shouldOpenMenu(deltaTime))
            std::cout << "OpenMenu" << std::endl;
    }

} // Tetris::Logic