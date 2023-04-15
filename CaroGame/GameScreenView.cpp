#include "GameScreenView.h"

void GameScreenView::GameScreenView(NavigationHost& NavHost)
{
    // Setting essential context
    NavHost.SetContext(Constants::NEXT_VIEW, Constants::NULL_VIEW);
    NavHost.SetContext(Constants::IS_SAVED, false);
    NavHost.SetContext(Constants::CURRENT_BGM, Audio::Sound::GameBGM);

    // Game graphic related variables declaration
    std::mutex lock;
    GameScreenAction::ColorMatrix colorMatrix(
        Constants::BOARD_SIZE,
        std::vector<View::Color>(Constants::BOARD_SIZE, View::Color::BLACK)
    );

    std::wstring tmp;

    // Game backend related variables declaration
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::CURRENT_GAME)
        );

    // + Moves, players and board related variables
    GameAction::Board gameBoard(
        Constants::BOARD_SIZE, std::vector<short>(Constants::BOARD_SIZE, 0)
    );
    short prevRow = 0, prevCol = 0;
    GameAction::Board currentBoard;
    short moveCount = 0;
    short row = 0, col = 0;
    GameAction::Point previousToLastMove = {-1, -1};
    Constants::Player prevPlayer;

    GameAction::Point latestMove = {-1, -1};
    Constants::Player curPlayer;

    const int booltmp =
        (curGameState.playerOneFirst + (curGameState.moveList.size() % 2));
    bool isPlayerOneTurn = !(booltmp == 2 || booltmp == 0);

    short endGame = 0;

    // + AI related variables
    AI myAI;
    const bool aiFirst =
        (curGameState.gameMode == Constants::GAME_MODE_PVE &&
         !isPlayerOneTurn && curGameState.moveList.size() == 0);
    myAI.SetDifficulty(curGameState.aiDifficulty);

    // + Timers related variables
    const short timeAddition =
        (curGameState.gameType == Constants::GAME_TYPE_NORMAL) ? 1 : -1;

    // + Game utilities related variables
    bool isGhostMode = false;
    short goBack = 0;
    GameAction::Point hintMove = {-1, -1};
    std::vector<GameAction::Point> ghostMoveList, warningPointList;

    // Backgounrd music config check
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

    Audio::AudioPlayer gamePlaceSound(Audio::Sound::GamePlace);
    Audio::AudioPlayer gameWinSound(Audio::Sound::WinSound);
    Audio::AudioPlayer warningSound(Audio::Sound::WarningSound);
    Audio::AudioPlayer hintSound(Audio::Sound::Hint);
    Audio::AudioPlayer undoSound(Audio::Sound::Undo);
    Audio::AudioPlayer ghostSound(Audio::Sound::Ghost);
    Audio::AudioPlayer ghostOffSound(Audio::Sound::GhostOff);

    auto& soundEffect = Config::GetConfig(L"SoundEffect");

    // Game screen initialization
    GameScreen gameScreen(7, 2);
    gameScreen.DrawGameScreen();
    gameScreen.DrawToElements(curGameState);

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

    currentBoard = gameBoard;

    // Move related variable and log container initialization
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

    // Moves cursor to latest position
    View::Goto(
        gameScreen.boardContainer.xCoord + BoardContainer::X_OFFSET +
            gameScreen.boardContainer.CELL_WIDTH * col,
        gameScreen.boardContainer.yCoord + BoardContainer::Y_OFFSET +
            gameScreen.boardContainer.CELL_HEIGHT * row
    );

    // Timers initialization
    Timer timerPlayerOne([&] {
        if (!endGame) {
            curGameState.playerTimeOne += timeAddition;
            std::lock_guard guard(lock);
            auto currPos = View::GetCursorPos();
            gameScreen.timerContainerOne.DrawToContainer(
                Utils::SecondToMMSS(curGameState.playerTimeOne),
                Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR)
            );
            View::Goto(currPos.X, currPos.Y);
            if (curGameState.playerTimeOne == 0 && !endGame) {
                endGame = Constants::END_GAME_WIN_TIME_TWO;
                curGameState.playerScoreTwo++;
                gameScreen.timerContainerOne.DrawToContainer(
                    Language::GetString(L"TIME_OUT"),
                    Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR)
                );
                gameScreen.logContainer.DrawToLogContainer(
                    curGameState.moveList,
                    curGameState.playerNameOne,
                    curGameState.playerNameTwo,
                    curGameState.playerOneFirst,
                    endGame
                );
            }
        }
    });

    Timer timerPlayerTwo([&] {
        if (!endGame) {
            curGameState.playerTimeTwo += timeAddition;
            std::lock_guard guard(lock);
            auto currPos = View::GetCursorPos();
            gameScreen.timerContainerTwo.DrawToContainer(
                Utils::SecondToMMSS(curGameState.playerTimeTwo),
                Theme::GetColor(ThemeColor::PLAYER_TWO_COLOR)
            );
            View::Goto(currPos.X, currPos.Y);
            if (curGameState.playerTimeTwo == 0 && !endGame) {
                endGame = Constants::END_GAME_WIN_TIME_ONE;

                curGameState.playerScoreOne++;
                gameScreen.timerContainerTwo.DrawToContainer(
                    Language::GetString(L"TIME_OUT"),
                    Theme::GetColor(ThemeColor::PLAYER_TWO_COLOR)
                );

                gameScreen.logContainer.DrawToLogContainer(
                    curGameState.moveList,
                    curGameState.playerNameOne,
                    curGameState.playerNameTwo,
                    curGameState.playerOneFirst,
                    endGame
                );
            }
        }
    });

    // Draws current player's turn graphic
    lock.lock();
    gameScreen.SwitchAndDrawCurrentTurn(curPlayer.value);
    lock.unlock();

    // Timers activation
    timerPlayerOne.Start();
    timerPlayerOne.Pause();
    timerPlayerTwo.Start();
    timerPlayerTwo.Pause();

    if (isPlayerOneTurn) {
        prevPlayer = Constants::PLAYER_TWO;
        curPlayer = Constants::PLAYER_ONE;
        timerPlayerOne.Continue();
    } else {
        prevPlayer = Constants::PLAYER_ONE;
        curPlayer = Constants::PLAYER_TWO;

        timerPlayerTwo.Continue();
    }

    // Highlight cursor's first posistion
    GameScreenAction::HighLightCursor(
        gameScreen, gameBoard, {row, col}, colorMatrix, lock, isGhostMode
    );

    // Make AI's first move
    if (aiFirst) {
        Sleep(500);
        timerPlayerOne.Continue();
        timerPlayerTwo.Pause();

        GameScreenAction::HandlePlayerMove(
            gameScreen,
            currentBoard,
            gameBoard,
            moveCount,
            previousToLastMove,
            latestMove,
            myAI.GetFirstMove(),
            isPlayerOneTurn,
            prevPlayer,
            curPlayer,
            myAI,
            curGameState,
            endGame,
            colorMatrix,
            lock
        );
        if (soundEffect == Config::Value_True) gamePlaceSound.Play();
    }

    // Game loop
    while (!endGame) {
        tmp = InputHandle::Get();
        if (endGame) break;

        if (soundEffect == Config::Value_True) {
            if (tmp == L"\r") {
                gamePlaceSound.Play(1);
            } else if (tmp == L"ESC") {
                Audio::PlayAndForget(Audio::Sound::Pause);
            }
        }

        // Pauses the game
        if (tmp == L"ESC") {
            NavHost.SetContext(Constants::CURRENT_GAME, curGameState);
            return NavHost.Navigate("PauseMenuView");
        }

        // Undo move
        if ((tmp == L"z" || tmp == L"Z") && curGameState.moveList.size() != 0 &&
            Config::GetConfig(Config::UndoOption) == Config::Value_True) {
            goBack = 0;
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
                if (isPlayerOneTurn) {
                    timerPlayerOne.Continue();
                    timerPlayerTwo.Pause();
                } else {
                    timerPlayerTwo.Continue();
                    timerPlayerOne.Pause();
                }
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
                if (isPlayerOneTurn) {
                    timerPlayerOne.Continue();
                    timerPlayerTwo.Pause();
                } else {
                    timerPlayerTwo.Continue();
                    timerPlayerOne.Pause();
                }
            }
            if (Config::GetConfig(Config::FourWarning) == Config::Value_True) {
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
            if (soundEffect == Config::Value_True) undoSound.Play();
        }

        if (tmp == L"o" || tmp == L"O") {
            GameScreenAction::ScrollLogUp(
                gameScreen, goBack, curGameState, lock
            );
        }

        if (tmp == L"p" || tmp == L"P") {
            GameScreenAction::ScrollLogDown(
                gameScreen, goBack, curGameState, lock
            );
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
                if (soundEffect == Config::Value_True) ghostOffSound.Play();
            } else {
                isGhostMode = true;
                if (soundEffect == Config::Value_True) ghostSound.Play();
            }
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
            if (soundEffect == Config::Value_True) hintSound.Play();
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
                    goBack = 0;
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
                        timerPlayerOne.Continue();
                        timerPlayerTwo.Pause();
                    } else {
                        timerPlayerTwo.Continue();
                        timerPlayerOne.Pause();
                    }

                    if (endGame) break;
                    if (Config::GetConfig(Config::FourWarning) ==
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
                        if (hasWarning && soundEffect == Config::Value_True &&
                            curGameState.gameMode == Constants::GAME_MODE_PVP) {
                            warningSound.Play();
                        }
                    }

                    // AI's turn
                    if (curGameState.gameMode == Constants::GAME_MODE_PVE) {
                        Sleep(500);
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

                        if (soundEffect == Config::Value_True)
                            gamePlaceSound.Play();

                        GameScreenAction::UnhighlightWarning(
                            gameScreen,
                            curPlayer,
                            warningPointList,
                            colorMatrix,
                            lock
                        );

                        if (isPlayerOneTurn) {
                            timerPlayerOne.Continue();
                            timerPlayerTwo.Pause();
                        } else {
                            timerPlayerTwo.Continue();
                            timerPlayerOne.Pause();
                        }

                        if (endGame) break;

                        if (Config::GetConfig(Config::FourWarning) ==
                            Config::Value_True) {
                            bool hasWarning =
                                GameScreenAction::HighlightWarning(
                                    gameScreen,
                                    gameBoard,
                                    latestMove,
                                    prevPlayer,
                                    warningPointList,
                                    colorMatrix,
                                    lock
                                );
                            if (hasWarning &&
                                soundEffect == Config::Value_True) {
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
            gameScreen, currentBoard, {row, col}, colorMatrix, lock, isGhostMode
        );
    }

    if (endGame != Constants::END_GAME_WIN_TIME_ONE &&
        endGame != Constants::END_GAME_WIN_TIME_TWO) {
        lock.lock();
        gameScreen.logContainer.DrawToLogContainer(
            curGameState.moveList,
            curGameState.playerNameOne,
            curGameState.playerNameTwo,
            curGameState.playerOneFirst,
            endGame
        );
        lock.unlock();
        if (soundEffect == Config::Value_True) gameWinSound.Play();
    }

    while (tmp != L" ") {
        tmp = InputHandle::Get();
    }

    curGameState.gameEnd = endGame;
    NavHost.SetContext(Constants::FINISHED_GAME, curGameState);
    return NavHost.Navigate("GameEndView");
}