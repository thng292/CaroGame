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
        timerContainerOne.xCoord + timerContainerOne.cellWidth * 2 +
            playerContainerOne.cellWidth * 2 +
            winCountContainerOne.cellWidth * 2,
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

    
    Label::DrawGameScreenHint(logContainer.xCoord, logContainer.yCoord, logContainer.cellWidth, logContainer.cellHeight);
   
}

void GameScreen::DrawToElements(const GameState& gameState, bool isReplay)
{
    playerContainerOne.DrawToContainer(
        Constants::PLAYER_ONE.symbol, (View::Color)Constants::PLAYER_ONE_COLOR
    );
    playerContainerTwo.DrawToContainer(
        Constants::PLAYER_TWO.symbol, (View::Color)Constants::PLAYER_TWO_COLOR
    );

    short temp =
        (playerInfoContainerOne.cellWidth - gameState.playerNameOne.size()) / 2;
    playerInfoContainerOne.xOffset =
        (gameState.playerNameOne.size() % 2 == 0) ? temp + 1 : temp;

    temp =
        (playerInfoContainerTwo.cellWidth - gameState.playerNameTwo.size()) / 2;

    playerInfoContainerTwo.xOffset =
        (gameState.playerNameTwo.size() % 2 == 0) ? temp + 1 : temp;

    playerInfoContainerOne.DrawToContainer(
        gameState.playerNameOne, (View::Color)Constants::PLAYER_ONE_COLOR
    );
    playerInfoContainerTwo.DrawToContainer(
        gameState.playerNameTwo, (View::Color)Constants::PLAYER_TWO_COLOR
    );

    std::wstring playerScoreOne =
        (gameState.playerScoreOne < 10)
            ? std::format(L"0{}", gameState.playerScoreOne)
            : std::format(L"{}", gameState.playerScoreOne);

    std::wstring playerScoreTwo =
        (gameState.playerScoreTwo < 10)
            ? std::format(L"0{}", gameState.playerScoreTwo)
            : std::format(L"{}", gameState.playerScoreTwo);

    winCountContainerOne.DrawToContainer(
        playerScoreOne, View::Color::LIGHT_RED
    );
    winCountContainerTwo.DrawToContainer(
        playerScoreTwo, View::Color::LIGHT_BLUE
    );

    if (!isReplay) {
        timerContainerOne.DrawToContainer(
            Utils::SecondToMMSS(gameState.playerTimeOne),
            (View::Color)Constants::PLAYER_ONE_COLOR
        );
        timerContainerTwo.DrawToContainer(
            Utils::SecondToMMSS(gameState.playerTimeTwo),
            (View::Color)Constants::PLAYER_TWO_COLOR
        );
    } else {
        timerContainerOne.xOffset -= 1;
        timerContainerTwo.xOffset -= 1;

        timerContainerOne.DrawToContainer(L"\u221eREPLAY", View::Color::YELLOW);
        timerContainerTwo.DrawToContainer(L"REPLAY\u221e", View::Color::YELLOW);
    }

    const short avatarOffset[] = {3, 2, 3, 5, 2, 2, 3, 4};

    if (gameState.playerAvatarOne != 9)
        avatarMap[gameState.playerAvatarOne](
            playerInfoContainerOne.xCoord +
                avatarOffset[gameState.playerAvatarOne],
            playerInfoContainerOne.yCoord
        );
    if (gameState.playerAvatarTwo != 9)
        avatarMap[gameState.playerAvatarTwo](
            playerInfoContainerTwo.xCoord +
                avatarOffset[gameState.playerAvatarTwo],
            playerInfoContainerTwo.yCoord
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
