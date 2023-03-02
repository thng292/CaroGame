#include "Audio.h"

int Audio::AudioPlayer::instanceCount = 0;

Audio::AudioPlayer::AudioPlayer(Sound song) {
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

int Audio::AudioPlayer::Play(bool fromStart, bool repeat) {
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

int Audio::AudioPlayer::Pause() {
	return mciSendString(std::format(L"pause {}", currentInstance).c_str(), 0, 0, 0);
}

int Audio::AudioPlayer::Resume() {
	return mciSendString(std::format(L"resume {}", currentInstance).c_str(), 0, 0, 0);
}


int Audio::AudioPlayer::Stop() {
	return mciSendString(std::format(L"stop {}", currentInstance).c_str(), 0, 0, 0);
}
Audio::AudioPlayer::~AudioPlayer() {
	mciSendString(std::format(L"close {}", currentInstance).c_str(), 0, 0, 0);
}
