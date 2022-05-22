//
// Created by glosn on 4/24/2022.
//

#include <iostream>
#include <utility>
#include "GameLogic.h"
#include "../Input/PlayerInput.h"
#include "../Audio/PlaySound.h"

namespace Tetris::Logic
{
    GameLogic::GameLogic(Input::PlayerInput playerInput, State::GameState &gameState)
        : m_playerInput(std::move(playerInput))
        , m_gameState(gameState)
        , m_pieceLogic(m_gameState.activePiece, m_gameState.gameGrid)
    {
        activateNextPieceFromQueue();
    }

    void GameLogic::updateLogic(float deltaTime)
    {
        m_playerInput.updateButtons(deltaTime);


        if (m_timer.shouldThePieceFall(deltaTime, m_playerInput.fallFast.isButtonPressed()))
        {
            bool didTrick{false};

            if (!m_pieceLogic.tryFallOnce())
            {

                if (m_playerInput.moveRight.isButtonPressed())
                {
                    if (m_pieceLogic.tryFallDiagonalRight())
                    {
                        didTrick = true;
                    }
                }
                else if (m_playerInput.moveLeft.isButtonPressed())
                {
                    if (m_pieceLogic.tryFallDiagonalLeft())
                        didTrick = true;
                }

                if (didTrick)
                {
                    Audio::PlaySound::playSound(Audio::SoundId::Trick);
                    m_gameState.numOfSlides++;
                }

                if (m_timer.shouldThePieceSolidify(m_pieceLogic.getPiecePosition(), didTrick))
                    nextPiece();
            }
        }

        if (m_playerInput.moveLeft.getSignal())
        {
            m_pieceLogic.tryMoveOnceLeft();
        }

        if (m_playerInput.moveRight.getSignal())
        {
            m_pieceLogic.tryMoveOnceRight();
        }

        if (m_playerInput.rotateRight.getSignal())
        {
            if (m_pieceLogic.tryRotateRight())
            {
                Audio::PlaySound::playSound(Audio::SoundId::Rotate);
            }
            else
            {
                Audio::PlaySound::playSound(Audio::SoundId::CantRotate);
            }
        }

        if (m_playerInput.rotateLeft.getSignal())
        {
            if (m_pieceLogic.tryRotateLeft())
            {
                Audio::PlaySound::playSound(Audio::SoundId::Rotate);
            }
            else
            {
                Audio::PlaySound::playSound(Audio::SoundId::CantRotate);
            }
        }

        if (m_playerInput.instantFall.getSignal())
        {
            while(m_pieceLogic.tryFallOnce());
            Audio::PlaySound::playSound(Audio::SoundId::InstantFall);
            nextPiece();
        }
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

        if (m_gameState.gameOver) Audio::PlaySound::playSound(Audio::SoundId::GameOver);

        m_gameState.numOfSolidifiedPieces++;
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