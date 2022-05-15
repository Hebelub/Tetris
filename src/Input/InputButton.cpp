//
// Created by glosn on 5/8/2022.
//

#include "InputButton.h"
#include <SFML/Graphics.hpp>
#include <iostream>


namespace Tetris::Input
{

    InputButton::InputButton()
        : _signalType(SignalType::AlwaysOff)
    { }

    InputButton::InputButton(InputButton::SignalType signalType, InputButtonSource source)
        : _signalType(signalType)
    {
        addInputSource(source);
    }


    void InputButton::addInputSource(InputButtonSource &source)
    {
        _inputSources.push_back(source);
    }


    void InputButton::update(float deltaTime)
    {
        _intervalCount = _intervalCountShouldUpdateTo;

        bool inputCheck = isButtonPressed();
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
            case (SignalType::AlwaysOff):
                return false;
            case (SignalType::AlwaysOn):
                return true;
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
            case (SignalType::IntervalWhithDelayFirst):
                return checkInterval(true);
            default:
                std::cerr << "ERROR: Inspect this switch statement" << std::endl;
                return false;
        }
    }

    bool InputButton::isButtonPressed() const
    {
        return std::any_of(_inputSources.begin(), _inputSources.end(),
        [] (const InputButtonSource &source)
        {
            return source.isSourcePressed();
        });
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

    bool InputButton::checkInterval(bool withDelayFirst)
    {
        if (_isButtonPressed) {
            if (_didButtonSwitchStatePreviousFrame ||
                _downDuration > (_longIntervalTime * (float) withDelayFirst +
                                 _intervalTime * (float) (_intervalCount - withDelayFirst)
                )
                    ) {
                _intervalCountShouldUpdateTo = _intervalCount + 1;
                return true;
            }

            return false;
        }
        _intervalCountShouldUpdateTo = 0;
        return false;
    }

} // Tetris::Input
