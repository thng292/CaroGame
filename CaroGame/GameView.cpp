#include "GameView.h"

void GameView::GameModeVersusView(NavigationHost& NavHost)
{
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(GAME_STATE));

    short selectedOption = 0;
    const short MAX_OPTIONS = 2;

    std::vector<short> optionValueList = {GAME_MODE_PVP, GAME_MODE_PVE};
    short optionValue;
    std::vector<std::string> navigationValueList = {
        "PlayerNameView", "AIDifficultyView"};
    std::string navigationValue;

    std::wstring label = Language::GetString(L"LABEL_GAME_MODE");
    std::vector<View::Option> options = {
        {Language::GetString(L"OPTION_MODE_PVP"),
         Language::GetString(L"OPTION_MODE_PVP")[0]},
        {Language::GetString(L"OPTION_MODE_PVE"),
         Language::GetString(L"OPTION_MODE_PVE")[0]}
    };

    while (1) {
        View::DrawMenuCenter(label, options, selectedOption);

        auto tmp = InputHandle::Get();
        if (Utils::keyMeanUp(tmp)) {
            selectedOption = Utils::modCycle(selectedOption - 1, MAX_OPTIONS);
        }
        if (Utils::keyMeanDown(tmp)) {
            selectedOption = Utils::modCycle(selectedOption + 1, MAX_OPTIONS);
        }
        if (tmp == L"1") {
            optionValue = optionValueList[0];
            navigationValue = navigationValueList[0];
            break;
        }
        if (tmp == L"2") {
            optionValue = optionValueList[1];
            navigationValue = navigationValueList[1];
            break;
        }
        if (tmp == L"e" || tmp == L"E") {
            return NavHost.Back();
        }

        if (tmp == L"\r") {
            optionValue = optionValueList[selectedOption];
            navigationValue = navigationValueList[selectedOption];
            break;
        }
    }
    curGameState.gameMode = optionValue;
    NavHost.SetContext(GAME_STATE, curGameState);
    return NavHost.Navigate(navigationValue);
}

void GameView::PlayerNameView(NavigationHost& NavHost)
{
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(GAME_STATE));

    bool maxReached = false;
    const short MAX_LENGTH = 10;
    size_t curLabel = 0;

    InputBox::LabelList labelList;
    InputBox::InputList inputList;

    if (curGameState.gameMode == GAME_MODE_PVE) {
        labelList = {L"Player's name:"};
        inputList = {L"", L"Gura"};
    } else {
        labelList = {L"Player 1's name:", L"Player 2's name:"};
        inputList = {L"", L""};
    }

    const short MAX_LABEL = labelList.size();

    while (curLabel < MAX_LABEL) {
        InputBox::DrawInputBox(
            labelList, curLabel, inputList, maxReached, MAX_LENGTH
        );
    }
    curGameState.playerNameOne = inputList[0];
    curGameState.playerNameTwo = inputList[1];

    NavHost.SetContext(GAME_STATE, curGameState);
    return NavHost.Navigate("GameScreenView");
}

void GameView::GameModeTypeView(NavigationHost& NavHost)
{
    GameState curGameState;

    short selectedOption = 0;
    const short MAX_OPTIONS = 2;

    std::string navigateValue;
    short optionValue;
    std::vector<short> optionValueList = {GAME_TYPE_RUSH, GAME_TYPE_NORMAL};
    std::vector<std::string> navigationValueList = {
        "RushTimeView", "GameModeVersusView"};

    std::wstring label = Language::GetString(L"LABEL_GAME_TYPE");
    std::vector<View::Option> options = {
        {Language::GetString(L"OPTION_TYPE_RUSH"),
         Language::GetString(L"OPTION_TYPE_RUSH")[0]  },
        {Language::GetString(L"OPTION_TYPE_NORMAL"),
         Language::GetString(L"OPTION_TYPE_NORMAL")[0]}
    };

    while (1) {
        View::DrawMenuCenter(label, options, selectedOption);

        auto tmp = InputHandle::Get();
        if (Utils::keyMeanUp(tmp)) {
            selectedOption = (selectedOption - 1 + MAX_OPTIONS) % MAX_OPTIONS;
        }
        if (Utils::keyMeanDown(tmp)) {
            selectedOption = (selectedOption + 1) % MAX_OPTIONS;
        }
        if (tmp == L"1") {
            optionValue = optionValueList[0];
            navigateValue = navigationValueList[0];
            break;
        }
        if (tmp == L"2") {
            optionValue = optionValueList[1];
            navigateValue = navigationValueList[1];
            break;
        }
        if (tmp == L"e" || tmp == L"E") {
            return NavHost.Back();
        }

        if (tmp == L"\r") {
            optionValue = optionValueList[selectedOption];
            navigateValue = navigationValueList[selectedOption];
            break;
        }
    }
    curGameState.gameType = optionValue;
    NavHost.SetContext(GAME_STATE, curGameState);
    return NavHost.Navigate(navigateValue);
}

