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

        void setShape(const TetrisShape &piece);

        [[nodiscard]] sf::Vector2i getPosition() const;
        void setPosition(sf::Vector2i newPosition);
        void addPosition(sf::Vector2i offset);

        const std::vector<TetrisShape::TetrisTileRelative> &getTiles() const;
        std::vector<TetrisShape::TetrisTileRelative> m_tiles;

        // This is a test, should maybe be removed
        bool useQueasyMovement();

    private:

        Rotation m_rotation{Rotation::Up};
        TetrisShape m_currentShape;
        sf::Vector2i m_position{};

    };

} // Tetris::State

#endif //TETRISEXAM_TETRISPIECE_H
