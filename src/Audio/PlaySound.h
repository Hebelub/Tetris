#ifndef TETRIS_PLAYSOUND_H
#define TETRIS_PLAYSOUND_H

#include <string>
#include <unordered_map>
#include <SFML/Audio.hpp>

/// This header contains functions that plays sound when called.
namespace Tetris::Audio
{
    enum class MusicId
    {
        HappyTheme
    };

    enum class SoundId
    {
        AddPlayer,
        ClearRow,
        CloseWindow,
        InstantFall,
        GameOver,

        FourLines,
        Rotate,
        ToggleSound,
        Trick,
        CantRotate,

        Count /// <--- Keep at bottom
    };

    class PlaySound
    {
    private:
        struct Sound
        {
            sf::SoundBuffer soundBuffer{};
            sf::Sound sound{};
        };

    public:
        static void loadAllAudio();

        static void stopAllPlayingSounds();
        static void stopAllPlayingMusics();

        ///@param SoundId: is an enum class
        static void playSound(SoundId sound);

        ///@param MusicId: is an enum class
        static void playMusic(MusicId music);

        static inline bool isMusicOn() { return musicOn; }
        static inline bool isSoundOn() { return soundOn; }

        static inline void turnMusicOn() { musicOn = true; }
        static inline void turnMusicOff() { musicOn = false; stopAllPlayingMusics(); }

        static inline void turnSoundOn() { soundOn = true; }
        static inline void turnSoundOff() { soundOn = false; stopAllPlayingSounds(); }

    private:
        static inline bool musicOn{true};
        static inline bool soundOn{true};

        static inline std::unordered_map<SoundId, Sound> s_sounds{};
        static inline std::unordered_map<MusicId, std::unique_ptr<sf::Music>> s_musics{};

        static void loadSound(const std::string &filePath, SoundId soundId);

        static void loadMusic(const std::string &filePath, MusicId musicId);
    };
} /// end namespace tetris::sound

#endif