#pragma once
#include <format>

#include "Common.h"
#include "Config.h"
#include "Constants.h"
#include "InputHandle.h"
#include "Language.h"
#include "Navigate.h"
#include "SaveLoad.h"
#include "Utils.h"
#include "View.h"

namespace ReplaySave {

    class ReplaySaveState : public Common::SaveLoadScreenViewModel {
       public:
        bool Save(GameState currentGameState)
        {
            if (searchInput.length()) {
                return SaveLoad::Save(
                    currentGameState, searchInput, Constants::REPLAY_PATH
                );
            }
            return 0;
        }
    };

    void ReplaySave(NavigationHost& NavHost);
}  // namespace ReplaySave