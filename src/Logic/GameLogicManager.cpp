//
// Created by glosn on 4/24/2022.
//

#include <iostream>
#include "GameLogicManager.h"

namespace Tetris::Logic
{
    GameLogicManager::GameLogicManager(State::GameState &gameState)
        : m_gameState(gameState)
        , m_pieceLogic(m_gameState.activePiece, m_gameState.gameGrid)
    {
        activateNextPieceFromQueue();
    }

    void GameLogicManager::updateLogic(float deltaTime)
    {
        if (m_timer.shouldThePieceFall(deltaTime, m_inputManager.shouldSpeedFall(deltaTime)))
        {
            if (!m_pieceLogic.tryFallOnce())
            {
                m_pieceLogic.makePieceSolid();
                activateNextPieceFromQueue();
            }
        }


        if (m_inputManager.shouldMoveLeft(deltaTime))
            m_pieceLogic.tryMoveOnceLeft();
        if (m_inputManager.shouldMoveRight(deltaTime))
            m_pieceLogic.tryMoveOnceRight();

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

    void GameLogicManager::activateNextPieceFromQueue()
    {
        auto& queue = m_gameState.upcomingPieces;

        queue.push_back(m_gameState.generator.getRandomShape());
        m_pieceLogic.spawnNewPiece(queue.front());
        queue.pop_front();

    }

} // Tetris::Logic