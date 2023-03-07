#pragma once
#include <vector>
#include <string>

struct GameState {
	std::vector<std::pair<short, short>>moveList;
	short playerTimeOne = 0;
	short playerTimeTwo = 0;
	short playerScoreOne = 0;
	short playerScoreTwo = 0;
	std::wstring playerNameOne;
	std::wstring playerNameTwo;
	short gameMode = 0;
	short aiDifficulty = 0;
};