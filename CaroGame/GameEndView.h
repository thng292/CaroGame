#pragma once

#include "Common.h"
#include "Config.h"
#include "Constants.h"
#include "GameState.h"
#include "InputHandle.h"
#include "Language.h"
#include "Navigate.h"
#include "Utils.h"
#include "View.h"
#include "Label.h"
#include "AI.h"

namespace GameEndView {
    void GameEndView(NavigationHost& NavHost);
    
    void DrawLabelValuesAdjacent(
        short x,
        short y,
        const std::wstring& label,
        const std::wstring &playerOneValue, const std::wstring &playerTwoValue
    );
    void DrawLabelValue(
        short x, short y, const std::wstring& label, const std::wstring& value
    );
}