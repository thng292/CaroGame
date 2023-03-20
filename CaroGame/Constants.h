#pragma once
#include <filesystem>
#include <string>

namespace Constants {
    const std::wstring version = L"0.1.0";


	//Game const
	struct Player {
		short value;
		std::wstring symbol;
	};
	const short BOARD_SIZE = 13;
	const short PAGE_SIZE = 10;
	const std::string CURRENT_GAME = "CurrentGame";
	const Player PLAYER_ONE = { 1, L"X" };
	const Player PLAYER_TWO = { 2, L"O" };
	const int WIN_VALUE_COUNT = 5;

	// AI const


	// Asset path
	const std::wstring STR_ASSET_PATH = L"asset/";
	const std::wstring STR_AUDIO_PATH = STR_ASSET_PATH + L"audio/";
	const std::wstring STR_LANGUAGE_PATH = STR_ASSET_PATH + L"language/";

    const std::filesystem::path ASSET_PATH(STR_ASSET_PATH);
    const std::filesystem::path AUDIO_PATH(STR_AUDIO_PATH);
    const std::filesystem::path LANGUAGE_PATH(STR_LANGUAGE_PATH);

    // User config path
    const std::wstring STR_USERCONFIG_PATH = L"config/";
    const std::wstring STR_USERCONFIG_FILENAME = L"user_config";
    const std::filesystem::path USERCONFIG_FILE_PATH =
        STR_USERCONFIG_PATH + STR_USERCONFIG_FILENAME;

    // User config path
    const std::wstring STR_SAVE_PATH = L"saves/";
    const std::filesystem::path SAVE_PATH = STR_SAVE_PATH;
}  // namespace Constants
