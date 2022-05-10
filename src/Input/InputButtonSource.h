//
// Created by glosn on 5/9/2022.
//

#ifndef TETRISEXAM_INPUTBUTTONSOURCE_H
#define TETRISEXAM_INPUTBUTTONSOURCE_H

#include <SFML/Graphics.hpp>
#include <memory>


namespace Tetris::Input
{


    class InputButtonSource
    {
    private:
        class Source
        {
        public:
            [[nodiscard]] virtual bool isPressed() const { return false; };
            [[nodiscard]] virtual float getAxis() const { return 0; };
        };


        class KeyboardKey : public Source
        {
        public:
            explicit KeyboardKey(sf::Keyboard::Key key) : _key(key) { };
            [[nodiscard]] bool isPressed() const override { return sf::Keyboard::isKeyPressed(_key); };
        private:
            sf::Keyboard::Key _key;
        }; // KeyboardKey


        class JoystickButton : public Source
        {
        public:
            explicit JoystickButton(unsigned int controller, unsigned int button)
                    : _controller(controller), _button(button) { };
            [[nodiscard]] bool isPressed() const override { return sf::Joystick::isButtonPressed(_controller, _button); };
        private:
            unsigned int _controller;
            unsigned int _button;
        }; // JoystickButton


        class JoystickAxis : public Source
        {
        public:
            explicit JoystickAxis(unsigned int controller, sf::Joystick::Axis axis, float axisSensitivity = 0.1F)
                    : _controller(controller), _axis(axis), _axisSensitivity(axisSensitivity) { };
            [[nodiscard]] bool isPressed() const override { return getAxis() > _axisSensitivity; };
            [[nodiscard]] float getAxis() const override { return sf::Joystick::getAxisPosition(_controller, _axis); };
        private:
            unsigned int _controller;
            sf::Joystick::Axis _axis;
            float _axisSensitivity;
        }; // JoystickButton


        class MouseButton : public Source
        {
        public:
            explicit MouseButton(sf::Mouse::Button button) : _button(button) { };
            [[nodiscard]] bool isPressed() const override { return sf::Mouse::isButtonPressed(_button); };
        private:
            sf::Mouse::Button _button{};
        }; // MouseButton

    public:
        explicit InputButtonSource() = default;
        explicit InputButtonSource(sf::Keyboard::Key key);
        explicit InputButtonSource(sf::Mouse::Button button);
        explicit InputButtonSource(unsigned int controller, unsigned int button);
        explicit InputButtonSource(unsigned int controller, sf::Joystick::Axis axis);
        explicit InputButtonSource(unsigned int controller, sf::Joystick::Axis axis, float sensitivity);

        ~InputButtonSource();

        [[nodiscard]] bool isSourcePressed() const;

        void setSource(sf::Keyboard::Key key);
        void setSource(sf::Mouse::Button button);
        void setSource(unsigned int controller, unsigned int button);
        void setSource(unsigned int controller, sf::Joystick::Axis axis);
        void setSource(unsigned int controller, sf::Joystick::Axis axis, float sensitivity);

        Source *_inputSource{nullptr};
    };
} // Tetris::Input


#endif //TETRISEXAM_INPUTBUTTONSOURCE_H
