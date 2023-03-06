#pragma once

#include "Container.h"
#include "Label.h"
#include "BoardContainer.h"

// Class for the game's UI
class GameScreen {
public:
	BoardContainer boardContainer;
	Container timerContainer1, timerContainer2;
	Container playerContainer1, playerContainer2;
	Container winCountContainer1, winCountContainer2;
	Container playerInfoContainer1, playerInfoContainer2;
	Container logContainer;

	GameScreen(short x, short y);
	void DrawGameScreen();

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

