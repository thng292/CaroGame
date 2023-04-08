#pragma once
#include <Windows.h>
#include <wchar.h>

#include <array>
#include <format>

#include "Constants.h"
#pragma comment(lib, "Winmm.lib")

namespace Audio {

    enum class Sound : char {
        NoSound = 0,
        OnKey,
        Draw,
        Win,
        Lose,
        MenuBGM,
        MenuMove,
        MenuSelect,
        GameBGM,
        GameMove,
        GamePlace,
        GameStart,
        Pause
    };
    constexpr std::array SoundName{
        L"",
        L"Key.wav",
        L"Draw.mp3",
        L"Win.mp3",
        L"Lose.mp3",
        L"MenuBGM.mp3",
        L"MenuMove.wav",
        L"MenuSelect.wav",
        L"GameBGM.mp3",
        L"GameMove.wav",
        L"GamePlaceMove.mp3",
        L"GameStart.wav",
        L"Pause.wav"};

    class AudioPlayer {
       private:
        bool isPlaying = 0;
        bool hasStopped = 1;
        Sound currentSong = Sound::NoSound;
        static int instanceCount;
        int currentInstance;

       public:
        AudioPlayer(AudioPlayer&&) = delete;
        AudioPlayer(const AudioPlayer&) = delete;
        AudioPlayer& operator=(AudioPlayer&&) = delete;
        AudioPlayer& operator=(const AudioPlayer&) = delete;

        inline AudioPlayer()
        {
            currentSong = Sound::NoSound;
        }

        inline AudioPlayer(Sound song)
        {
            Open(song);
        }

        inline int Open(Sound song)
        {
            currentInstance = instanceCount++;
            currentSong = song;
            if (song == Sound::NoSound) {
                return 0;
            }
            auto tmp = SoundName[int(song)];
            auto command = std::format(
                L"open {}{} type {} alias {}",
                Constants::STR_AUDIO_PATH,
                tmp,
                L"waveaudio",
                currentInstance
            );
            if (tmp[std::wcslen(tmp) - 1] == L'3') {
                command = std::format(
                    L"open {}{} type {} alias {}",
                    Constants::STR_AUDIO_PATH,
                    tmp,
                    L"mpegvideo",
                    currentInstance
                );
            }
            return mciSendString(command.c_str(), 0, 0, 0);
        }

        inline Sound getCurrentSong() const { return currentSong; }

        inline int Play(bool fromStart = true, bool repeat = false) const
        {
            auto command = std::format(L"play {}", currentInstance);
            if (fromStart) {
                command += L" from 0";
            }
            if (repeat) {
                command += L" repeat";
            }
            return mciSendString(command.c_str(), 0, 0, 0);
        }

        inline int Pause() const
        {
            return mciSendString(
                std::format(L"pause {}", currentInstance).c_str(), 0, 0, 0
            );
        }

        inline int Resume() const
        {
            return mciSendString(
                std::format(L"resume {}", currentInstance).c_str(), 0, 0, 0
            );
        }

        inline int Stop() const
        {
            return mciSendString(
                std::format(L"stop {}", currentInstance).c_str(), 0, 0, 0
            );
        }

        inline int Close()
        {
            return mciSendString(
                std::format(L"close {}", currentInstance).c_str(), 0, 0, 0
            );
        }

        inline ~AudioPlayer() { Close(); }
    };

    inline bool PlayAndForget(Sound sound, bool wait = 0)
    {
        return PlaySound(
            std::format(
                L"{}{}", Constants::STR_AUDIO_PATH, SoundName[int(sound)]
            )
                .c_str(),
            0,
            (wait ? SND_SYNC : SND_ASYNC) | SND_FILENAME
        );
    }

}  // namespace Audio