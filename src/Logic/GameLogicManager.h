//
// Created by glosn on 4/24/2022.
//

#ifndef TETRISEXAM_GAMELOGICMANAGER_H
#define TETRISEXAM_GAMELOGICMANAGER_H

#include "../GameState/TetrisGameState.h"

namespace Tetris::Logic
{
    class GameLogicManager
    {
    public:
        void updateLogic(State::TetrisGameState &gameState, float deltaTime);

    private:

    };

} // Tetris::Logic

#endif //TETRISEXAM_GAMELOGICMANAGER_H
