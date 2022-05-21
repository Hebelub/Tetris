#include "playSounds.h"
#include <SFML/Audio.hpp>
#include <string>

void Tetris::Sound::playSound(const std::string &filepath)
{
    sf::Music music;
    music.openFromFile(filepath);
    music.play();
}

void Tetris::Sound::addPlayerSound()
{
    playSound("../Assets/Sounds/addPlayer.wav");
}

void Tetris::Sound::backgroundMusic()
{
    playSound("../Assets/Sounds/backgroundMusic.wav");
}

void Tetris::Sound::clearRowSound()
{
    playSound("../Assets/Sounds/clearRow.wav");
}

void Tetris::Sound::closeWindowSound()
{
    playSound("../Assets/Sounds/closeWindow.wav");
}

void Tetris::Sound::fastSpeedSound()
{
    playSound("../Assets/Sounds/fastSpeed.wav");
}

void Tetris::Sound::gameOverSound()
{
    playSound("../Assets/Sounds/gameOver.wav");
}