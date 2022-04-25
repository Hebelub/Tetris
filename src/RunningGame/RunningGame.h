//
// Created by glosn on 4/23/2022.
//

#ifndef TETRISEXAM_RUNNINGGAME_H
#define TETRISEXAM_RUNNINGGAME_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "../GameState/TetrisGameState.h"
#include "../Setup/GameSaver.h"
#include "../Setup/GameLoader.h"
#include "../GUI/GameRenderer.h"
#include "../Logic/GameLogicManager.h"
#include <memory>

namespace Tetris
{
    class RunningGame
    {

    public:
        RunningGame();
        sf::Sprite getSprite();

        void updateFrame(float deltaTime);

    private:
        std::unique_ptr<State::TetrisGameState> m_currentGameState{nullptr};

        std::unique_ptr<Graphics::GameRenderer> m_gameRenderer{nullptr};
        std::unique_ptr<Logic::GameLogicManager> m_gameLogic{nullptr};

        int m_framesPrSecond{100};

    };

} // Tetris


#endif //TETRISEXAM_RUNNINGGAME_H
