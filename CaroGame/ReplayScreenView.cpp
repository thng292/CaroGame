#include "ReplayScreenView.h"

void ReplayScreenView::ReplayScreenView(NavigationHost& NavHost)
{
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::FINISHED_GAME)
        );

    GameScreenAction::ColorMatrix colorMatrix(Constants::BOARD_SIZE, std::vector<View::Color>(Constants::BOARD_SIZE, (View::Color)0));

    GameState tempGameState = curGameState;
    tempGameState.moveList.clear();

    GameAction::Board gameBoard(
        Constants::BOARD_SIZE, std::vector<short>(Constants::BOARD_SIZE, 0)
    );

    GameScreen gameScreen(7, 2);
    gameScreen.DrawGameScreen(1);
    gameScreen.DrawToElements(curGameState, true);

    short moveCount = 0;

    GameAction::Point prevMove = {-1, -1};
    Constants::Player prevPlayer;

    short row = 0, col = 0;

    bool isPlayerOneTurn = curGameState.playerOneFirst;
    short endGame = 0;
    short index = -1;
    short moveListSize = curGameState.moveList.size();

    GameAction::Point curMove = {-1, -1};
    GameAction::Point winPoint;

    if (moveListSize == 0) {
        gameScreen.logContainer.DrawToLogContainer(
            curGameState.moveList,
            curGameState.playerNameOne,
            curGameState.playerNameTwo,
            curGameState.playerOneFirst,
            curGameState.gameEnd,
            true
        );
        while (1) {
            auto tmp = InputHandle::Get();
        
        if (tmp == L"ESC") {
                break;
            }
        }
    }

    else {
        while (1) {
            auto tmp = InputHandle::Get();
            bool validKey = false, moveBack = false;
            Constants::Player curPlayer;

            if (Utils::keyMeanLeft(tmp) && index >= 0) {
                validKey = true;
                moveBack = true;
            }

            if (Utils::keyMeanRight(tmp) && index < moveListSize - 1) {
                validKey = true;
            }

            if (tmp == L"b" || tmp == L"B") {
                break;
            }

            if (validKey) {
                if (!moveBack) {
                    index++;
                    curMove = {
                        curGameState.moveList[index].first,
                        curGameState.moveList[index].second};

                    curPlayer = (isPlayerOneTurn) ? Constants::PLAYER_ONE
                                                  : Constants::PLAYER_TWO;
                    GameScreenAction::UpdateGame(
                        gameScreen,
                        gameBoard,
                        moveCount,
                        curMove,
                        curPlayer,
                        tempGameState
                    );

                    winPoint = GameScreenAction::HandleState(
                        gameBoard,
                        moveCount,
                        curMove,
                        curPlayer,
                        isPlayerOneTurn,
                        tempGameState,
                        endGame,
                        gameScreen
                    );

                    if (index == curGameState.moveList.size() - 1) {
                        if (endGame == 0) endGame = curGameState.gameEnd;
                        gameScreen.logContainer.DrawToLogContainer(
                            curGameState.moveList,
                            curGameState.playerNameOne,
                            curGameState.playerNameTwo,
                            curGameState.playerOneFirst,
                            endGame,
                            true
                        );
                    }

                    GameScreenAction::UnhightlightMove(
                        gameScreen, prevMove, prevPlayer.symbol, colorMatrix
                    );

                } else {
                    index--;
                    if (endGame) {
                        if (endGame == Constants::END_GAME_WIN_ONE ||
                            endGame == Constants::END_GAME_WIN_TWO) {
                            Constants::Player temp =
                                (isPlayerOneTurn) ? Constants::PLAYER_TWO
                                                  : Constants::PLAYER_ONE;
                            GameScreenAction::HightLightWin(
                                winPoint, curMove, temp.symbol, gameScreen, true
                            );
                        }

                        endGame = 0;
                    }
                    GameScreenAction::DeleteMoveFromScreen(gameScreen, curMove, colorMatrix);

                    tempGameState.moveList.pop_back();

                    if (index >= 0) {
                        GameAction::UndoMove(gameBoard, moveCount, curMove);
                        tempGameState.moveList.pop_back();

                        curMove = {
                            curGameState.moveList[index].first,
                            curGameState.moveList[index].second};

                    } else {
                        curMove = {-1, -1};
                    }

                    curPlayer = (isPlayerOneTurn) ? Constants::PLAYER_ONE
                                                  : Constants::PLAYER_TWO;

                    GameScreenAction::UpdateGame(
                        gameScreen,
                        gameBoard,
                        moveCount,
                        curMove,
                        curPlayer,
                        tempGameState
                    );
                }

                if (endGame != Constants::END_GAME_WIN_ONE &&
                    endGame != Constants::END_GAME_WIN_TWO)
                    GameScreenAction::HighlightMove(
                        gameScreen, curMove, curPlayer.symbol, colorMatrix
                    );

                prevMove = curMove;
                prevPlayer = curPlayer;

                isPlayerOneTurn = !isPlayerOneTurn;
            }
        }
    }
    return NavHost.Back();
}
