//
// Created by glosn on 4/29/2022.
//

#ifndef TETRISEXAM_ACTIVETETRISPIECE_H
#define TETRISEXAM_ACTIVETETRISPIECE_H

#include <SFML/System/Vector2.hpp>
#include "TetrisPiece.h"

namespace Tetris::State
{
    class ActiveTetrisPiece
    {
    public:
        explicit ActiveTetrisPiece(TetrisPiece &piece);

        [[nodiscard]] int getRotation() const;
        void setRotation(int rotation);
        void addRotation(int turns);

        TetrisPiece &getPiece();
        void setPiece(TetrisPiece &piece);

        [[nodiscard]] sf::Vector2i getPosition() const;
        void setPosition(sf::Vector2i newPosition);
        void addPosition(sf::Vector2i offset);

    private:

        // Is a value between one and four
        int m_rotation{};
        TetrisPiece &m_currentPiece;
        sf::Vector2i m_position{};

    };

} // Tetris::State

#endif //TETRISEXAM_ACTIVETETRISPIECE_H
