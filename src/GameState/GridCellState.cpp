//
// Created by glosn on 4/23/2022.
//

#include "GridCellState.h"

namespace Tetris::State
{
    bool GridCellState::isEmpty() const { return m_isEmpty; }

    bool GridCellState::isSolid() const { return m_isSolid; }

    void GridCellState::setSolid() { m_isSolid = true; }

    bool GridCellState::isFalling() const { return !m_isSolid; }

    sf::Color GridCellState::getColor() const { return m_color; }

} // namespace Tetris::State
