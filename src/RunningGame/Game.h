//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GAME_H
#define TETRISEXAM_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../GameState/TetrisPiece.h"
#include "../Setup/GameSaver.h"
#include "../Setup/GameLoader.h"
#include "../Logic/GameLogic.h"
#include "../View/GameRenderer.h"
#include "../Input/TetrisPlayerInputManager.h"
#include "../Input/KeyboardLayout.h"
#include <memory>
#include <SFML/Graphics/Sprite.hpp>

namespace Tetris
{
    /// @brief Renders game (?)
    class Game
    {

    public:
        explicit Game(const KeyboardLayout &layout, unsigned int seed);

/// @brief Gets a sprite from gamerenderer.
        /// @return sf::Sprite a sprite from gamerenderer.
        sf::Sprite &getSprite();
        /// @brief Sends frames to logic to update it.
        /// @param deltaTime Time elapsed since last update.
        void updateFrame(float deltaTime);

        bool isGameOver();

    private:
        Logic::TetrisPieceGenerator m_pieceGenerator;

        State::GameState m_currentGameState{m_pieceGenerator, 5};
        Graphics::GameRenderer m_gameRenderer;
        Logic::GameLogic m_gameLogic;
    };

} // Tetris

#endif // TETRISEXAM_GAME_H
