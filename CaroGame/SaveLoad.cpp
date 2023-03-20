#include "SaveLoad.h"

bool SaveLoad::Save(
    const GameState& data, const std::wstring& name,
    const std::filesystem::path& dir
) {
    auto file = FileHandle::OpenOutFile(dir.generic_wstring() + name);
    if (file.fail()) {
        return false;
    }

    file << data.playerNameOne << '\n';
    file << data.playerScoreOne << '\n';
    file << data.playerTimeOne << '\n';

    file << data.playerNameTwo << '\n';
    file << data.playerScoreTwo << '\n';
    file << data.playerTimeTwo << '\n';

    file << data.gameMode << '\n';
    file << data.aiDifficulty << '\n';

    for (auto& i : data.moveList) {
        file << i.first << ' ' << i.second << '\n';
    }
    return 1;
}

std::optional<GameState> SaveLoad::Load(const std::filesystem::path& filePath) {
    auto file = FileHandle::OpenInFile(filePath);
    if (file.fail()) {
        return std::nullopt;
    }
    GameState data;

    file >> data.playerNameOne;
    if (file.fail()) {
        return std::nullopt;
    }
    
    file >> data.playerScoreOne;
    if (file.fail()) {
        return std::nullopt;
    }
    
    file >> data.playerTimeOne;
    if (file.fail()) {
        return std::nullopt;
    }
    
    file >> data.playerNameTwo;
    if (file.fail()) {
        return std::nullopt;
    }
    
    file >> data.playerScoreTwo;
    if (file.fail()) {
        return std::nullopt;
    }
    
    file >> data.playerTimeTwo;
    if (file.fail()) {
        return std::nullopt;
    }

    file >> data.gameMode;
    if (file.fail()) {
        return std::nullopt;
    }
    
    file >> data.aiDifficulty;
    if (file.fail()) {
        return std::nullopt;
    }
    
    short a, b;
    while (!file.eof()) {
        file >> a >> b;
        if (file.fail()) {
            return std::nullopt;
        }
        data.moveList.emplace_back(a, b);
    }
    
    return data;
}
