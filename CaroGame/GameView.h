#pragma once
#include "Navigate.h"

namespace GameView {
	// View when choosing PvP / PvE
	void GameModeVersusView(NavigationHost& NavHost);

	// View when the player is inputing their name
	void PlayerNameView(NavigationHost& NavHost);

	// View when choosing Normal / Rush
	void GameModeTypeView(NavigationHost& NavHost);

	// View for the actual game
	void GameScreenView(NavigationHost& NavHost);

	// View for choosing the AI's difficulty
	void AIDifficultyView(NavigationHost& NavHost);

	// View when saving the game's replay
	void ReplayMenuView(NavigationHost& NavHost);

	// View when asking if the player wants to play again
	void PlayAgainView(NavigationHost& NavHost);
}