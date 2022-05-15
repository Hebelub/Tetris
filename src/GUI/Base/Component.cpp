//
// Created by glosn on 5/13/2022.
//

#include "Component.h"

namespace Tetris::GUI
{

    Component::Component(const sf::Vector2i &position)
        : m_position(position)
    { }

    void Component::setPosition(const sf::Vector2i &position)
    {
        m_position = position;
    }
}