//
// Created by glosn on 5/13/2022.
//

#ifndef TETRISEXAM_BASESCREEN_H
#define TETRISEXAM_BASESCREEN_H

#include "Component.h"
#include "../Components/Button.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>

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

        virtual void setupGuiComponents() = 0;

    protected:
        inline Component& getComponent(int id) { return *m_components.at(id); }

        inline Button *addButton(const sf::Vector2i &position, sf::Sprite &&sprite)
        {
            auto *component = m_components.emplace_back(std::make_unique<Button>(position, sprite)).get();
            return dynamic_cast<Button*>(component);
        }
        ScreenManager *m_manager{nullptr};

    private:
        std::vector<std::unique_ptr<Component>> m_components{};
    };

}


#endif //TETRISEXAM_BASESCREEN_H
