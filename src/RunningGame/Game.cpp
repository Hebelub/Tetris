//
// Created by glosn on 4/23/2022.
//

#include "Game.h"
#include "../View/GameRenderer.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <utility>

namespace Tetris
{
    Game::Game(std::string name, const Input::PlayerInput &playerInput, unsigned int seed)
        : m_pieceGenerator(seed)
        , m_gameRenderer(m_currentGameState)
        , m_gameLogic(playerInput, m_currentGameState)
        , m_name(std::move(name))
    {
    }

    sf::Sprite &Game::getSprite()
    {
        return m_gameRenderer.getSprite();
    }

    void Game::updateFrame(float deltaTime)
    {
        m_gameLogic.updateLogic(deltaTime);
        m_gameRenderer.updateRender();
    }

    bool Game::isGameOver()
    {
        return m_gameLogic.isGameOver();
    }

    void Game::onOpponentClear(int numLines)
    {
        switch(numLines)
        {
            case 1:
            {
                m_currentGameState.upcomingPieces.push_back(m_pieceGenerator.getRandomShape(State::TetrisShape::Bad));
                break;
            }
            case 2:
            {
                m_currentGameState.upcomingPieces.push_back(m_pieceGenerator.getRandomShape(State::TetrisShape::Horrible));
                break;
            }
            case 3:
            {
                m_currentGameState.upcomingPieces.push_back(m_pieceGenerator.getRandomShape(State::TetrisShape::Bad));
                m_currentGameState.upcomingPieces.push_back(m_pieceGenerator.getRandomShape(State::TetrisShape::Bad));
                break;
            }
            case 4:
            {
                m_currentGameState.upcomingPieces.push_back(m_pieceGenerator.getRandomShape(State::TetrisShape::Horrible));
                m_currentGameState.upcomingPieces.push_back(m_pieceGenerator.getRandomShape(State::TetrisShape::Bad));
                break;
            }
            default:
            {
                m_currentGameState.upcomingPieces.push_back(m_pieceGenerator.getRandomShape(State::TetrisShape::Horrible));
                m_currentGameState.upcomingPieces.push_back(m_pieceGenerator.getRandomShape(State::TetrisShape::Horrible));
                break;
            }
        }

    }

    void Game::setLineClearCallback(const std::function<void(int)> &clearCallback)
    {
        m_gameLogic.setLineClearCallback(clearCallback);
    }

} // Tetris
