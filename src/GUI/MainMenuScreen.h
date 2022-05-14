//
// Created by glosn on 5/13/2022.
//

#ifndef TETRISEXAM_MAINMENUSCREEN_H
#define TETRISEXAM_MAINMENUSCREEN_H

#include "BaseScreen.h"

namespace Tetris::GUI
{

    class ScreenManager;

    class MainMenuScreen : public BaseScreen
    {
    public:
        explicit MainMenuScreen();

        void draw(sf::RenderTarget &renderTarget) override;

        void update(float deltaTime) override;

    private:
    };

} // Tetris::GUI

#endif //TETRISEXAM_MAINMENUSCREEN_H
