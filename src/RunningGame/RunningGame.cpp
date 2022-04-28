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
    {
        m_gameRenderer->updateRender();
    }

    sf::Sprite RunningGame::getSprite()
    {
        return m_gameRenderer->getSprite();
    }

    void RunningGame::updateFrame(float deltaTime)
    {
        m_gameLogic->updateLogic(deltaTime);
        m_gameRenderer->updateRender();
    }

} // Tetris
