#ifndef TETRIS_PLAYSOUNDS_H
#define TETRIS_PLAYSOUNDS_H
/// This header contains functions that plays sound when called.
#include <string>
namespace Tetris::Sound
{
    ///@brief Play sound at given filepath
    ///@param filepath: Path to .wav file.
    void playSound(const std::string &filepath);

    ///@brief Plays the addPlayer sound.
    void addPlayerSound();
    /// @brief Plays the clearRow sound.
    void clearRowSound();

    ///@brief Plays the CloseWindow sound.
    void closeWindowSound();

    ///@brief Plays the fastSpeed Sound
    void fastSpeedSound();

    ///@brief Plays the game over sound.
    void gameOverSound();
    ///@brief Plays the background music.
    void backgroundMusic();

} /// end namespace tetris::sound

#endif