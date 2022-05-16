//
// Created by glosn on 5/13/2022.
//

#include "ScreenManager.h"

#include "Screens/MainMenuScreen.h"
#include "Screens/GameScreen.h"
#include "Screens/OptionsScreen.h"
#include "Screens/LobbyScreen.h"

namespace Tetris::GUI
{
    ScreenManager::ScreenManager()
    {
        m_controls.initialize();
        setScreen(Screen::MainMenu);
    }

    void ScreenManager::setScreen(Screen screen)
    {
        switch(screen)
        {
            case Screen::MainMenu:      m_activeScreen = std::make_unique<MainMenuScreen>(); break;
            case Screen::LobbyScreen:   m_activeScreen = std::make_unique<LobbyScreen>(); break;
            case Screen::OptionsScreen: m_activeScreen = std::make_unique<OptionsScreen>(); break;
            case Screen::GameScreen:    m_activeScreen = std::make_unique<GameScreen>(); break;
        }
        m_activeScreen->setScreenManager(this);
        m_activeScreen->setupGuiComponents();
    }

    void ScreenManager::update(float deltaTime)
    {
        m_activeScreen->update(deltaTime);
    }

    void ScreenManager::draw(sf::RenderTarget &renderTarget)
    {
        m_activeScreen->draw(renderTarget);
    }

    void ScreenManager::startGame(int numPlayers)
    {
        auto seed = std::random_device{}();

        setScreen(Screen::GameScreen);
        for(int i = 0; i < numPlayers; i++)
        {
            BaseScreen &screen = *m_activeScreen;
            dynamic_cast<GameScreen&>(screen).initiateARunningGame("Player " + std::to_string(i + 1), seed, m_controls.getControlsForPlayer(i));
        }
    }


} // Tetris::GUI