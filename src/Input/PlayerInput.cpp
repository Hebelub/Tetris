//
// Created by glosn on 5/9/2022.
//

#include "PlayerInput.h"

namespace Tetris::Input
{

    void PlayerInput::updateButtons(float deltaTime)
    {
        moveLeft.update(deltaTime);
        moveRight.update(deltaTime);
        rotateLeft.update(deltaTime);
        rotateRight.update(deltaTime);
        fallFast.update(deltaTime);
        instantFall.update(deltaTime);
        menuButton.update(deltaTime);


    }
} // Tetris::Input