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
    // One that draws the upcoming Tetris's and score

    class GameRenderer
    {
    public:
        explicit GameRenderer();

        sf::Sprite getSprite();

        void updateRender(const Tetris::State::TetrisGameState& game);



    private:
        sf::RenderTexture m_renderTexture{};
        sf::Sprite m_renderSprite{};

        void initializeRendering();
    };
}


#endif //TETRISEXAM_GAMERENDERER_H
