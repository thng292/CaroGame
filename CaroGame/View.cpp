#include "View.h"

void View::Setup()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    DWORD currMode;
    CONSOLE_FONT_INFOEX fontex;

    // Turn off maximize, resize, horizontal and vertical scrolling
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME) & ~(WS_HSCROLL) &
            ~(WS_VSCROLL);
    SetWindowLong(consoleWindow, GWL_STYLE, style);

    // Turn off mouse input
    GetConsoleMode(hOut, &currMode);
    SetConsoleMode(
        hOut,
        ((currMode | ENABLE_EXTENDED_FLAGS) & ~ENABLE_QUICK_EDIT_MODE &
         ~ENABLE_MOUSE_INPUT)
    );

    // Hide scoll bar
    ShowScrollBar(consoleWindow, SB_BOTH, FALSE);

// Hide the cursor
#if _DEBUG
    ShowCursor(true);
#else
    ShowCursor(false);
#endif
    // Set font bold
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 800;
    fontex.dwFontSize.X = 24;
    fontex.dwFontSize.Y = 24;
    wcscpy_s(fontex.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);

    // Update console title
    SetConsoleTitle(TEXT("Caro Game"));

    // Change color and clear screen
    ClearScreen();

    // Set IO Unicode
    _setmode(_fileno(stdout), _O_WTEXT);
    _setmode(_fileno(stdin), _O_WTEXT);

    // Faster UI Update
    std::ios_base::sync_with_stdio(0);
    std::wcout.tie(0);
}

void View::ShowCursor(bool show)
{
    static HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = show;
    SetConsoleCursorInfo(hOut, &cursorInfo);
}

COORD View::GetCursorPos()
{
    static auto StdOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO tmp;
    GetConsoleScreenBufferInfo(StdOutputHandle, &tmp);
    return tmp.dwCursorPosition;
}

inline void View::WriteToView(
    short x,
    short y,  // Draw position
    const std::wstring& str,
    wchar_t shortcut,  // Character want to underline
    bool highlight,
    View::Color textColor,
    View::Color highlightColor,
    View::Color highlightTextColor,
    View::Color backgroundColor
)
{
    static auto STD_HANDLE = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(
        STD_HANDLE,
        highlight ? ((int(highlightColor) << 4) | int(highlightTextColor))
                  : ((int(backgroundColor) << 4) | int(textColor))
    );

    int shortcutIndex = str.find_first_of(shortcut);
    View::Goto(x, y);
    if (shortcut && shortcutIndex >= 0) {
        std::wcout << std::format(
            L"{}{}{}",
            str.substr(0, shortcutIndex),
            View::Underline(str[shortcutIndex]),
            str.c_str() + shortcutIndex + 1
        );
    } else {
        std::wcout << str;
    }
}

void View::WriteToView(
    short x,
    short y,  // Draw position
    wchar_t str,
    bool highlight,
    View::Color textColor,
    View::Color highlightColor,
    View::Color highlightTextColor,
    View::Color backgroundColor
)
{
    static auto STD_HANDLE = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(
        STD_HANDLE,
        highlight ? ((int(highlightColor) << 4) | int(highlightTextColor))
                  : ((int(backgroundColor) << 4) | int(textColor))
    );
    View::Goto(x, y);
    std::wcout << str;
}

void View::ClearScreen(short ScreenAttribute)
{
    DWORD tmp = 0;
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    FillConsoleOutputCharacter(StdOut, L' ', 120 * 30, {0, 0}, &tmp);
    FillConsoleOutputAttribute(StdOut, ScreenAttribute, 120 * 30, {0, 0}, &tmp);
}

void View::ClearRect(Rect area, short ScreenAttribute)
{
    DWORD tmp = 0;
    auto stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    for (auto i = area.Top; i <= area.Bottom; i++) {
        FillConsoleOutputCharacter(
            stdHandle, L' ', area.Right - area.Left + 1, {area.Left, i}, &tmp
        );
        FillConsoleOutputAttribute(
            stdHandle,
            ScreenAttribute,
            area.Right - area.Left + 1,
            {area.Left, i},
            &tmp
        );
    }
}

