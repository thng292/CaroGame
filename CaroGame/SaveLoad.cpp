#include "SaveLoad.h"

bool SaveLoad::Save(
    const GameState& data,
    const std::wstring& name,
    const std::filesystem::path& dir
)
{
    auto file = FileHandle::OpenOutFile(dir.generic_wstring() + name);
    if (file.fail()) {
        return false;
    }
    file << data.playerNameOne << '\n';
    file << data.playerScoreOne << '\n';
    file << data.playerTimeOne << '\n';
    file << data.playerAvatarOne << '\n';

    file << data.playerNameTwo << '\n';
    file << data.playerScoreTwo << '\n';
    file << data.playerTimeTwo << '\n';
    file << data.playerAvatarTwo << '\n';

    file << data.gameMode << '\n';
    file << data.aiDifficulty << '\n';
    file << data.playerOneFirst << '\n';

    file << data.gameTime << '\n';
    file << data.gameEnd << '\n';

    for (auto& i : data.moveList) {
        file << i.first << ' ' << i.second << '\n';
    }

    if (file.fail()) {
        std::filesystem::remove(dir.generic_wstring() + name);
    }

    return !file.fail();
}

std::optional<GameState> SaveLoad::Load(const std::filesystem::path& filePath)
{
    auto file = FileHandle::OpenInFile(filePath);
    GameState data;
    file >> data.playerNameOne;
    file >> data.playerScoreOne;
    file >> data.playerTimeOne;
    file >> data.playerAvatarOne;

    file >> data.playerNameTwo;
    file >> data.playerScoreTwo;
    file >> data.playerTimeTwo;
    file >> data.playerAvatarTwo;

    file >> data.gameMode;
    file >> data.aiDifficulty;
    file >> data.playerOneFirst;

    file >> data.gameTime;

    file >> data.gameEnd;

    if (file.fail()) {
        return std::nullopt;
    }

    short a, b;
    while (!file.eof()) {
        file >> a >> b;
        if (file.eof()) break;
        if (file.fail() && !file.eof()) {
            return std::nullopt;
        }
        data.moveList.emplace_back(a, b);
    }
    return data;
}
