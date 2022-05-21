#include "PlaySound.h"
#include <string>
#include <SFML/Audio.hpp>


namespace Tetris::Audio
{
    void PlaySound::loadAllAudio()
    {
       loadSound("Assets/Sounds/addPlayer.ogg", SoundId::AddPlayer);
       loadSound("Assets/Sounds/clearRow.ogg", SoundId::ClearRow);
       loadSound("Assets/Sounds/closeWindow.ogg", SoundId::CloseWindow);
       loadSound("Assets/Sounds/fastSpeed.ogg", SoundId::InstantFall);
       loadSound("Assets/Sounds/gameOver.ogg", SoundId::GameOver);
       loadSound("Assets/Sounds/fourLines.ogg", SoundId::FourLines);
       loadSound("Assets/Sounds/rotate.ogg", SoundId::Rotate);
       loadSound("Assets/Sounds/toggleSound.ogg", SoundId::ToggleSound);
       loadSound("Assets/Sounds/trick.ogg", SoundId::Trick);
       loadSound("Assets/Sounds/canNotRotate.ogg", SoundId::CantRotate);

       loadMusic("Assets/Sounds/happyTheme.ogg", MusicId::HappyTheme);
    }

    void PlaySound::playSound(Audio::SoundId sound)
    {
        if (soundOn) s_sounds.at(sound).sound.play();
    }

    void PlaySound::loadSound(const std::string &filePath, SoundId soundId)
    {
        Sound sound{};
        s_sounds.insert({soundId, sound});
        s_sounds.at(soundId).soundBuffer.loadFromFile(filePath);
        s_sounds.at(soundId).sound.setBuffer(s_sounds.at(soundId).soundBuffer);
    }

    void PlaySound::playMusic(MusicId music)
    {
        if (musicOn) s_musics.at(music)->play();
    }

    void PlaySound::loadMusic(const std::string &filePath, MusicId musicId)
    {
        s_musics.insert({musicId, std::make_unique<sf::Music>()});
        s_musics.at(musicId)->openFromFile(filePath);
        s_musics.at(musicId)->setLoop(true);
        s_musics.at(musicId)->setVolume(10.33f);
    }

    void PlaySound::stopAllPlayingSounds()
    {
        for (auto &[_, sound] : s_sounds)
        {
            sound.sound.stop();
        }
    }

    void PlaySound::stopAllPlayingMusics()
    {
        for (auto &[_, music] : s_musics)
        {
            music->stop();
        }
    }

} // Tetris::Audio
