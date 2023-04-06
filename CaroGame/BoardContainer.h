#pragma once
#include <string>

#include "Container.h"

// Container for the actual game's board
class BoardContainer {
   public:
    static const short CELL_WIDTH = 4, CELL_HEIGHT = 2;
    static const short X_OFFSET = 2, Y_OFFSET = 1;
    short xCoord, yCoord;

    void DrawBoardContainer();
    void DrawBoardRow();
    void DrawBoardCol();

    // Draws to the board's cell
    void DrawToBoardContainerCell(short row, short col, std::wstring value, View::Color color = View::Color::BLACK, bool highlight=false);

    // Draws the horizontal labels (Letters)
    void DrawBoardHorizontalLabels();

    // Draws the vertical labels (Numbers)
    void DrawBoardVerticalLabels();
};