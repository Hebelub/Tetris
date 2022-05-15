//
// Created by glosn on 5/13/2022.
//

#include "MainMenuScreen.h"
#include <SFML/Graphics.hpp>
#include "../ScreenManager.h"
#include "../Base/Component.h"

#include <iostream>

namespace Tetris::GUI
{
    void MainMenuScreen::setupGuiComponents()
    {
        auto &texture = m_manager->resources.getTexture("gui");
        m_singlePlayerButton = addButton(sf::Vector2i{200, 250}, sf::Sprite(texture, sf::IntRect(128, 0, 128, 256)));
        m_multiPlayerButton = addButton(sf::Vector2i{400, 250}, sf::Sprite(texture, sf::IntRect(384, 0, 128, 256)));
        m_optionsButton = addButton(sf::Vector2i{600, 250}, sf::Sprite(texture, sf::IntRect(0, 0, 128, 256)));

        setActiveButton(m_singlePlayerButton);
    }

    void MainMenuScreen::update(float deltaTime) {
        BaseScreen::update(deltaTime);

        m_left.update(deltaTime);
        m_right.update(deltaTime);
        m_enter.update(deltaTime);

        if (m_left.getSignal())
        {
            if (m_activeButton == m_singlePlayerButton) setActiveButton(m_optionsButton);
            else if (m_activeButton == m_multiPlayerButton)  setActiveButton(m_singlePlayerButton);
            else if (m_activeButton == m_optionsButton)      setActiveButton(m_multiPlayerButton);
        }
        else if (m_right.getSignal())
        {
            if (m_activeButton == m_singlePlayerButton) setActiveButton(m_multiPlayerButton);
            else if (m_activeButton == m_multiPlayerButton)  setActiveButton(m_optionsButton);
            else if (m_activeButton == m_optionsButton)      setActiveButton(m_singlePlayerButton);
        }
        else if (m_enter.getSignal())
        {
            if (m_activeButton == m_singlePlayerButton)
            {
                m_manager->startGame(1);
            }
            else if (m_activeButton == m_multiPlayerButton)
            {
                m_manager->startGame(3);
                // m_manager->setScreen(Screen::LobbyScreen);
            }
            else if (m_activeButton == m_optionsButton)
            {
                m_manager->setScreen(Screen::OptionsScreen);
            }
        }
    }

    void MainMenuScreen::setActiveButton(Button *component)
    {
        if (m_activeButton != nullptr) m_activeButton->setPosition({m_activeButton->getPosition().x, 250});
        m_activeButton = component;
        m_activeButton->setPosition({m_activeButton->getPosition().x, 200});
    }

    void MainMenuScreen::draw(sf::RenderTarget &renderTarget) {
        // Draw background image
        auto &texture = m_manager->resources.getTexture("mainMenuBackground");
        renderTarget.draw(sf::Sprite{texture});
        // Draws components
        BaseScreen::draw(renderTarget);
    }


} // Tetris::GUI