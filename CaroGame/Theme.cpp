#include "Theme.h"

std::wstring Theme::currentThemeName = L"Default";

std::array<View::Color, 21> Theme::CurrentTheme{
    View::Color::BLACK,         View::Color::BLACK,
    View::Color::BRIGHT_WHITE,  View::Color::BLACK,
    View::Color::BRIGHT_WHITE,  View::Color::BLACK,
    View::Color::RED,           View::Color::BLUE,
    View::Color::LIGHT_MAGENTA, View::Color::LIGHT_CYAN,
    View::Color::LIGHT_GREEN,   View::Color::BLUE,
    View::Color::RED,           View::Color::YELLOW,
    View::Color::GREEN,         View::Color::YELLOW,
    View::Color::MAGENTA,       View::Color::GRAY,
    View::Color::BLACK,         View::Color::BLUE,
    View::Color::RED};

std::array<View::Color, 21> Theme::defaultTheme = Theme::CurrentTheme;

void Theme::LoadDefaultTheme()
{
    CurrentTheme = defaultTheme;
    currentThemeName = L"Default";
}

bool Theme::LoadTheme(std::filesystem::path themePath)
{
    auto fin = FileHandle::OpenInFile(themePath);
    if (fin.fail()) {
        return false;
    }
    currentThemeName = themePath.filename();
    std::wstring inp;
    View::Color readColor = View::Color::BLACK;
    while (!fin.fail() || !fin.eof()) {
        std::getline(fin, inp);
        auto tmp = Utils::LineSplitter(inp);
        Utils::trim(tmp.first);
        Utils::trim(tmp.second);
        try {
            readColor = View::Color(std::stoi(tmp.second));
        } catch (std::invalid_argument) {
            continue;
        }
        if (tmp.first == L"TITLE_TEXT_COLOR") {
            CurrentTheme[0] = readColor;
        } else if (tmp.first == L"TEXT_COLOR") {
            CurrentTheme[1] = readColor;
        } else if (tmp.first == L"TEXT_HIGHLIGHT_COLOR") {
            CurrentTheme[2] = readColor;
        } else if (tmp.first == L"BORDER_COLOR") {
            CurrentTheme[3] = readColor;
        // } else if (tmp.first == L"CONSOLE_COLOR") {
        //     CurrentTheme[4] = readColor;
        } else if (tmp.first == L"CONSOLE_HIGHLIGHT_COLOR") {
            CurrentTheme[5] = readColor;
        } else if (tmp.first == L"PLAYER_ONE_COLOR") {
            CurrentTheme[6] = readColor;
        } else if (tmp.first == L"PLAYER_TWO_COLOR") {
            CurrentTheme[7] = readColor;
        } else if (tmp.first == L"PLAYER_ONE_HIGHLIGHT_COLOR") {
            CurrentTheme[8] = readColor;
        } else if (tmp.first == L"PLAYER_TWO_HIGHLIGHT_COLOR") {
            CurrentTheme[9] = readColor;
        } else if (tmp.first == L"AI_EASY_COLOR") {
            CurrentTheme[10] = readColor;
        } else if (tmp.first == L"AI_NORMAL_COLOR") {
            CurrentTheme[11] = readColor;
        } else if (tmp.first == L"AI_HARD_COLOR") {
            CurrentTheme[12] = readColor;
        } else if (tmp.first == L"RESULT_TEXT_COLOR") {
            CurrentTheme[13] = readColor;
        } else if (tmp.first == L"WIN_HIGHLIGHT_COLOR") {
            CurrentTheme[14] = readColor;
        } else if (tmp.first == L"HINT_COLOR") {
            CurrentTheme[15] = readColor;
        } else if (tmp.first == L"WARNING_COLOR") {
            CurrentTheme[16] = readColor;
        } else if (tmp.first == L"GHOST_MOVE_COLOR") {
            CurrentTheme[17] = readColor;
        } else if (tmp.first == L"CURSOR_COLOR") {
            CurrentTheme[18] = readColor;
        } else if (tmp.first == L"SWITCH_ON") {
            CurrentTheme[19] = readColor;
        } else if (tmp.first == L"SWITCH_OFF") {
            CurrentTheme[20] = readColor;
        }
    }
    return true;
}

bool Theme::LoadThemeOrDefault(std::filesystem::path themePath)
{
    if (LoadTheme(themePath)) {
        return true;
    } else {
        LoadDefaultTheme();
        return false;
    }
}
