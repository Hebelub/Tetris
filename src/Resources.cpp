//
// Created by glosn on 5/14/2022.
//

#include "Resources.h"

namespace Tetris
{

    void Resources::loadTexture(const std::string &path)
    {
        sf::Texture texture{};
        texture.loadFromFile(path);

        m_textures.insert({"gui", texture});
    }

    sf::Texture &Resources::getTexture(const std::string &name)
    {
        return m_textures.at(name);
    }

    Resources::Resources()
    {
        loadTexture("Assets/Gui.png");
    }

} // Tetris