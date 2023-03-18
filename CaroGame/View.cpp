#include "View.h"


void View::Setup() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    DWORD currMode;
    CONSOLE_FONT_INFOEX fontex;


    // Turn off maximize, resize, horizontal and vertical scrolling
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME) & ~(WS_HSCROLL) & ~(WS_VSCROLL);
    SetWindowLong(consoleWindow, GWL_STYLE, style);


    // Turn off mouse input
    GetConsoleMode(hOut, &currMode);
    SetConsoleMode(hOut,
        currMode & ~(ENABLE_MOUSE_INPUT) & ~(ENABLE_QUICK_EDIT_MODE));


    // Set font bold
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    wcscpy_s(fontex.FaceName, L"Consolas");
    fontex.FontWeight = 800;
    fontex.dwFontSize.X = 24;
    fontex.dwFontSize.Y = 24;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);


    // Update console title
    SetConsoleTitle(TEXT("Caro Game"));


    // Change color and clear screen
    ClearScreen();

    // Set IO Unicode
    _setmode(_fileno(stdout), _O_WTEXT);
    _setmode(_fileno(stdin), _O_WTEXT);
}

COORD View::GetCursorPos() {
    static auto StdOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO tmp;
    GetConsoleScreenBufferInfo(StdOutputHandle, &tmp);
    return tmp.dwCursorPosition;
}

void View::WriteToView(
    short x, short y, //Draw position
    const std::wstring& str,
    wchar_t shortcut, //Character want to underline
    bool highlight,
    View::Color textColor,
    View::Color highlightColor,
    View::Color highlightTextColor,
    View::Color backgroundColor
) {
    View::Goto(x, y);
    static auto STD_HANDLE = GetStdHandle(STD_OUTPUT_HANDLE);
    if (highlight) {
        SetConsoleTextAttribute(STD_HANDLE,
            (int(highlightColor) << 4) | int(highlightTextColor));
    }
    else {
        SetConsoleTextAttribute(STD_HANDLE,
            (int(backgroundColor) << 4) | int(textColor));
    }
    if (shortcut) {
        int shortcutIndex = str.find_first_of(shortcut);
        std::wcout << str.substr(0, shortcutIndex) <<
            View::Underline(str[shortcutIndex]) <<
            str.substr(shortcutIndex + 1, str.length() - 1);
    }
    else {
        std::wcout << str;
    }
}

void View::WriteToView(
    short x, short y, //Draw position
    wchar_t str,
    bool highlight,
    View::Color textColor,
    View::Color highlightColor,
    View::Color highlightTextColor,
    View::Color backgroundColor
) {
    View::Goto(x, y);
    static auto STD_HANDLE = GetStdHandle(STD_OUTPUT_HANDLE);
    if (highlight) {
        SetConsoleTextAttribute(STD_HANDLE,
            (int(highlightColor) << 4) | int(highlightTextColor));
    }
    else {
        SetConsoleTextAttribute(STD_HANDLE,
            (int(backgroundColor) << 4) | int(textColor));
    }
    std::wcout << str;
}

void View::ClearScreen() {
    DWORD tmp = 0;
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    FillConsoleOutputCharacter(StdOut, L' ', 120 * 30, { 0,0 }, &tmp);
    FillConsoleOutputAttribute(StdOut, DEFAULT_SCREEN_ATTRIBUTE, 120 * 30, { 0,0 }, &tmp);
}

void View::ClearRect(Rect area) {
    DWORD tmp = 0;
    auto stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    for (auto i = area.Top; i <= area.Bottom; i++)
    {
        FillConsoleOutputCharacter(stdHandle, L' ', area.Right - area.Left + 1,
            { area.Left,i }, &tmp);
        FillConsoleOutputAttribute(stdHandle, DEFAULT_SCREEN_ATTRIBUTE,
            area.Right - area.Left + 1, { area.Left,i }, &tmp);
    }
}

