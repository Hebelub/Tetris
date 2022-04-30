//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GAME_H
#define TETRISEXAM_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../GameState/TetrisPiece.h"
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
        Game() = default;

/// @brief Gets a sprite from gamerenderer.
        /// @return sf::Sprite a sprite from gamerenderer.
        const sf::Sprite& getSprite();
        /// @brief Sends frames to logic to update it.
        /// @param deltaTime Time elapsed since last update.
        void updateFrame(float deltaTime);

    private:
        Logic::TetrisPieceGenerator m_pieceGenerator{};

        State::GameState m_currentGameState{m_pieceGenerator, 5};
        Graphics::GameRenderer m_gameRenderer{ m_currentGameState };
        Logic::GameLogicManager m_gameLogic{ m_currentGameState };
    };

} // Tetris

#endif // TETRISEXAM_GAME_H
