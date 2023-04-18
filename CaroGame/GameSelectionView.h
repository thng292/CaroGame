#pragma once
#include <vector>

#include "Ai.h"
#include "Common.h"
#include "Config.h"
#include "Constants.h"
#include "GameState.h"
#include "InputBox.h"
#include "InputHandle.h"
#include "Language.h"
#include "Navigate.h"
#include "Pokemon.h"
#include "Theme.h"
#include "Utils.h"
#include "View.h"
#include "BackgroundAudioService.h"

namespace GameSelectionView {
    // View when choosing PvP / PvE
    void GameModeVersusView(NavigationHost& NavHost);

    // View when the player is inputing their name
    void PlayerNameView(NavigationHost& NavHost);

    // View when choosing Normal / Rush
    void GameModeTypeView(NavigationHost& NavHost);

    // View for choosing the AI's difficulty
    void AIDifficultyView(NavigationHost& NavHost);

    // View when asking if the player wants to save a replay
    void ReplayMenuView(NavigationHost& NavHost);

    // View when asking if the player wants to play again
    void PlayAgainView(NavigationHost& NavHost);

    void RushTimeView(NavigationHost& NavHost);

    void PauseMenuView(NavigationHost& NavHost);

    // View when choosing the player's avatar
    void AvatarSelectView(NavigationHost& NavHost);

    void DrawCurrentOptionBox(const GameState& gameState, short selected);

    void AreYouSureView(NavigationHost& NavHost);

}  // namespace GameSelectionView

// 24*11