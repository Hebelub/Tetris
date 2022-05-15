//
// Created by glosn on 5/14/2022.
//

#ifndef TETRISEXAM_RESOURCES_H
#define TETRISEXAM_RESOURCES_H

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace Tetris
{

    class Resources
    {
    public:
        explicit Resources();

        sf::Texture &getTexture(const std::string &name);

    private:
        void loadTexture(const std::string &path);

        std::map<std::string, sf::Texture> m_textures;
    };

} // Tetris

#endif //TETRISEXAM_RESOURCES_H
