#pragma once
#include <string>
#include <format>

#include "View.h"
#include "Container.h"
#include "Constants.h"
#include "Label.h"
#include "Language.h"

// Container for various elements such as timers, log, win counts,...
class Container {
   public:
    short xOffset, yOffset;
    short xCoord, yCoord, cellWidth, cellHeight;
    void DrawContainer();

    // Draws the value inside of the container
    void DrawToContainer(std::wstring value, View::Color color = Theme::GetColor(ThemeColor::TEXT_COLOR));
    void DrawToLogContainer(
        const std::vector<std::pair<short, short>>& valueList,
        const std::wstring& playerNameOne,
        const std::wstring& playerNameTwo,
        bool playerOneFirst,
        short winMethod = 0,
        bool isReplay = false
    );

    
};