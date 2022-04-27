//
// Created by glosn on 4/25/2022.
//

#include "TetrisGridDrawer.h"

namespace Tetris::Graphics
{

    TetrisGridDrawer::TetrisGridDrawer(sf::RenderTexture &renderTexture, State::TetrisGridState &gridState)
        : m_renderTexture(renderTexture)
        , m_gridState(gridState)
    {

        // TODO: The correct colors should be in GridCellState instead
        m_tileShape.setFillColor(sf::Color::Green);
    }

    void TetrisGridDrawer::drawGrid(const State::TetrisGridState& gridState, sf::IntRect &borders)
    {

        // TODO: The class should maybe own gridState and borders
        m_tileShape.setSize(sf::Vector2f(
                calculateTilePixelWidth(gridState, borders),
                calculateTilePixelHeight(gridState, borders)
        ));

        for (int x = 0; x < gridState.getGridTileWidth(); x++)
        {
            for (int y = 0; y < gridState.getGridTileHeight(); y++)
            {
                drawTileAt(x, y);
            }
        }
    }

    void TetrisGridDrawer::drawTileAt(int x, int y)
    {
        State::GridCellState tile = m_gridState.getTileAt(sf::Vector2i(x, y));

        if (tile.hasTile())
        {
            m_tileShape.setFillColor(tile.getTile().getColor());
        }
        else
        {
            // The four next lines is here for debug-reasons and creates a chessboard-pattern
            if ((x + y) % 2 == 0)
                m_tileShape.setFillColor(sf::Color::Magenta);
            else
                m_tileShape.setFillColor(sf::Color::Green);
        }

        m_tileShape.setPosition(getDrawPointX(x), getDrawPointY(y));

        m_renderTexture.draw(m_tileShape);
    }

    float TetrisGridDrawer::calculateTilePixelHeight(const State::TetrisGridState &gridState, const sf::IntRect &borders) const
    {
        return static_cast<float>(borders.width) / static_cast<float>(gridState.getGridTileWidth());
    }

    float TetrisGridDrawer::calculateTilePixelWidth(const State::TetrisGridState &gridState, const sf::IntRect &borders) const
    {
        return static_cast<float>(borders.height) / static_cast<float>(gridState.getGridTileHeight());
    }

    float TetrisGridDrawer::getDrawPointX(int xTilePos) const
    {
        return static_cast<float>(xTilePos) * m_tileShape.getSize().x;
    }

    float TetrisGridDrawer::getDrawPointY(int yTilePos) const
    {
        return static_cast<float>(yTilePos) * m_tileShape.getSize().y;
    }

} // Tetris::Graphics