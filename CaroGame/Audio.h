#pragma once
#include <Windows.h>
#include <wchar.h>

#include <array>
#include <format>

#include "Constants.h"
#pragma comment(lib, "Winmm.lib")

namespace Audio {
    static constexpr std::array SoundName{
        L"Key.wav",
        L"Draw.mp3",
        L"Win.mp3",
        L"Lose.wav",
        L"MenuBGM.mp3",
        L"GameBGM.mp3"};

    enum class Sound : char { OnKey, Draw, Win, Lose, MenuBGM, GameBGM };

    class AudioPlayer {
       private:
        bool isPlaying = 0;
        bool hasStopped = 1;
        bool isRepeat = 0;
        Sound currentSong;
        static int instanceCount;
        int currentInstance;

       public:
        AudioPlayer() { currentInstance = instanceCount++; }

        inline AudioPlayer(Sound song)
        {
            currentInstance = instanceCount++;
            Open(song);
        }

        inline int Open(Sound song)
        {
            currentSong = song;
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