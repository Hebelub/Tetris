#include "PlaySound.h"
#include <SFML/Audio.hpp>
#include <string>


namespace Tetris::Audio
{

    void PlaySound::playSound(const std::string &filepath)
    {
        sf::Music music;
        music.openFromFile(filepath);
        music.play();
    }

    void PlaySound::addPlayerSound()
    {
        playSound("../Assets/Sounds/addPlayer.wav");
    }

    void PlaySound::backgroundMusic()
    {
        playSound("../Assets/Sounds/backgroundMusic.wav");
    }

    void PlaySound::clearRowSound()
    {
        playSound("../Assets/Sounds/clearRow.wav");
    }

    void PlaySound::closeWindowSound()
    {
        playSound("../Assets/Sounds/closeWindow.wav");
    }

    void PlaySound::fastSpeedSound()
    {
        playSound("../Assets/Sounds/fastSpeed.wav");
    }

    void PlaySound::gameOverSound()
    {
        playSound("../Assets/Sounds/gameOver.wav");
    }

} // Tetris::Audio
