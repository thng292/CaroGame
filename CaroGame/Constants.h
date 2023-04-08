#pragma once
#include <filesystem>
#include <string>

//#define LANGUAGE_LABEL_FALLBACK

namespace Constants {
    const std::wstring version = L"1.0.0";

    // Game const
    struct Player {
        short value;
        std::wstring symbol;
    };

    const std::string CURRENT_BGM = "CurrentBGM";
    const std::string TUTORIAL_MODE = "TUTORIAL_MODE";

    const short BOARD_SIZE = 13;
    const short PAGE_SIZE = 10;
    const std::string CURRENT_GAME = "CurrentGame";
    const std::string FINISHED_GAME = "FinishedGame";
    const Player PLAYER_ONE = {1, L"X"};
    const Player PLAYER_TWO = {2, L"O"};
    const int WIN_VALUE_COUNT = 5;

    const short GAME_MODE_PVP = 0;
    const short GAME_MODE_PVE = 1;

    const short GAME_TYPE_NORMAL = 0;
    const short GAME_TYPE_RUSH = 1;

    const char PLAYER_ONE_COLOR = 4;  // RED
    const char PLAYER_TWO_COLOR = 1;  // BLUE

    const char PLAYER_ONE_HIGHLIGHT = 13;  // LIGHT MAGENTA
    const char PLAYER_TWO_HIGHLIGHT = 11;  // LIGHT CYAN

    const char WIN_HIGHLIGHT = 2;  // GREEN

    const short END_GAME_WIN_ONE = 1;
    const short END_GAME_WIN_TWO = 2;
    const short END_GAME_WIN_TIME_ONE = 3;
    const short END_GAME_WIN_TIME_TWO = 4;
    const short END_GAME_DRAW = 5;

    

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

    // Save/Load path
    const std::wstring STR_SAVE_PATH = L"saves/";
    const std::filesystem::path SAVE_PATH = STR_SAVE_PATH;

    // Replay Save/Load path
    const std::wstring STR_REPLAY_PATH = L"replays/";
    const std::filesystem::path REPLAY_PATH = STR_REPLAY_PATH;

    // Theme path
    const std::wstring STR_THEME_PATH = L"themes/";
    const std::filesystem::path THEME_PATH = STR_THEME_PATH;
}  // namespace Constants
