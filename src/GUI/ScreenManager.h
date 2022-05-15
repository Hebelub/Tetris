//
// Created by glosn on 5/13/2022.
//

#ifndef TETRISEXAM_SCREENMANAGER_H
#define TETRISEXAM_SCREENMANAGER_H

#include "Base/BaseScreen.h"
#include "../Input/ControlSettings.h"
#include "../Resources.h"

namespace Tetris::GUI
{
    enum class Screen
    {
        MainMenu,
        LobbyScreen,
        OptionsScreen,
        GameScreen
    };

    class ScreenManager
    {
    public:
        explicit ScreenManager();
        void setScreen(Screen screen);
        void update(float deltaTime);
        void draw(sf::RenderTarget &renderTarget);
        void startGame(int numPlayers);

        Resources m_resources{};
    private:
        std::unique_ptr<BaseScreen> m_activeScreen;
        Input::ControlSettings m_controls;
    };

} // Tetris::GUI

#endif //TETRISEXAM_SCREENMANAGER_H
