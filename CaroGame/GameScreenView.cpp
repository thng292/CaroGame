#include "GameScreenView.h"


void GameScreenView::GameScreenView(NavigationHost& NavHost)
{
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::CURRENT_GAME));

    NavHost.SetContext(Constants::CURRENT_BGM, Audio::Sound::GameBGM);

    GameAction::Board gameBoard(
        Constants::BOARD_SIZE, std::vector<short>(Constants::BOARD_SIZE, 0)
    );

    if (Config::GetSetting(Config::BGMusic) == Config::Value_True) {
        auto bgmAudio = BackgroundAudioService::getInstance();
        if (bgmAudio->getPlayer()->getCurrentSong() != Audio::Sound::GameBGM) {
            bgmAudio->ChangeSong(Sound::GameBGM);
            bgmAudio->getPlayer()->Play(true, true);
        }
    }

    GameScreen gameScreen(7, 2);
    gameScreen.DrawGameScreen();
    gameScreen.DrawToElements(curGameState);

    AI myAI;
    myAI.SetDifficulty(curGameState.aiDifficulty);
    short moveCount = 0;

    GameAction::Point prevMove = {-1, -1};
    Constants::Player prevPlayer;

    GameScreenAction::LoadGameToView(gameScreen, gameBoard, moveCount, curGameState, myAI);

    short row = 0, col = 0;
    if (curGameState.moveList.size() != 0) {
        row = curGameState.moveList.back().first;
        col = curGameState.moveList.back().second;

        prevMove = {
            curGameState.moveList.back().first,
            curGameState.moveList.back().second};

        gameScreen.logContainer.DrawToLogContainer(
            curGameState.moveList,
            curGameState.playerNameOne,
            curGameState.playerNameTwo,
            curGameState.playerOneFirst
        );
    }

    int booltmp =
        (curGameState.playerOneFirst + (curGameState.moveList.size() % 2));
    bool isPlayerOneTurn = !(booltmp == 2 || booltmp == 0);

    bool endGame = 0;
    bool aiFirst =
        (curGameState.gameMode == Constants::GAME_MODE_PVE && !isPlayerOneTurn &&
         curGameState.moveList.size() == 0);

    View::Goto(
        gameScreen.boardContainer.xCoord + BoardContainer::X_OFFSET +
            gameScreen.boardContainer.CELL_WIDTH * col,
        gameScreen.boardContainer.yCoord + BoardContainer::Y_OFFSET +
            gameScreen.boardContainer.CELL_HEIGHT * row
    );

    const short timeAddition =
        (curGameState.gameType == Constants::GAME_TYPE_NORMAL) ? 1 : -1;

    std::mutex lock;

    Timer timerPlayerOne(
        [&] {
            if (!endGame) {
                auto currPos = View::GetCursorPos();
                curGameState.playerTimeOne += timeAddition;
                std::lock_guard guard(lock);
                gameScreen.timerContainerOne.DrawToContainer(
                    Utils::SecondToMMSS(curGameState.playerTimeOne)
                );
                View::Goto(currPos.X, currPos.Y);
                if (curGameState.playerTimeOne == 0) {
                    endGame = true;
                    curGameState.playerScoreTwo++;
                }
            }
        },
        1000
    );

    Timer timerPlayerTwo(
        [&] {
            if (!endGame) {
                auto currPos = View::GetCursorPos();
                std::lock_guard guard(lock);
                curGameState.playerTimeTwo += timeAddition;
                gameScreen.timerContainerTwo.DrawToContainer(
                    Utils::SecondToMMSS(curGameState.playerTimeTwo)
                );
                View::Goto(currPos.X, currPos.Y);
                if (curGameState.playerTimeTwo == 0) {
                    endGame = true;
                    curGameState.playerScoreOne++;
                }
            }
        },
        1000
    );

    timerPlayerOne.Start();
    timerPlayerOne.Pause();
    timerPlayerTwo.Start();
    timerPlayerTwo.Pause();

    if (isPlayerOneTurn) {
        prevPlayer = Constants::PLAYER_TWO;
        timerPlayerOne.Continued();
    } else {
        prevPlayer = Constants::PLAYER_ONE;

        timerPlayerTwo.Continued();
    }

  

    while (!endGame) {
        if (aiFirst) {
            GameAction::Point curMove = myAI.GetFirstMove();
            myAI.UpdatePrivateValues(curMove);
            Constants::Player curPlayer = Constants::PLAYER_TWO;
            timerPlayerOne.Continued();
            std::lock_guard guard(lock);
            GameScreenAction::UpdateGame(
                gameScreen,
                gameBoard,
                moveCount,
                curMove,
                curPlayer,
                curGameState
            );
            timerPlayerTwo.Pause();
            aiFirst = false;
            isPlayerOneTurn = !isPlayerOneTurn;

            GameScreenAction::HighlightMove(
                gameScreen, curMove, curPlayer.symbol
            );
            prevMove = curMove;
            prevPlayer = curPlayer;

        }

        auto tmp = InputHandle::Get();
        if (endGame) break;

        if (tmp == L"ESC") {
            timerPlayerOne.Stop();
            timerPlayerTwo.Stop();
            NavHost.SetContext(Constants::CURRENT_GAME, curGameState);
            return NavHost.NavigateStack("PauseMenuView");
        }

        if (Utils::keyMeanUp(tmp)) {
            if (row - 1 >= 0) {
                row--;
            }
        }
        if (Utils::keyMeanLeft(tmp)) {
            if (col - 1 >= 0) {
                col--;
            }
        }
        if (Utils::keyMeanDown(tmp)) {
            if (row + 1 < Constants::BOARD_SIZE) {
                row++;
            }
        }
        if (Utils::keyMeanRight(tmp)) {
            if (col + 1 < Constants::BOARD_SIZE) {
                col++;
            }
        }

        if (tmp == L"p" || tmp == L"P") {
            return NavHost.Navigate("ReplayMenuView");
        }

        if (tmp == L"\r") {
            if (gameBoard[row][col] == 0) {
                Constants::Player curPlayer;
                GameAction::Point curMove = {row, col};

                if (isPlayerOneTurn) {

                    curPlayer = Constants::PLAYER_ONE;

                    timerPlayerOne.Pause();
                } else {


                    curPlayer = Constants::PLAYER_TWO;
                    timerPlayerTwo.Pause();
                }

                lock.lock();
                GameScreenAction::UpdateGame(
                    gameScreen,
                    gameBoard,
                    moveCount,
                    curMove,
                    curPlayer,
                    curGameState
                );
                lock.unlock();

                GameScreenAction::HandleState(
                    gameBoard,
                    moveCount,
                    curMove,
                    curPlayer,
                    isPlayerOneTurn,
                    curGameState,
                    endGame,
                    gameScreen
                );

                // AI's turn
                if (!endGame && curGameState.gameMode == Constants::GAME_MODE_PVE) {
                    myAI.UpdatePrivateValues(curMove);
                    isPlayerOneTurn = !isPlayerOneTurn;

                    if (isPlayerOneTurn) {
                        curPlayer = Constants::PLAYER_ONE;
                        timerPlayerOne.Pause();
                    } else {
                        curPlayer = Constants::PLAYER_TWO;
                        timerPlayerTwo.Pause();
                    }

                    curMove = myAI.GetBestMove(gameBoard, moveCount);

                    if (isPlayerOneTurn) {
                        timerPlayerOne.Pause();
                    } else {
                        timerPlayerTwo.Pause();
                    }

                    lock.lock();
                    GameScreenAction::UpdateGame(
                        gameScreen,
                        gameBoard,
                        moveCount,
                        curMove,
                        curPlayer,
                        curGameState

                    );
                    lock.unlock();
                    myAI.UpdatePrivateValues(curMove);

                    GameScreenAction::HandleState(
                        gameBoard,
                        moveCount,
                        curMove,
                        curPlayer,
                        isPlayerOneTurn,
                        curGameState,
                        endGame,
                        gameScreen

                    );
                }

                if (isPlayerOneTurn) {
                    timerPlayerTwo.Continued();
                } else {
                    timerPlayerOne.Continued();
                }

                isPlayerOneTurn = !isPlayerOneTurn;

                if (!endGame) {
                    GameScreenAction::HighlightMove(
                        gameScreen, curMove, curPlayer.symbol
                    );
                    GameScreenAction::UnhightlightMove(
                        gameScreen, prevMove, prevPlayer.symbol
                    );
                }
                
                prevMove = curMove;
                prevPlayer = curPlayer;
            }
        }
        std::lock_guard guard(lock);
        View::Goto(
            gameScreen.boardContainer.xCoord +
                BoardContainer::CELL_WIDTH * col + BoardContainer::X_OFFSET,
            gameScreen.boardContainer.yCoord +
                BoardContainer::CELL_HEIGHT * row + BoardContainer::Y_OFFSET
        );
    }

    curGameState.playerTimeOne = curGameState.playerTimeTwo =
        curGameState.gameTime;

    auto tmp = InputHandle::Get();
    //curGameState.moveList.clear();
    NavHost.SetContext(Constants::CURRENT_GAME, curGameState);
    return NavHost.Navigate("ReplaySave");
}