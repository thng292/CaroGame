#pragma once
#include <algorithm>
#include <format>

#include "Config.h"
#include "Constants.h"
#include "InputHandle.h"
#include "Language.h"
#include "Navigate.h"
#include "SaveLoad.h"
#include "Utils.h"
#include "View.h"
#include "Common.h"

namespace ReplayLoad {

    class ReplayLoadState: public Common::SaveLoadScreenViewModel {
       public:
        std::optional<GameState> LoadCurrentSelect();
    };

    void ReplayLoad(NavigationHost& NavHost);
}  // namespace ReplayLoad