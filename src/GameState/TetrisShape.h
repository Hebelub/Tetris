//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_TETRISSHAPE_H
#define TETRISEXAM_TETRISSHAPE_H


#include "TetrisTile.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

namespace Tetris::State
{
    struct hash_fn
    {
        template <class T1>
        std::size_t operator() (const sf::Vector2i &vec) const
        {
            std::size_t h1 = std::hash<T1>()(vec.x);
            std::size_t h2 = std::hash<T1>()(vec.y);

            return h1 ^ h2;
        }
    };

    class TetrisShape
    {
    public:
        struct TetrisTileRelative
        {
            sf::Vector2i offset;
            TetrisTile tile;
        };

        void addTile(int x, int y, TetrisTile tile);

        [[nodiscard]] const std::vector<TetrisShape::TetrisTileRelative> &getTiles() const;

    private:
        std::vector<TetrisTileRelative> m_tiles;
    };

} // Tetris::Logic


#endif //TETRISEXAM_TETRISSHAPE_H
