#pragma once

#include <string>
#include <vector>

// Draws labels for containers or for instructions
namespace Label {
    // Draws a label at x and y
    void DrawLabel(const short& X, const short& Y, const std::wstring& VALUE);

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
        const short& X_LEFT,
        const short& X_RIGHT,
        const short& X,
        const short& Y,
        const std::vector<std::wstring>& VALUE_LIST,
        const short& COL_NUM
    );

    short GetCenterX(short x, short width, short length);
}  // namespace Label