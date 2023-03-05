#include <vector>
#include "GameScreen.h"


GameScreen::GameScreen(short x, short y) {
	InitElement(boardContainer, x, y);
	x += Constants::BOARD_SIZE * BoardContainer::CELL_WIDTH + 5;
	y += 1;
	const short X_PIVOT = x; // Resets X to original position (next to board)
	InitElement(timerContainer1, x, y);
	x += TimerContainer::CELL_WIDTH;
	InitElement(winCountContainer1, x, y);
	x += WinCountContainer::CELL_WIDTH;
	InitElement(playerContainer1, x, y);
	x += PlayerContainer::CELL_WIDTH;
	InitElement(playerContainer2, x, y);
	x += PlayerContainer::CELL_WIDTH;
	InitElement(winCountContainer2, x, y);
	x += WinCountContainer::CELL_WIDTH;
	InitElement(timerContainer2, x, y);

	x = X_PIVOT;
	y += TimerContainer::CELL_HEIGHT * 2;
	InitElement(playerInfoContainer1, x, y);
	x += PlayerInfoContainer::CELL_WIDTH;
	InitElement(playerInfoContainer2, x, y);

	x = X_PIVOT;
	y += PlayerInfoContainer::CELL_HEIGHT + TimerContainer::CELL_HEIGHT;
	InitElement(logContainer, x, y);
	y += TimerContainer::CELL_HEIGHT * 2;
}
void GameScreen::DrawGameScreen()
{
	boardContainer.DrawBoardContainer();
	timerContainer1.DrawContainer(TimerContainer::CELL_WIDTH, TimerContainer::CELL_HEIGHT);
	winCountContainer1.DrawContainer(WinCountContainer::CELL_WIDTH, WinCountContainer::CELL_HEIGHT);
	playerContainer1.DrawContainer(PlayerContainer::CELL_WIDTH, PlayerContainer::CELL_HEIGHT);
	playerContainer2.DrawContainer(PlayerContainer::CELL_WIDTH, PlayerContainer::CELL_HEIGHT);
	winCountContainer2.DrawContainer(WinCountContainer::CELL_WIDTH, WinCountContainer::CELL_HEIGHT);
	timerContainer2.DrawContainer(TimerContainer::CELL_WIDTH, TimerContainer::CELL_HEIGHT);
	playerInfoContainer1.DrawContainer(PlayerInfoContainer::CELL_WIDTH, PlayerInfoContainer::CELL_HEIGHT);
	playerInfoContainer2.DrawContainer(PlayerInfoContainer::CELL_WIDTH, PlayerInfoContainer::CELL_HEIGHT);
	logContainer.DrawContainer(LogContainer::CELL_WIDTH, LogContainer::CELL_HEIGHT);

	CornersHandler::FixBoardCorners(boardContainer.xCoord, boardContainer.yCoord);
	CornersHandler::FixPlayerInfoCorners(playerInfoContainer1.xCoord, playerInfoContainer1.yCoord);
	CornersHandler::FixStatusBarCorners(timerContainer1.xCoord, timerContainer1.yCoord);

	Label::DrawLabelCenter(logContainer.xCoord, logContainer.xCoord + LogContainer::CELL_WIDTH, 
		timerContainer1.xCoord, timerContainer1.yCoord - 1, L"Game Status");
	Label::DrawLabelCenter(logContainer.xCoord, logContainer.xCoord + LogContainer::CELL_WIDTH, 
		playerInfoContainer1.xCoord, playerInfoContainer1.yCoord - 1, L"Player Info");
	Label::DrawLabelCenter(logContainer.xCoord, logContainer.xCoord + LogContainer::CELL_WIDTH,
		logContainer.xCoord, logContainer.yCoord - 1, L"Move History");

	const std::vector<std::wstring> INSTRUCTION_LIST = {L"A: Lorem ispum", L"A: Lorem ispum", L"A: Lorem ispum", L"A: Lorem ispum",
											L"A: Lorem ispum", L"A: Lorem ispum", L"A: Lorem ispum", L"A: Lorem ispum" , L"A: Lorem ispum" };
	Label::DrawLabelGrid(logContainer.xCoord, logContainer.xCoord + LogContainer::CELL_WIDTH,
		logContainer.xCoord, logContainer.yCoord + LogContainer::CELL_HEIGHT + 2,
		INSTRUCTION_LIST, 3);


}

template <typename T>
void GameScreen::InitElement(T&element, short x, short y)
{
	element.xCoord = x;
	element.yCoord = y;
}
