//
// Created by glosn on 5/13/2022.
//

#ifndef TETRISEXAM_BUTTON_H
#define TETRISEXAM_BUTTON_H

#include "../Base/Component.h"

namespace Tetris::GUI
{
    class Button : public Component
    {
    public:
        Button(const sf::Vector2i &position, sf::Sprite &sprite);

        void update(float deltaTime) override;

        void draw(sf::RenderTarget &renderTarget) override;

    private:
        sf::Sprite m_sprite;

    };

} // Tetris::GUI

#endif //TETRISEXAM_BUTTON_H
