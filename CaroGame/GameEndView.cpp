#include "GameEndView.h"

void GameEndView::GameEndView(NavigationHost& NavHost)
{
    auto gameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::FINISHED_GAME
        ));
    const short WIDTH = 43, HEIGHT = 2 * 9;

    const short X_PIVOT = (120 - WIDTH) / 2, Y_PIVOT = (29 - HEIGHT) / 2;
    View::Rect rect = {Y_PIVOT, X_PIVOT, X_PIVOT + WIDTH, Y_PIVOT + HEIGHT};
    View::DrawRect(rect);

    std::wstring playerResultLabel;
    std::wstring nameLabel = Language::GetString(L"CUR_NAME") + L":";
    std::wstring timeLabel = Language::GetString(L"CUR_TIME") + L":";
    std::wstring scoreLabel = Language::GetString(L"CUR_SCORE") + L":";
    std::wstring movesLabel = Language::GetString(L"CUR_MOVE_COUNT") + L":";
    std::wstring totalTimeLabel = Language::GetString(L"PLAYER_TIME") + L":";
    std::wstring gameTypeLabel = Language::GetString(L"CUR_GAME_TYPE") + L":";
    std::wstring gameModeLabel = Language::GetString(L"CUR_GAME_MODE") + L":";
    std::wstring aiDifficultyLabel =
        Language::GetString(L"CUR_DIFFICULTY") + L":";

    int booltmp = (gameState.playerOneFirst + (gameState.moveList.size() % 2));
    bool isPlayerOneWin = (booltmp == 2 || booltmp == 0);
    if (isPlayerOneWin) {
        playerResultLabel = std::format(
            L"{} ({}) {}",
            gameState.playerNameOne,
            Constants::PLAYER_ONE.symbol,
            Language::GetString(L"WIN_TEXT")

        );
    } else {
        playerResultLabel = std::format(
            L"{} ({}) {}",
            gameState.playerNameTwo,
            Constants::PLAYER_TWO.symbol,
            Language::GetString(L"WIN_TEXT")

        );
    }

    short x = Label::GetCenterX(X_PIVOT, WIDTH, playerResultLabel.size()),
          y = Y_PIVOT + 1;

    View::WriteToView(x, y, playerResultLabel);
    x = X_PIVOT + 3, y += 2;

    // Name
    DrawLabelValuesAdjacent(
        x,
        y,
        nameLabel,
        std::format(
            L"{} ({})", gameState.playerNameOne, Constants::PLAYER_ONE.symbol
        ),
        std::format(
            L"({}) {}", Constants::PLAYER_TWO.symbol, gameState.playerNameTwo
        )

    );
    // Score
    y += 2;
    DrawLabelValuesAdjacent(
        x,
        y,
        scoreLabel,
        (gameState.playerScoreOne < 10)
            ? std::format(L"0{}", gameState.playerScoreOne)
            : std::format(L"{}", gameState.playerScoreOne),
        (gameState.playerScoreTwo < 10)
            ? std::format(L"0{}", gameState.playerScoreTwo)
            : std::format(L"{}", gameState.playerScoreTwo)
    );

    // Total time
    y += 2;
    DrawLabelValue(
        x,
        y,
        totalTimeLabel,
        (gameState.gameType == Constants::GAME_TYPE_NORMAL)
            ? L"\u221e"
            : Utils::SecondToMMSS(gameState.gameTime)
    );

    // Time left
    y += 2;
    DrawLabelValuesAdjacent(
        x,
        y,
        timeLabel,
        Utils::SecondToMMSS(gameState.playerTimeOne),
        Utils::SecondToMMSS(gameState.playerTimeTwo)
    );

    // Game type
    y += 2;
    DrawLabelValue(
        x,
        y,
        gameTypeLabel,
        (gameState.gameType == Constants::GAME_TYPE_NORMAL)
            ? Language::GetString(L"OPTION_TYPE_NORMAL")
            : Language::GetString(L"OPTION_TYPE_RUSH")

    );

    // Game Mode
    y += 2;
    DrawLabelValue(
        x,
        y,
        gameModeLabel,
        (gameState.gameMode == Constants::GAME_MODE_PVP)
            ? Language::GetString(L"OPTION_MODE_PVP")
            : Language::GetString(L"OPTION_MODE_PVE")

    );

    // AI Diff
    y += 2;
    std::wstring aiDiffValue;
    if (gameState.gameMode == Constants::GAME_MODE_PVE) {
        switch (gameState.aiDifficulty) {
            case AI::AI_DIFFICULTY_EASY:
                aiDiffValue = Language::GetString(L"OPTION_AI_EASY");
                break;
            case AI::AI_DIFFICULTY_NORMAL:
                aiDiffValue = Language::GetString(L"OPTION_AI_NORMAL");
                break;
            case AI::AI_DIFFICULTY_HARD:
                aiDiffValue = Language::GetString(L"OPTION_AI_HARD");
                break;
        }
    } else {
        aiDiffValue = Language::GetString(L"OPTION_NULL");
    }
    DrawLabelValue(
        x, y, aiDifficultyLabel, aiDiffValue

    );

    // Moves
    y += 2;
    DrawLabelValue(
        x,
        y,
        // movesLabel, std::format(L"{}", gameState.moveList.size()),
        movesLabel,
        std::format(L"{}", 12)

    );

    y += 2;
    std::wstring exitLabel = Language::GetString(L"ANY_KEY_CONTINUE");
    View::WriteToView(
        Label::GetCenterX(x, WIDTH, exitLabel.size()), y, exitLabel
    );

    auto c = InputHandle::Get();
    return NavHost.Navigate("ReplayMenuView");
}

void GameEndView::DrawLabelValuesAdjacent(
    short x,
    short y,
    const std::wstring& label,
    const std::wstring& playerOneValue,
    const std::wstring& playerTwoValue
)
{
    View::WriteToView(x, y, label);
    if (playerOneValue.size() > 5) {
        x = x + 17 - (playerOneValue.size() - 5);

    } else
        x += 17;
    View::WriteToView(
        x,
        y,
        playerOneValue,
        (wchar_t)0U,
        false,
        (View::Color)Constants::PLAYER_ONE_COLOR
    );
    if (playerOneValue.size() > 5) {
        x += playerOneValue.size() + 1;

    } else
        x += 6;
    View::WriteToView(x, y, L"|");
    if (playerOneValue.size() >= 5) {
        x += 2;
    } else
        x += 5;
    View::WriteToView(
        x,
        y,
        playerTwoValue,
        (wchar_t)0U,
        false,
        (View::Color)Constants::PLAYER_TWO_COLOR
    );
}

void GameEndView::DrawLabelValue(
    short x, short y, const std::wstring& label, const std::wstring& value
)
{
    View::WriteToView(x, y, label);
    if (value.size() == 1)
        x += 23;
    else
        x += 21;
    View::WriteToView(x, y, value);
}
