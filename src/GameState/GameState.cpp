//
// Created by glosn on 4/23/2022.
//

#include <iostream>
#include "GameState.h"
#include "../Logic/TetrsPiece/TetrisPieceGenerator.h"
#include "ActiveTetrisPiece.h"

// TODO FINISH IMPLEMENTATION
namespace Tetris::State
{
    GameState::GameState(int queuedPieces)
    {
        for (int i = 0; i < queuedPieces; ++i)
        {
            addTetrisLast(m_pieceGenerator.getRandomPiece());
        }
    }

    TetrisPiece &GameState::getNextTetris()
    {
        if (m_upcomingPieces.empty())
        {
            std::cerr << "Something is wrong in GameState::getNextTetris because m_upcomingPieces is empty" << std::endl;
            exit(-88);
        }
        return m_upcomingPieces.front();
    }

    void GameState::conveyPieces()
    {
        addTetrisLast(m_pieceGenerator.getRandomPiece());
        popNextTetris();
    }

    TetrisPiece &GameState::getNextTetrisAndConvey()
    {
        TetrisPiece &state = getNextTetris();
        conveyPieces();
        std::cout << "D" << std::endl;

        return state;
    }

    void GameState::popNextTetris()
    {
        if (m_upcomingPieces.empty())
        {
            std::cerr << "Something is wrong in GameState::popNextTetris because m_upcomingPieces is empty" << std::endl;
            exit(-99);
        }

        m_upcomingPieces.pop_front();
    }

    void GameState::addTetrisLast(TetrisPiece & tetrisPiece)
    {
        m_upcomingPieces.push_back(tetrisPiece);
    }

    void GameState::tryRemoveTetrisLast()
    {
        if(queuedPieces() > 1)
            m_upcomingPieces.pop_back();
    }

    GridState &GameState::getGridState()
    {
        return m_gameGrid;
    }

    size_t GameState::queuedPieces()
    {
        return m_upcomingPieces.size();
    }

    ActiveTetrisPiece &GameState::getActiveTetris()
    {
        return m_activeTetrisPiece;
    }
}
