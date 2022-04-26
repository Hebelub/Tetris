//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GAMERENDERER_H
#define TETRISEXAM_GAMERENDERER_H

#include <SFML/Graphics.hpp>

#include "../GameState/TetrisGameState.h"
#include "TetrisGridDrawer.h"

namespace Tetris::Graphics
{
    // This class should probably have other classes.
    // One that draws the grid
    // One that draws the upcoming Tetris's and score

    class GameRenderer
    {
    public:

        /// @brief Constructor initializing rendering
        explicit GameRenderer(State::TetrisGameState &gameState);

        /// @brief getter for m_renderSprite
        sf::Sprite getSprite();

        /// @brief Updates the game rendering.
        /// @param game  The new gamestate to render
        void updateRender(const Tetris::State::TetrisGameState &game);

    private:
        // TODO: This should be accessed from another place
        int m_pixelWidth = 300;
        int m_pixelHeight = 300;

        sf::RenderTexture m_renderTexture{};

        State::TetrisGameState &m_gameState;
        std::unique_ptr<TetrisGridDrawer> m_gridDrawer;

        sf::Sprite m_renderSprite{};

        /// @brief Renders the game! Textrure, sprite
        void initializeRendering();
    };
}

#endif // TETRISEXAM_GAMERENDERER_H
