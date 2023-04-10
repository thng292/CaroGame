#include "CornersHandler.h"

#include "BoardContainer.h"
#include "Constants.h"
#include "View.h"

void CornersHandler::FixBoardCorners(short x, short y)
{
    // Fixes the surrounding 4 corners
    View::WriteToView(
        x, y, L'\u2554', 0, Theme::GetColor(ThemeColor::BORDER_COLOR)
    );
    View::WriteToView(
        x + Constants::BOARD_SIZE * BoardContainer::CELL_WIDTH,
        y,
        L'\u2557',
        0,
        Theme::GetColor(ThemeColor::BORDER_COLOR)
    );
    View::WriteToView(
        x,
        y + Constants::BOARD_SIZE * BoardContainer::CELL_HEIGHT,
        L'\u255A',
        0,
        Theme::GetColor(ThemeColor::BORDER_COLOR)
    );
    View::WriteToView(
        x + Constants::BOARD_SIZE * BoardContainer::CELL_WIDTH,
        y + Constants::BOARD_SIZE * BoardContainer::CELL_HEIGHT,
        L'\u255D',
        0,
        Theme::GetColor(ThemeColor::BORDER_COLOR)
    );

    // Fixes the top and bottom corners
    for (short i = 1; i < Constants::BOARD_SIZE; ++i) {
        View::WriteToView(
            x + i * BoardContainer::CELL_WIDTH,
            y,
            L'\u2566',
            0,
            Theme::GetColor(ThemeColor::BORDER_COLOR)
        );
        View::WriteToView(
            x + i * BoardContainer::CELL_WIDTH,
            y + Constants::BOARD_SIZE * BoardContainer::CELL_HEIGHT,
            L'\u2569',
            0,
            Theme::GetColor(ThemeColor::BORDER_COLOR)
        );
    }

    // Fixes the cells corners
    for (short row = 1; row < Constants::BOARD_SIZE; ++row) {
        for (short col = 1; col < Constants::BOARD_SIZE; ++col) {
            View::WriteToView(
                x + col * BoardContainer::CELL_WIDTH,
                y + row * BoardContainer::CELL_HEIGHT,
                L'\u256C',
                0,
                Theme::GetColor(ThemeColor::BORDER_COLOR)
            );
        }
    }

    // Fixes the side corners
    for (short i = 1; i < Constants::BOARD_SIZE; ++i) {
        View::WriteToView(
            x,
            y + i * BoardContainer::CELL_HEIGHT,
            L'\u2560',
            0,
            Theme::GetColor(ThemeColor::BORDER_COLOR)
        );
        View::WriteToView(
            x + Constants::BOARD_SIZE * BoardContainer::CELL_WIDTH,
            y + i * BoardContainer::CELL_HEIGHT,
            L'\u2563',
            0,
            Theme::GetColor(ThemeColor::BORDER_COLOR)
        );
    }
}

void CornersHandler::FixStatusBarCorners(
    short x,
    short y,
    const Container& timerContainer,
    const Container& winCountContainer,
    const Container& playerContainer
)
{
    short xCur = x;
    xCur += timerContainer.cellWidth;
    View::WriteToView(
        xCur, y, L'\u2566', 0, Theme::GetColor(ThemeColor::BORDER_COLOR)
    );
    View::WriteToView(
        xCur,
        y + timerContainer.cellHeight,
        L'\u2569',
        0,
        Theme::GetColor(ThemeColor::BORDER_COLOR)
    );
    xCur += winCountContainer.cellWidth;
    View::WriteToView(
        xCur, y, L'\u2566', 0, Theme::GetColor(ThemeColor::BORDER_COLOR)
    );
    View::WriteToView(
        xCur,
        y + timerContainer.cellHeight,
        L'\u2569',
        0,
        Theme::GetColor(ThemeColor::BORDER_COLOR)
    );
    xCur += playerContainer.cellWidth;
    View::WriteToView(
        xCur, y, L'\u2566', 0, Theme::GetColor(ThemeColor::BORDER_COLOR)
    );
    View::WriteToView(
        xCur,
        y + timerContainer.cellHeight,
        L'\u2569',
        0,
        Theme::GetColor(ThemeColor::BORDER_COLOR)
    );
    xCur += playerContainer.cellWidth;
    View::WriteToView(
        xCur, y, L'\u2566', 0, Theme::GetColor(ThemeColor::BORDER_COLOR)
    );
    View::WriteToView(
        xCur,
        y + timerContainer.cellHeight,
        L'\u2569',
        0,
        Theme::GetColor(ThemeColor::BORDER_COLOR)
    );
    xCur += winCountContainer.cellWidth;
    View::WriteToView(
        xCur, y, L'\u2566', 0, Theme::GetColor(ThemeColor::BORDER_COLOR)
    );
    View::WriteToView(
        xCur,
        y + timerContainer.cellHeight,
        L'\u2569',
        0,
        Theme::GetColor(ThemeColor::BORDER_COLOR)
    );
}

void CornersHandler::FixPlayerInfoCorners(
    short x, short y, const Container& playerInfoContainer
)
{
    View::WriteToView(
        x + playerInfoContainer.cellWidth,
        y,
        L'\u2566',
        0,
        Theme::GetColor(ThemeColor::BORDER_COLOR)
    );
    View::WriteToView(
        x + playerInfoContainer.cellWidth,
        y + playerInfoContainer.cellHeight,
        L'\u2569',
        0,
        Theme::GetColor(ThemeColor::BORDER_COLOR)
    );
}
