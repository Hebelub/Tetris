//
// Created by glosn on 4/23/2022.
//

#include "GameRenderer.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Tetris::Graphics
{
    GameRenderer::GameRenderer(State::GameState &gameState)
        : m_gameState(gameState)
        , m_gridDrawer(
                std::make_unique<GridDrawer>(
                        GridDrawer(
                            m_renderTexture,
                            m_gameState.getGridState()
                    )
                )
          )
    {
        initializeRendering();
    }

    void GameRenderer::initializeRendering()
    {
        // TODO: Pass dimensions in

        m_renderTexture.create(300, 400);

        m_renderSprite.setTexture(m_renderTexture.getTexture());
    }

    void GameRenderer::updateRender(const State::GameState &game)
    {
        m_renderTexture.clear(sf::Color::Cyan);

        sf::IntRect borders(0, 0, 200, 400);

        m_gridDrawer->drawGrid(m_gameState.getGridState(), borders);

        m_renderTexture.display();
        m_renderSprite.setTexture(m_renderTexture.getTexture());
    }

    sf::Sprite GameRenderer::getSprite()
    {
        return m_renderSprite;
    }

} // Tetris::Graphics
