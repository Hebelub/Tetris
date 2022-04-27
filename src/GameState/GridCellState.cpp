//
// Created by glosn on 4/23/2022.
//

#include "GridCellState.h"

namespace Tetris::State
{
    GridCellState::GridCellState() = default;

    GridCellState::~GridCellState()
    {
        delete m_containedTile;
    };

    bool GridCellState::hasTile() const { return m_containedTile != nullptr; }

    TetrisTile &GridCellState::getTile()
    {
        return *m_containedTile;
    }

    void GridCellState::setTile(TetrisTile *tile)
    {
        m_containedTile = tile;
    }

    void GridCellState::setEmpty()
    {
        m_containedTile = nullptr;
    }

} // namespace Tetris::State
