#pragma once

#include "BoardContainer.h"
#include "LogContainer.h"
#include "TimerContainer.h"
#include "PlayerContainer.h"
#include "PlayerInfoContainer.h"
#include "WinCountContainer.h"
#include "CornersHandler.h"
#include "Label.h"

class GameScreen {
public:
	BoardContainer boardContainer;
	TimerContainer timerContainer1, timerContainer2;
	PlayerContainer playerContainer1, playerContainer2;
	WinCountContainer winCountContainer1, winCountContainer2;
	PlayerInfoContainer playerInfoContainer1, playerInfoContainer2;
	LogContainer logContainer;

	GameScreen(short x, short y);
	void DrawGameScreen();

private:
	template <typename T>
	void InitElement(T&element, short x, short y);
};

