//
// Created by glosn on 4/27/2022.
//

#include "KeyboardInput.h"
#include "SFML/Graphics.hpp"
#include "KeyboardLayout.h"

namespace Tetris::Input
{
    KeyboardInput::KeyboardInput(const KeyboardLayout &layout)
        : m_layout(layout)
    {
    }

    bool KeyboardInput::turnRightIsPressed()
    {
        sf::Keyboard::isKeyPressed(m_layout.rotateRight);
    }

    bool KeyboardInput::turnLeftIsPressed()
    {
        return false;
    }

    bool KeyboardInput::instantFallIsPressed()
    {
        sf::Keyboard::isKeyPressed(m_layout.instantFall);
    }

    bool KeyboardInput::speedFallIsPressed()
    {
        sf::Keyboard::isKeyPressed(m_layout.fallFast);
    }

    bool KeyboardInput::moveRightIsPressed()
    {
        sf::Keyboard::isKeyPressed(m_layout.moveRight);
    }

    bool KeyboardInput::moveLeftIsPressed()
    {
        sf::Keyboard::isKeyPressed(m_layout.moveLeft);
    }

    bool KeyboardInput::holdPieceIsPressed()
    {
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C);
    }

    bool KeyboardInput::pauseIsPressed()
    {
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P);
    }

} // Tetris::Input