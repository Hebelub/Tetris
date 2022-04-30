//
// Created by glosn on 4/24/2022.
//

#include <iostream>
#include "GameLogicManager.h"

namespace Tetris::Logic
{
    GameLogicManager::GameLogicManager(State::GameState &gameState)
        : m_gameState(gameState)
        , m_piece(m_gameState.getActiveTetris(), m_gameState.getGridState())
    {
        m_piece.spawnNewPiece();
    }

    void GameLogicManager::updateLogic(float deltaTime)
    {
        if (m_timer.shouldThePieceFall(deltaTime, m_inputManager.shouldSpeedFall(deltaTime)))
        {
            m_piece.tryFallOnce();
        }


        if (m_inputManager.shouldMoveLeft(deltaTime))
            m_piece.tryMoveOnceLeft();
        if (m_inputManager.shouldMoveRight(deltaTime))
            m_piece.tryMoveOnceRight();

        if (m_inputManager.shouldRotateRight(deltaTime))
            std::cout << "RotateRight" << std::endl;
        if (m_inputManager.shouldRotateLeft(deltaTime))
            std::cout << "RotateLeft" << std::endl;
        if (m_inputManager.shouldInstantFall(deltaTime))
            std::cout << "InstantFall" << std::endl;
        if (m_inputManager.shouldHoldPiece(deltaTime))
            std::cout << "HoldPiece" << std::endl;
        if (m_inputManager.shouldOpenMenu(deltaTime))
            std::cout << "OpenMenu" << std::endl;
    }

} // Tetris::Logic