void View::DrawBorder(const Rect& rect, Color textColor, Color bgColor)
{
    View::WriteToView(
        rect.Left,
        rect.Top,
        L'\u2554',
        0,
        textColor,
        Color::BLACK,
        Color::BLACK,
        bgColor
    );
    View::WriteToView(
        rect.Right,
        rect.Top,
        L'\u2557',
        0,
        textColor,
        Color::BLACK,
        Color::BLACK,
        bgColor
    );
    View::WriteToView(
        rect.Left,
        rect.Bottom,
        L'\u255A',
        0,
        textColor,
        Color::BLACK,
        Color::BLACK,
        bgColor
    );
    View::WriteToView(
        rect.Right,
        rect.Bottom,
        L'\u255D',
        0,
        textColor,
        Color::BLACK,
        Color::BLACK,
        bgColor
    );
    DWORD tmp = 0;
    auto stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    FillConsoleOutputCharacter(
        stdHandle,
        L'\u2550',
        rect.Right - rect.Left - View::BORDER_WIDTH,
        {rect.Left + View::BORDER_WIDTH, rect.Top},
        &tmp
    );
    FillConsoleOutputCharacter(
        stdHandle,
        L'\u2550',
        rect.Right - rect.Left - View::BORDER_WIDTH,
        {rect.Left + View::BORDER_WIDTH, rect.Bottom},
        &tmp
    );
    FillConsoleOutputAttribute(
        stdHandle,
        int(textColor) | int(bgColor) << 4,
        rect.Right - rect.Left - View::BORDER_WIDTH,
        {rect.Left + View::BORDER_WIDTH, rect.Top},
        &tmp
    );
    FillConsoleOutputAttribute(
        stdHandle,
        int(textColor) | int(bgColor) << 4,
        rect.Right - rect.Left - View::BORDER_WIDTH,
        {rect.Left + View::BORDER_WIDTH, rect.Bottom},
        &tmp
    );
    for (int i = rect.Top + 1; i < rect.Bottom; i++) {
        View::WriteToView(
            rect.Left,
            i,
            L'\u2551',
            0,
            textColor,
            Color::BLACK,
            Color::BLACK,
            bgColor
        );
        View::WriteToView(
            rect.Right,
            i,
            L'\u2551',
            0,
            textColor,
            Color::BLACK,
            Color::BLACK,
            bgColor
        );
    }
}

void View::DrawRect(
    const Rect& rect, Color textColor, Color bgColor, short ScreenAttribute
)
{
    View::ClearRect(rect, ScreenAttribute);
    View::DrawBorder(rect, textColor, bgColor);
}

constexpr inline short CalcWidth(
    const std::vector<View::Option>& options, const std::wstring& title
)
{
    int tmp = 0;
    for (auto& i : options) {
        tmp = max(i.option.length(), tmp);
    }
    return max(tmp, title.length()) + (View::BORDER_WIDTH * View::HPADDING) * 2;
}

constexpr inline short CalcHeight(
    const std::vector<View::Option>& options, const std::wstring& title
)
{
    return options.size() + (View::BORDER_WIDTH + View::VPADDING) * 2 +
           (title.length() ? 2 : 0);
}

