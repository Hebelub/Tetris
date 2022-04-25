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
    class TetrisGameManager
    {
    public:
        // default constructor
        TetrisGameManager();

        void openGameWindow();

        void initiateARunningGame()
        {
            auto newGame = std::make_unique<Tetris::RunningGame>();
            m_runningGames.push_back(std::move(newGame));
        }

        void runGameLoop();

    private:

        std::unique_ptr<sf::RenderWindow> m_window = nullptr;

        std::vector<std::unique_ptr<Tetris::RunningGame>> m_runningGames;

    };

} // Tetris

#endif //TETRISEXAM_TETRISGAMEMANAGER_H
