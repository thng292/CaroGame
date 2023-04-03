#pragma once
#include <format>
#include <mutex>
#include <vector>

#include "AI.h"
#include "BackgroundAudioService.h"
#include "Config.h"
#include "Constants.h"
#include "GameAction.h"
#include "GameScreen.h"
#include "GameState.h"
#include "InputHandle.h"
#include "Language.h"
#include "Logic.h"
#include "Navigate.h"
#include "Timer.h"
#include "Utils.h"
#include "View.h"

#include "GameScreenAction.h"

namespace GameScreenView {

    // View for the actual game
    void GameScreenView(NavigationHost& NavHost);


}  // namespace GameView