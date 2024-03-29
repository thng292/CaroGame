#include "GameEndView.h"

void GameEndView::GameEndView(NavigationHost& NavHost)
{
    auto gameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::FINISHED_GAME
        ));
    short WIDTH = 47, HEIGHT = 2 * 9;

    short X_PIVOT = (120 - WIDTH) / 2, Y_PIVOT = (29 - HEIGHT) / 2;

    std::wstring endScreenLabel = Language::GetString(L"END_SCREEN_TITLE");
    std::wstring playerResultLabel;
    std::wstring timeLabel = Language::GetString(L"CUR_TIME") + L":";
    std::wstring scoreLabel = Language::GetString(L"CUR_SCORE") + L":";
    std::wstring movesLabel = Language::GetString(L"CUR_MOVE_COUNT") + L":";
    std::wstring playerTimeLabel =
        Language::GetString(L"PLAYER_TIME_TEXT") + L":";
    std::wstring gameTypeLabel = Language::GetString(L"CUR_GAME_TYPE") + L":";
    std::wstring gameModeLabel = Language::GetString(L"CUR_GAME_MODE") + L":";
    std::wstring nameLabel = Language::GetString(L"CUR_NAME") + L":";
    std::wstring aiDifficultyLabel =
        Language::GetString(L"CUR_DIFFICULTY") + L":";
    std::wstring playerLabel = Language::GetString(L"PLAYER_TEXT");

    View::Color tempColor;
    switch (gameState.gameEnd) {
        case Constants::END_GAME_WIN_ONE:
            playerResultLabel = std::format(
                L"{} {} ({}) {}",
                playerLabel,
                gameState.playerNameOne,
                Constants::PLAYER_ONE.symbol,
                Language::GetString(L"WIN_TEXT")

            );
            tempColor = Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR);
            X_PIVOT -= 3;
            break;
        case Constants::END_GAME_WIN_TWO:
            playerResultLabel = std::format(
                L"{} {} ({}) {}",
                playerLabel,
                gameState.playerNameTwo,
                Constants::PLAYER_TWO.symbol,
                Language::GetString(L"WIN_TEXT")

            );
            tempColor = Theme::GetColor(ThemeColor::PLAYER_TWO_COLOR);
            X_PIVOT += 1;
            break;
        case Constants::END_GAME_WIN_TIME_ONE:
            playerResultLabel = std::format(
                L"{} {} ({}) {}",
                playerLabel,
                gameState.playerNameOne,
                Constants::PLAYER_ONE.symbol,
                Language::GetString(L"WIN_TIME_TEXT")

            );
            tempColor = Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR);
            X_PIVOT -= 3;
            break;
        case Constants::END_GAME_WIN_TIME_TWO:
            playerResultLabel = std::format(
                L"{} {} ({}) {}",
                playerLabel,
                gameState.playerNameTwo,
                Constants::PLAYER_TWO.symbol,
                Language::GetString(L"WIN_TIME_TEXT")

            );
            tempColor = Theme::GetColor(ThemeColor::PLAYER_TWO_COLOR);
            X_PIVOT += 1;
            break;
        case Constants::END_GAME_DRAW:
            playerResultLabel = Language::GetString(L"DRAW_TEXT");
            tempColor = Theme::GetColor(ThemeColor::RESULT_TEXT_COLOR);
            WIDTH = 39;
            X_PIVOT += 4;
            break;
    }

    View::WriteToView(
        Label::GetCenterX(X_PIVOT, WIDTH, endScreenLabel.size()),
        Y_PIVOT - 1,
        endScreenLabel
    );
    View::Rect rect = {Y_PIVOT, X_PIVOT, X_PIVOT + WIDTH, Y_PIVOT + HEIGHT};
    View::DrawRect(rect);

    short x = Label::GetCenterX(X_PIVOT, WIDTH, playerResultLabel.size()),
          y = Y_PIVOT + 1;

    View::WriteToView(x, y, playerResultLabel, (wchar_t)0U, false, tempColor);
    x = X_PIVOT, y += 2;

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
        ),
        WIDTH

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
            : std::format(L"{}", gameState.playerScoreTwo),
        WIDTH
    );

    // Time left
    y += 2;
    DrawLabelValuesAdjacent(
        x,
        y,
        playerTimeLabel,
        Utils::SecondToMMSS(gameState.playerTimeOne),
        Utils::SecondToMMSS(gameState.playerTimeTwo),
        WIDTH
    );

    // Game type
    y += 2;
    DrawLabelValue(
        x,
        y,
        gameTypeLabel,
        (gameState.gameType == Constants::GAME_TYPE_NORMAL)
            ? Language::GetString(L"OPTION_TYPE_NORMAL")
            : Language::GetString(L"OPTION_TYPE_RUSH"),
        WIDTH

    );

    // Game Mode
    y += 2;
    DrawLabelValue(
        x,
        y,
        gameModeLabel,
        (gameState.gameMode == Constants::GAME_MODE_PVP)
            ? Language::GetString(L"OPTION_MODE_PVP")
            : Language::GetString(L"OPTION_MODE_PVE"),
        WIDTH

    );

    // Total time
    y += 2;
    DrawLabelValue(
        x,
        y,
        timeLabel,
        (gameState.gameType == Constants::GAME_TYPE_NORMAL)
            ? L"\u221e"
            : Utils::SecondToMMSS(gameState.gameTime),
        WIDTH
    );

    // AI Diff
    y += 2;
    std::wstring aiDiffValue;
    View::Color aiColor = Theme::GetColor(ThemeColor::TEXT_COLOR);
    if (gameState.gameMode == Constants::GAME_MODE_PVE) {
        switch (gameState.aiDifficulty) {
            case AI::AI_DIFFICULTY_EASY:
                aiDiffValue = Language::GetString(L"OPTION_AI_EASY");
                aiColor = Theme::GetColor(ThemeColor::AI_EASY_COLOR);
                break;
            case AI::AI_DIFFICULTY_NORMAL:
                aiDiffValue = Language::GetString(L"OPTION_AI_NORMAL");
                aiColor = Theme::GetColor(ThemeColor::AI_NORMAL_COLOR);
                break;
            case AI::AI_DIFFICULTY_HARD:
                aiDiffValue = Language::GetString(L"OPTION_AI_HARD");
                aiColor = Theme::GetColor(ThemeColor::AI_HARD_COLOR);
                break;
        }
    } else {
        aiDiffValue = Language::GetString(L"OPTION_NULL");
    }
    DrawLabelValue(
        x, y, aiDifficultyLabel, aiDiffValue, WIDTH, aiColor

    );

    // Moves
    y += 2;
    DrawLabelValue(
        x, y, movesLabel, std::format(L"{}", gameState.moveList.size()), WIDTH

    );

    y += 2;
    std::wstring exitLabel = Language::GetString(L"ANY_KEY_CONTINUE");
    View::WriteToView(
        Label::GetCenterX(x, WIDTH, exitLabel.size()), y + 2, exitLabel
    );

    bool stop = false;
    auto logoThread =
        std::thread(Logo_Result, gameState.gameEnd, std::ref(stop));

    Audio::AudioPlayer player;
    if (Config::GetConfig(Config::SoundEffect) == Config::Value_True) {
        if (gameState.gameEnd == Constants::END_GAME_DRAW) {
            player.Open(Audio::Sound::Draw);
        } else {
            if (gameState.gameMode == Constants::GAME_MODE_PVE &&
                (gameState.gameEnd == Constants::END_GAME_WIN_TWO ||
                 gameState.gameEnd == Constants::END_GAME_WIN_TIME_TWO)) {
                player.Open(Audio::Sound::Lose);
            } else {
                player.Open(Audio::Sound::Win);
            }
        }

        player.Play();
    }
    auto tmp = InputHandle::Get();
    stop = true;
    logoThread.join();
    if (Config::GetConfig(Config::SoundEffect) == Config::Value_True) {
        Utils::PlaySpecialKeySound();
    }
    return NavHost.Navigate("ReplayMenuView");
}

