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
        View::WriteToView(
            X + X_SPACE * col, Y + Y_SPACE * row, VALUE_LIST[ind]
        );
        ind++;
        col++;
        if (col >= COL_NUM) {
            row++;
            col = 0;
        }
    }
}

void Label::DrawGameScreenHint(
    short logX, short logY, short logWidth, short logHeight
)
{
    const std::vector<std::wstring> INSTRUCTION_LIST = {
        Label::GetShortcutString(
            L"A, W, S, D, \u2190\u2191\u2192\u2193",
            Language::GetString(L"NAVIGATION_KEYS_TITLE")
        ),
        Label::GetShortcutString(
            Language::GetString(L"PLACE_SHORTCUT"),
            Language::GetString(L"PLACE_TITLE")
        ),
        Label::GetShortcutString(
            Language::GetString(L"UNDO_SHORTCUT"),
            Language::GetString(L"UNDO_OPTION_TITLE")
        ),

        Label::GetShortcutString(
            Language::GetString(L"PAUSE_SHORTCUT"),
            Language::GetString(L"PAUSE_TITLE")
        )

    };
    short spaceVal = 5;
    std::wstring row1, row2, space(spaceVal, L' ');
    row1 = INSTRUCTION_LIST[0] + space + INSTRUCTION_LIST[1];
    if (INSTRUCTION_LIST[0].size() > INSTRUCTION_LIST[2].size()) {
        std::wstring space(
            spaceVal + INSTRUCTION_LIST[0].size() - INSTRUCTION_LIST[2].size(),
            L' '
        );
        row2 = INSTRUCTION_LIST[2] + space + INSTRUCTION_LIST[3];
    } else {
        std::wstring space(
            spaceVal -
                (INSTRUCTION_LIST[2].size() - INSTRUCTION_LIST[0].size()),
            L' '
        );
        row2 = INSTRUCTION_LIST[2] + space + INSTRUCTION_LIST[3];
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

short Label::GetCenterX(short x, short width, short length)
{
    short addition = (width - length) % 2 != 0;
    return x + (width - length) / 2 + addition;
}
