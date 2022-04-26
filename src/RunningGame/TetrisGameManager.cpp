//
// Created by glosn on 4/24/2022.
//

#include <iostream>
#include "TetrisGameManager.h"

namespace Tetris
{
    TetrisGameManager::TetrisGameManager()
    = default;

    void TetrisGameManager::runGameLoop()
    {
        sf::Event event{};

        sf::Clock clock;

        while (m_window->isOpen())
        {
            float deltaTime = clock.getElapsedTime().asSeconds();
            clock.restart();

            while (m_window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    m_window->close();
            }

            for (auto &game : m_runningGames)
            {
                game->updateFrame(deltaTime);
            }

            m_window->clear(sf::Color::Yellow);

            // TODO: Currently it is just drawing one player
            m_window->draw(m_runningGames[0]->getSprite());
            m_window->display();
        }
    }

    void TetrisGameManager::openGameWindow()
    {
        m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(640, 480), "Tetris");
        m_window->setVerticalSyncEnabled(true);
    }

} // Tetris