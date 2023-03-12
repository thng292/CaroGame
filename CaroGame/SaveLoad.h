#pragma once
#include "GameState.h"
#include "FileHandle.h"
#include "Constants.h"

namespace SaveLoad {
	bool Save(
		const GameState& data, 
		const std::wstring& name, 
		const std::filesystem::path& dir = Constants::SAVE_PATH
	);

	std::optional<GameState> Load(
		const std::filesystem::path& filePath
	);

	inline std::optional<GameState> Load(
		const std::wstring& name,
		const std::filesystem::path& dir = Constants::SAVE_PATH
	) {
		return Load(dir.generic_wstring() + name);
	}

	inline std::vector<FileHandle::FileDetail>
	DiscoverSaveFiles(
		const std::filesystem::path& dir = Constants::SAVE_PATH
	) {
		return FileHandle::GetAllTextFileInDir(dir);
	}
};

