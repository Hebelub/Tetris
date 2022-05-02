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
            Active,      // These m_tiles are part of the falling TetrisShape
            Solid,       // These m_tiles are part of the solid ground
            GhostTile,   // These are the m_tiles with border only that you can see at the bottom
            OutOfBounds, // Nonexistent m_tiles returned outide of the grid
            OverGrid,
            EmptyCell,
            QueuedTile   //
        };

        TetrisTile() = default;
        explicit TetrisTile(Type type);

        [[nodiscard]] Type getType() const;
        [[nodiscard]] sf::Color getColor() const;
        // TODO: Add a get sprite so that they can be really cool and have animations also, woo!

        void setColor(sf::Color color);
        void setType(Type type);

    private:
        sf::Color m_tileColor{};
        Type m_type{Active};
    };
} // Tetris::State


#endif //TETRISEXAM_TETRISTILE_H
