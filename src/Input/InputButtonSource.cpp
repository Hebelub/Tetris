//
// Created by glosn on 5/9/2022.
//

#include <iostream>
#include "InputButtonSource.h"
#include <memory>

namespace Tetris::Input
{
    InputButtonSource::InputButtonSource(sf::Keyboard::Key key)
    {
        setSource(key);
    }

    InputButtonSource::InputButtonSource(sf::Mouse::Button button)
    {
        setSource(button);
    }

    InputButtonSource::InputButtonSource(unsigned int controller, unsigned int button)
    {
        setSource(controller, button);
    }

    InputButtonSource::InputButtonSource(unsigned int controller, sf::Joystick::Axis axis)
    {
        setSource(controller, axis);
    }

    InputButtonSource::InputButtonSource(unsigned int controller, sf::Joystick::Axis axis, float sensitivity)
    {
        setSource(controller, axis, sensitivity);
    }


    bool InputButtonSource::isSourcePressed() const
    {
        return _inputSource != nullptr && _inputSource->isPressed();
    }


    void InputButtonSource::setSource(sf::Keyboard::Key key)
    {
        _inputSource = new KeyboardKey(key);
    }

    void InputButtonSource::setSource(sf::Mouse::Button button)
    {
        _inputSource = new MouseButton(button);
    }

    void InputButtonSource::setSource(unsigned int controller, unsigned int button)
    {
        _inputSource = new JoystickButton(controller, button);
    }

    void InputButtonSource::setSource(unsigned int controller, sf::Joystick::Axis axis)
    {
        _inputSource = new JoystickAxis(controller, axis);
    }

    void InputButtonSource::setSource(unsigned int controller, sf::Joystick::Axis axis, float sensitivity)
    {
        _inputSource = new JoystickAxis(controller, axis, sensitivity);
    }

    InputButtonSource::~InputButtonSource()
    {
        // This class does not resolve memory lecage
    }

} // Tetris::Input