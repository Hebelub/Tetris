//
// Created by glosn on 4/27/2022.
//

#ifndef TETRISEXAM_TETRISTILE_H
#define TETRISEXAM_TETRISTILE_H

#include <SFML/Graphics.hpp>

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
        explicit TetrisTile(const sf::IntRect &intRect, Type type);

        [[nodiscard]] Type getType() const;
        [[nodiscard]] const sf::IntRect & getSpriteRect() const;

        void setColor(sf::Color color);
        void setType(Type type);

        [[nodiscard]] const sf::Color &getColor() const;

    private:
        sf::Color m_tileColor{};
        Type m_type{Active};
        sf::IntRect m_intRect;
    };
} // Tetris::State


#endif //TETRISEXAM_TETRISTILE_H
