//
// Created by glosn on 4/23/2022.
//

#include "GridCellState.h"

namespace Tetris::State
{
    GridCellState::GridCellState() = default;

    GridCellState::~GridCellState()
    {
    };

    bool GridCellState::hasTile() const { return m_containedTile.has_value(); }

    const TetrisTile& GridCellState::getTile() const
    {
        return m_containedTile.value();
    }

    void GridCellState::setTile(const TetrisTile& tile)
    {
        m_containedTile = tile;
    }

    void GridCellState::setEmpty()
    {
        m_containedTile = std::nullopt;
    }

} // namespace Tetris::State
