//
// Created by glosn on 4/23/2022.
//

#include "Game.h"
#include "../View/GameRenderer.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

namespace Tetris
{
    Game::Game()
    {
        m_gameRenderer->updateRender();
    }

    sf::Sprite Game::getSprite()
    {
        return m_gameRenderer->getSprite();
    }

    void Game::updateFrame(float deltaTime)
    {
        m_gameLogic->updateLogic(deltaTime);
        m_gameRenderer->updateRender();
    }

} // Tetris
