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
#include "PokemonBlack.h"
#include "PokemonBlue.h"
#include "PokemonGray.h"
#include "PokemonGreen.h"
#include "PokemonPink.h"
#include "PokemonRed.h"
#include "PokemonWhite.h"
#include "PokemonYellow.h"
#include "Utils.h"
#include "View.h"

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

}  // namespace GameSelectionView

// 24*11