#pragma once
#include <string>
#include <format>

#include "View.h"
#include "Container.h"
#include "Constants.h"

// Container for various elements such as timers, log, win counts,...
class Container {
   public:
    short xOffset, yOffset;
    short xCoord, yCoord, cellWidth, cellHeight;
    void DrawContainer();

    // Draws the value inside of the container
    void DrawToContainer(std::wstring value, View::Color color = View::DEFAULT_TEXT_COLOR);
    void DrawToLogContainer(
        const std::vector<std::pair<short, short>>& valueList,
        const std::wstring& playerNameOne,
        const std::wstring& playerNameTwo,
        bool playerOneFirst
    );

    
};