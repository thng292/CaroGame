#include "GameView.h"

void GameView::GameModeVersusView(NavigationHost& NavHost)
{
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(GAME_STATE));

    short selectedOption = 0;
    const short MAX_OPTIONS = 2;
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
            curGameState.gameMode = GAME_MODE_PVP;
            NavHost.SetContext(GAME_STATE, curGameState);
            return NavHost.Navigate("PlayerNameView");
        }
        if (tmp == L"2") {
            curGameState.gameMode = GAME_MODE_PVE;
            NavHost.SetContext(GAME_STATE, curGameState);
            return NavHost.Navigate("AIDifficultyView");
        }
        if (tmp == L"e" || tmp == L"E") {
            return NavHost.Back();
        }

        if (tmp == L"\r") {
            switch (selectedOption) {
                case 0:
                    curGameState.gameMode = GAME_MODE_PVP;
                    NavHost.SetContext(GAME_STATE, curGameState);
                    return NavHost.Navigate("PlayerNameView");
                case 1:
                    curGameState.gameMode = GAME_MODE_PVE;
                    NavHost.SetContext(GAME_STATE, curGameState);
                    return NavHost.Navigate("AIDifficultyView");
            }
        }
    }
}

void GameView::PlayerNameView(NavigationHost& NavHost)
{
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(GAME_STATE));

    std::vector<std::wstring> labelList;
    std::vector<std::string> contextList;
    std::wstring value;
    bool maxReached = false;
    const short MAX_LENGTH = 10;
    size_t curLabel = 0;

    if (curGameState.gameMode == GAME_MODE_PVE) {
        labelList = {L"Player's name:"};
        curGameState.playerNameTwo = L"Gura";
    } else {
        labelList = {L"Player 1's name:", L"Player 2's name:"};
    }

    const short MAX_LABEL = labelList.size();

    while (curLabel < MAX_LABEL) {
        InputBox::DrawInputBox(
            labelList, curLabel, value, maxReached, MAX_LENGTH
        );
        auto tmp = InputHandle::Get();
        if (tmp == L"ESC") {
            value.pop_back();
        } else if (tmp == L"\r") {
            if (curLabel == 0)
                curGameState.playerNameOne = value;
            else
                curGameState.playerNameTwo = value;
            value = L"";
            curLabel++;
        } else {
            if (value.length() < MAX_LENGTH) value += tmp;
        }
    }
    NavHost.SetContext(GAME_STATE, curGameState);
    return NavHost.Navigate("GameScreenView");
}

void GameView::GameModeTypeView(NavigationHost& NavHost)
{
    GameState curGameState;
    NavHost.SetContext(GAME_STATE, curGameState);

    short selectedOption = 0;
    const short MAX_OPTIONS = 2;

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
            curGameState.gameType = GAME_TYPE_RUSH;
            NavHost.SetContext(GAME_STATE, curGameState);
            return NavHost.Navigate("GameModeVersusView");
        }
        if (tmp == L"2") {
            curGameState.gameType = GAME_TYPE_NORMAL;
            NavHost.SetContext(GAME_STATE, curGameState);
            return NavHost.Navigate("GameModeVersusView");
        }
        if (tmp == L"e" || tmp == L"E") {
            return NavHost.Back();
        }

        if (tmp == L"\r") {
            switch (selectedOption) {
                case 0:
                    curGameState.gameType = GAME_TYPE_RUSH;
                    NavHost.SetContext(GAME_STATE, curGameState);
                    return NavHost.Navigate("GameModeVersusView");
                case 1:
                    curGameState.gameType = GAME_TYPE_NORMAL;
                    NavHost.SetContext(GAME_STATE, curGameState);
                    return NavHost.Navigate("GameModeVersusView");
            }
        }
    }
}

