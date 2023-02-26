#include "Audio.h"

Audio::AudioPlayer::AudioPlayer(Song song) {
	currentSong = song;
	mciSendString(
		std::format(
			L"open {} type waveaudio alias {}",
			SongName[int(song)],
			this
		).c_str(),
		0, 0, 0);
}

int Audio::AudioPlayer::Play(bool fromStart, bool repeat) {
	isRepeat = repeat;
	auto command = std::format(
		L"play {}", this
	);
	if (fromStart) {
		command += L" from 0";
	}
	if (repeat) {
		command += L" repeat";
	}
	return mciSendString(command.c_str(), 0, 0, 0);
}

int Audio::AudioPlayer::Pause() {
	return mciSendString(std::format(L"pause {}", this).c_str(), 0, 0, 0);
}

int Audio::AudioPlayer::Resume() {
	return mciSendString(std::format(L"resume {}", this).c_str(), 0, 0, 0);
}


int Audio::AudioPlayer::Stop() {
	return mciSendString(std::format(L"stop {}", this).c_str(), 0, 0, 0);
}
Audio::AudioPlayer::~AudioPlayer() {
	mciSendString(std::format(L"close {}", this).c_str(), 0, 0, 0);
}
