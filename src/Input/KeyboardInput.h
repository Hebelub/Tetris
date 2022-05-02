//
// Created by glosn on 4/27/2022.
//

#ifndef TETRISEXAM_KEYBOARDINPUT_H
#define TETRISEXAM_KEYBOARDINPUT_H

#include "InputType.h"
#include "KeyboardLayout.h"

namespace Tetris::Input
{
    /// @bief Takes input from computer
    class KeyboardInput : public InputType
    {
    public:
        // TODO: It should take the input from an inputLayout (should be an interface) so that you can add people to the same keyboard

        KeyboardInput(const KeyboardLayout &layout);

        bool turnRightIsPressed() override;

        bool turnLeftIsPressed() override;

        bool instantFallIsPressed() override;

        bool speedFallIsPressed() override;

        bool moveRightIsPressed() override;

        bool moveLeftIsPressed() override;

        bool holdPieceIsPressed() override;

        bool pauseIsPressed() override;

    private:
        KeyboardLayout m_layout;
    };

} // Tetris::Input

#endif //TETRISEXAM_KEYBOARDINPUT_H
