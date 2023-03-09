#pragma once
#include "Navigate.h"

namespace GameView {
	const short GAME_MODE_PVP = 0;
	const short GAME_MODE_PVE = 1;

	const short GAME_TYPE_NORMAL = 0;
	const short GAME_TYPE_RUSH = 1;

	const short AI_DIFFICULTY_EASY = 0;
	const short AI_DIFFICULTY_NORMAL = 1;
	const short AI_DIFFICULTY_HARD = 2;

	const std::string GAME_STATE = "GAME_STATE";

	typedef std::vector<std::vector<short>> GameBoard;

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