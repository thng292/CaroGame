#pragma once
#include <wchar.h>
#include <format>
#include <Windows.h>
#pragma comment(lib, "Winmm.lib")

// To be changed
namespace Audio {
	const wchar_t* SongName[] = {
		L".wav",
		L".wav"
	};

	enum class Song : char {
		BackgroundMusic = 1,
	};

	class AudioPlayer {
	private:
		bool isPlaying = 0;
		bool hasStopped = 1;
		bool isRepeat = 0;
		Song currentSong;
	public:
		AudioPlayer(Song song);
		int Play(bool fromStart = true, bool repeat = false);
		int Pause();
		int Resume();
		int Stop();
		~AudioPlayer();
	};
}