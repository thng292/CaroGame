#include "BoardContainer.h"

void BoardContainer::DrawBoardContainer()
{
    DrawBoardRow();
    DrawBoardCol();
    DrawBoardHorizontalLabels();
    DrawBoardVerticalLabels();
}

void BoardContainer::DrawBoardRow()
{
    for (short row = 0; row < Constants::BOARD_SIZE + 1; ++row) {
        for (short i = 0; i < Constants::BOARD_SIZE; ++i) {
            for (short j = 0; j < CELL_WIDTH; j++) {
                View::WriteToView(
                    xCoord + i * CELL_WIDTH + j,
                    yCoord + row * CELL_HEIGHT,
                    L'\u2550',
                    false,
                    Theme::GetColor(ThemeColor::BORDER_COLOR)
                );
            }
        }
    }
}

void BoardContainer::DrawBoardCol()
{
    for (short col = 0; col < Constants::BOARD_SIZE + 1; ++col) {
        for (short i = 0; i < Constants::BOARD_SIZE; ++i) {
            for (short j = 0; j < CELL_HEIGHT; j++) {
                View::WriteToView(
                    xCoord + col * CELL_WIDTH,
                    yCoord + i * CELL_HEIGHT + j,
                    L'\u2551',
                    false,
                    Theme::GetColor(ThemeColor::BORDER_COLOR)
                );
            }
        }
    }
}

void BoardContainer::DrawToBoardContainerCell(
    short row, short col, std::wstring value, View::Color color, bool highlight, bool isGhostMode
)
{
    View::Color textHighlightColor =
        (color == Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR) || color == Theme::GetColor(ThemeColor::PLAYER_ONE_HIGHLIGHT_COLOR))
            ? Theme::GetColor(ThemeColor::PLAYER_ONE_HIGHLIGHT_COLOR)
            : Theme::GetColor(ThemeColor::PLAYER_TWO_HIGHLIGHT_COLOR);
    if (highlight) {
        View::Color highColor = Theme::GetColor(ThemeColor::CURSOR_COLOR);
        if (isGhostMode)
            highColor = Theme::GetColor(ThemeColor::GHOST_MOVE_COLOR);
        View::WriteToView(
            xCoord + col * CELL_WIDTH + X_OFFSET,
            yCoord + row * CELL_HEIGHT + Y_OFFSET,
            value,
            (wchar_t)0U,
            highlight,
            color,
            highColor,
            textHighlightColor,
            highColor

        );
    } else {
        View::WriteToView(
            xCoord + col * CELL_WIDTH + X_OFFSET,
            yCoord + row * CELL_HEIGHT + Y_OFFSET,
            value,
            (wchar_t)0U,
            highlight,
            color
        );
    }
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

        } else {
            s[0] = c++;
            View::WriteToView(xCoord - 2, yCoord + CELL_HEIGHT * i + 1, s);
        }
    }
}
