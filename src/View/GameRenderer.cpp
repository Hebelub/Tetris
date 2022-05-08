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
                            m_gameState
                    )
                )
          )
    {
        initializeRendering();
    }

    void GameRenderer::initializeRendering()
    {
        // TODO: Pass dimensions in

        m_renderTexture.create(m_pixelWidth, m_pixelHeight);

        m_renderSprite.setTexture(m_renderTexture.getTexture());

        m_font.loadFromFile("Assets/Pixeltype.ttf");

        m_scoreText.setFont(m_font);
        m_scoreText.setStyle(sf::Text::Regular);
        m_scoreText.setCharacterSize(50);
        m_scoreText.setFillColor(sf::Color::Black);
        m_scoreText.setPosition(10, 2);
    }

    void GameRenderer::updateRender()
    {
        m_renderTexture.clear(sf::Color(200, 200, 200));

        sf::IntRect borders(0, 0, 200, 400);

        m_gridDrawer->drawGrid(m_gameState.gameGrid, borders);

        m_renderTexture.draw(m_renderSprite);

        m_scoreText.setString(std::to_string(m_gameState.score));
        if (m_gameState.gameOver)
        {
            m_scoreText.setString("Game Over!\nScore: " + std::to_string(m_gameState.score));
        }
        m_renderTexture.draw(m_scoreText);

        m_renderTexture.display();

        m_renderSprite.setTexture(m_renderTexture.getTexture());
    }

    sf::Sprite &GameRenderer::getSprite()
    {
        return m_renderSprite;
    }

} // Tetris::Graphics
