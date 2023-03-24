#pragma once
#include <mutex>

#include "Audio.h"

using Audio::AudioPlayer;
using Audio::Sound;

class BackgroundAudioService {
    static std::mutex locker;
    AudioPlayer player;
    static BackgroundAudioService* singletonInstance;

    static BackgroundAudioService* getInstance()
    {
        locker.lock();
        if (singletonInstance == nullptr) {
            singletonInstance = new BackgroundAudioService();
        }
        locker.unlock();
        return singletonInstance;
    }

    const AudioPlayer& getPlayer() { return player; }

    void ChangeSong(Sound song)
    {
        player.Stop();
        player = AudioPlayer(song);
    }
};
