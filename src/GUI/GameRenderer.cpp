//
// Created by glosn on 4/23/2022.
//

#include "GameRenderer.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Tetris::Graphics
{
    GameRenderer::GameRenderer()
    {
        initializeRendering();
    }

    void GameRenderer::initializeRendering()
    {
        // TODO: Pass dimensions in

        m_renderTexture.create(300, 400);

        m_renderSprite.setTexture(m_renderTexture.getTexture());

        m_renderSprite.setTextureRect(
                sf::IntRect(
                        0,
                        0,
                        300,
                        400
                )
        );
        
    }

    void GameRenderer::updateRender(const State::TetrisGameState& game)
    {
        m_renderTexture.clear(sf::Color::Cyan);

        m_renderTexture.display();
        m_renderSprite.setTexture(m_renderTexture.getTexture());

    }

    sf::Sprite GameRenderer::getSprite()
    {
        return m_renderSprite;
    }

} // Tetris::Graphics
