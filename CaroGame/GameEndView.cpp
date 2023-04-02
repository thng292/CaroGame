#include "GameEndView.h"

void GameEndView::GameEndView(NavigationHost& NavHost)
{
    bool isPlayerOneWin = 1;
    GameState temp;
    temp.playerNameOne = L"123456";
    temp.playerNameTwo = L"1234567899";
    
    temp.playerScoreOne = 12;
    temp.playerScoreTwo = 2;

    NavHost.SetContext(Constants::CURRENT_GAME, temp);

    auto gameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::CURRENT_GAME)
        );
    const short WIDTH = 43, HEIGHT = 11;

    const short X_PIVOT = (120 - WIDTH) / 2, Y_PIVOT = (29 - HEIGHT) / 2;
    View::Rect rect = {Y_PIVOT, X_PIVOT, X_PIVOT + WIDTH, Y_PIVOT + HEIGHT};
    View::DrawRect(rect);

    std::wstring playerResultLabel;
    std::wstring nameLabel = Language::GetString(L"CUR_NAME") + L":";
    std::wstring timeLabel = Language::GetString(L"CUR_TIME") + L":";
    std::wstring scoreLabel = Language::GetString(L"CUR_SCORE") + L":";
    std::wstring movesLabel = Language::GetString(L"CUR_MOVE_COUNT") + L":";

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
    DrawLabelValuesAdjacent(
        x,
        y,
        nameLabel,
        std::format(L"{} ({})", gameState.playerNameOne, Constants::PLAYER_ONE.symbol),
        std::format(
            L"({}) {}", Constants::PLAYER_TWO.symbol, gameState.playerNameTwo
        )

    );
    y += 2;
    DrawLabelValuesAdjacent(
        x,
        y,
        timeLabel,
        Utils::SecondToMMSS(gameState.playerTimeOne),
        Utils::SecondToMMSS(gameState.playerTimeTwo)
    );
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
    y += 2;
    DrawLabelValue(
        x,
        y,
        //movesLabel, std::format(L"{}", gameState.moveList.size()),
        movesLabel,
        std::format(L"{}", 12)

    );
    
    

    auto c = InputHandle::Get();
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
    
    }
    else x += 17;
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

    } else x += 6;
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

void GameEndView::DrawLabelValue(short x, short y, const std::wstring& label, const std::wstring& value) {
    View::WriteToView(x, y, label);
    if (value.size() == 1)
        x += 23;
    else
        x += 22;
    View::WriteToView(
        x,
        y,
        value
    );
}

