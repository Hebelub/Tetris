//
// Created by glosn on 4/27/2022.
//

#ifndef TETRISEXAM_TETRISSINGLETILE_H
#define TETRISEXAM_TETRISSINGLETILE_H

#include <SFML/Graphics/Color.hpp>

namespace Tetris::State
{

    class TetrisSingleTile
    {
        enum Type
        {
            Active,     // These tiles are part of the falling TetrisPiece
            Solid,      // These tiles are part of the solid ground
            GhostTile   // These are the tiles with border only that you can see at the bottom
        };

    public:

        TetrisSingleTile() = default;

        Type getType();
        sf::Color getColor();
        // TODO: Add a get sprite so that they can be really cool and have animations also, woo!

    private:
        sf::Color m_tileColor;
        Type m_type;
    };
} // Tetris::State


#endif //TETRISEXAM_TETRISSINGLETILE_H
