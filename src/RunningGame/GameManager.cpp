//
// Created by glosn on 4/24/2022.
//

#include <iostream>
#include "GameManager.h"

namespace Tetris
{
    GameManager::GameManager()
    {
        m_window.setVerticalSyncEnabled(true);
    }

    void GameManager::runGameLoop()
    {
        sf::Event event{};

        sf::Clock clock;

        while (m_window.isOpen())
        {
            float deltaTime = clock.restart().asSeconds();

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
        m_runningGames.push_back(std::make_unique<Tetris::Game>());
    }

} // Tetris