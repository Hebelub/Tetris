//
// Created by glosn on 5/8/2022.
//

#include "InputButton.h"
#include <SFML/Graphics.hpp>
#include <iostream>


namespace Tetris::Input
{

    InputButton::InputButton(InputButton::SignalType signalType, sf::Keyboard::Key key)
        : _signalType(signalType)
        , _keyboardKey(KeyboardKey{key})
    { }

    InputButton::InputButton(InputButton::SignalType signalType, sf::Mouse::Button button)
        : _signalType(signalType)
        , _mouseButton(button)
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


    void InputButton::update(float deltaTime)
    {
        _intervalCount = _intervalCountShouldUpdateTo;

        bool inputCheck = checkIfAnyInputButtonsAreDownForUpdate();
        _didButtonSwitchStatePreviousFrame = (_isButtonPressed != inputCheck);
        _isButtonPressed = inputCheck;

        if (_isButtonPressed)
        {
            _upDuration = 0;
            _downDuration += deltaTime;
        }
        else
        {
            _upDuration += deltaTime;
            _downDuration = 0;
        }
    }


    bool InputButton::getSignal()
    {
        switch (_signalType)
        {
            case (SignalType::ButtonState):
                return _isButtonPressed;
            case (SignalType::NotButtonState):
                return !_isButtonPressed;
            case (SignalType::OnButtonDown):
                return _didButtonSwitchStatePreviousFrame && _isButtonPressed;
            case (SignalType::OnButtonUp):
                return _didButtonSwitchStatePreviousFrame && !_isButtonPressed;
            case (SignalType::OnButtonUpAndDown):
                return _didButtonSwitchStatePreviousFrame;
            case (SignalType::Interval):
                return checkInterval(false);
            case (SignalType::IntervalDifferentDelayFirst):
                return checkInterval(true);
            default:
                std::cerr << "ERROR: Inspect this switch statement" << std::endl;
                return false;
        }
    }

    bool InputButton::isButtonPressed() const
    {
        return _isButtonPressed;
    }

    void InputButton::setSignalType(SignalType signalType)
    {
        _signalType = signalType;
    }

    void InputButton::setPreferredInterval(float interval)
    {
        _intervalTime = interval;
    }

    void InputButton::setPreferredLongInterval(float interval)
    {
        _longIntervalTime = interval;
    }

    bool InputButton::checkIfAnyInputButtonsAreDownForUpdate() const
    {
        bool anyPressed = false;
        if (_keyboardKey.has_value())
            anyPressed |= _keyboardKey.value().isKeyDown();
        if (_mouseButton.has_value())
            anyPressed |= _mouseButton.value().isButtonDown();
        if (_joystickButton.has_value())
            anyPressed |= _joystickButton.value().isButtonDown();
        if (_joystickAxis.has_value())
            anyPressed |= _joystickButton.value().isButtonDown();
        return anyPressed;
    }

    bool InputButton::checkInterval(bool withDelayFirst)
    {
        if (_isButtonPressed)
        {
            if (_didButtonSwitchStatePreviousFrame ||
                _downDuration > (_longIntervalTime * (float)!withDelayFirst +
                                _intervalTime * (float)(_intervalCount - withDelayFirst)
                    )
                )
            {
                _intervalCountShouldUpdateTo = _intervalCount + 1;
                return true;
            }

            return false;
        }
        _intervalCountShouldUpdateTo = 0;
        return false;
    }


} // Tetris::Input
