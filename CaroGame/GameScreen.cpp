#include "GameScreen.h"

#include <vector>

#include "Constants.h"
#include "CornersHandler.h"

GameScreen::GameScreen(short x, short y)
{
    boardContainer.xCoord = x, boardContainer.yCoord = y;
    x += Constants::BOARD_SIZE * BoardContainer::CELL_WIDTH + 3;
    // y += 1;
    const short X_PIVOT = x;  // Resets X to original position (next to board)
    x += 2;
    InitElement(timerContainerOne, x, y, 12, 2, 4, 1);
    x += timerContainerOne.cellWidth;

    InitElement(winCountContainerOne, x, y, 7, 2, 3, 1);
    x += winCountContainerOne.cellWidth;

    InitElement(playerContainerOne, x, y, 6, 2, 3, 1);
    x += playerContainerOne.cellWidth;

    InitElement(playerContainerTwo, x, y, 6, 2, 3, 1);
    x += playerContainerTwo.cellWidth;

    InitElement(winCountContainerTwo, x, y, 7, 2, 3, 1);
    x += winCountContainerTwo.cellWidth;

    InitElement(timerContainerTwo, x, y, 12, 2, 4, 1);

    x = X_PIVOT;
    y += timerContainerOne.cellHeight + 1;
    InitElement(playerInfoContainerOne, x, y, 27, 12, 9, 0);
    x += playerInfoContainerOne.cellWidth;
    InitElement(playerInfoContainerTwo, x, y, 27, 12, 8, 0);

    x = X_PIVOT;
    y += playerInfoContainerOne.cellHeight + timerContainerOne.cellHeight;
    InitElement(logContainer, x, y, 54, 7, 7, 1);



}

void GameScreen::DrawGameScreen()
{
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
        playerInfoContainerOne.xCoord,
        playerInfoContainerOne.yCoord,
        playerInfoContainerOne
    );
    CornersHandler::FixStatusBarCorners(
        timerContainerOne.xCoord,
        timerContainerOne.yCoord,
        timerContainerOne,
        winCountContainerOne,
        playerContainerOne
    );

    Label::DrawLabelCenter(
        timerContainerOne.xCoord,
        timerContainerOne.xCoord + timerContainerOne.cellWidth * 2 + playerContainerOne.cellWidth * 2 + winCountContainerOne.cellWidth * 2,
        timerContainerOne.xCoord,
        timerContainerOne.yCoord - 1,
        L"Game Status"
    );
    /* Label::DrawLabelCenter(
         logContainer.xCoord,
         logContainer.xCoord + logContainer.cellWidth,
         playerInfoContainerOne.xCoord,
         playerInfoContainerOne.yCoord - 1,
         L"Player Info"
     );*/
    Label::DrawLabelCenter(
        logContainer.xCoord,
        logContainer.xCoord + logContainer.cellWidth,
        logContainer.xCoord,
        logContainer.yCoord - 1,
        L"Move History"
    );

    const std::vector<std::wstring> INSTRUCTION_LIST = {
        L"A: Lorem ispum",
        L"A: Lorem ispum",
        L"A: Lorem ispum",
        L"A: Lorem ispum",
    };
    Label::DrawLabelGrid(
        logContainer.xCoord,
        logContainer.xCoord + logContainer.cellWidth,
        logContainer.xCoord,
        logContainer.yCoord + logContainer.cellHeight + 1,
        INSTRUCTION_LIST,
        2
    );
}

void GameScreen::DrawToElements(const GameState& gameState, bool isReplay)
{
    playerContainerOne.DrawToContainer(L"X");
    playerContainerTwo.DrawToContainer(L"O");

    short temp =
        (playerInfoContainerOne.cellWidth - gameState.playerNameOne.size()) / 2;
    playerInfoContainerOne.xOffset =
        (gameState.playerNameOne.size() % 2 == 0) ? temp + 1 : temp;

    temp =
        (playerInfoContainerTwo.cellWidth - gameState.playerNameTwo.size()) / 2;

    playerInfoContainerTwo.xOffset =
        (gameState.playerNameTwo.size() % 2 == 0) ? temp + 1 : temp;

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

    if (!isReplay) {
        timerContainerOne.DrawToContainer(
            Utils::SecondToMMSS(gameState.playerTimeOne)
        );
        timerContainerTwo.DrawToContainer(
            Utils::SecondToMMSS(gameState.playerTimeTwo)
        );
    } else {
        timerContainerOne.xOffset -= 1;
        timerContainerTwo.xOffset -= 1;

        timerContainerOne.DrawToContainer(L"\u221eREPLAY");
        timerContainerTwo.DrawToContainer(L"REPLAY\u221e");
    }

    if (gameState.playerAvatarOne != 9 ) avatarMap[gameState.playerAvatarOne](playerInfoContainerOne.xCoord + 3, playerInfoContainerOne.yCoord);
    if (gameState.playerAvatarTwo != 9)
        avatarMap[gameState.playerAvatarTwo](
        playerInfoContainerTwo.xCoord + 3, playerInfoContainerTwo.yCoord
    );


}


void GameScreen::InitElement(
    Container& element,
    short x,
    short y,
    short cell_width,
    short cell_height,
    short x_offset,
    short y_offset
)
{
    element.xCoord = x;
    element.yCoord = y;
    element.cellWidth = cell_width;
    element.cellHeight = cell_height;
    element.xOffset = x_offset;
    element.yOffset = y_offset;
}
