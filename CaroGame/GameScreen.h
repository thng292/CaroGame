#pragma once

#include "Container.h"
#include "Label.h"
#include "BoardContainer.h"
#include "GameState.h"

// Class for the game's UI
class GameScreen {
public:
	BoardContainer boardContainer;
	Container timerContainerOne, timerContainerTwo;
	Container playerContainerOne, playerContainerTwo;
	Container winCountContainerOne, winCountContainerTwo;
	Container playerInfoContainerOne, playerInfoContainerTwo;
	Container logContainer;

	GameScreen(short x, short y);
	void DrawGameScreen();
	void DrawToElements(GameState gameState);

private:
	void InitElement(
		Container& element,
		short x,
		short y,
		short cell_width,
		short cell_height,
		short x_offset,
		short y_offset);
};

