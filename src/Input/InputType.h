//
// Created by glosn on 4/27/2022.
//

#ifndef TETRISEXAM_INPUTTYPE_H
#define TETRISEXAM_INPUTTYPE_H

namespace Tetris::Input
{
    /// @brief An interface
    class InputType
    {
        virtual bool turnRightIsPressed() = 0;

        virtual bool turnLeftIsPressed() = 0;

        virtual bool instantFallIsPressed() = 0;

        virtual bool speedFallIsPressed() = 0;

        virtual bool moveRightIsPressed() = 0;

        virtual bool moveLeftIsPressed() = 0;
        
        virtual bool pauseIsPressed() = 0;

    };

} // Tetris::Input

#endif //TETRISEXAM_INPUTTYPE_H