void GameView::UpdateGame(
    GameScreen gameScreen,
    GameAction::Board& board,
    short& moveCount,
    const GameAction::Point& move,
    const Constants::Player& player,
    GameState& gameState,
    bool loadFromSave
)
{
    GameAction::MakeMove(board, moveCount, move, player.value);
    gameScreen.boardContainer.DrawToBoardContainerCell(
        move.row, move.col, player.symbol
    );
    if (!loadFromSave) gameState.moveList.push_back({move.row, move.col});
    gameScreen.logContainer.DrawToLogContainer(
        gameState.moveList,
        gameState.playerNameOne,
        gameState.playerNameTwo,
        gameState.playerOneFirst
    );
}

void GameView::HandleState(
    const GameAction::Board& board,
    const short& moveCount,
    const GameAction::Point& move,
    const Constants::Player& player,
    const bool& isPlayerOneTurn,
    GameState& curGameState,
    bool& endGame
)
{
    short state = Logic::GetGameState(board, moveCount, move, player.value);
    switch (state) {
        case Logic::WIN_VALUE:
            if (isPlayerOneTurn)
                curGameState.playerScoreOne++;
            else
                curGameState.playerScoreTwo++;

            View::WriteToView(80, 5, player.symbol + L" won");
            endGame = 1;
            break;
        case Logic::DRAW_VALUE:
            View::WriteToView(80, 5, L"Draw");
            endGame = 1;
            break;
    }
}

