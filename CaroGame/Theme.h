#pragma once
#include <array>
#include <filesystem>
#include <memory>
#include <mutex>
#include <string>

#include "FileHandle.h"
#include "Constants.h"
#include "Utils.h"

namespace View {
    enum class Color : char {
        BLACK = 0,
        BLUE = 1,
        GREEN = 2,
        CYAN = 3,
        RED = 4,
        MAGENTA = 5,
        YELLOW = 6,
        WHITE = 7,
        GRAY = 8,
        LIGHT_BLUE = 9,
        LIGHT_GREEN = 10,
        LIGHT_CYAN = 11,
        LIGHT_RED = 12,
        LIGHT_MAGENTA = 13,
        LIGHT_YELLOW = 14,
        BRIGHT_WHITE = 15
    };
}
enum class ThemeColor : char {
    TITLE_TEXT_COLOR = 0,
    TEXT_COLOR,
    TEXT_HIGHLIGHT_COLOR,
    BORDER_COLOR,
    CONSOLE_COLOR,
    CONSOLE_HIGHLIGHT_COLOR,
    PLAYER_ONE_COLOR,
    PLAYER_TWO_COLOR,
    PLAYER_ONE_HIGHLIGHT_COLOR,
    PLAYER_TWO_HIGHLIGHT_COLOR,
    AI_EASY_COLOR,
    AI_NORMAL_COLOR,
    AI_HARD_COLOR,
    RESULT_TEXT_COLOR,
    WIN_HIGHLIGHT_COLOR,
    HINT_COLOR,
    WARNING_COLOR,
    GHOST_MOVE_COLOR,
    CURSOR_COLOR,
    SWITCH_ON,
    SWITCH_OFF
};

class Theme {
    static std::array<View::Color, 21> CurrentTheme;
    static std::array<View::Color, 21> defaultTheme;
    static std::wstring currentThemeName;

   public:
    Theme() = delete;
    static inline short GetScreenAttribute()
    {
        return (int(CurrentTheme[int(ThemeColor::CONSOLE_COLOR)]) << 4) |
               int(CurrentTheme[int(ThemeColor::TEXT_COLOR)]);
    }

    static inline View::Color GetColor(ThemeColor id)
    {
        return CurrentTheme[int(id)];
    }

    static void LoadDefaultTheme();

    static bool LoadTheme(std::filesystem::path themePath);

    static bool LoadThemeOrDefault(std::filesystem::path themePath);

    static inline std::wstring GetCurrentThemeName() {
        return currentThemeName;
    }

    static inline std::vector<FileHandle::FileDetail> DiscoverThemeFiles() {
        return FileHandle::GetAllTextFileInDir(Constants::THEME_PATH);
    }
};