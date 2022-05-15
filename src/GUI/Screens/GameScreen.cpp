//
// Created by glosn on 5/13/2022.
//

#include "GameScreen.h"
#include "../ScreenManager.h"

void Tetris::GUI::GameScreen::setupGuiComponents() {

}

namespace Tetris::GUI
{
    void GameScreen::draw(sf::RenderTarget &renderTarget)
    {
        int i = 0;
        for (auto &game : m_runningGames)
        {
            auto &sprite = game->getSprite();
            sprite.setPosition(300 * i, 0);
            renderTarget.draw(game->getSprite());
            i++;
        }
    }

    void GameScreen::update(float deltaTime)
    {
        int numGameOver = 0;
        for (auto &game : m_runningGames)
        {
            if (!game->isGameOver())
            {
                game->updateFrame(deltaTime);
            }
            else
            {
                numGameOver++;
            }
        }

        // Check game over in singleplayer
        if (m_runningGames.size() == 1 && numGameOver == 1)
        {
            returnToMenu();
        }

        // Check gameover of all but 1 player in multiplayer
        if (m_runningGames.size() > 1 && numGameOver == m_runningGames.size() - 1)
        {
            returnToMenu();
        }
    }

    void GameScreen::initiateARunningGame(const std::string &name, unsigned int seed,
                                          const Input::PlayerInput &playerInput)
    {
        auto f = [=](int n) { return onLineClear(name, n); };

        auto game = std::make_unique<Tetris::Game>(name, playerInput, seed);
        game->setLineClearCallback(f);

        m_runningGames.emplace_back(std::move(game));
    }

    void GameScreen::onLineClear(const std::string &gameThatCleared, int numLines)
    {
        for(auto &game : m_runningGames)
        {
            if (game->getName() == gameThatCleared) continue;
            game->onOpponentClear(numLines);
        }
    }

    void GameScreen::returnToMenu()
    {
        m_manager->setScreen(Screen::MainMenu);
    }

} // Tetris::GUI