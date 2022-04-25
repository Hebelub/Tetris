//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_GAMESAVER_H
#define TETRISEXAM_GAMESAVER_H

#include "../GameState/TetrisGameState.h"

namespace Tetris
{
    /// @brief Saves score and frame to json file.
    class GameSaver
    {
        /// @brief Fetces the current game state.
        Tetris::State::TetrisGameState loadGameToJson();
        /// @brief Saves score and frame to json
        /// @param gameToSave the gamesate to save
        void saveGameToJson(Tetris::State::TetrisGameState const &);
    };
}

#endif // TETRISEXAM_GAMESAVER_H