void GameView::GameScreenView(NavigationHost& NavHost)
{
    // GameState temp;
    // NavHost.SetContext(GAME_STATE, temp);
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(GAME_STATE));

    GameAction::Board gameBoard;
    for (size_t i = 0; i < Constants::BOARD_SIZE; i++) {
        memset(gameBoard[i].data(), 0, Constants::BOARD_SIZE * sizeof(char));
    }

    if (Config::GetSetting(Config::BGMusic) == Config::Value_True) {
        auto bgmAudio = BackgroundAudioService::getInstance();
        bgmAudio->ChangeSong(Sound::GameBGM);
        bgmAudio->getPlayer()->Play();
    }

    GameScreen gameScreen(7, 2);
    gameScreen.DrawGameScreen();
    gameScreen.DrawToElements(curGameState);

    short moveCount = 0;

    static AI myAI;
    myAI.SetDifficulty(curGameState.aiDifficulty);

    LoadGameToView(gameScreen, gameBoard, moveCount, curGameState, myAI);

    short row = 0, col = 0;
    if (curGameState.moveList.size() != 0) {
        row = curGameState.moveList.back().first;
        col = curGameState.moveList.back().second;
    }

    int booltmp =
        (curGameState.playerOneFirst + (curGameState.moveList.size() % 2));
    bool isPlayerOneTurn = !(booltmp == 2 || booltmp == 0);

    bool endGame = 0;
    bool aiFirst =
        (curGameState.gameMode == GAME_MODE_PVE && !isPlayerOneTurn &&
         curGameState.moveList.size() == 0);

    View::Goto(
        gameScreen.boardContainer.xCoord + BoardContainer::X_OFFSET +
            gameScreen.boardContainer.CELL_WIDTH * col,
        gameScreen.boardContainer.yCoord + BoardContainer::Y_OFFSET +
            gameScreen.boardContainer.CELL_HEIGHT * row
    );

    const short timeAddition =
        (curGameState.gameType == GAME_TYPE_NORMAL) ? 1 : -1;

    std::mutex lock;

    Timer timerPlayerOne(
        [&] {
            if (!endGame) {
                auto currPos = View::GetCursorPos();
                curGameState.playerTimeOne += timeAddition;
                gameScreen.timerContainerOne.DrawToContainer(
                    Utils::SecondToMMSS(curGameState.playerTimeOne)
                );
                View::Goto(currPos.X, currPos.Y);
                if (curGameState.playerTimeOne == 0) {
                    lock.lock();
                    endGame = true;
                    curGameState.playerScoreTwo++;
                    lock.unlock();
                }
            }
        },
        1000
    );

    Timer timerPlayerTwo(
        [&] {
            if (!endGame) {
                auto currPos = View::GetCursorPos();
                curGameState.playerTimeTwo += timeAddition;
                gameScreen.timerContainerTwo.DrawToContainer(
                    Utils::SecondToMMSS(curGameState.playerTimeTwo)
                );
                View::Goto(currPos.X, currPos.Y);
                if (curGameState.playerTimeTwo == 0) {
                    lock.lock();
                    endGame = true;
                    curGameState.playerScoreOne++;
                    lock.unlock();
                }
            }
        },
        1000
    );

    /*Utils::ON_SCOPE_EXIT([&] {
        timerPlayerOne.Stop();
        timerPlayerTwo.Stop();
    });*/

    timerPlayerOne.Start();
    timerPlayerOne.Pause();
    timerPlayerTwo.Start();
    timerPlayerTwo.Pause();

    if (isPlayerOneTurn) {
        timerPlayerOne.Continued();
    } else {
        timerPlayerTwo.Continued();
    }

    while (!endGame) {
        if (aiFirst) {
            GameAction::Point curMove = myAI.GetFirstMove();
            myAI.UpdatePrivateValues(curMove);
            Constants::Player curPlayer = Constants::PLAYER_TWO;
            timerPlayerOne.Continued();
            UpdateGame(
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
        }

        auto tmp = InputHandle::Get();
        if (endGame) break;

        if (tmp == L"ESC") {
            timerPlayerOne.Stop();
            timerPlayerTwo.Stop();
            NavHost.SetContext(GAME_STATE, curGameState);
            return NavHost.NavigateStack("PauseMenuView");
        }

        if (Utils::keyMeanUp(tmp)) {
            if (row - 1 >= 0) {
                row--;
                View::Goto(
                    gameScreen.boardContainer.xCoord +
                        BoardContainer::CELL_WIDTH * col +
                        BoardContainer::X_OFFSET,
                    gameScreen.boardContainer.yCoord +
                        BoardContainer::CELL_HEIGHT * row +
                        BoardContainer::Y_OFFSET
                );
            }
        }
        if (Utils::keyMeanLeft(tmp)) {
            if (col - 1 >= 0) {
                col--;
                View::Goto(
                    gameScreen.boardContainer.xCoord +
                        BoardContainer::CELL_WIDTH * col +
                        BoardContainer::X_OFFSET,
                    gameScreen.boardContainer.yCoord +
                        BoardContainer::CELL_HEIGHT * row +
                        BoardContainer::Y_OFFSET
                );
            }
        }
        if (Utils::keyMeanDown(tmp)) {
            if (row + 1 < Constants::BOARD_SIZE) {
                row++;
                View::Goto(
                    gameScreen.boardContainer.xCoord +
                        BoardContainer::CELL_WIDTH * col +
                        BoardContainer::X_OFFSET,
                    gameScreen.boardContainer.yCoord +
                        BoardContainer::CELL_HEIGHT * row +
                        BoardContainer::Y_OFFSET
                );
            }
        }
        if (Utils::keyMeanRight(tmp)) {
            if (col + 1 < Constants::BOARD_SIZE) {
                col++;
                View::Goto(
                    gameScreen.boardContainer.xCoord +
                        BoardContainer::CELL_WIDTH * col +
                        BoardContainer::X_OFFSET,
                    gameScreen.boardContainer.yCoord +
                        BoardContainer::CELL_HEIGHT * row +
                        BoardContainer::Y_OFFSET
                );
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

                UpdateGame(
                    gameScreen,
                    gameBoard,
                    moveCount,
                    curMove,
                    curPlayer,
                    curGameState
                );
                HandleState(
                    gameBoard,
                    moveCount,
                    curMove,
                    curPlayer,
                    isPlayerOneTurn,
                    curGameState,
                    endGame
                );

                // AI's turn
                if (!endGame && curGameState.gameMode == GAME_MODE_PVE) {
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

                    UpdateGame(
                        gameScreen,
                        gameBoard,
                        moveCount,
                        curMove,
                        curPlayer,
                        curGameState
                    );
                    myAI.UpdatePrivateValues(curMove);

                    HandleState(
                        gameBoard,
                        moveCount,
                        curMove,
                        curPlayer,
                        isPlayerOneTurn,
                        curGameState,
                        endGame
                    );
                }

                if (isPlayerOneTurn) {
                    timerPlayerTwo.Continued();
                } else {
                    timerPlayerOne.Continued();
                }

                isPlayerOneTurn = !isPlayerOneTurn;
            }
        }
    }

    curGameState.playerTimeOne = curGameState.playerTimeTwo =
        curGameState.gameTime;
    curGameState.playerOneFirst = !curGameState.playerOneFirst;

    auto tmp = InputHandle::Get();
    curGameState.moveList.clear();
    NavHost.SetContext(GAME_STATE, curGameState);
    return NavHost.Navigate("ReplayMenuView");
}

