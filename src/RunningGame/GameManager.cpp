//
// Created by glosn on 4/24/2022.
//

#include <iostream>
#include "GameManager.h"
#include "../Input/InputButton.h"
#include "../Input/PlayerInput.h"

namespace Tetris
{
    GameManager::GameManager()
    {
        m_window.setVerticalSyncEnabled(true);
        m_window.setPosition({60, 120});
        m_window.setSize({m_window.getSize().x * 2, m_window.getSize().y * 2 });
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

            m_window.clear(sf::Color::Black);

            int i = 0;
            for (auto &game : m_runningGames)
            {
                if (!game->isGameOver())
                {
                    game->updateFrame(deltaTime);
                }
                auto &sprite = game->getSprite();
                sprite.setPosition(300 * i, 0);
                m_window.draw(game->getSprite());
                i++;
            }

            m_window.display();
        }
    }

    void GameManager::initiateARunningGame(const std::string &name, unsigned int seed, const Input::PlayerInput &playerInput)
    {
        auto f = [=](int n) { return onLineClear(name, n); };

        auto game = std::make_unique<Tetris::Game>(name, playerInput, seed);
        game->setLineClearCallback(f);

        m_runningGames.emplace_back(std::move(game));
    }

    void GameManager::onLineClear(const std::string &gameThatCleared, int numLines)
    {
        // std::cout << gameThatCleared << std::endl;
        for(auto &game : m_runningGames)
        {
            if (game->getName() == gameThatCleared) continue;
            game->onOpponentClear(numLines);
        }
    }

} // Tetris