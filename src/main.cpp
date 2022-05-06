#include "RunningGame/Game.h"
#include "RunningGame/GameManager.h"

#include <memory>
#include <random>

std::vector<KeyboardLayout> setupPlayerControls()
{
    // PLAYER 1
    KeyboardLayout player1Controls{};
    player1Controls.rotateRight = sf::Keyboard::W;
    player1Controls.fallFast = sf::Keyboard::S;
    player1Controls.instantFall = sf::Keyboard::Space;
    player1Controls.moveLeft = sf::Keyboard::A;
    player1Controls.moveRight = sf::Keyboard::D;

    // PLAYER 2
    KeyboardLayout player2Controls{};
    player2Controls.rotateRight = sf::Keyboard::Up;
    player2Controls.fallFast = sf::Keyboard::Down;
    player2Controls.instantFall = sf::Keyboard::Enter;
    player2Controls.moveLeft = sf::Keyboard::Left;
    player2Controls.moveRight = sf::Keyboard::Right;

    return { player1Controls, player2Controls };

}

int main()
{
    Tetris::GameManager game;

    auto seed = std::random_device{}();
    int numPlayers = 2;
    auto controls = setupPlayerControls();

    for(int i = 0; i < controls.size(); i++)
    {
        if (numPlayers >= i + 1) game.initiateARunningGame(seed, controls[i]);
    }

    game.runGameLoop();

    return 0;
}
