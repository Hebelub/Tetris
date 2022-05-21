//
// Created by glosn on 5/15/2022.
//

#ifndef TETRISEXAM_OPTIONSSCREEN_H
#define TETRISEXAM_OPTIONSSCREEN_H

#include "../Base/BaseScreen.h"
#include "../../Input/InputButton.h"
#include "../../Audio/PlaySound.h"


namespace Tetris::GUI {

    class OptionsScreen : public BaseScreen
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
        Button *m_soundButton{nullptr};
        Button *m_musicButton{nullptr};

        static sf::IntRect inline getIntRectForMusicButton() {
            if (Audio::PlaySound::isMusicOn())
                return {512, 0, 128, 256};
            else return {512, 256, 128, 256};
        }

        static sf::IntRect inline getIntRectForSoundButton() {
            if (Audio::PlaySound::isSoundOn())
                return {640, 0, 128, 256};
            else return {640, 256, 128, 256};
        }
    };

} // Tetris::GUI

#endif //TETRISEXAM_OPTIONSSCREEN_H
