#pragma once

#include "GameAction.h"
#include "GameScreen.h"
#include "GameScreenAction.h"
#include "GameState.h"
#include "Navigate.h"
#include "Utils.h"

namespace ReplayScreenView {
    void ReplayScreenView(NavigationHost &NavHost);
    void UpdateScreen(
        GameScreen gameScreen,
        const GameAction::Point &move,
        const Constants::Player &player,
        const std::vector<std::pair<short, short>> &moveList,
        const GameState &gameState

    );
}  // namespace ReplayScreenView