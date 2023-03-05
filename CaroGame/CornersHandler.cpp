#include "CornersHandler.h"
#include "View.h"
#include "Constants.h"
#include "GameScreen.h"

void CornersHandler::FixBoardCorners(short x, short y)
{
	//Fixes the surrounding 4 corners
	View::WriteToView(x, y, L'\u2554');
	View::WriteToView(x + Constants::BOARD_SIZE * BoardContainer::CELL_WIDTH, y, L'\u2557');
	View::WriteToView(x, y + Constants::BOARD_SIZE * BoardContainer::CELL_HEIGHT, L'\u255A');
	View::WriteToView(x + Constants::BOARD_SIZE * BoardContainer::CELL_WIDTH,
		y + Constants::BOARD_SIZE * BoardContainer::CELL_HEIGHT, L'\u255D');

	//Fixes the top and bottom corners
	for (short i = 1; i < Constants::BOARD_SIZE; ++i) {
		View::WriteToView(x + i * BoardContainer::CELL_WIDTH, y, L'\u2566');
		View::WriteToView(x + i * BoardContainer::CELL_WIDTH, y + Constants::BOARD_SIZE * BoardContainer::CELL_HEIGHT, L'\u2569');

	}

	// Fixes the cells corners
	for (short row = 1; row < Constants::BOARD_SIZE; ++row) {
		for (short col = 1; col < Constants::BOARD_SIZE; ++col) {
			View::WriteToView(x + col * BoardContainer::CELL_WIDTH, y + row * BoardContainer::CELL_HEIGHT, L'\u256C');

		}
	}
	

	// Fixes the side corners
	for (short i = 1; i < Constants::BOARD_SIZE; ++i) {
		View::WriteToView(x, y + i * BoardContainer::CELL_HEIGHT, L'\u2560');
		View::WriteToView(x + Constants::BOARD_SIZE * BoardContainer::CELL_WIDTH, y + i * BoardContainer::CELL_HEIGHT, L'\u2563');

	}
	

}

void CornersHandler::FixStatusBarCorners(short x, short y)
{
	short xCur = x;
	xCur += TimerContainer::CELL_WIDTH;
	View::WriteToView(xCur, y, L'\u2566');
	View::WriteToView(xCur, y + TimerContainer::CELL_HEIGHT, L'\u2569');
	xCur += WinCountContainer::CELL_WIDTH;
	View::WriteToView(xCur, y, L'\u2566');
	View::WriteToView(xCur, y + TimerContainer::CELL_HEIGHT, L'\u2569');
	xCur += PlayerContainer::CELL_WIDTH;
	View::WriteToView(xCur, y, L'\u2566');
	View::WriteToView(xCur, y + TimerContainer::CELL_HEIGHT, L'\u2569');
	xCur += PlayerContainer::CELL_WIDTH;
	View::WriteToView(xCur, y, L'\u2566');
	View::WriteToView(xCur, y + TimerContainer::CELL_HEIGHT, L'\u2569');
	xCur += WinCountContainer::CELL_WIDTH;
	View::WriteToView(xCur, y, L'\u2566');
	View::WriteToView(xCur, y + TimerContainer::CELL_HEIGHT, L'\u2569');
}

void CornersHandler::FixPlayerInfoCorners(short x, short y)
{
	View::WriteToView(x + PlayerInfoContainer::CELL_WIDTH, y, L'\u2566');
	View::WriteToView(x + PlayerInfoContainer::CELL_WIDTH, y + PlayerInfoContainer::CELL_HEIGHT, L'\u2569');
}

