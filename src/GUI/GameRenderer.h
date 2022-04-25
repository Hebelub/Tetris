//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GAMERENDERER_H
#define TETRISEXAM_GAMERENDERER_H

#include <SFML/Graphics.hpp>

#include "../GameState/TetrisGameState.h"

namespace Tetris::Graphics
{
    // This class should probably have other classes.
    // One that draws the grid
    // One that draws the upcoming Tetrises and score

    class GameRenderer
    {
    public:
        /// @brief Constructor initializing rendering
        explicit GameRenderer();

        /// @brief getter for m_renderSprite
        sf::Sprite getSprite();

        /// @brief Updates the game rendering.
        /// @param game  The new gamestate to render
        void updateRender(const Tetris::State::TetrisGameState &game);

    private:
        sf::RenderTexture m_renderTexture{};
        sf::Sprite m_renderSprite{};

        /// @brief Renders the game! Textrure, sprite
        void initializeRendering();
    };
}

#endif // TETRISEXAM_GAMERENDERER_H