void GameView::AIDifficultyView(NavigationHost& NavHost)
{
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(GAME_STATE));

    short selectedOption = 0;
    const short MAX_OPTIONS = 3;

    std::vector<short> optionValueList = {
        AI::AI_DIFFICULTY_EASY,
        AI::AI_DIFFICULTY_NORMAL,
        AI::AI_DIFFICULTY_HARD};
    short optionValue;
    std::string navigationValue = "PlayerNameView";

    std::wstring label = Language::GetString(L"LABEL_AI_DIFICULTY");
    std::vector<View::Option> options = {
        {Language::GetString(L"OPTION_AI_EASY"),
         Language::GetString(L"OPTION_AI_EASY")[0]  },
        {Language::GetString(L"OPTION_AI_NORMAL"),
         Language::GetString(L"OPTION_AI_NORMAL")[0]},
        {Language::GetString(L"OPTION_AI_HARD"),
         Language::GetString(L"OPTION_AI_HARD")[0]  }
    };

    while (1) {
        View::DrawMenuCenter(label, options, selectedOption);

        auto tmp = InputHandle::Get();
        if (Utils::keyMeanUp(tmp)) {
            selectedOption = (selectedOption - 1 + MAX_OPTIONS) % MAX_OPTIONS;
        }
        if (Utils::keyMeanDown(tmp)) {
            selectedOption = (selectedOption + 1) % MAX_OPTIONS;
        }
        if (tmp == L"1") {
            optionValue = optionValueList[0];
            break;
        }
        if (tmp == L"2") {
            optionValue = optionValueList[1];
            break;
        }
        if (tmp == L"3") {
            optionValue = optionValueList[2];
            break;
        }
        if (tmp == L"e" || tmp == L"E") {
            return NavHost.Back();
        }

        if (tmp == L"\r") {
            optionValue = optionValueList[selectedOption];
            break;
        }
    }
    curGameState.aiDifficulty = optionValue;
    NavHost.SetContext(GAME_STATE, curGameState);
    return NavHost.Navigate(navigationValue);
}

