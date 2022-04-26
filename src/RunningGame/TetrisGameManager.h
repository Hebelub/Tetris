//
// Created by glosn on 4/24/2022.
//

#ifndef TETRISEXAM_TETRISGAMEMANAGER_H
#define TETRISEXAM_TETRISGAMEMANAGER_H

#include <vector>
#include <memory>
#include "RunningGame.h"

namespace Tetris
{
    /// @brief Manages the whole thing. Can include multiple
    // running games. And opens the game window etc.
    class TetrisGameManager
    {
    public:
        /// @brief  constructor
        TetrisGameManager();

        /// @brief Opens game window at the start.
        void openGameWindow();

        /// @brief Makes a new running game to be played by a
        // player. Adds it to m_runningGames.
        void initiateARunningGame()
        {
            auto newGame = std::make_unique<Tetris::RunningGame>();
            m_runningGames.push_back(std::move(newGame));
        }
        /// @brief Starts and runs the gameloop.
        void runGameLoop();

    private:
        /// Render window
        std::unique_ptr<sf::RenderWindow> m_window = nullptr;

        /// @brief Vector of runing games.
        std::vector<std::unique_ptr<Tetris::RunningGame>> m_runningGames;

        void onResize();
    };

} // Tetris

#endif // TETRISEXAM_TETRISGAMEMANAGER_H
