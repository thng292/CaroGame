#pragma once

#include <thread>

#include "AI.h"
#include "Common.h"
#include "Config.h"
#include "Constants.h"
#include "GameState.h"
#include "InputHandle.h"
#include "Label.h"
#include "Language.h"
#include "Navigate.h"
#include "Result.h"
#include "Utils.h"
#include "View.h"

namespace GameEndView {
    void GameEndView(NavigationHost& NavHost);

    void DrawLabelValuesAdjacent(
        short x,
        short y,
        const std::wstring& label,
        const std::wstring& playerOneValue,
        const std::wstring& playerTwoValue,
        short width

    );

    void DrawLabelValue(
        short x,
        short y,
        const std::wstring& label,
        const std::wstring& value,
        short width
    );
}  // namespace GameEndView