View::Rect View::DrawMenu(
    DrawMenuPrevState& prevState,
    short x,
    short y,
    const std::wstring& title,
    const std::vector<Option>& optionsList,
    size_t selected,
    Color textColor,
    Color highlightColor,
    Color highlightTextColor,
    Color backgroundColor,
    Color titleColor
)
{
    short w = CalcWidth(optionsList, title);
    short h = CalcHeight(optionsList, title);

    bool redrawAll = x != prevState.x || y != prevState.y || w != prevState.w ||
                     h != prevState.h || textColor != prevState.textColor ||
                     highlightColor != prevState.highlightColor ||
                     highlightTextColor != prevState.highlightTextColor ||
                     backgroundColor != prevState.backgroundColor;

    bool redrawTitle =
        title != prevState.title || prevState.titleColor != titleColor;
    bool redrawBorder =
        redrawAll || redrawTitle || w != prevState.w || h != prevState.h;

    if (redrawAll) {
        SetConsoleTextAttribute(
            GetStdHandle(STD_OUTPUT_HANDLE),
            (int(backgroundColor) << 4) | int(textColor)
        );
    }

    View::Rect res = {y, x, x + w, y + h - 1};
    if (redrawBorder) {
        View::ClearRect(
            {prevState.y,
             prevState.x,
             prevState.x + prevState.w,
             prevState.y + prevState.h - 1}
        );
        View::DrawRect(res);
    }

    short leftAlign = View::BORDER_WIDTH + View::HPADDING + x;
    short topAlign = View::BORDER_WIDTH + View::VPADDING + y;

    if (redrawTitle || redrawBorder) {
        View::WriteToView(
            leftAlign,
            topAlign,
            title,
            0,
            false,
            titleColor,
            highlightColor,
            highlightTextColor,
            backgroundColor
        );
    }
    if (title.size()) {
        topAlign += 2;
    }

    bool redrawFlag = 0;

    if (redrawBorder) {
        for (int i = 0; i < optionsList.size(); i++) {
            redrawFlag = 1;
            View::WriteToView(
                leftAlign,
                topAlign + i,
                optionsList[i].option,
                optionsList[i].underline,
                selected == i,
                textColor,
                highlightColor,
                highlightTextColor,
                backgroundColor
            );
        }
    } else {
        for (int i = 0; i < optionsList.size(); i++) {
            if (selected == i || prevState.selected == i ||
                i >= prevState.optionsList.size() ||
                optionsList[i] != prevState.optionsList[i]) {
                redrawFlag = 1;
                View::ClearRect(
                    {short(topAlign + i),
                     leftAlign,
                     short(leftAlign + optionsList[i].option.size()),
                     short(topAlign + i)}
                );
                View::WriteToView(
                    leftAlign,
                    topAlign + i,
                    optionsList[i].option,
                    optionsList[i].underline,
                    selected == i,
                    textColor,
                    highlightColor,
                    highlightTextColor,
                    backgroundColor
                );
            }
        }
    }
    prevState.h = h;
    prevState.w = w;
    prevState.x = x;
    prevState.y = y;
    prevState.textColor = textColor;
    prevState.backgroundColor = backgroundColor;
    prevState.highlightColor = highlightColor;
    prevState.highlightTextColor = highlightTextColor;
    prevState.selected = selected;
    if (redrawFlag) {
        prevState.optionsList.clear();
        prevState.optionsList.resize(optionsList.size());
        for (size_t i = 0; i < optionsList.size(); i++) {
            prevState.optionsList[i] = optionsList[i];
        }
    }
    if (redrawTitle) {
        prevState.title = title;
    }

    return res;
}

View::Rect View::DrawMenuCenter(
    DrawMenuPrevState& prevState,
    const std::wstring& title,
    const std::vector<Option>& optionsList,
    size_t selected,
    Color textColor,
    Color highlightColor,
    Color highlightTextColor,
    Color backgroundColor,
    Color titleColor
)
{
    short w = CalcWidth(optionsList, title);
    short h = CalcHeight(optionsList, title);
    auto [x, y] = CalcCenter(w, h);

    return DrawMenu(
        prevState,
        x,
        y,
        title,
        optionsList,
        selected,
        textColor,
        highlightColor,
        highlightTextColor,
        backgroundColor
    );
}

std::vector<std::wstring> View::WrapText(
    const std::wstring& text,
    short maxRow,
    short maxWidth,
    const std::wstring& overflowStr
)
{
    std::vector<std::wstring> res;
    std::wistringstream iss(text);
    std::wstring tmp, buff;
    int cnt = 0;

    while ((!iss.eof() || buff.length()) && cnt < maxRow) {
        res.emplace_back();
        auto& currentRow = res.back();

        if (buff.length()) {
            currentRow.append(buff);
            currentRow.append(L" ");
            buff.clear();
        }

        while (!iss.eof()) {
            iss >> tmp;
            if (currentRow.length() + tmp.length() - 1 <= maxWidth) {
                currentRow.append(tmp);
                currentRow.append(L" ");
            } else {
                currentRow.pop_back();
                buff = tmp;
                break;
            }
        };

        cnt++;
    }
    if (!iss.eof()) {
        if (res.back().length() <= maxWidth - overflowStr.length()) {
            res.back().append(overflowStr);
        } else {
            std::wstring& t = res.back();
            t.resize(maxWidth);
            auto overflowStrLen = overflowStr.length();
            for (size_t i = 1; i <= overflowStrLen; i++) {
                t[maxWidth - i] = overflowStr[overflowStrLen - i];
            }
        }
    }

    return res;
}

