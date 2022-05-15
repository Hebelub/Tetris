//
// Created by glosn on 5/14/2022.
//

#ifndef TETRISEXAM_CONTROLSETTINGS_H
#define TETRISEXAM_CONTROLSETTINGS_H

#include <vector>
#include "PlayerInput.h"

namespace Tetris::Input
{
    class ControlSettings
    {
    public:
        void initialize();
        [[nodiscard]] const Tetris::Input::PlayerInput &getControlsForPlayer(int index) const;
    private:
        std::vector<Tetris::Input::PlayerInput> m_playerInputs;
    };
} // Tetris::Input


#endif //TETRISEXAM_CONTROLSETTINGS_H