void View::DrawRect(const Rect& rect, Color textColor, Color bgColor) {
    View::ClearRect(rect);
    View::WriteToView(rect.Left, rect.Top, L'\u2554');
    View::WriteToView(rect.Left, rect.Bottom, L'\u255A');
    View::WriteToView(rect.Right, rect.Top, L'\u2557');
    View::WriteToView(rect.Right, rect.Bottom, L'\u255D');
    DWORD tmp = 0;
    auto stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    FillConsoleOutputCharacter(stdHandle, L'\u2550',
        rect.Right - rect.Left - View::BORDER_WIDTH,
        { rect.Left + View::BORDER_WIDTH, rect.Top },
        &tmp);
    FillConsoleOutputCharacter(stdHandle, L'\u2550',
        rect.Right - rect.Left - View::BORDER_WIDTH,
        { rect.Left + View::BORDER_WIDTH, rect.Bottom },
        &tmp);
    for (int i = rect.Top + 1; i < rect.Bottom; i++)
    {
        View::WriteToView(rect.Left, i, L'\u2551');
        View::WriteToView(rect.Right, i, L'\u2551');
    }
}

inline short CalcWidth(const std::vector<View::Option>& options, const std::wstring& title) {
    int tmp = 0;
    for (auto i : options) {
        tmp = max(i.option.length(), tmp);
    }
    return max(tmp, title.length()) + (View::BORDER_WIDTH * View::HPADDING) * 2;
}

inline short CalcHeight(
    const std::vector<View::Option>& options,
    const std::wstring& title
) {
    return options.size() + (View::BORDER_WIDTH + View::VPADDING) * 2 +
        (title.length() ? 2 : 0);
}

View::Rect View::DrawMenu(
    short x, short y,
    const std::wstring& title,
    const std::vector<Option>& optionsList,
    size_t selected,
    Color textColor,
    Color highlightColor,
    Color highlightTextColor,
    Color backgroundColor
) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int(backgroundColor) << 4) | int(textColor));
    short w = CalcWidth(optionsList, title);
    short h = CalcHeight(optionsList, title);
    View::Rect res = { y, x, x + w, y + h - 1 };
    View::DrawRect(res);
    short leftAlign = View::BORDER_WIDTH + View::HPADDING + x;
    short topAlign = View::BORDER_WIDTH + View::VPADDING + y;
    if (title.length()) {
        View::WriteToView(leftAlign, topAlign, title);
        topAlign += 2;
    }
    for (int i = 0; i < optionsList.size(); i++) {
        View::WriteToView(leftAlign, topAlign + i,
            optionsList[i].option,
            optionsList[i].underline,
            selected == i,
            textColor,
            highlightColor,
            highlightTextColor,
            backgroundColor);
    }
    return res;
}

View::Rect View::DrawMenuCenter(
    std::wstring title,
    std::vector<Option> optionsList,
    size_t selected,
    Color textColor,
    Color highlightColor,
    Color highlightTextColor,
    Color backgroundColor
) {
    short w = CalcWidth(optionsList, title);
    short h = CalcHeight(optionsList, title);
    auto tmp = CalcCenter(w, h);
    return View::DrawMenu(tmp.first, tmp.second,
        title, optionsList, selected,
        textColor, highlightColor,
        highlightTextColor, backgroundColor);
}

std::vector<std::wstring>
View::WrapText(
    const std::wstring& text,
    short maxRow, short maxWidth,
    const std::wstring& overflowStr
) {
    std::vector<std::wstring> res;
    std::wistringstream iss(text);
    std::wstring tmp, buff;
    int cnt = 0;
    while (iss && cnt < maxRow) {
        res.emplace_back();
        if (buff.length()) {
            res[cnt].append(buff);
            res[cnt].append(L" ");
            buff = L"";
        }
        while (iss) {
            iss >> tmp;
            if (res[cnt].length() + tmp.length() + 1 <= maxWidth) {
                res[cnt].append(tmp);
                res[cnt].append(L" ");
            }
            else {
                buff = tmp;
                break;
            }
        };
        cnt++;
    }
    if (iss) {
        if (res.back().length() <= maxWidth - overflowStr.length()) {
            res.back().append(overflowStr);
        }
        else {
            std::wstring& t = res.back();
            t.resize(maxWidth);
            auto overflowStrLen = overflowStr.length();
            for (size_t i = 1; i <= overflowStrLen; i++)
            {
                t[maxWidth - i] = overflowStr[overflowStrLen - i];
            }
        }
    }
    return res;
}

