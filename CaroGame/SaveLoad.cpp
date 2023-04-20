#include "SaveLoad.h"

static constexpr int buffSize = 11;

bool SaveLoad::Save(
    const GameState& data,
    const std::wstring& name,
    const std::filesystem::path& dir
)
{
    std::ofstream file(
        dir.generic_wstring() + name, std::ios::out | std::ios::binary
    );
    if (file.fail()) {
        return false;
    }
    wchar_t buff[buffSize] = {0};

    memcpy_s(
        buff,
        sizeof(buff),
        data.playerNameOne.c_str(),
        data.playerNameOne.size() * sizeof(wchar_t)
    );

    file.write((char*)buff, sizeof(buff));
    file.write((char*)&data.playerScoreOne, sizeof(data.playerScoreOne));
    file.write((char*)&data.playerTimeOne, sizeof(data.playerTimeOne));
    file.write((char*)&data.playerAvatarOne, sizeof(data.playerAvatarOne));

    memset(buff, 0, sizeof(buff));
    memcpy_s(
        buff,
        sizeof(buff),
        data.playerNameTwo.c_str(),
        data.playerNameTwo.size() * sizeof(wchar_t)
    );
    file.write((char*)buff, sizeof(buff));
    file.write((char*)&data.playerScoreTwo, sizeof(data.playerScoreTwo));
    file.write((char*)&data.playerTimeTwo, sizeof(data.playerTimeTwo));
    file.write((char*)&data.playerAvatarTwo, sizeof(data.playerAvatarTwo));

    file.write((char*)&data.gameMode, sizeof(data.gameMode));
    file.write((char*)&data.aiDifficulty, sizeof(data.aiDifficulty));
    file.write((char*)&data.playerOneFirst, sizeof(data.playerOneFirst));
    file.write((char*)&data.gameTime, sizeof(data.gameTime));
    file.write((char*)&data.gameEnd, sizeof(data.gameEnd));

    for (auto& i : data.moveList) {
        file.write((char*)&i.first, sizeof(i.first));
        file.write((char*)&i.second, sizeof(i.second));
    }

    if (file.fail()) {
        std::filesystem::remove(dir.generic_wstring() + name);
    }

    return !file.fail();
}

std::optional<GameState> SaveLoad::Load(const std::filesystem::path& filePath)
{
    std::ifstream file(filePath, std::ios::in | std::ios::binary);
    GameState data;
    wchar_t buff[buffSize] = {0};
    
    file.read((char*)buff, sizeof(buff));
    data.playerNameOne = std::wstring(buff);
    file.read((char*)&data.playerScoreOne, sizeof(data.playerScoreOne));
    file.read((char*)&data.playerTimeOne, sizeof(data.playerTimeOne));
    file.read((char*)&data.playerAvatarOne, sizeof(data.playerAvatarOne));

    memset(buff, 0, sizeof(buff));
    file.read((char*)buff, sizeof(buff));
    data.playerNameTwo = std::wstring(buff);
    file.read((char*)&data.playerScoreTwo, sizeof(data.playerScoreTwo));
    file.read((char*)&data.playerTimeTwo, sizeof(data.playerTimeTwo));
    file.read((char*)&data.playerAvatarTwo, sizeof(data.playerAvatarTwo));

    file.read((char*)&data.gameMode, sizeof(data.gameMode));
    file.read((char*)&data.aiDifficulty, sizeof(data.aiDifficulty));
    file.read((char*)&data.playerOneFirst, sizeof(data.playerOneFirst));
    file.read((char*)&data.gameTime, sizeof(data.gameTime));
    file.read((char*)&data.gameEnd, sizeof(data.gameEnd));

    short a = 0, b = 0;
    while (!file.fail()) {
        file.read((char*)&a, sizeof(a));
        file.read((char*)&b, sizeof(b));
        if (file.eof()) break;
        data.moveList.emplace_back(a, b);
    }

    if (file.fail() && !file.eof()) {
        return std::nullopt;
    }

    return data;
}
