//
// Created by glosn on 5/14/2022.
//

#include "ControlSettings.h"

void Tetris::Input::ControlSettings::initialize()
{
        using InputButton = Tetris::Input::InputButton;
        using InputButtonSource = Tetris::Input::InputButtonSource;
        using SignalType = Tetris::Input::InputButton::SignalType;

        // PLAYER 1
        Tetris::Input::PlayerInput player1Controls{};
        player1Controls.rotateRight = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Keyboard::W));
        player1Controls.fallFast    = InputButton(SignalType::ButtonState, InputButtonSource(sf::Keyboard::S));
        player1Controls.instantFall = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Keyboard::LControl));
        player1Controls.moveLeft    = InputButton(SignalType::IntervalWithDelayFirst, InputButtonSource(sf::Keyboard::A));
        player1Controls.moveRight   = InputButton(SignalType::IntervalWithDelayFirst, InputButtonSource(sf::Keyboard::D));
        m_playerInputs.push_back(player1Controls);

        // PLAYER 2
        Tetris::Input::PlayerInput player2Controls{};
        player2Controls.rotateRight = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Keyboard::I));
        player2Controls.fallFast    = InputButton(SignalType::ButtonState, InputButtonSource(sf::Keyboard::K));
        player2Controls.instantFall = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Keyboard::Space));
        player2Controls.moveLeft    = InputButton(SignalType::IntervalWithDelayFirst, InputButtonSource(sf::Keyboard::J));
        player2Controls.moveRight   = InputButton(SignalType::IntervalWithDelayFirst, InputButtonSource(sf::Keyboard::L));
        m_playerInputs.push_back(player2Controls);

        // PLAYER 3
        Tetris::Input::PlayerInput player3Controls{};
        player3Controls.rotateRight = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Keyboard::Up));
        player3Controls.fallFast    = InputButton(SignalType::ButtonState, InputButtonSource(sf::Keyboard::Down));
        player3Controls.instantFall = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Keyboard::Enter));
        player3Controls.moveLeft    = InputButton(SignalType::IntervalWithDelayFirst, InputButtonSource(sf::Keyboard::Left));
        player3Controls.moveRight   = InputButton(SignalType::IntervalWithDelayFirst, InputButtonSource(sf::Keyboard::Right));
        m_playerInputs.push_back(player3Controls);

        // PLAYER 4
        Tetris::Input::PlayerInput mouseControls{};
        mouseControls.rotateRight = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Mouse::XButton1));
        mouseControls.rotateLeft  = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Mouse::XButton2));
        mouseControls.fallFast    = InputButton(SignalType::ButtonState, InputButtonSource(sf::Mouse::Middle));
        mouseControls.instantFall = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Keyboard::F10));
        mouseControls.moveRight   = InputButton(SignalType::IntervalWithDelayFirst, InputButtonSource(sf::Mouse::Right));
        mouseControls.moveLeft    = InputButton(SignalType::IntervalWithDelayFirst, InputButtonSource(sf::Mouse::Left));
        m_playerInputs.push_back(mouseControls);
}

const Tetris::Input::PlayerInput &Tetris::Input::ControlSettings::getControlsForPlayer(int index) const
{
    return m_playerInputs.at(index);
}