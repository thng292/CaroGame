#include <Windows.h>

#include "BoardContainer.h"
#include "Constants.h"

void BoardContainer::DrawBoardContainer()
{
	DrawBoardRow();
	DrawBoardCol();
	DrawBoardHorizontalLabels();
	DrawBoardVerticalLabels();
}

void BoardContainer::DrawBoardRow()
{
	auto stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD tmp = 0;
	for (short row = 0; row < Constants::BOARD_SIZE + 1; ++row) {
		FillConsoleOutputCharacter(stdHandle, L'\u2550',
			CELL_WIDTH * Constants::BOARD_SIZE,
			{ xCoord, yCoord + row * CELL_HEIGHT },
			&tmp);
	}
}

void BoardContainer::DrawBoardCol()
{
	for (short col = 0; col < Constants::BOARD_SIZE + 1; ++col) {
		for (short i = 0; i < Constants::BOARD_SIZE; ++i) {
			for (short j = 0; j < CELL_HEIGHT; j++)
			{
				View::WriteToView(xCoord + col * CELL_WIDTH,
					yCoord + i * CELL_HEIGHT + j, L'\u2551');

			}
		}

	}
}

void BoardContainer::DrawToBoardContainerCell(short row, short col, std::wstring value)
{
	View::WriteToView(xCoord + col * CELL_WIDTH + X_OFFSET, yCoord + row * CELL_HEIGHT + Y_OFFSET, value);
}

void BoardContainer::DrawBoardHorizontalLabels()
{
	char c = 'A';
	for (int i = 0; i < Constants::BOARD_SIZE; ++i) {
		std::wstring s = L"1";
		s[0] = c++;
		View::WriteToView(xCoord + CELL_WIDTH * i + 2, yCoord - 1, s);
	}
}

void BoardContainer::DrawBoardVerticalLabels()
{
	char c = '1';
	for (int i = 0; i < Constants::BOARD_SIZE; ++i) {
		std::wstring s = L"1";

		if (i == 9) c = '0';
		if (i >= 9) {
			s = L"10";
			s[1] = c++;
			View::WriteToView(xCoord - 3, yCoord + CELL_HEIGHT * i + 1, s);

		}
		else {
			s[0] = c++;
			View::WriteToView(xCoord - 2, yCoord + CELL_HEIGHT * i + 1, s);
		}
	}
}


