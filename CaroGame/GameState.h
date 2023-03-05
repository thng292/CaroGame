#pragma once
#include <vector>
#include <string>

struct GameState {
	std::vector<std::pair<short, short>>moveList;
	short playerTimeOne, playerTimeTwo;
	short playerScoreOne, playerScoreTwo;
	std::wstring playerNameOne, playerNameTwo;
	short gameMode;
	short aiDifficulty;
};