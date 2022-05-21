//
// Created by glosn on 5/15/2022.
//

#include "OptionsScreen.h"

#include <SFML/Graphics.hpp>
#include "../Base/Component.h"
#include "../../Input/InputButton.h"
#include "../ScreenManager.h"
#include "../../Audio/PlaySound.h"


namespace Tetris::GUI
{
    void OptionsScreen::setupGuiComponents()
    {
        auto &texture =  m_manager->m_resources.getTexture("gui");
        m_backButton = addButton(sf::Vector2i{200, 250}, sf::Sprite(texture, sf::IntRect(256, 0, 128, 256)));
        m_soundButton = addButton(sf::Vector2i{400, 250}, sf::Sprite(texture, getIntRectForSoundButton()));
        m_musicButton = addButton(sf::Vector2i{600, 250}, sf::Sprite(texture, getIntRectForMusicButton()));

        setActiveButton(m_soundButton);
    }

    void OptionsScreen::update(float deltaTime)
    {
        BaseScreen::update(deltaTime);

        m_left.update(deltaTime);
        m_right.update(deltaTime);
        m_enter.update(deltaTime);

        if (m_left.getSignal())
        {
            if (m_activeButton == m_soundButton)      setActiveButton(m_backButton);
            else if (m_activeButton == m_musicButton) setActiveButton(m_soundButton);
            else if (m_activeButton == m_backButton)  setActiveButton(m_musicButton);
        }
        else if (m_right.getSignal())
        {
            if (m_activeButton == m_soundButton)      setActiveButton(m_musicButton);
            else if (m_activeButton == m_musicButton) setActiveButton(m_backButton);
            else if (m_activeButton == m_backButton)  setActiveButton(m_soundButton);
        }
        else if (m_enter.getSignal())
        {
            if (m_activeButton == m_soundButton)
            {
                if (Audio::PlaySound::isSoundOn())
                {
                    Audio::PlaySound::turnSoundOff();
                    m_soundButton->setSpriteIntRect(getIntRectForSoundButton());
                }
                else
                {
                    Audio::PlaySound::turnSoundOn();
                    Audio::PlaySound::playSound(Audio::SoundId::ToggleSound);
                    m_soundButton->setSpriteIntRect(getIntRectForSoundButton());
                }
            }
            else if (m_activeButton == m_backButton)
            {
                m_manager->setScreen(Screen::MainMenu);
            }
            else if (m_activeButton == m_musicButton)
            {
                if (Audio::PlaySound::isMusicOn())
                {
                    Audio::PlaySound::turnMusicOff();
                    m_musicButton->setSpriteIntRect(getIntRectForMusicButton());
                }
                else
                {
                    Audio::PlaySound::turnMusicOn();
                    Audio::PlaySound::playMusic(Audio::MusicId::HappyTheme);
                    m_musicButton->setSpriteIntRect(getIntRectForMusicButton());
                }
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