void GameEndView::DrawLabelValuesAdjacent(
    short x,
    short y,
    const std::wstring& label,
    const std::wstring& playerOneValue,
    const std::wstring& playerTwoValue,
    short width
)
{
    x += 2;
    View::WriteToView(
        x,
        y,
        label,
        (wchar_t)0U,
        false,
        Theme::GetColor(ThemeColor::TITLE_TEXT_COLOR)
    );

    x += (width - 2) / 2 + 2;
    const short X_MID_PIVOT = x;
    x -= playerOneValue.size() + 1;

    View::WriteToView(
        x,
        y,
        playerOneValue,
        (wchar_t)0U,
        false,
        Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR)
    );
    x = X_MID_PIVOT;
    View::WriteToView(x, y, L"|");
    x += 2;
    View::WriteToView(
        x,
        y,
        playerTwoValue,
        (wchar_t)0U,
        false,
        Theme::GetColor(ThemeColor::PLAYER_TWO_COLOR)
    );
}

void GameEndView::DrawLabelValue(
    short x,
    short y,
    const std::wstring& label,
    const std::wstring& value,
    short width,
    View::Color color
)
{
    x += 2;
    View::WriteToView(x, y, label, (wchar_t)0U, false, Theme::GetColor(ThemeColor::TITLE_TEXT_COLOR));
    x += width / 2;
    View::WriteToView(x, y, value, (wchar_t)0U, false, color);
}
