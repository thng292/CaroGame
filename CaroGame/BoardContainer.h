#pragma once
#include <string>
#include "Container.h"

class BoardContainer {
public:
	static const short CELL_WIDTH = 4, CELL_HEIGHT = 2;
	static const short X_OFFSET = 2, Y_OFFSET = 1;
	short xCoord, yCoord;
	void DrawBoardContainer();
	void DrawBoardRow();
	void DrawBoardCol();
	void DrawToBoardContainerCell(short row, short col, std::wstring value);
	void DrawBoardHorizontalLabels();
	void DrawBoardVerticalLabels();
};