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
    InitElement(logContainer, x, y, 54, 6, 7, 1);
}

void GameScreen::DrawGameScreen(bool isReplay)
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
        Language::GetString(L"GAME_STATUS_TITLE")
    );

    Label::DrawLabelCenter(
        logContainer.xCoord,
        logContainer.xCoord + logContainer.cellWidth,
        logContainer.xCoord,
        logContainer.yCoord - 1,
        std::format(
            L"{} ({})",
            Language::GetString(L"MOVE_HISTORY_TITLE"),
            
            Label::GetShortcutString(
                Language::GetString(L"SCROLL_SHORTCUT"),
                Language::GetString(L"SCROLL_TITLE")
            )
        )
        

    );

    Label::DrawGameScreenHint(
        logContainer.xCoord,
        logContainer.yCoord,
        logContainer.cellWidth,
        logContainer.cellHeight,
        isReplay
    );
}

void GameScreen::DrawToElements(const GameState& gameState, bool isReplay)
{
    playerContainerOne.DrawToContainer(
        Constants::PLAYER_ONE.symbol, Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR)
    );
    playerContainerTwo.DrawToContainer(
        Constants::PLAYER_TWO.symbol, Theme::GetColor(ThemeColor::PLAYER_TWO_COLOR)
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
        gameState.playerNameOne, Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR)
    );
    playerInfoContainerTwo.DrawToContainer(
        gameState.playerNameTwo, Theme::GetColor(ThemeColor::PLAYER_TWO_COLOR)
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
        playerScoreOne, Theme::GetColor(ThemeColor::PLAYER_ONE_HIGHLIGHT_COLOR)
    );
    winCountContainerTwo.DrawToContainer(
        playerScoreTwo, Theme::GetColor(ThemeColor::PLAYER_TWO_HIGHLIGHT_COLOR)
    );

    if (!isReplay) {
        timerContainerOne.DrawToContainer(
            Utils::SecondToMMSS(gameState.playerTimeOne),
            Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR)
        );
        timerContainerTwo.DrawToContainer(
            Utils::SecondToMMSS(gameState.playerTimeTwo),
            Theme::GetColor(ThemeColor::PLAYER_TWO_COLOR)
        );
    } else {
        timerContainerOne.xOffset -= 1;
        timerContainerTwo.xOffset -= 1;

        timerContainerOne.DrawToContainer(L"\u221eREPLAY", Theme::GetColor(ThemeColor::RESULT_TEXT_COLOR));
        timerContainerTwo.DrawToContainer(L"REPLAY\u221e", Theme::GetColor(ThemeColor::RESULT_TEXT_COLOR));
    }

    const short avatarOffset[] = {3, 2, 3, 5, 2, 2, 3, 4, 2};

    avatarMap[gameState.playerAvatarOne](
        playerInfoContainerOne.xCoord + avatarOffset[gameState.playerAvatarOne],
        playerInfoContainerOne.yCoord
    );
    gameState.playerAvatarTwo;
    avatarMap[gameState.playerAvatarTwo](
        playerInfoContainerTwo.xCoord + avatarOffset[gameState.playerAvatarTwo],
        playerInfoContainerTwo.yCoord
    );
}

void GameScreen::SwitchAndDrawCurrentTurn(const short& currentPlayer) { 
    Container& playerToDelete = (currentPlayer == Constants::PLAYER_ONE.value)
                                    ? playerInfoContainerOne
                                    : playerInfoContainerTwo;
    Container& playerToDraw = (currentPlayer == Constants::PLAYER_ONE.value)
                             ? playerInfoContainerTwo
                             : playerInfoContainerOne;
    DeleteCurrentTurn(playerToDelete);
    DrawCurrentTurn(playerToDraw);
}

void GameScreen::DeleteCurrentTurn(Container& playerInfoContainer)
{
    xoaluot(playerInfoContainer.xCoord, playerInfoContainer.yCoord);
}

void GameScreen::DrawCurrentTurn(Container& playerInfoContainer)
{
    luot(playerInfoContainer.xCoord, playerInfoContainer.yCoord);
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
