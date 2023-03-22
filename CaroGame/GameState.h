#pragma once
#include <string>
#include <vector>

struct GameState {
    std::vector<std::pair<short, short>> moveList;

    short playerTimeOne = 0;

    short playerTimeTwo = 0;

    short playerScoreOne = 0;

    short playerScoreTwo = 0;

    std::wstring playerNameOne;

    std::wstring playerNameTwo;

    short gameType = 0;

    short gameMode = 0;

    short aiDifficulty = 0;

    bool whosFirst = 1;

    short avatarId = 0;
};