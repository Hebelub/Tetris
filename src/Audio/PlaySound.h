#ifndef TETRIS_PLAYSOUNDS_H
#define TETRIS_PLAYSOUNDS_H
/// This header contains functions that plays sound when called.
#include <string>

namespace Tetris::Audio
{
    class PlaySound
    {
    private:
        ///@brief Play sound at given filepath
        ///@param filepath: Path to .wav file.
        static void playSound(const std::string &filepath);

    public:
        ///@brief Plays the addPlayer sound.
        static void addPlayerSound();
        /// @brief Plays the clearRow sound.
        static void clearRowSound();

        ///@brief Plays the CloseWindow sound.
        static void closeWindowSound();

        ///@brief Plays the fastSpeed Sound
        static void fastSpeedSound();

        ///@brief Plays the game over sound.
        static void gameOverSound();
        ///@brief Plays the background music.
        static void backgroundMusic();
    };
} /// end namespace tetris::sound

#endif