#pragma once
#include <string>
#include <filesystem>

namespace Constants {
	const std::string version = "0.1.0";

	// AI const
	const int PLAYER_AI = -1, PLAYER_HUMAN = 1;
	const std::string PLAYER_HUMAN_STRING = "X", PLAYER_AI_STRING = "O";
	const int WIN_VALUE_COUNT = 5;
	const int INF = 1000, NULL_VALUE = -5;
	const int MAX_SCORE = 100;
	const int WIN_SCORE_THRESHOLD = 32;
	const int LOOKUP_RANGE = 3;
	const int DEPTH = 3;

	const int BOARD_SIZE = 10;


	// Asset path
	const std::string STR_ASSET_PATH = "asset/";
	const std::string STR_AUDIO_PATH = STR_ASSET_PATH + "audio/";
	const std::string STR_LANGUAGE_PATH = STR_ASSET_PATH + "language/";

	const std::filesystem::path ASSET_PATH(STR_ASSET_PATH);
	const std::filesystem::path AUDIO_PATH(STR_AUDIO_PATH);
	const std::filesystem::path LANGUAGE_PATH(STR_LANGUAGE_PATH);


	// User config path
	const std::string STR_USERCONFIG_PATH = "config/";
	const std::string STR_USERCONFIG_FILENAME = "user_config.txt";
	const std::filesystem::path USERCONFIG_PATH = STR_USERCONFIG_PATH + STR_USERCONFIG_FILENAME;

	// Error
	const std::wstring STR_ERROR_CANNOT_FIND_LABEL = L"Cannot find";
	
}