void GameView::ReplayMenuView(NavigationHost& NavHost)
{
    short selectedOption = 0;
    const short MAX_OPTIONS = 2;

    std::wstring label = Language::GetString(L"LABEL_SAVE_REPLAY");
    std::vector<std::string> navigationValueList = {
        "ReplaySaveView", "PlayAgainView"};
    std::string navigationValue;

    std::vector<View::Option> options = {
        {Language::GetString(L"OPTION_YES"),
         Language::GetString(L"OPTION_YES")[0]},
        {Language::GetString(L"OPTION_NO"),
         Language::GetString(L"OPTION_NO")[0] }
    };

    while (1) {
        View::DrawMenuCenter(label, options, selectedOption);
        auto tmp = InputHandle::Get();
        if (Utils::keyMeanUp(tmp)) {
            selectedOption = (selectedOption - 1 + MAX_OPTIONS) % MAX_OPTIONS;
        }
        if (Utils::keyMeanDown(tmp)) {
            selectedOption = (selectedOption + 1) % MAX_OPTIONS;
        }
        if (tmp == L"1") {
            navigationValue = navigationValueList[0];
            break;
        }
        if (tmp == L"2") {
            navigationValue = navigationValueList[1];
            break;
        }

        if (tmp == L"\r") {
            navigationValue = navigationValueList[selectedOption];
            break;
        }
    }
    return NavHost.Navigate(navigationValue);
}

void GameView::ReplaySaveView(NavigationHost& NavHost)
{
    View::WriteToView(20, 20, L"Replay saving view, press any key to continue");
    auto tmp = InputHandle::Get();
    return NavHost.Navigate("PlayAgainView");
}

void GameView::PlayAgainView(NavigationHost& NavHost)
{
    short selectedOption = 0;
    const short MAX_OPTIONS = 2;

    std::vector<std::string> navigationValueList = {
        "GameScreenView", "GameModeTypeView"};
    std::string navigationValue;

    std::wstring label = Language::GetString(L"LABEL_PLAY_AGAIN");
    std::vector<View::Option> options = {
        {Language::GetString(L"OPTION_YES"),
         Language::GetString(L"OPTION_YES")[0]},
        {Language::GetString(L"OPTION_NO"),
         Language::GetString(L"OPTION_NO")[0] }
    };
    while (1) {
        View::DrawMenuCenter(label, options, selectedOption);
        auto tmp = InputHandle::Get();
        if (Utils::keyMeanUp(tmp)) {
            selectedOption = (selectedOption - 1 + MAX_OPTIONS) % MAX_OPTIONS;
        }
        if (Utils::keyMeanDown(tmp)) {
            selectedOption = (selectedOption + 1) % MAX_OPTIONS;
        }
        if (tmp == L"1") {
            navigationValue = navigationValueList[0];
            break;
        }
        if (tmp == L"2") {
            navigationValue = navigationValueList[1];
            break;
        }
        if (tmp == L"e" || tmp == L"E") {
            return NavHost.Back();
        }

        if (tmp == L"\r") {
            navigationValue = navigationValueList[selectedOption];
            break;
        }
    }
    return NavHost.Navigate(navigationValue);
}

void GameView::RushTimeView(NavigationHost& NavHost)
{
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(GAME_STATE));

    short selectedOption = 0;
    const short MAX_OPTIONS = 3;

    std::vector<short> optionValueList = {15 * 60, 5 * 60, 10};
    short optionValue;
    std::string navigationValue = "GameModeVersusView";

    std::wstring label = Language::GetString(L"LABEL_RUSH_TIME");
    std::vector<View::Option> options = {
        {Language::GetString(L"OPTION_15"),
         Language::GetString(L"OPTION_15")[0]                                  },
        {Language::GetString(L"OPTION_5"),  Language::GetString(L"OPTION_5")[0]},
        {Language::GetString(L"OPTION_1"),
         Language::GetString(L"OPTION_1")[0]                                   }
    };

    while (1) {
        View::DrawMenuCenter(label, options, selectedOption);
        auto tmp = InputHandle::Get();
        if (Utils::keyMeanUp(tmp)) {
            selectedOption = (selectedOption - 1 + MAX_OPTIONS) % MAX_OPTIONS;
        }
        if (Utils::keyMeanDown(tmp)) {
            selectedOption = (selectedOption + 1) % MAX_OPTIONS;
        }
        if (tmp == L"1") {
            optionValue = optionValueList[0];
            break;
        }
        if (tmp == L"2") {
            optionValue = optionValueList[1];
            break;
        }
        if (tmp == L"3") {
            optionValue = optionValueList[2];
            break;
        }

        if (tmp == L"e" || tmp == L"E") {
            return NavHost.Back();
        }

        if (tmp == L"\r") {
            optionValue = optionValueList[selectedOption];
            break;
        }
    }
    curGameState.playerTimeOne = curGameState.playerTimeTwo = optionValue;
    curGameState.gameTime = optionValue;
    NavHost.SetContext(GAME_STATE, curGameState);
    return NavHost.Navigate(navigationValue);
}

