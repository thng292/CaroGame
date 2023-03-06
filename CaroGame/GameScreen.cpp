#include <vector>
#include "GameScreen.h"
#include "Constants.h"
#include "CornersHandler.h"


GameScreen::GameScreen(short x, short y) {
	boardContainer.xCoord = x, boardContainer.yCoord = y;
	x += Constants::BOARD_SIZE * BoardContainer::CELL_WIDTH + 5;
	y += 1;
	const short X_PIVOT = x; // Resets X to original position (next to board)
	InitElement(timerContainer1, x, y, 12, 2, 3, 1);
	x += timerContainer1.cellWidth;
	InitElement(winCountContainer1, x, y, 7, 2, 2, 1);
	x += winCountContainer1.cellWidth;
	InitElement(playerContainer1, x, y, 6, 2, 3, 1);
	x += playerContainer1.cellWidth;
	InitElement(playerContainer2, x, y, 6, 2, 3, 1);
	x += playerContainer2.cellWidth;
	InitElement(winCountContainer2, x, y, 7, 2, 2, 1);
	x += winCountContainer2.cellWidth;
	InitElement(timerContainer2, x, y, 12, 2, 3, 1);

	x = X_PIVOT;
	y += timerContainer1.cellHeight * 2;
	InitElement(playerInfoContainer1, x, y, 25, 4, 3, 1);
	x += playerInfoContainer1.cellWidth;
	InitElement(playerInfoContainer2, x, y, 25, 4, 3, 1);

	x = X_PIVOT;
	y += playerInfoContainer1.cellHeight + timerContainer1.cellHeight;
	InitElement(logContainer, x, y, 50, 7, 3, 1);
}
void GameScreen::DrawGameScreen()
{
	boardContainer.DrawBoardContainer();
	timerContainer1.DrawContainer();
	winCountContainer1.DrawContainer();
	playerContainer1.DrawContainer();
	playerContainer2.DrawContainer();
	winCountContainer2.DrawContainer();
	timerContainer2.DrawContainer();
	playerInfoContainer1.DrawContainer();
	playerInfoContainer2.DrawContainer();
	logContainer.DrawContainer();

	CornersHandler::FixBoardCorners(boardContainer.xCoord, boardContainer.yCoord);
	CornersHandler::FixPlayerInfoCorners(playerInfoContainer1.xCoord, playerInfoContainer1.yCoord, playerInfoContainer1);
	CornersHandler::FixStatusBarCorners(timerContainer1.xCoord, timerContainer1.yCoord, timerContainer1, winCountContainer1, playerContainer1);

	Label::DrawLabelCenter(logContainer.xCoord, logContainer.xCoord + logContainer.cellWidth,
		timerContainer1.xCoord, timerContainer1.yCoord - 1, L"Game Status");
	Label::DrawLabelCenter(logContainer.xCoord, logContainer.xCoord + logContainer.cellWidth,
		playerInfoContainer1.xCoord, playerInfoContainer1.yCoord - 1, L"Player Info");
	Label::DrawLabelCenter(logContainer.xCoord, logContainer.xCoord + logContainer.cellWidth,
		logContainer.xCoord, logContainer.yCoord - 1, L"Move History");

	const std::vector<std::wstring> INSTRUCTION_LIST = { L"A: Lorem ispum", L"A: Lorem ispum", L"A: Lorem ispum", L"A: Lorem ispum",
											L"A: Lorem ispum", L"A: Lorem ispum", L"A: Lorem ispum", L"A: Lorem ispum" , L"A: Lorem ispum" };
	Label::DrawLabelGrid(logContainer.xCoord, logContainer.xCoord + logContainer.cellWidth,
		logContainer.xCoord, logContainer.yCoord + logContainer.cellHeight + 2,
		INSTRUCTION_LIST, 3);


}


void GameScreen::InitElement(
	Container& element,
	short x,
	short y,
	short cell_width,
	short cell_height,
	short x_offset,
	short y_offset)
{
	element.xCoord = x;
	element.yCoord = y;
	element.cellWidth = cell_width;
	element.cellHeight = cell_height;
	element.xOffset = x_offset;
	element.yOffset = y_offset;
}