void GameView::UpdateGame(
    GameScreen gameScreen,
    GameAction::Board& board,
    short& moveCount,
    const GameAction::Point& move,
    const Constants::Player& player,
    GameState& gameState
)
{
    GameAction::MakeMove(board, moveCount, move, player.value);
    gameScreen.boardContainer.DrawToBoardContainerCell(
        move.row, move.col, player.symbol
    );
    gameState.moveList.push_back({move.row, move.col});
    gameScreen.logContainer.DrawToLogContainer(
        gameState.moveList, gameState.playerNameOne, gameState.playerNameTwo
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
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(GAME_STATE));
    GameScreen gameScreen(7, 2);
    gameScreen.DrawGameScreen();
    gameScreen.DrawToElements(curGameState);

    short row = 0, col = 0, moveCount = 0;
    GameAction::Board gameBoard(
        Constants::BOARD_SIZE, std::vector<short>(Constants::BOARD_SIZE, 0)
    );
    bool isPlayerOneTurn = 1, endGame = 0;

    View::Goto(
        gameScreen.boardContainer.xCoord + BoardContainer::X_OFFSET,
        gameScreen.boardContainer.yCoord + BoardContainer::Y_OFFSET
    );

    AI myAI;
    myAI.SetDifficulty(curGameState.aiDifficulty);

    while (!endGame) {
        auto tmp = InputHandle::Get();
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
                Constants::Player curPlayer = (isPlayerOneTurn)
                                                  ? Constants::PLAYER_ONE
                                                  : Constants::PLAYER_TWO;
                GameAction::Point curMove = {row, col};

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
                    curPlayer = (isPlayerOneTurn) ? Constants::PLAYER_ONE
                                                  : Constants::PLAYER_TWO;

                    curMove = myAI.GetBestMove(gameBoard, moveCount);
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

                isPlayerOneTurn = !isPlayerOneTurn;
            }
        }
    }
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
            curGameState.aiDifficulty = AI::AI_DIFFICULTY_EASY;
            NavHost.SetContext(GAME_STATE, curGameState);
            return NavHost.Navigate("PlayerNameView");
        }
        if (tmp == L"2") {
            curGameState.aiDifficulty = AI::AI_DIFFICULTY_NORMAL;
            NavHost.SetContext(GAME_STATE, curGameState);
            return NavHost.Navigate("PlayerNameView");
        }
        if (tmp == L"3") {
            curGameState.aiDifficulty = AI::AI_DIFFICULTY_HARD;
            NavHost.SetContext(GAME_STATE, curGameState);
            return NavHost.Navigate("PlayerNameView");
        }
        if (tmp == L"e" || tmp == L"E") {
            return NavHost.Back();
        }

        if (tmp == L"\r") {
            switch (selectedOption) {
                case 0:
                    curGameState.aiDifficulty = AI::AI_DIFFICULTY_EASY;
                    NavHost.SetContext(GAME_STATE, curGameState);
                    return NavHost.Navigate("PlayerNameView");
                case 1:
                    curGameState.aiDifficulty = AI::AI_DIFFICULTY_NORMAL;
                    NavHost.SetContext(GAME_STATE, curGameState);
                    return NavHost.Navigate("PlayerNameView");

                case 2:
                    curGameState.aiDifficulty = AI::AI_DIFFICULTY_HARD;
                    NavHost.SetContext(GAME_STATE, curGameState);
                    return NavHost.Navigate("PlayerNameView");
            }
        }
    }
}

void GameView::ReplayMenuView(NavigationHost& NavHost)
{
    short selectedOption = 0;
    const short MAX_OPTIONS = 2;

    std::wstring label = Language::GetString(L"LABEL_SAVE_REPLAY");

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
            return NavHost.Navigate("ReplaySaveView");
        }
        if (tmp == L"2") {
            return NavHost.Navigate("PlayAgainView");
        }

        if (tmp == L"\r") {
            switch (selectedOption) {
                case 0:
                    return NavHost.Navigate("ReplaySaveView");
                case 1:
                    return NavHost.Navigate("PlayAgainView");
            }
        }
    }
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
            return NavHost.Navigate("GameScreenView");
        }
        if (tmp == L"2") {
            return NavHost.Navigate("GameModeTypeView");
        }
        if (tmp == L"e" || tmp == L"E") {
            return NavHost.Back();
        }

        if (tmp == L"\r") {
            switch (selectedOption) {
                case 0:
                    return NavHost.Navigate("GameScreenView");
                case 1:
                    return NavHost.Navigate("GameModeTypeView");
            }
        }
    }
}
