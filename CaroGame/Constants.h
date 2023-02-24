#pragma once
#include <string>
#include <filesystem>

namespace Constants {
	const std::string version = "0.1.0";

	// AI const
	const int PLAYER_AI = -1, PLAYER_HUMAN = 1;
	const int WIN_VALUE_COUNT = 3;
	const int INF = 1000, NULL_VALUE = -5;


	// Asset path
	const std::string STR_ASSET_PATH = "asset/";
	const std::string STR_AUDIO_PATH = STR_ASSET_PATH + "audio/";
	const std::string STR_LANGUAGE_PATH = STR_ASSET_PATH + "language/";

	const std::filesystem::path ASSET_PATH(STR_ASSET_PATH);
	const std::filesystem::path AUDIO_PATH(STR_AUDIO_PATH);
	const std::filesystem::path LANGUAGE_PATH(STR_LANGUAGE_PATH);


	// User config path

	// Error
	const std::wstring STR_ERROR_CANNOT_FIND_LABEL = L"Cannot find";
	
}
