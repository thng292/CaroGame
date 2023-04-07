#include "GameScreenView.h"

void GameScreenView::GameScreenView(NavigationHost& NavHost)
{
    GameState temp;
    temp.aiDifficulty = AI::AI_DIFFICULTY_NORMAL;
    temp.playerAvatarOne = temp.playerAvatarTwo = 1;
    temp.gameMode = Constants::GAME_MODE_PVE;

    NavHost.SetContext(Constants::CURRENT_GAME, temp);

    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::CURRENT_GAME)
        );

    GameAction::Board gameBoard(
        Constants::BOARD_SIZE, std::vector<short>(Constants::BOARD_SIZE, 0)
    );
    NavHost.SetContext(Constants::CURRENT_BGM, Audio::Sound::GameBGM);
    if (Config::GetSetting(Config::BGMusic) == Config::Value_True) {
        auto bgmAudio = BackgroundAudioService::getInstance();
        if (bgmAudio->getPlayer()->getCurrentSong() != Audio::Sound::GameBGM) {
            bgmAudio->ChangeSong(Sound::GameBGM);
            bgmAudio->getPlayer()->Play(true, true);
        } else {
            bgmAudio->getPlayer()->Play(false, true);
        }
    }
    auto keyPressSound = Utils::KeyPressSound::getInstance();
    keyPressSound->ChangeSong(Audio::Sound::GameMove);
    Utils::ON_SCOPE_EXIT on_exit([&NavHost, &keyPressSound] {
        NavHost.SetContext(Constants::CURRENT_BGM, Audio::Sound::MenuBGM);
        keyPressSound->ChangeSong(Audio::Sound::MenuMove);
        BackgroundAudioService::getInstance()->getPlayer()->Stop();
    });

    Audio::AudioPlayer placeMoveSound(Sound::GamePlace);

    auto& soundEffect = Config::GetSetting(L"SoundEffect");

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
        gameScreen, gameBoard, moveCount, curGameState, myAI
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

    std::mutex lock;

    Timer timerPlayerOne(
        [&] {
            if (!endGame) {
                curGameState.playerTimeOne += timeAddition;
                lock.lock();
                auto currPos = View::GetCursorPos();
                gameScreen.timerContainerOne.DrawToContainer(
                    Utils::SecondToMMSS(curGameState.playerTimeOne),
                    (View::Color)Constants::PLAYER_ONE_COLOR
                );
                View::Goto(currPos.X, currPos.Y);
                lock.unlock();
                if (curGameState.playerTimeOne == 0 && !endGame) {
                    endGame = Constants::END_GAME_WIN_TIME_TWO;
                    curGameState.playerScoreTwo++;
                    lock.lock();
                    gameScreen.timerContainerOne.DrawToContainer(
                        Language::GetString(L"TIME_OUT"),
                        (View::Color)Constants::PLAYER_ONE_COLOR
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
                    (View::Color)Constants::PLAYER_TWO_COLOR
                );
                View::Goto(currPos.X, currPos.Y);
                lock.unlock();
                if (curGameState.playerTimeTwo == 0 && !endGame) {
                    endGame = Constants::END_GAME_WIN_TIME_ONE;

                    curGameState.playerScoreOne++;
                    lock.lock();
                    gameScreen.timerContainerTwo.DrawToContainer(
                        Language::GetString(L"TIME_OUT"),
                        (View::Color)Constants::PLAYER_TWO_COLOR
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
        gameScreen, gameBoard, {row, col}, latestMove
    );

    if (aiFirst) {
        timerPlayerOne.Continued();
        timerPlayerTwo.Pause();

        latestMove = myAI.GetFirstMove();
        myAI.UpdatePrivateValues(latestMove);  

        lock.lock();
        GameScreenAction::UpdateGame(
            gameScreen, gameBoard, moveCount, latestMove, curPlayer, curGameState
        );
        lock.unlock();

        lock.lock();
        GameScreenAction::HighlightMove(gameScreen, latestMove, curPlayer.symbol);
        lock.unlock();

        GameScreenAction::FlipTurn(prevPlayer, curPlayer, isPlayerOneTurn);
    }

    GameAction::Point hintMove;

    while (!endGame) {
        tmp = InputHandle::Get();
        if (endGame) break;

        if (soundEffect == Config::Value_True) {
            if (tmp == L"\r") {
                placeMoveSound.Play(1);
            } else if (tmp == L"ESC") {
                Audio::PlayAndForget(Sound::Pause);
            } else {
                Utils::PlayKeyPressSound();
            }
        }

        if (tmp == L"ESC") {
            timerPlayerOne.Stop();
            timerPlayerTwo.Stop();
            lock.lock();
            GameScreenAction::UnhighlightCursor(
                gameScreen, gameBoard, {prevRow, prevCol}, latestMove
            );
            lock.unlock();
            NavHost.SetContext(Constants::CURRENT_GAME, curGameState);
            return NavHost.NavigateStack("PauseMenuView");
        }

        if ((tmp == L"z" || tmp == L"Z") && curGameState.moveList.size() != 0 &&

            Config::GetSetting(Config::UndoOption) == Config::Value_True) {
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
                    isPlayerOneTurn
                );
                lock.unlock();

                if (curGameState.gameMode == Constants::GAME_MODE_PVE)
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
                    isPlayerOneTurn
                );
                lock.unlock();

                if (curGameState.gameMode == Constants::GAME_MODE_PVE)
                    myAI.RevertPrivateValues();
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

        lock.lock();
        GameScreenAction::UnhighlightCursor(
            gameScreen, gameBoard, {prevRow, prevCol}, latestMove
        );
        lock.unlock();

        if (tmp == L"h") {
            hintMove = GameScreenAction::GetHintMove(
                gameBoard, moveCount, isPlayerOneTurn, myAI
            );
            GameScreenAction::DrawMove(
                gameScreen, hintMove, curPlayer, View::Color::YELLOW
            );
        }

        if (tmp == L"\r" && !endGame) {
            if (gameBoard[row][col] == 0) {
                if (isPlayerOneTurn) {
                    timerPlayerTwo.Continued();
                    timerPlayerOne.Pause();
                } else {
                    timerPlayerOne.Continued();
                    timerPlayerTwo.Pause();
                }

                previousToLastMove = latestMove;
                latestMove = {row, col};

                lock.lock();
                GameScreenAction::UnhightlightMove(
                    gameScreen, previousToLastMove, prevPlayer.symbol
                );
                lock.unlock();
                lock.lock();
                GameScreenAction::HighlightMove(
                    gameScreen, latestMove, curPlayer.symbol
                );
                lock.unlock();

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
                GameScreenAction::HandleState(
                    gameBoard,
                    moveCount,
                    latestMove,
                    curPlayer,
                    isPlayerOneTurn,
                    curGameState,
                    endGame,
                    gameScreen
                );
                lock.unlock();

                GameScreenAction::FlipTurn(
                    prevPlayer, curPlayer, isPlayerOneTurn
                );

                

                myAI.UpdatePrivateValues(latestMove);

                // AI's turn
                if (!endGame &&
                    curGameState.gameMode == Constants::GAME_MODE_PVE) {
                    previousToLastMove = latestMove;             
                    latestMove = myAI.GetBestMove(gameBoard, moveCount);

                    lock.lock();
                    GameScreenAction::UnhightlightMove(
                        gameScreen, previousToLastMove, prevPlayer.symbol
                    );
                    lock.unlock();
                    lock.lock();
                    GameScreenAction::HighlightMove(
                        gameScreen, latestMove, curPlayer.symbol
                    );
                    lock.unlock();

                    myAI.UpdatePrivateValues(latestMove);

                    if (isPlayerOneTurn) {
                        timerPlayerOne.Pause();
                        timerPlayerTwo.Continued();
                    } else {
                        timerPlayerTwo.Pause();
                        timerPlayerOne.Continued();
                    }

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
                    GameScreenAction::HandleState(
                        gameBoard,
                        moveCount,
                        latestMove,
                        curPlayer,
                        isPlayerOneTurn,
                        curGameState,
                        endGame,
                        gameScreen

                    );
                    lock.unlock();

                    GameScreenAction::FlipTurn(
                        prevPlayer, curPlayer, isPlayerOneTurn
                    );
                }

            

            }
        }

        lock.lock();
        View::Goto(
            gameScreen.boardContainer.xCoord +
                BoardContainer::CELL_WIDTH * col + BoardContainer::X_OFFSET,
            gameScreen.boardContainer.yCoord +
                BoardContainer::CELL_HEIGHT * row + BoardContainer::Y_OFFSET
        );
        lock.unlock();

        lock.lock();
        GameScreenAction::HighLightCursor(
            gameScreen, gameBoard, {row, col}, latestMove
        );
        lock.unlock();
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