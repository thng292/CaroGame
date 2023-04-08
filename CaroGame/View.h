#pragma once
#include <Windows.h>
#include <fcntl.h>
#include <io.h>

#include <algorithm>
#include <cwctype>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <vector>

#include "InputHandle.h"
#include "FileHandle.h"
#include "Utils.h"
#include "Theme.h"

namespace View {
    // All posible color
    struct Rect {
        short Top = 0, Left = 0, Right = 0, Bottom = 0;
    };

    struct Option {
        const std::wstring& option;
        const wchar_t underline;

        bool operator==(const Option& other) const
        {
            return option == other.option && underline == other.underline;
        }
    };

    const short HPADDING = 3;
    const short VPADDING = 1;
    const short BORDER_WIDTH = 1;

    void ShowCursor(bool show);

    // Setup console
    void Setup();

    // Set cursor position
    inline void Goto(short x, short y)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x, y});
    }

    COORD GetCursorPos();

    // Print string to console
    void WriteToView(
        short x,
        short y,  // Draw position
        const std::wstring& str,
        wchar_t shortcut = 0,  // Character want to underline
        bool highlight = false,
        Color textColor = Theme::GetColor(ThemeColor::TEXT_COLOR),
        Color highlightColor = Theme::GetColor(ThemeColor::CONSOLE_HIGHLIGHT_COLOR),
        Color highlightTextColor = Theme::GetColor(ThemeColor::TEXT_HIGHLIGHT_COLOR),
        Color backgroundColor = Theme::GetColor(ThemeColor::CONSOLE_COLOR)
    );

    // Print character to console
    void WriteToView(
        short x,
        short y,  // Draw position
        wchar_t str,
        bool highlight = false,
        Color textColor = Theme::GetColor(ThemeColor::TEXT_COLOR),
        Color highlightColor = Theme::GetColor(ThemeColor::CONSOLE_HIGHLIGHT_COLOR),
        Color highlightTextColor = Theme::GetColor(ThemeColor::TEXT_HIGHLIGHT_COLOR),
        Color backgroundColor = Theme::GetColor(ThemeColor::CONSOLE_COLOR)
    );

    inline std::pair<short, short> CalcCenter(short width, short height)
    {
        return {59 - width / 2, 14 - height / 2};
    }

    inline std::wstring Underline(const std::wstring& str)
    {
        return L"\033[4m" + str + L"\033[24m";
    }

    inline std::wstring Underline(wchar_t str)
    {
        return L"\033[4m" + std::wstring(1, str) + L"\033[24m";
    }

    void ClearScreen(short ScreenAttribute = Theme::GetScreenAttribute());

    void ClearRect(Rect area, short ScreenAttribute = Theme::GetScreenAttribute());

    void DrawBorder(
        const Rect& rect,
        Color textColor = Theme::GetColor(ThemeColor::BORDER_COLOR),
        Color bgColor = Theme::GetColor(ThemeColor::CONSOLE_COLOR)
    );

    void DrawRect(
        const Rect& rect,
        Color textColor = Theme::GetColor(ThemeColor::BORDER_COLOR),
        Color bgColor = Theme::GetColor(ThemeColor::CONSOLE_COLOR),
        short ScreenAttribute = Theme::GetScreenAttribute()
    );

    struct OptionNoRef {
        std::wstring option;
        wchar_t underline;

        bool operator==(const Option& other) const
        {
            return option == other.option && underline == other.underline;
        }

        OptionNoRef operator=(const Option& other)
        {
            option = other.option;
            underline = other.underline;
            return *this;
        }
    };

    struct DrawMenuPrevState {
        short x = 0;
        short y = 0;
        short w = 0;
        short h = 0;

        std::wstring title;
        std::vector<OptionNoRef> optionsList;
        size_t selected;

        Color textColor;
        Color highlightColor;
        Color highlightTextColor;
        Color backgroundColor;
        Color titleColor;

        DrawMenuPrevState() {
            textColor = Theme::GetColor(ThemeColor::TEXT_COLOR);
            highlightColor =
                Theme::GetColor(ThemeColor::CONSOLE_HIGHLIGHT_COLOR);
            highlightTextColor =
                Theme::GetColor(ThemeColor::TEXT_HIGHLIGHT_COLOR);
            backgroundColor = Theme::GetColor(ThemeColor::CONSOLE_COLOR);
            titleColor = Theme::GetColor(ThemeColor::TITLE_TEXT_COLOR);

        }
    };

    Rect DrawMenu(
        DrawMenuPrevState& prevState,
        short x,
        short y,
        const std::wstring& title,
        const std::vector<Option>& optionsList,
        size_t selected,
        Color textColor = Theme::GetColor(ThemeColor::TEXT_COLOR),
        Color highlightColor = Theme::GetColor(ThemeColor::CONSOLE_HIGHLIGHT_COLOR),
        Color highlightTextColor = Theme::GetColor(ThemeColor::TEXT_HIGHLIGHT_COLOR),
        Color backgroundColor = Theme::GetColor(ThemeColor::CONSOLE_COLOR),
        Color titleColor = Theme::GetColor(ThemeColor::TITLE_TEXT_COLOR)
    );

    Rect DrawMenuCenter(
        DrawMenuPrevState& prevState,
        const std::wstring& title,
        const std::vector<Option>& optionsList,
        size_t selected,
        Color textColor = Theme::GetColor(ThemeColor::TEXT_COLOR),
        Color highlightColor = Theme::GetColor(ThemeColor::CONSOLE_HIGHLIGHT_COLOR),
        Color highlightTextColor = Theme::GetColor(ThemeColor::TEXT_HIGHLIGHT_COLOR),
        Color backgroundColor = Theme::GetColor(ThemeColor::CONSOLE_COLOR),
        Color titleColor = Theme::GetColor(ThemeColor::TITLE_TEXT_COLOR)
    );

    std::vector<std::wstring> WrapText(
        const std::wstring& text,
        short maxRow,
        short maxWidth,
        const std::wstring& overflowStr = L"..."
    );

    void DrawTextWrapped(
        short x,
        short y,
        const std::wstring& text,
        short maxRow,
        short maxWidth,
        const std::wstring& overflowStr = L"...",
        Color textColor = Theme::GetColor(ThemeColor::TEXT_COLOR)
    );

    inline void DrawTextCenterdVertically(
        short y,
        const std::wstring& text,
        Color textColor = Theme::GetColor(ThemeColor::TEXT_COLOR),
        Color backgroundColor = Theme::GetColor(ThemeColor::CONSOLE_COLOR)
    )
    {
        WriteToView(
            (119 - text.size()) / 2,
            y,
            text,
            0,
            0,
            textColor,
            backgroundColor,
            textColor,
            backgroundColor
        );
    }

    inline bool defaultToogleFocus(wchar_t inp)
    {
        return Utils::keyMatchPattern(inp, {L'\t', L'\r', L'\n', L'\x1b'});
    }

    wchar_t Input(
        short x,
        short y,
        const std::wstring& leadingText,
        std::wstring& inputText,
        bool hasFocus = 0,
        const std::function<void(const std::wstring&)>& onValueChange =
            [](const std::wstring&) {},
        const std::function<bool(wchar_t)>& toogleFocus = defaultToogleFocus,
        const wchar_t delimiter = L':',
        Color textColor = Theme::GetColor(ThemeColor::TEXT_COLOR),
        Color backgroundColor = Theme::GetColor(ThemeColor::CONSOLE_COLOR),
        Color focusTextColor = Theme::GetColor(ThemeColor::TEXT_HIGHLIGHT_COLOR),
        Color focusBackgroundColor =
            Theme::GetColor(ThemeColor::CONSOLE_HIGHLIGHT_COLOR)
    );
}  // namespace View