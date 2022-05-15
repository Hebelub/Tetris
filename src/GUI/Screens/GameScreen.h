//
// Created by glosn on 5/13/2022.
//

#ifndef TETRISEXAM_GAMESCREEN_H
#define TETRISEXAM_GAMESCREEN_H

#include "../Base/BaseScreen.h"
#include "../../RunningGame/Game.h"

namespace Tetris::GUI
{
    class GameScreen : public BaseScreen
    {
    public:
        explicit GameScreen() = default;

        void draw(sf::RenderTarget &renderTarget) override;

        void update(float deltaTime) override;

        /// @brief Makes a new running game to be played by a
        // player. Adds it to m_runningGames.
        void initiateARunningGame(const std::string &name, unsigned int seed, const Input::PlayerInput &playerInput);

        void onLineClear(const std::string &gameThatCleared, int numLines);

        void setupGuiComponents() override;

    private:
        Input::InputButton m_escape{Input::InputButton::SignalType::OnButtonDown, Input::InputButtonSource{sf::Keyboard::Escape}};

        /// @brief Vector of running games.
        std::vector<std::unique_ptr<Tetris::Game>> m_runningGames;

        void returnToMenu();
    };

} // Tetris::GUI

#endif //TETRISEXAM_GAMESCREEN_H
