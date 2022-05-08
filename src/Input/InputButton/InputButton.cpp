//
// Created by glosn on 5/8/2022.
//

#include "InputButton.h"
#include <SFML/Graphics.hpp>
#include <optional>


namespace Tetris::Input
{

    InputButton::InputButton(InputButton::SignalType signalType, sf::Keyboard::Key key)
        : _signalType(signalType)
        , _keyboardKey(KeyboardKey{key})
    { }

    InputButton::InputButton(InputButton::SignalType signalType, sf::Mouse::Button button)
        : _signalType(signalType)
    { }

    InputButton::InputButton(InputButton::SignalType signalType, unsigned int controller, unsigned int button)
        : _signalType(signalType)
        , _joystickButton(JoystickButton{controller, button})
    { }

    InputButton::InputButton(InputButton::SignalType signalType, unsigned int controller, sf::Joystick::Axis axis)
        : _signalType(signalType)
        , _joystickAxis(JoystickAxis(controller, axis))
    { }

    InputButton::InputButton(InputButton::SignalType signalType, unsigned int controller, sf::Joystick::Axis axis, float axisSensitivity)
        :_signalType(signalType)
        , _joystickAxis(JoystickAxis(controller, axis, axisSensitivity))
    { }

    bool InputButton::getSignal()
    {
        return false;
    }

} // Tetris::Input