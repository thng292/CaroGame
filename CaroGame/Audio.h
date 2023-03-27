#pragma once
#include <Windows.h>
#include <wchar.h>

#include <array>
#include <format>

#include "Constants.h"
#pragma comment(lib, "Winmm.lib")

namespace Audio {

    enum class Sound : char { NoSound, OnKey, Draw, Win, Lose, MenuBGM, GameBGM };

    class AudioPlayer {
       private:
        static constexpr std::array SoundName{
            L"",
            L"Key.wav",
            L"Draw.mp3",
            L"Win.mp3",
            L"Lose.wav",
            L"MenuBGM.mp3",
            L"GameBGM.mp3"};
        bool isPlaying = 0;
        bool hasStopped = 1;
        bool isRepeat = 0;
        Sound currentSong = Sound::NoSound;
        static int instanceCount;
        int currentInstance;

       public:
        AudioPlayer(AudioPlayer&&) = delete;
        AudioPlayer(const AudioPlayer&) = delete;
        AudioPlayer& operator=(AudioPlayer&&) = delete;
        AudioPlayer& operator=(const AudioPlayer&) = delete;

        AudioPlayer() {}

        inline AudioPlayer(Sound song) { Open(song); }

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

        inline Sound getCurrentSong() { return currentSong; }

        inline int Play(bool fromStart = true, bool repeat = false)
        {
            isRepeat = repeat;
            auto command = std::format(L"play {}", currentInstance);
            if (fromStart) {
                command += L" from 0";
            }
            if (repeat) {
                command += L" repeat";
            }
            return mciSendString(command.c_str(), 0, 0, 0);
        }

        inline int Pause()
        {
            return mciSendString(
                std::format(L"pause {}", currentInstance).c_str(), 0, 0, 0
            );
        }

        inline int Resume()
        {
            return mciSendString(
                std::format(L"resume {}", currentInstance).c_str(), 0, 0, 0
            );
        }

        inline int Stop()
        {
            return mciSendString(
                std::format(L"stop {}", currentInstance).c_str(), 0, 0, 0
            );
        }

        inline ~AudioPlayer()
        {
            mciSendString(
                std::format(L"close {}", currentInstance).c_str(), 0, 0, 0
            );
        }
    };
}  // namespace Audio