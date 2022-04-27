//
// Created by glosn on 4/27/2022.
//

#ifndef TETRISEXAM_KEYBOARDINPUT_H
#define TETRISEXAM_KEYBOARDINPUT_H

#include "InputType.h"

namespace Tetris::Input
{
    /// @bief Takes input from computer
    class KeyboardInput : public InputType
    {
        // TODO: It should take the input from an inputLayout (should be an interface) so that you can add people to the same keyboard

        bool turnRightIsPressed() override;

        bool turnLeftIsPressed() override;

        bool instantFallIsPressed() override;

        bool speedFallIsPressed() override;

        bool moveRightIsPressed() override;

        bool moveLeftIsPressed() override;

        bool holdPieceIsPressed() override;

        bool pauseIsPressed() override;

    public:
        KeyboardInput();
    };

} // Tetris::Input

#endif //TETRISEXAM_KEYBOARDINPUT_H
