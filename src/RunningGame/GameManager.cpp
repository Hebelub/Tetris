//
// Created by glosn on 4/24/2022.
//

#include <iostream>
#include "GameManager.h"

namespace Tetris
{
    GameManager::GameManager()
        : m_window(sf::VideoMode(640, 480), "Tetris")
    {
        m_window.setVerticalSyncEnabled(true);
    }

    void GameManager::runGameLoop()
    {
        sf::Event event{};

        sf::Clock clock;

        while (m_window.isOpen())
        {
            float deltaTime = clock.getElapsedTime().asSeconds();
            clock.restart();

            while (m_window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    m_window.close();
            }

            for (auto &game : m_runningGames)
            {
                game->updateFrame(deltaTime);
            }

            m_window.clear(sf::Color::Yellow);

            // TODO: Currently it is just drawing one player
            m_window.draw(m_runningGames[0]->getSprite());
            m_window.display();
        }
    }

    void GameManager::initiateARunningGame()
    {
        auto newGame = std::make_unique<Tetris::Game>();
        m_runningGames.push_back(std::move(newGame));
    }

} // Tetris