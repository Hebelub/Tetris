//
// Created by glosn on 4/25/2022.
//

#include "GridDrawer.h"

namespace Tetris::Graphics
{

    GridDrawer::GridDrawer(sf::RenderTexture &renderTexture, State::GameState &gameState)
        : m_renderTexture(renderTexture)
        , m_gameState(gameState)
    {

        // TODO: The correct colors should be in GridCellState instead
        m_tileShape.setFillColor(sf::Color::Green);
    }

    void GridDrawer::drawGrid(const State::Grid &gridState, sf::IntRect &borders)
    {

        // TODO: The class should maybe own gridState and borders
        auto tileSize = sf::Vector2f(
                calculateTilePixelWidth(gridState, borders),
                calculateTilePixelHeight(gridState, borders)
        );
        m_tileShape.setSize(tileSize);

        for (int x = 0; x < gridState.width(); x++)
        {
            for (int y = 0; y < gridState.height(); y++)
            {
                drawTileAt(x, y);
            }
        }


        sf::RectangleShape rect{tileSize};
        int x_offset = 240;
        int y_offset = 20;
        for (auto &shape : m_gameState.upcomingPieces)
        {
            for(auto relative_tile : shape.getTiles())
            {
                rect.setFillColor(relative_tile.tile.getColor());
                rect.setPosition(sf::Vector2f{x_offset + relative_tile.offset.x * tileSize.x,
                                              y_offset + -relative_tile.offset.y * tileSize.y});
                m_renderTexture.draw(rect);
            }
            y_offset += tileSize.y * 4;
        }
    }

    void GridDrawer::drawTileAt(int x, int y)
    {
        m_tileShape.setPosition(getDrawPointX(x), getDrawPointY(y));

        State::GridCellState &cell = m_gameState.gameGrid.getCellAt(x, y);

        if (cell.hasTile())
        {
            m_tileShape.setFillColor(cell.getTile().getColor());
        }
        else
        {
            // The four next lines is here for debug-reasons and creates a chessboard-pattern
            if ((x + y) % 2 == 0)
                m_tileShape.setFillColor(sf::Color(255, 255, 255));
            else
                m_tileShape.setFillColor(sf::Color(230, 230, 230));
        }

        m_renderTexture.draw(m_tileShape);
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
        return static_cast<float>(xTilePos) * m_tileShape.getSize().x;
    }

    float GridDrawer::getDrawPointY(int yTilePos) const
    {
        return static_cast<float>(m_gameState.gameGrid.height() - 1) * m_tileShape.getSize().y
                             - static_cast<float>(yTilePos) * m_tileShape.getSize().y;
    }

} // Tetris::Graphics