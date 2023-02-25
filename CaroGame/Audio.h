#pragma once
#include <wchar.h>
#include <array>
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

	void Play(Song song);
}