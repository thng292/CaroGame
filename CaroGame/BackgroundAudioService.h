#pragma once
#include <memory>
#include <mutex>

#include "Audio.h"

using Audio::AudioPlayer;
using Audio::Sound;

class BackgroundAudioService {
    static std::mutex locker;
    std::unique_ptr<AudioPlayer> player;
    static std::unique_ptr<BackgroundAudioService> singletonInstance;

   public:
    static BackgroundAudioService* getInstance()
    {
        locker.lock();
        if (singletonInstance == nullptr) {
            singletonInstance = std::make_unique<BackgroundAudioService>();
        }
        locker.unlock();
        return singletonInstance.get();
    }

    AudioPlayer* getPlayer() { return player.get(); }

    void ChangeSong(Sound song)
    {
        if (player != nullptr) {
            player->Stop();
        }
        player = std::make_unique<AudioPlayer>(song);
    }
};
