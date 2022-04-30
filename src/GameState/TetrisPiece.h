//
// Created by glosn on 4/29/2022.
//

#ifndef TETRISEXAM_TETRISPIECE_H
#define TETRISEXAM_TETRISPIECE_H

#include <SFML/System/Vector2.hpp>
#include "TetrisShape.h"

namespace Tetris::State
{
    class TetrisPiece
    {
    public:
        enum class Rotation
        {
            Up,
            Down,
            Left,
            Right
        };

        explicit TetrisPiece(TetrisShape piece);

        [[nodiscard]] Rotation getRotation() const;
        void setRotation(Rotation rotation);

        TetrisShape &getShape();
        void setShape(TetrisShape &piece);

        [[nodiscard]] sf::Vector2i getPosition() const;
        void setPosition(sf::Vector2i newPosition);
        void addPosition(sf::Vector2i offset);

    private:

        Rotation m_rotation{Rotation::Up};
        TetrisShape m_currentPiece;
        sf::Vector2i m_position{};

    };

} // Tetris::State

#endif //TETRISEXAM_TETRISPIECE_H
