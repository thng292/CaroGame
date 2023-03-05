#pragma once
#include "Navigate.h"

namespace GameView {

	// View for choosing PvP or PvE
	void GameModeVersusView(NavigationHost& NavHost);

	// View for the player to enter their name
	void PlayerNameView(NavigationHost& NavHost);

	// View for choosing Normal or Rush
	void GameModeTypeView(NavigationHost& NavHost);

	// View for the game screen
	void GameScreenView(NavigationHost& NavHost);

	// View for choosing the AI's difficulty
	void AIDifficultyView(NavigationHost& NavHost);
}