//
// Created by glosn on 5/13/2022.
//

#ifndef TETRISEXAM_COMPONENT_H
#define TETRISEXAM_COMPONENT_H

#include <SFML/Graphics.hpp>

namespace Tetris::GUI
{

    class Component
    {
    public:
        explicit Component(const sf::Vector2i &position);
        virtual ~Component() = default;

        virtual void update(float deltaTime) = 0;
        virtual void draw(sf::RenderTarget &renderTarget) = 0;

    protected:
        sf::Vector2i m_position;
    };

} // Tetris::GUI

#endif //TETRISEXAM_COMPONENT_H
