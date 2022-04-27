//
// Created by glosn on 4/27/2022.
//

#ifndef TETRISEXAM_TETRISTILE_H
#define TETRISEXAM_TETRISTILE_H

#include <SFML/Graphics/Color.hpp>

namespace Tetris::State
{

    class TetrisTile
    {
    public:
        enum Type
        {
            Active,     // These tiles are part of the falling TetrisPiece
            Solid,      // These tiles are part of the solid ground
            GhostTile   // These are the tiles with border only that you can see at the bottom
        };

        TetrisTile() = default;

        Type getType();
        sf::Color getColor();
        // TODO: Add a get sprite so that they can be really cool and have animations also, woo!

        void setColor(sf::Color color);


    private:
        sf::Color m_tileColor{};
        Type m_type{Solid};
    };
} // Tetris::State


#endif //TETRISEXAM_TETRISTILE_H