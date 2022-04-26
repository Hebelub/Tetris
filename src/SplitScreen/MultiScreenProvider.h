//
// Created by glosn on 4/26/2022.
//

#ifndef TETRISEXAM_MULTISCREENPROVIDER_H
#define TETRISEXAM_MULTISCREENPROVIDER_H

#include "../RunningGame/RunningGame.h"
#include <vector>

namespace Tetris
{
    /// @brief Manages position and scaling of game screens based
    // on the windowSize, number of players & other parameters
    class MultiScreenProvider
    {
        MultiScreenProvider(std::vector<RunningGame> &games);
    };

} // Tetris

#endif //TETRISEXAM_MULTISCREENPROVIDER_H
