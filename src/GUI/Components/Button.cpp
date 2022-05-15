//
// Created by glosn on 5/13/2022.
//

#include "Button.h"

namespace Tetris::GUI
{

    Button::Button(const sf::Vector2i &position, sf::Sprite &sprite)
        : Component(position)
        , m_sprite(sprite)
    {
        m_sprite.setPosition(static_cast<sf::Vector2f>(position));
    }

    void Button::update(float deltaTime)
    {
    }

    void Button::draw(sf::RenderTarget &renderTarget)
    {
        renderTarget.draw(m_sprite);
    }

    void Button::setPosition(const sf::Vector2i &position) {
        Component::setPosition(position);
        m_sprite.setPosition(static_cast<sf::Vector2f>(position));
    }

} // Tetris::GUI