//
// Created by glosn on 5/15/2022.
//

#ifndef TETRISEXAM_LOBBYSCREEN_H
#define TETRISEXAM_LOBBYSCREEN_H

#include "../Base/BaseScreen.h"
#include "../../Input/InputButton.h"

namespace Tetris::GUI {

    class LobbyScreen : public BaseScreen
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

        Button *m_backButton{nullptr};
        Button *m_playButton{nullptr};
    };

} // Tetris::GUI

#endif //TETRISEXAM_LOBBYSCREEN_H
