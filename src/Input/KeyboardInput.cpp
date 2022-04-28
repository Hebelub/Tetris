//
// Created by glosn on 4/27/2022.
//

#include "KeyboardInput.h"
#include "SFML/Graphics.hpp"

namespace Tetris::Input
{
    KeyboardInput::KeyboardInput() = default;

    bool KeyboardInput::turnRightIsPressed()
    {
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    }

    bool KeyboardInput::turnLeftIsPressed()
    {
        return false;
    }

    bool KeyboardInput::instantFallIsPressed()
    {
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
    }

    bool KeyboardInput::speedFallIsPressed()
    {
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
    }

    bool KeyboardInput::moveRightIsPressed()
    {
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
    }

    bool KeyboardInput::moveLeftIsPressed()
    {
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
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