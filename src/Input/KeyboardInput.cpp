//
// Created by glosn on 4/27/2022.
//

#include "KeyboardInput.h"
#include <sfml/Graphics.hpp>

namespace Tetris::Input
{
    bool InputType::turnRightIsPressed()
    {
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    }

    bool InputType::turnLeftIsPressed()
    {
        return false;
    }

    bool InputType::instantFallIsPressed()
    {
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
    }

    bool InputType::speedFallIsPressed()
    {
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
    }

    bool InputType::moveRightIsPressed()
    {
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
    }

    bool InputType::moveLeftIsPressed()
    {
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
    }

    bool InputType::pauseIsPressed()
    {
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P);
    }



} // Tetris::Input