#include "RunningGame/GameManager.h"
#include "Input/PlayerInput.h"

#include <memory>
#include <random>


std::vector<Tetris::Input::PlayerInput> setupPlayerControls()
{
    using InputButton = Tetris::Input::InputButton;
    using InputButtonSource = Tetris::Input::InputButtonSource;
    using SignalType = Tetris::Input::InputButton::SignalType;

    // PLAYER 1
    Tetris::Input::PlayerInput player1Controls{};
    player1Controls.rotateRight = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Keyboard::W));
    player1Controls.fallFast    = InputButton(SignalType::ButtonState, InputButtonSource(sf::Keyboard::S));
    player1Controls.instantFall = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Keyboard::LControl));
    player1Controls.moveLeft    = InputButton(SignalType::IntervalWhithDelayFirst, InputButtonSource(sf::Keyboard::A));
    player1Controls.moveRight   = InputButton(SignalType::IntervalWhithDelayFirst, InputButtonSource(sf::Keyboard::D));

    // PLAYER 2
    Tetris::Input::PlayerInput player2Controls{};
    player2Controls.rotateRight = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Keyboard::I));
    player2Controls.fallFast    = InputButton(SignalType::ButtonState, InputButtonSource(sf::Keyboard::K));
    player2Controls.instantFall = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Keyboard::Space));
    player2Controls.moveLeft    = InputButton(SignalType::IntervalWhithDelayFirst, InputButtonSource(sf::Keyboard::J));
    player2Controls.moveRight   = InputButton(SignalType::IntervalWhithDelayFirst, InputButtonSource(sf::Keyboard::L));

    // PLAYER 3
    Tetris::Input::PlayerInput player3Controls{};
    player3Controls.rotateRight = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Keyboard::Up));
    player3Controls.fallFast    = InputButton(SignalType::ButtonState, InputButtonSource(sf::Keyboard::Down));
    player3Controls.instantFall = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Keyboard::Enter));
    player3Controls.moveLeft    = InputButton(SignalType::IntervalWhithDelayFirst, InputButtonSource(sf::Keyboard::Left));
    player3Controls.moveRight   = InputButton(SignalType::IntervalWhithDelayFirst, InputButtonSource(sf::Keyboard::Right));

    // PLAYER 4
    Tetris::Input::PlayerInput mouseControls{};
    mouseControls.rotateRight = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Mouse::XButton1));
    mouseControls.rotateLeft  = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Mouse::XButton2));
    mouseControls.fallFast    = InputButton(SignalType::ButtonState, InputButtonSource(sf::Mouse::Middle));
    mouseControls.instantFall = InputButton(SignalType::OnButtonDown, InputButtonSource(sf::Keyboard::F10));
    mouseControls.moveRight   = InputButton(SignalType::IntervalWhithDelayFirst, InputButtonSource(sf::Mouse::Right));
    mouseControls.moveLeft    = InputButton(SignalType::IntervalWhithDelayFirst, InputButtonSource(sf::Mouse::Left));

    return { player1Controls, player2Controls, player3Controls, mouseControls };

}

int main()
{
    Tetris::GameManager game;

    auto seed = std::random_device{}();
    int numPlayers = 4;
    auto controls = setupPlayerControls();

    for(int i = 0; i < controls.size(); i++)
    {
        if (numPlayers >= i + 1) game.initiateARunningGame("Player " + std::to_string(i + 1), seed, controls[i]);
    }

    game.runGameLoop();

    return 0;
}
