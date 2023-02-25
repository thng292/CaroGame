#include "Audio.h"

void Audio::Play(Song song) {
	PlaySound(Audio::SongName[char(song)], NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}