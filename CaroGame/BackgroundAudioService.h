#pragma once

#include "Audio.h"

static class BackgroundAudioService {
    static Audio::AudioPlayer player;

   public:
    BackgroundAudioService() = delete;

    static inline int ChangeSong(Audio::Sound song)
    {
        player.Close();
        return player.Open(song);
    }

    static inline int Pause() { return player.Pause(); }

    static inline int Resume() { return player.Resume(); }

    static inline int Stop() { return player.Stop(); }

    static inline int Play(bool fromStart = 0, bool repeat = 1)
    {
        return player.Play(fromStart, repeat);
    }

    static inline Audio::Sound GetCurrentSong() { return player.getCurrentSong(); }

};