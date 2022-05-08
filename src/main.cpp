#include "RunningGame/Game.h"
#include "RunningGame/GameManager.h"

#include <memory>
#include <random>

std::vector<KeyboardLayout> setupPlayerControls()
{
    // PLAYER 1
    KeyboardLayout player1Controls{};
    player1Controls.rotateRight = sf::Keyboard::W;
    player1Controls.fallFast    = sf::Keyboard::S;
    player1Controls.instantFall = sf::Keyboard::LControl;
    player1Controls.moveLeft    = sf::Keyboard::A;
    player1Controls.moveRight   = sf::Keyboard::D;

    // PLAYER 2
    KeyboardLayout player2Controls{};
    player2Controls.rotateRight = sf::Keyboard::I;
    player2Controls.fallFast    = sf::Keyboard::K;
    player2Controls.instantFall = sf::Keyboard::Space;
    player2Controls.moveLeft    = sf::Keyboard::J;
    player2Controls.moveRight   = sf::Keyboard::L;

    // PLAYER 3
    KeyboardLayout player3Controls{};
    player3Controls.rotateRight = sf::Keyboard::Up;
    player3Controls.fallFast    = sf::Keyboard::Down;
    player3Controls.instantFall = sf::Keyboard::Enter;
    player3Controls.moveLeft    = sf::Keyboard::Left;
    player3Controls.moveRight   = sf::Keyboard::Right;

    return { player1Controls, player2Controls, player3Controls };

}

int main()
{
    Tetris::GameManager game;

    auto seed = std::random_device{}();
    int numPlayers = 3;
    auto controls = setupPlayerControls();

    for(int i = 0; i < controls.size(); i++)
    {
        if (numPlayers >= i + 1) game.initiateARunningGame("Player " + std::to_string(i + 1), seed, controls[i]);
    }

    game.runGameLoop();

    return 0;
}
