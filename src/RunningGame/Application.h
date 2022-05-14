//
// Created by glosn on 4/24/2022.
//

#ifndef TETRISEXAM_APPLICATION_H
#define TETRISEXAM_APPLICATION_H

#include <vector>
#include <memory>
#include <string>
#include "Game.h"
#include "../GUI/ScreenManager.h"
#include "../Resources.h"

namespace Tetris
{
    /// @brief Manages the whole thing. Can include multiple
    // running games. And opens the game window etc.
    class Application
    {
    public:
        /// @brief  constructor
        Application();

        /// @brief Starts and runs the gameloop.
        void runGameLoop();

    private:
        /// Render window
        sf::RenderWindow m_window{sf::VideoMode(900, 400), "Tetris"};

        GUI::ScreenManager m_manager;

    };

} // Tetris

#endif // TETRISEXAM_APPLICATION_H
