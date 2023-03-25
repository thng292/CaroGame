#pragma once
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

namespace SaveScreen {

    class SaveScreenState : public Common::SaveLoadScreenViewModel {
       public:
        bool Save(const GameState& currentGameState);
    };

    void SaveSuccess(NavigationHost& NavHost);
    void SaveFailed(NavigationHost& NavHost);
    void SaveScreen(NavigationHost& NavHost);
}  // namespace SaveScreen