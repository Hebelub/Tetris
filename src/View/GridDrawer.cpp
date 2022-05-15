//
// Created by glosn on 4/25/2022.
//

#include "GridDrawer.h"
#include "../RunningGame/Application.h"

#include <iostream>

namespace Tetris::Graphics
{
    GridDrawer::GridDrawer(sf::RenderTexture &renderTexture, State::GameState &gameState)
        : m_renderTexture(renderTexture)
        , m_gameState(gameState)
    {
        m_tileSprite.setTexture(m_gameState.resources.getTexture("tiles"));
    }

    void GridDrawer::drawGrid(const State::Grid &gridState, sf::IntRect &borders)
    {
        auto tileSize = sf::Vector2f(
                calculateTilePixelWidth(gridState, borders),
                calculateTilePixelHeight(gridState, borders)
        );

        for (int x = 0; x < gridState.width(); x++)
        {
            for (int y = 0; y < gridState.height(); y++)
            {
                drawTileAt(x, y, tileSize);
            }
        }

        int x_offset = 240;
        int y_offset = 20;
        for (auto &shape : m_gameState.upcomingPieces)
        {
            for(auto &relative_tile : shape.getTiles())
            {
                m_tileSprite.setPosition(sf::Vector2f{x_offset + relative_tile.offset.x * tileSize.x,
                                                y_offset + -relative_tile.offset.y * tileSize.y});
                m_tileSprite.setTextureRect(relative_tile.tile.getSpriteRect());
                m_tileSprite.setColor(relative_tile.tile.getColor());
                m_tileSprite.setScale(tileSize.x / 32, tileSize.y / 32);
                m_renderTexture.draw(m_tileSprite);
            }
            y_offset += tileSize.y * 4;
        }
    }

    void GridDrawer::drawTileAt(int x, int y, const sf::Vector2f &tileSize)
    {
        State::GridCellState &cell = m_gameState.gameGrid.getCellAt(x, y);

        if (cell.hasTile())
        {
            const auto &tile = m_gameState.gameGrid.getTileAt(x, y);
            m_tileSprite.setTextureRect(tile.getSpriteRect());
            m_tileSprite.setPosition(getDrawPointX(x), getDrawPointY(y));
            m_tileSprite.setColor(tile.getColor());
            m_tileSprite.setScale(tileSize.x / 32, tileSize.y / 32);
            m_renderTexture.draw(m_tileSprite);
        }
        else
        {
            m_rect.setSize(tileSize);
            m_rect.setPosition(getDrawPointX(x), getDrawPointY(y));
            // The four next lines is here for debug-reasons and creates a chessboard-pattern
            if ((x + y) % 2 == 0)
                m_rect.setFillColor(sf::Color(255, 255, 255));
            else
                m_rect.setFillColor(sf::Color(230, 230, 230));
            m_renderTexture.draw(m_rect);
        }


    }

    float GridDrawer::calculateTilePixelHeight(const State::Grid &gridState, const sf::IntRect &borders) const
    {
        return static_cast<float>(borders.width) / static_cast<float>(gridState.width());
    }

    float GridDrawer::calculateTilePixelWidth(const State::Grid &gridState, const sf::IntRect &borders) const
    {
        return static_cast<float>(borders.height) / static_cast<float>(gridState.height());
    }

    float GridDrawer::getDrawPointX(int xTilePos) const
    {
        return static_cast<float>(xTilePos) * m_rect.getSize().x;
    }

    float GridDrawer::getDrawPointY(int yTilePos) const
    {
        return static_cast<float>(m_gameState.gameGrid.height() - 1) * m_rect.getSize().y
                             - static_cast<float>(yTilePos) * m_rect.getSize().y;
    }

} // Tetris::Graphics