//
// Created by glosn on 4/23/2022.
//

#include "RunningGame.h"
#include "../View/GameRenderer.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

namespace Tetris
{
    RunningGame::RunningGame()
        : m_currentGameState(std::make_unique<State::TetrisGameState>(GameLoader::loadGame()))
        , m_gameRenderer(std::make_unique<Graphics::GameRenderer>(*m_currentGameState))
        , m_gameLogic(std::make_unique<Logic::GameLogicManager>(*m_currentGameState))
    {
        m_gameRenderer->updateRender(*m_currentGameState);
    }

    sf::Sprite RunningGame::getSprite()
    {
        return m_gameRenderer->getSprite();
    }

    void RunningGame::updateFrame(float deltaTime)
    {
        m_gameLogic->updateLogic(deltaTime);
        m_gameRenderer->updateRender(*m_currentGameState);


    }

} // Tetris
