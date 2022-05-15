//
// Created by glosn on 5/13/2022.
//

#ifndef TETRISEXAM_BASESCREEN_H
#define TETRISEXAM_BASESCREEN_H

#include "Base/Component.h"
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

namespace Tetris::GUI
{
    class ScreenManager;

    class BaseScreen
    {
    public:

        virtual void draw(sf::RenderTarget &renderTarget)
        {
            for (auto& comp : m_components)
            {
                comp->draw(renderTarget);
            }
        }
        virtual void update(float deltaTime)
        {
            for (auto& comp : m_components)
            {
                comp->update(deltaTime);
            }
        }

        inline void setScreenManager(ScreenManager *manager) { m_manager = manager; }

    protected:
        inline void addButton(const sf::Vector2i &position, sf::Sprite &sprite) { m_components.push_back(std::make_unique<Button>(position, sprite)); }
        ScreenManager *m_manager{nullptr};

    private:
        std::vector<std::unique_ptr<Component>> m_components{};
    };

}


#endif //TETRISEXAM_BASESCREEN_H
