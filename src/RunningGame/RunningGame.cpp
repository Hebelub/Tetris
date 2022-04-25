//
// Created by glosn on 4/23/2022.
//

#include "RunningGame.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace Tetris
{
    RunningGame::RunningGame()
        : m_currentGameState(GameLoader::loadGame())
        , m_gameRenderer(std::make_unique<Graphics::GameRenderer>())
        , m_gameLogic(std::make_unique<Logic::GameLogicManager>())
    {
        m_gameRenderer->updateRender(m_currentGameState);
    }

    sf::Sprite RunningGame::getSprite()
    {
        return m_gameRenderer->getSprite();
    }

    void RunningGame::updateFrame(float deltaTime)
    {
        m_gameLogic->updateLogic(m_currentGameState, deltaTime);
        m_gameRenderer->updateRender(m_currentGameState);
    }

} // Tetris
