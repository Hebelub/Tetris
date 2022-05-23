//
// Created by glosn on 5/22/2022.
//

#ifndef TETRISEXAM_PROGRESSBAR_H
#define TETRISEXAM_PROGRESSBAR_H

#include "../Base/Component.h"

namespace Tetris::GUI
{
    class ProgressBar : public Component
    {
    public:
        void update(float deltaTime) override;

        void draw(sf::RenderTarget &renderTarget) override;

        void setProgress(float progress);
        void getProgress();

    private:
        float m_progress;


    };

} // Tetris::GUI


#endif //TETRISEXAM_PROGRESSBAR_H
