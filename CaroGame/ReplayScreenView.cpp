#include "ReplayScreenView.h"

void ReplayScreenView::ReplayScreenView(NavigationHost& NavHost)
{
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::FINISHED_GAME)
        );

    GameState tempGameState = curGameState;
    tempGameState.moveList.clear();

    GameAction::Board gameBoard(
        Constants::BOARD_SIZE, std::vector<short>(Constants::BOARD_SIZE, 0)
    );

    GameScreen gameScreen(7, 2);
    gameScreen.DrawGameScreen();
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

        if (tmp == L"ESC") {
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

                GameScreenAction::UnhightlightMove(
                    gameScreen, prevMove, prevPlayer.symbol
                );

            } else {
                index--;
                if (endGame) {
                    Constants::Player temp = (isPlayerOneTurn)
                                                 ? Constants::PLAYER_TWO
                                                 : Constants::PLAYER_ONE;
                    GameScreenAction::HightLightWin(
                        winPoint, curMove, temp.symbol, gameScreen, true
                    );
                    endGame = false;
                }
                GameScreenAction::DeleteMoveFromScreen(gameScreen, curMove);

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

            if (!endGame)
                GameScreenAction::HighlightMove(
                    gameScreen, curMove, curPlayer.symbol
                );

            prevMove = curMove;
            prevPlayer = curPlayer;

            isPlayerOneTurn = !isPlayerOneTurn;
        }
    }
    return NavHost.Back();
}
