#include "GameScreen.h"

#include <vector>

#include "Constants.h"
#include "CornersHandler.h"

GameScreen::GameScreen(short x, short y) {
    boardContainer.xCoord = x, boardContainer.yCoord = y;
    x += Constants::BOARD_SIZE * BoardContainer::CELL_WIDTH + 5;
    y += 1;
    const short X_PIVOT = x;  // Resets X to original position (next to board)
    InitElement(timerContainerOne, x, y, 12, 2, 3, 1);
    x += timerContainerOne.cellWidth;

    InitElement(winCountContainerOne, x, y, 7, 2, 3, 1);
    x += winCountContainerOne.cellWidth;

    InitElement(playerContainerOne, x, y, 6, 2, 3, 1);
    x += playerContainerOne.cellWidth;

    InitElement(playerContainerTwo, x, y, 6, 2, 3, 1);
    x += playerContainerTwo.cellWidth;

    InitElement(winCountContainerTwo, x, y, 7, 2, 3, 1);
    x += winCountContainerTwo.cellWidth;

    InitElement(timerContainerTwo, x, y, 12, 2, 3, 1);

    x = X_PIVOT;
    y += timerContainerOne.cellHeight * 2;
    InitElement(playerInfoContainerOne, x, y, 25, 4, 3, 1);
    x += playerInfoContainerOne.cellWidth;
    InitElement(playerInfoContainerTwo, x, y, 25, 4, 3, 1);

    x = X_PIVOT;
    y += playerInfoContainerOne.cellHeight + timerContainerOne.cellHeight;
    InitElement(logContainer, x, y, 50, 7, 3, 1);
}

void GameScreen::DrawGameScreen() {
    boardContainer.DrawBoardContainer();
    timerContainerOne.DrawContainer();
    winCountContainerOne.DrawContainer();
    playerContainerOne.DrawContainer();
    playerContainerTwo.DrawContainer();
    winCountContainerTwo.DrawContainer();
    timerContainerTwo.DrawContainer();
    playerInfoContainerOne.DrawContainer();
    playerInfoContainerTwo.DrawContainer();
    logContainer.DrawContainer();

    CornersHandler::FixBoardCorners(
        boardContainer.xCoord, boardContainer.yCoord
    );
    CornersHandler::FixPlayerInfoCorners(
        playerInfoContainerOne.xCoord, playerInfoContainerOne.yCoord,
        playerInfoContainerOne
    );
    CornersHandler::FixStatusBarCorners(
        timerContainerOne.xCoord, timerContainerOne.yCoord, timerContainerOne,
        winCountContainerOne, playerContainerOne
    );

    Label::DrawLabelCenter(
        logContainer.xCoord, logContainer.xCoord + logContainer.cellWidth,
        timerContainerOne.xCoord, timerContainerOne.yCoord - 1, L"Game Status"
    );
    Label::DrawLabelCenter(
        logContainer.xCoord, logContainer.xCoord + logContainer.cellWidth,
        playerInfoContainerOne.xCoord, playerInfoContainerOne.yCoord - 1,
        L"Player Info"
    );
    Label::DrawLabelCenter(
        logContainer.xCoord, logContainer.xCoord + logContainer.cellWidth,
        logContainer.xCoord, logContainer.yCoord - 1, L"Move History"
    );

    const std::vector<std::wstring> INSTRUCTION_LIST = {
        L"A: Lorem ispum", L"A: Lorem ispum", L"A: Lorem ispum",
        L"A: Lorem ispum", L"A: Lorem ispum", L"A: Lorem ispum",
        L"A: Lorem ispum", L"A: Lorem ispum", L"A: Lorem ispum"};
    Label::DrawLabelGrid(
        logContainer.xCoord, logContainer.xCoord + logContainer.cellWidth,
        logContainer.xCoord, logContainer.yCoord + logContainer.cellHeight + 2,
        INSTRUCTION_LIST, 3
    );
}

void GameScreen::DrawToElements(GameState gameState) {
    playerContainerOne.DrawToContainer(L"X");
    playerContainerTwo.DrawToContainer(L"O");

    playerInfoContainerOne.DrawToContainer(gameState.playerNameOne);
    playerInfoContainerTwo.DrawToContainer(gameState.playerNameTwo);

    std::wstring playerScoreOne =
        (gameState.playerScoreOne < 10)
            ? std::format(L"0{}", gameState.playerScoreOne)
            : std::format(L"{}", gameState.playerScoreOne);

    std::wstring playerScoreTwo =
        (gameState.playerScoreTwo < 10)
            ? std::format(L"0{}", gameState.playerScoreTwo)
            : std::format(L"{}", gameState.playerScoreTwo);

    winCountContainerOne.DrawToContainer(playerScoreOne);
    winCountContainerTwo.DrawToContainer(playerScoreTwo);
}

void GameScreen::InitElement(
    Container& element, short x, short y, short cell_width, short cell_height,
    short x_offset, short y_offset
) {
    element.xCoord = x;
    element.yCoord = y;
    element.cellWidth = cell_width;
    element.cellHeight = cell_height;
    element.xOffset = x_offset;
    element.yOffset = y_offset;
}
