//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GAME_H
#define TETRISEXAM_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../GameState/GameState.h"
#include "../Setup/GameSaver.h"
#include "../Setup/GameLoader.h"
#include "../Logic/GameLogicManager.h"
#include "../View/GameRenderer.h"
#include "../Input/TetrisPlayerInputManager.h"
#include <memory>
#include <SFML/Graphics/Sprite.hpp>

namespace Tetris
{
    /// @brief Renders game (?)
    class Game
    {

    public:
        Game();
        /// @brief Gets a sprite from gamerenderer.
        /// @return sf::Sprite a sprite from gamerenderer.
        sf::Sprite getSprite();
        /// @brief Sends frames to logic to update it.
        /// @param deltaTime Time elapsed since last update.
        void updateFrame(float deltaTime);

    private:
        State::GameState m_currentGameState {GameLoader::loadGame()};

        std::unique_ptr<Graphics::GameRenderer> m_gameRenderer
            {std::make_unique<Graphics::GameRenderer>(m_currentGameState)};

        std::unique_ptr<Logic::GameLogicManager> m_gameLogic
            {std::make_unique<Logic::GameLogicManager>(m_currentGameState)};

        int m_framesPrSecond{100};
    };

} // Tetris

#endif // TETRISEXAM_GAME_H