void View::DrawTextWrapped(
    short x, short y,
    const std::wstring& text,
    short maxRow, short maxWidth,
    const std::wstring& overflowStr,
    Color textColor
) {
    auto wrappedText = WrapText(text, maxRow, maxWidth, overflowStr);
    int n = wrappedText.size();
    for (size_t i = 0; i < n; i++)
    {
        WriteToView(x, y + i, wrappedText[i], 0, false, textColor);
    }
}

wchar_t View::Input(
    short x,
    short y,
    const std::wstring& leadingText,
    std::wstring& inputText,
    bool hasFocus,
    const std::function<void(std::wstring)>& onValueChange,
    Color textColor,
    Color backgroundColor,
    const std::function<bool(wchar_t)>& toogleFocus
) {

    if (hasFocus) {

        bool redraw = 1;
        bool needReservePos = 0;
        COORD baseAnchor = { 0,0 };
        COORD reservedPos = { 0,0 };
        std::wstring inputTextCopy;

        while (1) {
            if (redraw) {
                redraw = 0;
                if (needReservePos) {
                    reservedPos = GetCursorPos();
                }
                inputTextCopy = inputText;
                auto text = leadingText.length() ? leadingText + L": " : L"";

                View::WriteToView(
                    x, y, text, 0,
                    false,
                    textColor,
                    DEFAULT_HIGHLIGHT_COLOR,
                    DEFAULT_HIGHLIGHT_TEXT_COLOR,
                    backgroundColor
                );

                baseAnchor = { x + (short)text.length(), y };

                View::WriteToView(
                    x + text.length(), y, inputTextCopy, 0,
                    hasFocus,
                    textColor,
                    DEFAULT_HIGHLIGHT_COLOR,
                    DEFAULT_HIGHLIGHT_TEXT_COLOR,
                    backgroundColor
                );
                if (needReservePos) {
                    Goto(reservedPos.X, reservedPos.Y);
                    needReservePos = 0;
                }
            }

            wchar_t inp = _getwch();
            if (toogleFocus(inp)) {
                return inp;
            }

            auto filteredInp = InputHandle::Filter(inp);
            auto currPos = GetCursorPos();

            if (filteredInp.length() > 1) {

                if (filteredInp == InputHandle::LEFT) {
                    Goto(max(currPos.X - 1, baseAnchor.X), currPos.Y);
                }

                if (filteredInp == InputHandle::RIGHT) {
                    Goto(min(currPos.X + 1, baseAnchor.X + inputTextCopy.length()), currPos.Y);
                }

                if (filteredInp == InputHandle::DEL) {
                    ClearRect({ currPos.Y, baseAnchor.X, baseAnchor.X + (short)inputTextCopy.length(), currPos.Y });
                    inputTextCopy.erase(currPos.X - baseAnchor.X, 1);
                    onValueChange(inputTextCopy);
                    redraw = 1;
                    needReservePos = 1;
                }

                if (filteredInp == InputHandle::HOME) {
                    Goto(baseAnchor.X, baseAnchor.Y);
                }

                if (filteredInp == InputHandle::END) {
                    Goto(baseAnchor.X + inputTextCopy.length(), baseAnchor.Y);
                }

            }
            else {

                if (inp == L'\b' && (currPos.X - baseAnchor.X)) {
                    inputTextCopy.erase(currPos.X - baseAnchor.X - 1, 1);
                    onValueChange(inputTextCopy);
                    ClearRect({ currPos.Y, baseAnchor.X, baseAnchor.X + (short)inputTextCopy.length(), currPos.Y });
                    Goto(max(currPos.X - 1, baseAnchor.X), currPos.Y);
                    redraw = 1;
                    needReservePos = 1;
                }

                if (std::iswprint(inp)) {
                    if (currPos.X < baseAnchor.X + inputTextCopy.length()) {
                        needReservePos = 1;
                        Goto(currPos.X + 1, currPos.Y);
                    }
                    inputTextCopy.insert(currPos.X - baseAnchor.X, 1, inp);
                    onValueChange(inputTextCopy);
                    redraw = 1;
                }

            }
        }
    }
    else {

        View::WriteToView(
            x, y, (leadingText.length() ? leadingText + L": " : L"") + inputText, 0,
            false,
            textColor,
            DEFAULT_HIGHLIGHT_COLOR,
            DEFAULT_HIGHLIGHT_TEXT_COLOR,
            backgroundColor
        );

    }

    return 0;
}