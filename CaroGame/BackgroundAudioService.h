#pragma once
#include <memory>
#include <mutex>

#include "Audio.h"

namespace BackgroundAudioService {
    extern Audio::AudioPlayer player;

    inline int ChangeSong(Audio::Sound song)
    {
        player.Close();
        return player.Open(song);
    }

    inline int Pause() { return player.Pause(); }

    inline int Resume() { return player.Resume(); }

    inline int Stop() { return player.Stop(); }

    inline int Play(bool fromStart = 0, bool repeat = 1)
    {
        return player.Play(fromStart, repeat);
    }

    inline Audio::Sound GetCurrentSong() { return player.getCurrentSong(); }

};  // namespace BackgroundAudioService
