//
// Created by glosn on 5/9/2022.
//

#ifndef TETRISEXAM_PLAYERINPUT_H
#define TETRISEXAM_PLAYERINPUT_H

#include "InputButton.h"

namespace Tetris::Input
{

    class PlayerInput
    {
    public:
        void updateButtons(float deltaTime);

        InputButton moveLeft{};
        InputButton moveRight{};
        InputButton rotateLeft{};
        InputButton rotateRight{};
        InputButton fallFast{};
        InputButton instantFall{};
        InputButton menuButton{};
    };

} // Tetris::Input

#endif //TETRISEXAM_PLAYERINPUT_H
