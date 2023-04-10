#include "GameScreenView.h"

void GameScreenView::GameScreenView(NavigationHost& NavHost)
{
    std::mutex lock;
    GameScreenAction::ColorMatrix colorMatrix(
        Constants::BOARD_SIZE,
        std::vector<View::Color>(Constants::BOARD_SIZE, Theme::GetColor(ThemeColor::BORDER_COLOR))
    );
    NavHost.SetContext(Constants::NEXT_VIEW, Constants::NULL_VIEW);
    NavHost.SetContext(Constants::IS_SAVED, false);

    std::vector<GameAction::Point> ghostMoveList, warningPointList;

    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::CURRENT_GAME)
        );

    GameAction::Board gameBoard(
        Constants::BOARD_SIZE, std::vector<short>(Constants::BOARD_SIZE, 0)
    );

    NavHost.SetContext(Constants::CURRENT_BGM, Audio::Sound::GameBGM);
    if (Config::GetConfig(Config::BGMusic) == Config::Value_True) {
        if (BackgroundAudioService::GetCurrentSong() != Audio::Sound::GameBGM) {
            BackgroundAudioService::ChangeSong(Audio::Sound::GameBGM);
            BackgroundAudioService::Play(true, true);
        } else {
            BackgroundAudioService::Play(false, true);
        }
    }
    Utils::ON_SCOPE_EXIT on_exit([&NavHost] {
        NavHost.SetContext(Constants::CURRENT_BGM, Audio::Sound::MenuBGM);
        BackgroundAudioService::Stop();
    });

    auto& soundEffect = Config::GetConfig(L"SoundEffect");

    GameScreen gameScreen(7, 2);
    gameScreen.DrawGameScreen();
    gameScreen.DrawToElements(curGameState);

    AI myAI;
    myAI.SetDifficulty(curGameState.aiDifficulty);
    short moveCount = 0;

    GameAction::Point previousToLastMove = {-1, -1};
    Constants::Player prevPlayer;

    GameAction::Point latestMove = {-1, -1};
    Constants::Player curPlayer;

    GameScreenAction::LoadGameToView(
        gameScreen,
        gameBoard,
        moveCount,
        curGameState,
        myAI,
        warningPointList,
        colorMatrix,
        lock
    );

    short row = 0, col = 0;
    if (curGameState.moveList.size() != 0) {
        row = curGameState.moveList.back().first;
        col = curGameState.moveList.back().second;

        previousToLastMove = {
            curGameState.moveList.back().first,
            curGameState.moveList.back().second};

        latestMove = previousToLastMove;

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

    short endGame = 0;
    bool aiFirst =
        (curGameState.gameMode == Constants::GAME_MODE_PVE &&
         !isPlayerOneTurn && curGameState.moveList.size() == 0);

    View::Goto(
        gameScreen.boardContainer.xCoord + BoardContainer::X_OFFSET +
            gameScreen.boardContainer.CELL_WIDTH * col,
        gameScreen.boardContainer.yCoord + BoardContainer::Y_OFFSET +
            gameScreen.boardContainer.CELL_HEIGHT * row
    );

    const short timeAddition =
        (curGameState.gameType == Constants::GAME_TYPE_NORMAL) ? 1 : -1;

    Timer timerPlayerOne(
        [&] {
            if (!endGame) {
                curGameState.playerTimeOne += timeAddition;
                lock.lock();
                auto currPos = View::GetCursorPos();
                gameScreen.timerContainerOne.DrawToContainer(
                    Utils::SecondToMMSS(curGameState.playerTimeOne),
                    Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR)
                );
                View::Goto(currPos.X, currPos.Y);
                lock.unlock();
                if (curGameState.playerTimeOne == 0 && !endGame) {
                    endGame = Constants::END_GAME_WIN_TIME_TWO;
                    curGameState.playerScoreTwo++;
                    lock.lock();
                    gameScreen.timerContainerOne.DrawToContainer(
                        Language::GetString(L"TIME_OUT"),
                        Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR)
                    );
                    lock.unlock();

                    lock.lock();
                    gameScreen.logContainer.DrawToLogContainer(
                        curGameState.moveList,
                        curGameState.playerNameOne,
                        curGameState.playerNameTwo,
                        curGameState.playerOneFirst,
                        endGame
                    );
                    lock.unlock();
                }
            }
        },
        1000
    );


    
    Timer timerPlayerTwo(
        [&] {
            if (!endGame) {
                curGameState.playerTimeTwo += timeAddition;
                lock.lock();
                auto currPos = View::GetCursorPos();
                gameScreen.timerContainerTwo.DrawToContainer(
                    Utils::SecondToMMSS(curGameState.playerTimeTwo),
                    Theme::GetColor(ThemeColor::PLAYER_TWO_COLOR)
                );
                View::Goto(currPos.X, currPos.Y);
                lock.unlock();
                if (curGameState.playerTimeTwo == 0 && !endGame) {
                    endGame = Constants::END_GAME_WIN_TIME_ONE;

                    curGameState.playerScoreOne++;
                    lock.lock();
                    gameScreen.timerContainerTwo.DrawToContainer(
                        Language::GetString(L"TIME_OUT"),
                        Theme::GetColor(ThemeColor::PLAYER_TWO_COLOR)
                    );
                    lock.unlock();

                    lock.lock();
                    gameScreen.logContainer.DrawToLogContainer(
                        curGameState.moveList,
                        curGameState.playerNameOne,
                        curGameState.playerNameTwo,
                        curGameState.playerOneFirst,
                        endGame
                    );
                    lock.unlock();
                }
            }
        },
        1000
    );

    lock.lock();
    gameScreen.SwitchAndDrawCurrentTurn(curPlayer.value);
    lock.unlock();

    timerPlayerOne.Start();
    timerPlayerOne.Pause();
    timerPlayerTwo.Start();
    timerPlayerTwo.Pause();

    if (isPlayerOneTurn) {
        prevPlayer = Constants::PLAYER_TWO;
        curPlayer = Constants::PLAYER_ONE;
        timerPlayerOne.Continued();
    } else {
        prevPlayer = Constants::PLAYER_ONE;
        curPlayer = Constants::PLAYER_TWO;

        timerPlayerTwo.Continued();
    }
    

    std::wstring tmp;
    short prevRow = 0, prevCol = 0;

    GameScreenAction::HighLightCursor(
        gameScreen, gameBoard, {row, col}, colorMatrix, lock
    );

    if (aiFirst) {
        timerPlayerOne.Continued();
        timerPlayerTwo.Pause();

        latestMove = myAI.GetFirstMove();
        myAI.UpdatePrivateValues(latestMove);

        lock.lock();
        GameScreenAction::UpdateGame(
            gameScreen,
            gameBoard,
            moveCount,
            latestMove,
            curPlayer,
            curGameState
        );
        lock.unlock();

        lock.lock();
        GameScreenAction::HighlightMove(
            gameScreen, latestMove, curPlayer.symbol, colorMatrix
        );
        lock.unlock();

        GameScreenAction::FlipTurn(prevPlayer, curPlayer, isPlayerOneTurn);
    }

    GameAction::Point hintMove = {-1, -1};
    GameAction::Board currentBoard = gameBoard;
    bool isGhostMode = false;

    Audio::AudioPlayer gamePlaceSound(Audio::Sound::GamePlace);
    Audio::AudioPlayer gameMoveSound(Audio::Sound::GameMove);
    Audio::AudioPlayer warningSound(Audio::Sound::WarningSound);
    

    // Game loop
    while (!endGame) {
        tmp = InputHandle::Get();
        if (endGame) break;

        if (soundEffect == Config::Value_True) {
            if (tmp == L"\r") {
                gamePlaceSound.Play(1);
            } else if (tmp == L"ESC") {
                Audio::PlayAndForget(Audio::Sound::Pause);
            } else {
                // Audio::PlayAndForget(Audio::Sound::GameMove);
                gameMoveSound.Play();
            }
        }

        // Pauses the game
        if (tmp == L"ESC") {
            timerPlayerOne.Stop();
            timerPlayerTwo.Stop();
            GameScreenAction::UnhighlightCursor(
                gameScreen, currentBoard, {row, col}, colorMatrix, lock
            );

            GameScreenAction::TurnOffGhostMode(
                gameScreen,
                currentBoard,
                gameBoard,
                ghostMoveList,
                isGhostMode,
                isPlayerOneTurn,
                prevPlayer,
                curPlayer,
                colorMatrix,
                lock
            );

            NavHost.SetContext(Constants::CURRENT_GAME, curGameState);
            return NavHost.Navigate("PauseMenuView");
        }

        // Undo move
        if ((tmp == L"z" || tmp == L"Z") && curGameState.moveList.size() != 0 &&
            Config::GetConfig(Config::UndoOption) == Config::Value_True) {
            GameScreenAction::TurnOffGhostMode(
                gameScreen,
                currentBoard,
                gameBoard,
                ghostMoveList,
                isGhostMode,
                isPlayerOneTurn,
                prevPlayer,
                curPlayer,
                colorMatrix,
                lock
            );

            GameScreenAction::DeleteHintMove(
                gameScreen, hintMove, colorMatrix, lock
            );
            GameScreenAction::UnhighlightWarning(
                gameScreen, prevPlayer, warningPointList, colorMatrix, lock
            );

            if ((curGameState.gameMode == Constants::GAME_MODE_PVP) ||
                (curGameState.gameMode == Constants::GAME_MODE_PVE &&
                 (curGameState.moveList.size() > 2 ||
                  curGameState.playerOneFirst))) {
                lock.lock();
                GameScreenAction::UndoMove(
                    gameScreen,
                    gameBoard,
                    moveCount,
                    curGameState,
                    latestMove,
                    previousToLastMove,
                    curPlayer,
                    prevPlayer,
                    isPlayerOneTurn,
                    colorMatrix
                );
                lock.unlock();

                myAI.RevertPrivateValues();
            }

            if (curGameState.gameMode == Constants::GAME_MODE_PVE &&
                (curGameState.moveList.size() > 1 || curGameState.playerOneFirst
                )) {
                lock.lock();
                GameScreenAction::UndoMove(
                    gameScreen,
                    gameBoard,
                    moveCount,
                    curGameState,
                    latestMove,
                    previousToLastMove,
                    curPlayer,
                    prevPlayer,
                    isPlayerOneTurn,
                    colorMatrix
                );
                lock.unlock();

                myAI.RevertPrivateValues();
            }
            if (Config::GetConfig(Config::FourWarning) != Config::Value_True) {
                GameScreenAction::HighlightWarning(
                    gameScreen,
                    gameBoard,
                    latestMove,
                    prevPlayer,
                    warningPointList,
                    colorMatrix,
                    lock
                );
            }

            currentBoard = gameBoard;
        }

        // Turn on/off ghost mode
        if (tmp == L"g" || tmp == L"G") {
            if (isGhostMode) {
                GameScreenAction::TurnOffGhostMode(
                    gameScreen,
                    currentBoard,
                    gameBoard,
                    ghostMoveList,
                    isGhostMode,
                    isPlayerOneTurn,
                    prevPlayer,
                    curPlayer,
                    colorMatrix,
                    lock
                );
            } else
                isGhostMode = true;
        }

        if (Utils::keyMeanUp(tmp)) {
            if (row - 1 >= 0) {
                prevCol = col;
                prevRow = row;
                row--;
            }
        }
        if (Utils::keyMeanLeft(tmp)) {
            if (col - 1 >= 0) {
                prevCol = col;
                prevRow = row;
                col--;
            }
        }
        if (Utils::keyMeanDown(tmp)) {
            if (row + 1 < Constants::BOARD_SIZE) {
                prevCol = col;
                prevRow = row;
                row++;
            }
        }
        if (Utils::keyMeanRight(tmp)) {
            if (col + 1 < Constants::BOARD_SIZE) {
                prevCol = col;
                prevRow = row;
                col++;
            }
        }

        GameScreenAction::UnhighlightCursor(
            gameScreen, currentBoard, {prevRow, prevCol}, colorMatrix, lock
        );

        // Get hint
        if ((tmp == L"h" || tmp == L"H") &&
            Config::GetConfig(Config::Hint) == Config::Value_True) {
            GameScreenAction::TurnOffGhostMode(
                gameScreen,
                currentBoard,
                gameBoard,
                ghostMoveList,
                isGhostMode,
                isPlayerOneTurn,
                prevPlayer,
                curPlayer,
                colorMatrix,
                lock
            );

            GameScreenAction::DeleteHintMove(
                gameScreen, hintMove, colorMatrix, lock
            );
            hintMove = GameScreenAction::GetHintMove(
                gameBoard, moveCount, isPlayerOneTurn, myAI
            );
            currentBoard[hintMove.row][hintMove.col] = curPlayer.value;

            GameScreenAction::DrawHintMove(
                gameScreen, hintMove, curPlayer, colorMatrix, lock
            );
        }

        // Makes move
        if (tmp == L"\r" && !endGame) {
            if (gameBoard[row][col] == 0) {
                if (isGhostMode) {
                    GameScreenAction::MakeGhostMove(
                        gameScreen,
                        currentBoard,
                        ghostMoveList,
                        {row, col},
                        isPlayerOneTurn,
                        prevPlayer,
                        curPlayer,
                        colorMatrix,
                        lock
                    );
                }

                else {
                    GameScreenAction::DeleteHintMove(
                        gameScreen, hintMove, colorMatrix, lock
                    );
                    GameScreenAction::UnhighlightWarning(
                        gameScreen,
                        prevPlayer,
                        warningPointList,
                        colorMatrix,
                        lock
                    );

                    GameScreenAction::HandlePlayerMove(
                        gameScreen,
                        currentBoard,
                        gameBoard,
                        moveCount,
                        previousToLastMove,
                        latestMove,
                        {row, col},
                        isPlayerOneTurn,
                        prevPlayer,
                        curPlayer,
                        myAI,
                        curGameState,
                        endGame,
                        colorMatrix,
                        lock
                    );


                    if (isPlayerOneTurn) {
                        timerPlayerOne.Continued();
                        timerPlayerTwo.Pause();
                    } else {
                        timerPlayerTwo.Continued();
                        timerPlayerOne.Pause();
                    }

                    if (endGame) break;
                    if (Config::GetConfig(Config::FourWarning) !=
                        Config::Value_True && curGameState.gameMode == Constants::GAME_MODE_PVP) {
                        bool hasWarning = GameScreenAction::HighlightWarning(
                            gameScreen,
                            gameBoard,
                            latestMove,
                            prevPlayer,
                            warningPointList,
                            colorMatrix,
                            lock
                        );
                        if (hasWarning && soundEffect == Config::Value_True) {
                            warningSound.Play();
                        }
                    }

                    // AI's turn
                    if (curGameState.gameMode == Constants::GAME_MODE_PVE) {
                        GameScreenAction::HandlePlayerMove(
                            gameScreen,
                            currentBoard,
                            gameBoard,
                            moveCount,
                            previousToLastMove,
                            latestMove,
                            myAI.GetBestMove(gameBoard, moveCount),
                            isPlayerOneTurn,
                            prevPlayer,
                            curPlayer,
                            myAI,
                            curGameState,
                            endGame,
                            colorMatrix,
                            lock
                        );

                        GameScreenAction::UnhighlightWarning(
                            gameScreen,
                            curPlayer,
                            warningPointList,
                            colorMatrix,
                            lock
                        );

                        if (isPlayerOneTurn) {
                            timerPlayerOne.Continued();
                            timerPlayerTwo.Pause();
                        } else {
                            timerPlayerTwo.Continued();
                            timerPlayerOne.Pause();
                        }

                        if (endGame) break;

                        if (Config::GetConfig(Config::FourWarning) !=
                            Config::Value_True) {
                            bool hasWarning = GameScreenAction::HighlightWarning(
                                gameScreen,
                                gameBoard,
                                latestMove,
                                prevPlayer,
                                warningPointList,
                                colorMatrix,
                                lock
                            );
                            if (hasWarning && soundEffect == Config::Value_True) {
                                warningSound.Play();
                            }
                        }
                    }
                }
            }
        }

        // Move cursor to current position
        lock.lock();
        View::Goto(
            gameScreen.boardContainer.xCoord +
                BoardContainer::CELL_WIDTH * col + BoardContainer::X_OFFSET,
            gameScreen.boardContainer.yCoord +
                BoardContainer::CELL_HEIGHT * row + BoardContainer::Y_OFFSET
        );
        lock.unlock();

        // Highlight cursor
        GameScreenAction::HighLightCursor(
            gameScreen, currentBoard, {row, col}, colorMatrix, lock
        );
    }

    if (endGame != Constants::END_GAME_WIN_TIME_ONE &&
        endGame != Constants::END_GAME_WIN_TIME_TWO) {
        gameScreen.logContainer.DrawToLogContainer(
            curGameState.moveList,
            curGameState.playerNameOne,
            curGameState.playerNameTwo,
            curGameState.playerOneFirst,
            endGame
        );
    }

    while (tmp != L" ") {
        tmp = InputHandle::Get();
    }

    curGameState.gameEnd = endGame;
    NavHost.SetContext(Constants::FINISHED_GAME, curGameState);
    return NavHost.Navigate("GameEndView");
}