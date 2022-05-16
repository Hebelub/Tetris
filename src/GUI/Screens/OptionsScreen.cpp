//
// Created by glosn on 5/15/2022.
//

#include "OptionsScreen.h"

#include <SFML/Graphics.hpp>
#include "../Base/Component.h"
#include "../../Input/InputButton.h"
#include "../ScreenManager.h"


namespace Tetris::GUI
{
    void OptionsScreen::setupGuiComponents()
    {
        auto &texture =  m_manager->m_resources.getTexture("gui");
        m_backButton = addButton(sf::Vector2i{200, 250}, sf::Sprite(texture, sf::IntRect(256, 0, 128, 256)));
        m_audioButton = addButton(sf::Vector2i{400, 250}, sf::Sprite(texture, sf::IntRect(640, 0, 128, 256)));

        setActiveButton(m_audioButton);
    }

    void OptionsScreen::update(float deltaTime)
    {
        BaseScreen::update(deltaTime);

        m_left.update(deltaTime);
        m_right.update(deltaTime);
        m_enter.update(deltaTime);

        if (m_left.getSignal())
        {
            if (m_activeButton == m_audioButton)      setActiveButton(m_backButton);
            else if (m_activeButton == m_backButton) setActiveButton(m_audioButton);
        }
        else if (m_right.getSignal())
        {
            if (m_activeButton == m_audioButton)      setActiveButton(m_backButton);
            else if (m_activeButton == m_backButton) setActiveButton(m_audioButton);
        }
        else if (m_enter.getSignal())
        {
            if (m_activeButton == m_audioButton)
            {
                // Audio !! :)
            }
            else if (m_activeButton == m_backButton)
            {
                m_manager->setScreen(Screen::MainMenu);
            }
        }
    }

    void OptionsScreen::draw(sf::RenderTarget &renderTarget)
    {
        BaseScreen::draw(renderTarget);

        // Draw background image
        auto &texture = m_manager->m_resources.getTexture("mainMenuBackground");
        renderTarget.draw(sf::Sprite{texture});
        // Draws components
        BaseScreen::draw(renderTarget);
    }

    void OptionsScreen::setActiveButton(Button *component)
    {
        if (m_activeButton != nullptr) m_activeButton->setPosition({m_activeButton->getPosition().x, 250});
        m_activeButton = component;
        m_activeButton->setPosition({m_activeButton->getPosition().x, 200});
    }

} // Tetris::GUI