void GameView::PauseMenuView(NavigationHost& NavHost)
{
    short selectedOption = 0;
    const short MAX_OPTIONS = 6;

    std::string navigationValue;

    std::wstring label = Language::GetString(L"LABEL_PAUSE");
    std::vector<View::Option> options = {
        {Language::GetString(L"SAVE_TITLE"),
         Language::GetString(L"SAVE_SHORTCUT")[0]     },

        {Language::GetString(L"NEW_GAME_TITLE"),
         Language::GetString(L"NEW_GAME_SHORTCUT")[0] },

        {Language::GetString(L"LOAD_TITLE"),
         Language::GetString(L"LOAD_SHORTCUT")[0]     },

        {Language::GetString(L"SETTINGS_TITLE"),
         Language::GetString(L"SETTINGS_SHORTCUT")[0] },

        {Language::GetString(L"MAIN_MENU_TITLE"),
         Language::GetString(L"MAIN_MENU_SHORTCUT")[0]},

        {Language::GetString(L"BACK_TITLE"),
         Language::GetString(L"BACK_TITLE")[0]        }
    };

    std::array<std::string, MAX_OPTIONS> navigationValueList = {
        "SaveScreen",
        "GameModeTypeView",
        "LoadScreen",
        "Setting",
        "MainMenu",
        "Back"};

    while (1) {
        View::DrawMenuCenter(label, options, selectedOption);
        auto tmp = InputHandle::Get();
        if (Utils::keyMeanUp(tmp)) {
            selectedOption = (selectedOption - 1 + MAX_OPTIONS) % MAX_OPTIONS;
        }
        if (Utils::keyMeanDown(tmp)) {
            selectedOption = (selectedOption + 1) % MAX_OPTIONS;
        }
        if (tmp == L"1") {
            navigationValue = navigationValueList[0];
            break;
        }
        if (tmp == L"2") {
            navigationValue = navigationValueList[1];
            break;
        }
        if (tmp == L"3") {
            navigationValue = navigationValueList[2];
            break;
        }
        if (tmp == L"4") {
            navigationValue = navigationValueList[3];
            break;
        }
        if (tmp == L"5") {
            navigationValue = navigationValueList[4];
            break;
        }
        if (tmp == L"6") {
            navigationValue = navigationValueList[5];
            break;
        }
        if (tmp == L"e" || tmp == L"E") {
            return NavHost.Back();
        }

        if (tmp == L"\r") {
            navigationValue = navigationValueList[selectedOption];
            break;
        }
    }
    if (selectedOption == 5) return NavHost.Back();
    return NavHost.Navigate(navigationValue);
}

void GameView::LoadGameToView(
    GameScreen& gameScreen,
    GameAction::Board& board,
    short& moveCount,
    GameState gameState,
    AI& ai
)
{
    bool isPlayerOne = gameState.playerOneFirst;

    const short moveListSize = gameState.moveList.size();
    Constants::Player player;

    for (size_t i = 0; i < moveListSize; ++i) {
        player = (isPlayerOne) ? Constants::PLAYER_ONE : Constants::PLAYER_TWO;
        ai.UpdatePrivateValues(
            {gameState.moveList[i].first, gameState.moveList[i].second}
        );
        UpdateGame(
            gameScreen,
            board,
            moveCount,
            {gameState.moveList[i].first, gameState.moveList[i].second},
            player,
            gameState,
            true
        );
        isPlayerOne = !isPlayerOne;
    }
}
