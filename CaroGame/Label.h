#pragma once

#include <string>

#include "Language.h"
#include "View.h"

// Draws labels for containers or for instructions
namespace Label {
    // Draws a label at x and y

    // Draws a centered-label based on the width of the container
    void DrawLabelCenter(
        const short& X_LEFT,
        const short& X_RIGHT,
        const short& X,
        const short& Y,
        const std::wstring& VALUE
    );

    // Draws a grid of labels based on the width of the container
    void DrawLabelGrid(
        const short& X,
        const short& Y,
        const std::vector<std::wstring>& VALUE_LIST,
        const short& COL_NUM
    );

    void DrawGameScreenHint(
        short logX, short logY, short logWidth, short logHeight, bool isReplay = false
    );

    std::wstring GetShortcutString(
        const std::wstring shortcut, const std::wstring title
    );

    short GetCenterX(short x, short width, short length);
}  // namespace Label