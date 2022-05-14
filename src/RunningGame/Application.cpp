//
// Created by glosn on 4/24/2022.
//

#include <iostream>
#include "Application.h"
#include "../Input/InputButton.h"
#include "../Input/PlayerInput.h"

namespace Tetris
{
    Application::Application()
    {
        m_window.setVerticalSyncEnabled(true);
        m_window.setPosition({60, 120});
        m_window.setSize({m_window.getSize().x * 2, m_window.getSize().y * 2 });
    }

    void Application::runGameLoop()
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

            m_manager.update(deltaTime);

            m_window.clear(sf::Color::Black);
            m_manager.draw(m_window);
            m_window.display();
        }
    }

} // Tetris