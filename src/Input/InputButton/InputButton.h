//
// Created by glosn on 5/8/2022.
//

#ifndef TETRISEXAM_INPUTBUTTON_H
#define TETRISEXAM_INPUTBUTTON_H

#include <SFML/Graphics.hpp>
#include <utility>
#include <optional>


namespace Tetris::Input
{
    class InputButton
    {
    private:
        class KeyboardKey
        {
        public:
            explicit KeyboardKey(sf::Keyboard::Key key) : _key(key) { };
            bool isKeyDown() { return sf::Keyboard::isKeyPressed(_key); };
        private:
            sf::Keyboard::Key _key;
        }; // KeyboardKey


        class JoystickButton
        {
        public:
            explicit JoystickButton(unsigned int controller, unsigned int button)
                : _controller(controller), _button(button) { };
            [[nodiscard]] bool isButtonDown() const { return sf::Joystick::isButtonPressed(_controller, _button); };
        private:
            unsigned int _controller;
            unsigned int _button;
        }; // JoystickButton


        class JoystickAxis
        {
        public:
            explicit JoystickAxis(unsigned int controller, sf::Joystick::Axis axis, float axisSensitivity = 0.1F)
                : _controller(controller), _axis(axis), _axisSensitivity(axisSensitivity) { };
            [[nodiscard]] float getAxis() const { return sf::Joystick::getAxisPosition(_controller, _axis); };
            [[nodiscard]] bool isAxisActive() const { return getAxis() > _axisSensitivity; };
        private:
            unsigned int _controller;
            sf::Joystick::Axis _axis;
            float _axisSensitivity;
        }; // JoystickButton


        class MouseButton
        {
        public:
            explicit MouseButton(sf::Mouse::Button button) : _button(button) { };
            bool isButtonDown() { return sf::Mouse::isButtonPressed(_button); };
        private:
            sf::Mouse::Button _button{};
        }; // MouseButton


    public:
        enum class SignalType
        {
            ButtonState,                 ///< True when button is down
            NotButtonState,              ///< True when button is up
            OnButtonDown,                ///< True when button goes down
            OnButtonUp,                  ///< True when button goes up
            OnStateChange,               ///< True when button goes up or down
            Interval,                    ///< True every interval
            IntervalDifferentDelayFirst, ///< True every interval but the fist interval is different

            ButtonCount                  ///< Keep last -- the total number of SignalTypes
        };

        explicit InputButton(SignalType signalType, sf::Keyboard::Key key);
        explicit InputButton(SignalType signalType, sf::Mouse::Button button);
        explicit InputButton(SignalType signalType, unsigned int controller, unsigned int button);
        explicit InputButton(SignalType signalType, unsigned int controller, sf::Joystick::Axis axis);
        explicit InputButton(SignalType signalType, unsigned int controller, sf::Joystick::Axis axis, float axisSensitivity);

        bool getSignal();

    private:
        SignalType _signalType{};

        std::optional<KeyboardKey> _keyboardKey{std::nullopt};
        std::optional<MouseButton> _mouseButton{std::nullopt};
        std::optional<JoystickButton> _joystickButton{std::nullopt};
        std::optional<JoystickAxis> _joystickAxis{std::nullopt};
    };

} // Tetris::Input

#endif //TETRISEXAM_INPUTBUTTON_H
