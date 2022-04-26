//
// Created by glosn on 4/25/2022.
//

#ifndef TETRISEXAM_TETRISGRIDDRAWER_H
#define TETRISEXAM_TETRISGRIDDRAWER_H

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../GameState/TetrisGridState.h"

namespace Tetris::Graphics
{
    /// @brief calculates size and position of tiles taking borders into consideration.
    // Draws the correct tiles on the different grid positions
    class TetrisGridDrawer
    {
    public:
        explicit TetrisGridDrawer(sf::RenderTexture &renderTexture);

        void drawGrid(const State::TetrisGridState& gridState, sf::IntRect &borders);

    private:
        sf::RectangleShape m_tileShape;
        sf::RenderTexture &m_renderTexture;

        void drawTileAt(int x, int y);

        [[nodiscard]] float calculateTilePixelHeight(const State::TetrisGridState &gridState, const sf::IntRect &borders) const;
        [[nodiscard]] float calculateTilePixelWidth(const State::TetrisGridState &gridState, const sf::IntRect &borders) const;
        [[nodiscard]] float getDrawPointX(int xTilePos) const;
        [[nodiscard]] float getDrawPointY(int yTilePos) const;
    };

} // Tetris::Graphics

#endif //TETRISEXAM_TETRISGRIDDRAWER_H
