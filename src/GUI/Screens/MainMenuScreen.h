//
// Created by glosn on 5/13/2022.
//

#ifndef TETRISEXAM_MAINMENUSCREEN_H
#define TETRISEXAM_MAINMENUSCREEN_H

#include "../Base/BaseScreen.h"
#include "../../Input/InputButton.h"

namespace Tetris::GUI
{
    class MainMenuScreen : public BaseScreen
    {
    public:
        void setupGuiComponents() override;
        void update(float deltaTime) override;
        void draw(sf::RenderTarget &renderTarget) override;

        void setActiveButton(Button *component);

    private:
        Input::InputButton m_enter{Input::InputButton::SignalType::OnButtonDown, Input::InputButtonSource{sf::Keyboard::Enter}};
        Input::InputButton m_left{Input::InputButton::SignalType::IntervalWithDelayFirst, Input::InputButtonSource{sf::Keyboard::Left}};
        Input::InputButton m_right{Input::InputButton::SignalType::IntervalWithDelayFirst, Input::InputButtonSource{sf::Keyboard::Right}};

        Button *m_activeButton{nullptr};

        Button *m_singlePlayerButton{nullptr};
        Button *m_optionsButton{nullptr};
        Button *m_multiPlayerButton{nullptr};
    };

} // Tetris::GUI

#endif //TETRISEXAM_MAINMENUSCREEN_H
