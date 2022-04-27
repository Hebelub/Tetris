//
// Created by glosn on 4/25/2022.
//

#ifndef TETRISEXAM_GRIDDRAWER_H
#define TETRISEXAM_GRIDDRAWER_H

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../GameState/GridState.h"

namespace Tetris::Graphics
{
    /// @brief calculates size and position of tiles taking borders into consideration.
    // Draws the correct tiles on the different grid positions
    class GridDrawer
    {
    public:
        explicit GridDrawer(sf::RenderTexture &renderTexture, State::GridState &m_gridState);

        void drawGrid(const State::GridState &gridState, sf::IntRect &borders);

    private:
        sf::RectangleShape m_tileShape{sf::RectangleShape()};
        sf::RenderTexture &m_renderTexture;
        State::GridState &m_gridState;

        void drawTileAt(int x, int y);

        [[nodiscard]] float calculateTilePixelHeight(const State::GridState &gridState, const sf::IntRect &borders) const;
        [[nodiscard]] float calculateTilePixelWidth(const State::GridState &gridState, const sf::IntRect &borders) const;
        [[nodiscard]] float getDrawPointX(int xTilePos) const;
        [[nodiscard]] float getDrawPointY(int yTilePos) const;
    };

} // Tetris::Graphics

#endif //TETRISEXAM_GRIDDRAWER_H
