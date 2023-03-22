#pragma once
#include "View.h"

// Container for various elements such as timers, log, win counts,...
class Container {
   public:
    short xOffset, yOffset;
    short xCoord, yCoord, cellWidth, cellHeight;
    void DrawContainer();

    // Draws the value inside of the container
    void DrawToContainer(std::wstring value);
    void DrawToLogContainer(
        const std::vector<std::pair<short, short>>& valueList,
        std::wstring playerNameOne,
        std::wstring playerNameTwo
    );
};