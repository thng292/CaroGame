#pragma once
#include <wchar.h>
#include <format>
#include <Windows.h>
#include "Constants.h"
#pragma comment(lib, "Winmm.lib")

// To be changed
namespace Audio {
	static const wchar_t* SoundName[] = {
		L".wav",
		L"onKey.wav"
	};

	enum class Sound : char {
		BackgroundMusic,
		OnKey
	};

	class AudioPlayer {
	private:
		bool isPlaying = 0;
		bool hasStopped = 1;
		bool isRepeat = 0;
		Sound currentSong;
		static int instanceCount;
		int currentInstance;
	public:
		AudioPlayer(Sound song);
		int Play(bool fromStart = true, bool repeat = false);
		int Pause();
		int Resume();
		int Stop();
		~AudioPlayer();
	};
}