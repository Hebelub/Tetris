//
// Created by glosn on 4/24/2022.
//

#include <iostream>
#include "GameLogic.h"

namespace Tetris::Logic
{
    GameLogic::GameLogic(const KeyboardLayout &layout, State::GameState &gameState)
        : m_inputManager(layout)
        , m_gameState(gameState)
        , m_pieceLogic(m_gameState.activePiece, m_gameState.gameGrid)
    {
        activateNextPieceFromQueue();
    }

    void GameLogic::updateLogic(float deltaTime)
    {
        if (m_timer.shouldThePieceFall(deltaTime, m_inputManager.shouldSpeedFall(deltaTime)))
        {
            if (!m_pieceLogic.tryFallOnce())
            {
                if (m_inputManager.rightButtonIsDown())
                {
                    m_pieceLogic.tryFallDiagonalRight();
                }
                else if (m_inputManager.leftButtonIsDown())
                {
                    m_pieceLogic.tryFallDiagonalLeft();
                }

                if (m_timer.shouldThePieceSolidify(m_pieceLogic.getPiecePosition()))
                    nextPiece();
            }
        }

        if (m_inputManager.shouldMoveLeft(deltaTime))
            m_pieceLogic.tryMoveOnceLeft();
        if (m_inputManager.shouldMoveRight(deltaTime))
            m_pieceLogic.tryMoveOnceRight();

        if (m_inputManager.shouldRotateRight(deltaTime)) {
            m_pieceLogic.tryRotateRight(); }
        if (m_inputManager.shouldRotateLeft(deltaTime)) {}
        if (m_inputManager.shouldInstantFall(deltaTime))
        {
            while(m_pieceLogic.tryFallOnce());
            nextPiece();
        }
        if (m_inputManager.shouldHoldPiece(deltaTime)) {}
        if (m_inputManager.shouldOpenMenu(deltaTime)) {}
    }

    void GameLogic::activateNextPieceFromQueue()
    {
        auto &queue = m_gameState.upcomingPieces;

        queue.push_back(m_gameState.generator.getRandomShape());
        m_pieceLogic.spawnNewPiece(queue.front());
        queue.pop_front();

    }

    void GameLogic::nextPiece()
    {
        m_gameState.gameOver = !m_pieceLogic.makePieceSolid();
        int numLinesCleared = m_gridLogic.removeSolidHorizontalLines();
        if (numLinesCleared > 0 && m_lineClearCallback.has_value())
        {
            m_gameState.score += numLinesCleared * numLinesCleared;
            if (numLinesCleared > 1) m_gameState.upcomingPieces.push_back(m_gameState.generator.getRandomShape(State::TetrisShape::Good));
            m_lineClearCallback.value()(numLinesCleared);
        }
        activateNextPieceFromQueue();
    }

    bool GameLogic::isGameOver() const
    {
        return m_gameState.gameOver;
    }

    void GameLogic::setLineClearCallback(const std::function<void(int)> &callback)
    {
        m_lineClearCallback = callback;
    }

} // Tetris::Logic