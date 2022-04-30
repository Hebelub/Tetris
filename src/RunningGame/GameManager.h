//
// Created by glosn on 4/24/2022.
//

#ifndef TETRISEXAM_GAMEMANAGER_H
#define TETRISEXAM_GAMEMANAGER_H

#include <vector>
#include <memory>
#include "Game.h"

namespace Tetris
{
    /// @brief Manages the whole thing. Can include multiple
    // running games. And opens the game window etc.
    class GameManager
    {
    public:
        /// @brief  constructor
        GameManager();

        /// @brief Makes a new running game to be played by a
        // player. Adds it to m_runningGames.
        void initiateARunningGame();

        /// @brief Starts and runs the gameloop.
        void runGameLoop();

    private:
        /// Render window
        sf::RenderWindow m_window{sf::VideoMode(640, 480), "Tetris"};

        /// @brief Vector of running games.
        std::vector<std::unique_ptr<Tetris::Game>> m_runningGames;
    };

} // Tetris

#endif // TETRISEXAM_GAMEMANAGER_H
