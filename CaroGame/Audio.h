#pragma once
#include <wchar.h>
#include <format>
#include <Windows.h>
#include <array>
#include "Constants.h"
#pragma comment(lib, "Winmm.lib")

// To be changed
namespace Audio {
	static const std::array<std::wstring, 2> SoundName = { 
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
		inline AudioPlayer(Sound song) {
			currentInstance = instanceCount++;
			currentSong = song;
			mciSendString(
				std::format(
					L"open {}{} type waveaudio alias {}",
					Constants::STR_AUDIO_PATH,
					SoundName[int(song)],
					currentInstance
				).c_str(),
				0, 0, 0);
		}

		inline int Play(bool fromStart = true, bool repeat = false) {
			isRepeat = repeat;
			auto command = std::format(
				L"play {}", currentInstance
			);
			if (fromStart) {
				command += L" from 0";
			}
			if (repeat) {
				command += L" repeat";
			}
			return mciSendString(command.c_str(), 0, 0, 0);
		}

		inline int Pause() {
			return mciSendString(std::format(L"pause {}", currentInstance).c_str(), 0, 0, 0);
		}

		inline int Resume() {
			return mciSendString(std::format(L"resume {}", currentInstance).c_str(), 0, 0, 0);
		}


		inline int Stop() {
			return mciSendString(std::format(L"stop {}", currentInstance).c_str(), 0, 0, 0);
		}
		inline ~AudioPlayer() {
			mciSendString(std::format(L"close {}", currentInstance).c_str(), 0, 0, 0);
		}

	};
}