//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_RUNNINGGAME_H
#define TETRISEXAM_RUNNINGGAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../GameState/TetrisGameState.h"
#include "../Setup/GameSaver.h"
#include "../Setup/GameLoader.h"
#include "../Logic/GameLogicManager.h"
#include "../View/GameRenderer.h"
#include <memory>
#include <SFML/Graphics/Sprite.hpp>

namespace Tetris
{
    /// @brief Renders game (?)
    class RunningGame
    {

    public:
        /// @brief Default constructor.
        RunningGame();
        /// @brief Gets a sprite from gamerenderer.
        /// @return sf::Sprite a sprite from gamerenderer.
        sf::Sprite getSprite();
        /// @brief Sends frames to logic to update it.
        /// @param deltaTime Time elapsed since last update.
        void updateFrame(float deltaTime);

    private:
        std::unique_ptr<State::TetrisGameState> m_currentGameState{nullptr};

        std::unique_ptr<Graphics::GameRenderer> m_gameRenderer{nullptr};
        std::unique_ptr<Logic::GameLogicManager> m_gameLogic{nullptr};

        int m_framesPrSecond{100};
    };

} // Tetris

#endif // TETRISEXAM_RUNNINGGAME_H
