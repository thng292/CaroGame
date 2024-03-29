#pragma once
#include <algorithm>

#include "Constants.h"
#include "FileHandle.h"
#include "GameState.h"

namespace SaveLoad {
    bool Save(
        const GameState& data,
        const std::wstring& name,
        const std::filesystem::path& dir = Constants::SAVE_PATH
    );

    std::optional<GameState> Load(const std::filesystem::path& filePath);

    inline std::vector<FileHandle::FileDetail> DiscoverSaveFiles(
        const std::filesystem::path& dir = Constants::SAVE_PATH
    )
    {
        return FileHandle::GetAllTextFileInDir(dir);
    }
};  // namespace SaveLoad
