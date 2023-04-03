#include "Label.h"




void Label::DrawLabelCenter(
    const short& X_LEFT,
    const short& X_RIGHT,
    const short& X,
    const short& Y,
    const std::wstring& VALUE
)
{
    const short X_CENTER = ((X_RIGHT - X_LEFT + 1) % 2 == 0)
                               ? (X_RIGHT - X_LEFT - VALUE.size()) / 2
                               : (X_RIGHT - X_LEFT - VALUE.size()) / 2 + 1;
    View::WriteToView(X + X_CENTER, Y, VALUE);
}

void Label::DrawLabelGrid(
    const short& X,
    const short& Y,
    const std::vector<std::wstring>& VALUE_LIST,
    const short& COL_NUM
)
{
    const short X_SPACE = 2, Y_SPACE = 1;
    short ind = 0;
    const short LIST_LENGTH = VALUE_LIST.size();

    short row = 0, col = 0;
    while (ind < LIST_LENGTH) {
        View::WriteToView(X + X_SPACE * col, Y + Y_SPACE * row, VALUE_LIST[ind]);
        ind++;
        col++;
        if (col >= COL_NUM) {
            row++;
            col = 0;
        }
    }
}

void Label::DrawGameScreenHint(short logX, short logY, short logWidth, short logHeight)
{
    const std::vector<std::wstring> INSTRUCTION_LIST = {
        Label::GetShortcutString(
            Language::GetString(L"SAVE_SHORTCUT"),
            Language::GetString(L"SAVE_TITLE")
        ),

        Label::GetShortcutString(
            Language::GetString(L"PAUSE_SHORTCUT"),
            Language::GetString(L"PAUSE_TITLE")
        ),

        Label::GetShortcutString(
            Language::GetString(L"SETTINGS_SHORTCUT"),
            Language::GetString(L"SETTINGS_TITLE")
        ),

        Label::GetShortcutString(
            Language::GetString(L"NEW_GAME_SHORTCUT"),
            Language::GetString(L"NEW_GAME_TITLE")
        ),
        Label::GetShortcutString(
            Language::GetString(L"LOAD_SHORTCUT"),
            Language::GetString(L"LOAD_TITLE")
        ),
        Label::GetShortcutString(
            Language::GetString(L"MAIN_MENU_SHORTCUT"),
            Language::GetString(L"MAIN_MENU_TITLE")
        )

    };
    short padding = 8;
    std::wstring row1, row2, space = L"  ";
    for (int i = 0; i < 3; ++i) {
        row1 += INSTRUCTION_LIST[i];
        if (i != 2) row1 += space;
        row2 += INSTRUCTION_LIST[i + 3];
        if (i != 5) row2 += space;
    }
    short maxLen = std::max<short>(row1.size(), row2.size());
    short centerX = Label::GetCenterX(logX, logWidth, maxLen),
          y = logY + logHeight + 1;

    View::WriteToView(centerX, y, row1);
    View::WriteToView(centerX, y + 1, row2);
}

std::wstring Label::GetShortcutString(
    const std::wstring shortcut, const std::wstring title
)
{
    return shortcut + L": " + title;
}

short Label::GetCenterX(short x, short width, short length) { 
    return x + (width - length) / 2;
}
