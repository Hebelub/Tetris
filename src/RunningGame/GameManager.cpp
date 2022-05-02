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
                if (!game->isGameOver())
                    game->updateFrame(deltaTime);
            }

            m_window.clear(sf::Color::Black);

            // TODO: Currently it is just drawing one player
            // make it smarter

            if (m_runningGames.size() >= 1 && !m_runningGames[0]->isGameOver())
            {
                    m_window.draw(m_runningGames[0]->getSprite());
            }
            if (m_runningGames.size() >= 2 && !m_runningGames[1]->isGameOver())
            {
                auto &sprite = m_runningGames[1]->getSprite();
                sprite.setPosition(300, 0);
                m_window.draw(m_runningGames[1]->getSprite());
            }
            m_window.display();
        }
    }

    void GameManager::initiateARunningGame(const KeyboardLayout &layout)
    {
        m_runningGames.push_back(std::make_unique<Tetris::Game>(layout));
    }

} // Tetris