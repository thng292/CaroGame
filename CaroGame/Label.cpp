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
    View::WriteToView(X + X_CENTER, Y, VALUE, (wchar_t)0U, false, Theme::GetColor(ThemeColor::TITLE_TEXT_COLOR));
}

void Label::DrawGameScreenHint(
    short logX, short logY, short logWidth, short logHeight, bool isReplay
)
{
    if (!isReplay) {
        const std::vector<std::wstring> INSTRUCTION_LIST = {
            Label::GetShortcutString(
                L"A, W, D, S, \u2190\u2191\u2192\u2193",
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
            ),
            Label::GetShortcutString(
                Language::GetString(L"HINT_SHORTCUT"),
                Language::GetString(L"HINT_OPTION_TITLE")
            ),
            Label::GetShortcutString(
                Language::GetString(L"GHOST_SHORTCUT"),
                Language::GetString(L"GHOST_TITLE")
            )
         
        };
        short spaceVal = 3;
        std::vector<std::wstring> hintRows;

        short maxLeftHintLength = std::max<short>(
            INSTRUCTION_LIST[0].size(),
            std::max<short>(
            INSTRUCTION_LIST[2].size(),
            INSTRUCTION_LIST[4].size())
        );

        short maxLen = 0;

        for (size_t i = 0; i < 6; i += 2) {
            hintRows.push_back(
                INSTRUCTION_LIST[i] +
                ExtraSpace(INSTRUCTION_LIST[i], maxLeftHintLength, spaceVal) +
                INSTRUCTION_LIST[i + 1]
            );
            maxLen = std::max<short>(maxLen, hintRows[hintRows.size()-1].size());
        }

        short centerX = Label::GetCenterX(logX, logWidth, maxLen),
              y = logY + logHeight + 1;

        for (size_t i = 0; i < hintRows.size(); ++i) {
            View::WriteToView(centerX, y + i, hintRows[i]);
        }

       
    } else {
        View::WriteToView(
            logX,
            logY + logHeight + 1,
            Label::GetShortcutString(
                L"A, D, \u2190\u2192", Language::GetString(L"REPLAY_SEEK_TITLE")
            )
        );
        View::WriteToView(
            logX,
            logY + logHeight + 2,
            Label::GetShortcutString(
                L"B", Language::GetString(L"NAVIGATE_BACK_KEY_TITLE")
            )
        );
    }
}

inline std::wstring Label::GetShortcutString(
    const std::wstring shortcut, const std::wstring title
)
{

    return shortcut + L": " + title;
}

std::wstring Label::ExtraSpace(
    const std::wstring& hint, short maxLeftLength, short space
)
{
    return std::wstring(space + maxLeftLength - hint.size(), L' ');
}

inline short Label::GetCenterX(short x, short width, short length)
{
    short addition = (width - length) % 2 != 0;
    return x + (width - length) / 2 + addition;
}