void View::DrawTextWrapped(
    short x,
    short y,
    const std::wstring& text,
    short maxRow,
    short maxWidth,
    const std::wstring& overflowStr,
    Color textColor
)
{
    auto wrappedText = WrapText(text, maxRow, maxWidth, overflowStr);
    int n = wrappedText.size();

    for (size_t i = 0; i < n; i++) {
        WriteToView(x, y + i, wrappedText[i], 0, false, textColor);
    }
}

static COORD DrawInput(
    short x,
    short y,
    const std::wstring& leadingText,
    const std::wstring& inputText,
    bool hasFocus,
    wchar_t delimiter,
    View::Color textColor,
    View::Color backgroundColor,
    View::Color focusTextColor,
    View::Color focusBackgroundColor
)
{
    std::wstring strdelimiter;
    if (delimiter) {
        strdelimiter = std::wstring(1, delimiter);
    }
    auto text = leadingText.length() ? leadingText + strdelimiter + L" " : L"";

    View::WriteToView(
        x,
        y,
        text,
        0,
        false,
        textColor,
        focusBackgroundColor,
        focusTextColor,
        backgroundColor
    );

    View::WriteToView(
        x + text.length(),
        y,
        inputText,
        0,
        hasFocus,
        textColor,
        focusBackgroundColor,
        focusTextColor,
        backgroundColor
    );
    return {x + (short)text.length(), y};
}

wchar_t View::Input(
    short x,
    short y,
    const std::wstring& leadingText,
    std::wstring& inputText,
    bool hasFocus,
    const std::function<void(const std::wstring&)>& onValueChange,
    const std::function<bool(wchar_t)>& toogleFocus,
    const wchar_t delimiter,
    Color textColor,
    Color backgroundColor,
    Color focusTextColor,
    Color focusBackgroundColor
)
{
    ShowCursor(true);
    Utils::ON_SCOPE_EXIT onScopeExit([&] { ShowCursor(false); });
    if (hasFocus) {
        bool redraw = 1;
        bool needReservePos = 0;
        COORD baseAnchor = {0, 0};
        COORD reservedPos = {0, 0};
        std::wstring inputTextCopy;

        while (1) {
            if (redraw) {
                redraw = 0;
                if (needReservePos) {
                    reservedPos = GetCursorPos();
                }
                inputTextCopy = inputText;

                baseAnchor = DrawInput(
                    x,
                    y,
                    leadingText,
                    inputTextCopy,
                    hasFocus,
                    delimiter,
                    textColor,
                    backgroundColor,
                    focusTextColor,
                    focusBackgroundColor
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
                    Goto(
                        min(currPos.X + 1,
                            baseAnchor.X + inputTextCopy.length()),
                        currPos.Y
                    );
                }

                if (filteredInp == InputHandle::DEL) {
                    ClearRect(
                        {currPos.Y,
                         baseAnchor.X,
                         baseAnchor.X + (short)inputTextCopy.length(),
                         currPos.Y}
                    );
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

            } else {
                if (inp == L'\b' && (currPos.X - baseAnchor.X)) {
                    inputTextCopy.erase(currPos.X - baseAnchor.X - 1, 1);
                    onValueChange(inputTextCopy);
                    ClearRect(
                        {currPos.Y,
                         baseAnchor.X,
                         baseAnchor.X + (short)inputTextCopy.length(),
                         currPos.Y}
                    );
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
    } else {
        DrawInput(
            x,
            y,
            leadingText,
            inputText,
            hasFocus,
            delimiter,
            textColor,
            backgroundColor,
            focusTextColor,
            focusBackgroundColor
        );
    }

    return 0;
}
