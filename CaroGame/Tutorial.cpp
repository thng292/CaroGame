#include "Tutorial.h"

void Tutorial::TutorialScreen(NavigationHost& NavHost)
{
    const short maxWidth = 60;
    const short maxHeight = 20;
    GameState mockGameState;
    mockGameState.gameMode = Constants::GAME_MODE_PVE;
    mockGameState.moveList = {
        {0, 0},
        {1, 1},
        {2, 2},
        {3, 3},
        {4, 4},
        {5, 5},
        {6, 6}
    };

greeting : {
    View::ClearScreen();
    auto wrappedText = View::WrapText(
        Language::GetString(L"HELP_1_TITLE"), maxHeight, maxWidth
    );
    auto tmp = View::CalcCenter(
        ([&wrappedText] {
            short mmax = 0;
            for (auto& i : wrappedText) {
                mmax = max(i.length(), mmax);
            }
            return mmax;
        })(),
        wrappedText.size()
    );
    View::DrawTextWrapped(
        tmp.first,
        tmp.second,
        Language::GetString(L"HELP_1_TITLE"),
        maxHeight,
        maxWidth
    );
    if (Utils::ShortcutCompare(InputHandle::Get(), L"b")) {
        return NavHost.Navigate("MainMenu");
    }
    Utils::PlaySpecialKeySound();
}

Screen_layout : {
    View::ClearScreen();
    Common::DrawHintsLess();
    auto wrappedText = View::WrapText(
        Language::GetString(L"HELP_2_TITLE"), maxHeight, maxWidth
    );
    auto tmp = View::CalcCenter(
        ([&wrappedText] {
            short mmax = 0;
            for (auto& i : wrappedText) {
                mmax = max(i.length(), mmax);
            }
            return mmax;
        })(),
        wrappedText.size()
    );
    View::DrawTextWrapped(
        tmp.first,
        tmp.second,
        Language::GetString(L"HELP_2_TITLE"),
        maxHeight,
        maxWidth
    );

    if (Utils::ShortcutCompare(InputHandle::Get(), L"b")) {
        goto greeting;
    }
    Utils::PlaySpecialKeySound();
}

Settings_walk_through : {
    View::ClearScreen();
    NavigationHost mockNavHost;
    mockNavHost.SetContext(Constants::TUTORIAL_MODE, true);
    auto tmp = View::WrapText(Language::GetString(L"HELP_3_TITLE"), 5, 80);
    for (size_t i = 0; i < tmp.size(); i++) {
        View::DrawTextCenterdVertically(2 + i, tmp[i]);
    }
    View::DrawTextCenterdVertically(
        6,
        Language::GetString(L"HELP_3-1_TITLE"),
        Theme::GetColor(ThemeColor::WIN_HIGHLIGHT_COLOR)
    );
    Setting::SettingScreen(mockNavHost);
    if (mockNavHost.IsHistoryEmpty()) {
        goto Screen_layout;
    }
}

Game_mode_and_menu_walk_through : {
    View::ClearScreen();
    NavigationHost mockNavHost;
    mockNavHost.SetContext(Constants::TUTORIAL_MODE, true);
    auto tmp =
        View::WrapText(Language::GetString(L"HELP_4_TITLE"), 5, maxWidth);
    View::DrawTextWrapped(
        5,
        10,
        Language::GetString(L"HELP_4-1_TITLE"),
        5,
        30,
        L"...",
        Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR)
    );
    View::DrawTextWrapped(
        5,
        17,
        Language::GetString(L"HELP_4-2_TITLE"),
        5,
        30,
        L"...",
        Theme::GetColor(ThemeColor::PLAYER_TWO_COLOR)
    );
    for (size_t i = 0; i < tmp.size(); i++) {
        View::DrawTextCenterdVertically(22 + i, tmp[i]);
    }
    GameSelectionView::GameModeTypeView(mockNavHost);
    if (mockNavHost.IsHistoryEmpty()) {
        goto Settings_walk_through;
    }
}

String_input_walk_through : {
    View::ClearScreen();
    NavigationHost mockNavHost;
    mockNavHost.SetContext(Constants::TUTORIAL_MODE, true);
    mockNavHost.SetContext(Constants::CURRENT_GAME, mockGameState);
    auto tmp = View::WrapText(Language::GetString(L"HELP_5_TITLE"), 4, 60);
    for (size_t i = 0; i < tmp.size(); i++) {
        View::DrawTextCenterdVertically(20 + i, tmp[i]);
    }
    GameSelectionView::PlayerNameView(mockNavHost);
    if (mockNavHost.IsHistoryEmpty()) {
        goto Game_mode_and_menu_walk_through;
    }
    mockGameState = std::any_cast<GameState>(
        mockNavHost.GetFromContext(Constants::CURRENT_GAME)
    );
}

Pokemon_select_walk_through : {
    View::ClearScreen();
    NavigationHost mockNavHost;
    mockNavHost.SetContext(Constants::TUTORIAL_MODE, true);
    mockGameState.playerAvatarOne = -1;
    mockNavHost.SetContext(Constants::CURRENT_GAME, mockGameState);
    auto tmp = View::WrapText(Language::GetString(L"HELP_6_TITLE"), 2, 80);
    for (size_t i = 0; i < tmp.size(); i++) {
        View::DrawTextCenterdVertically(i, tmp[i]);
    }
    View::DrawTextCenterdVertically(2, Language::GetString(L"HELP_6-1_TITLE"));
    GameSelectionView::AvatarSelectView(mockNavHost);
    if (mockNavHost.IsHistoryEmpty()) {
        goto String_input_walk_through;
    }
    mockGameState = std::any_cast<GameState>(
        mockNavHost.GetFromContext(Constants::CURRENT_GAME)
    );
}

Right_side_of_the_game_board : {
    View::ClearScreen();
    NavigationHost mockNavHost;
    mockNavHost.SetContext(Constants::TUTORIAL_MODE, true);
    mockNavHost.SetContext(Constants::CURRENT_GAME, mockGameState);
    mockGameState = std::any_cast<GameState>(
        mockNavHost.GetFromContext(Constants::CURRENT_GAME)
    );
    mockGameState.playerNameTwo = L"Gura";
    GameScreen gameScreen(7, 2);

    gameScreen.DrawGameScreen();
    gameScreen.DrawToElements(mockGameState);
    View::ClearRect({0, 0, 60, 29});

    gameScreen.logContainer.DrawToLogContainer(
        mockGameState.moveList,
        mockGameState.playerNameOne,
        mockGameState.playerNameTwo,
        mockGameState.playerOneFirst
    );

    auto tmp = View::WrapText(Language::GetString(L"HELP_7-2_TITLE"), 5, 40);
    for (size_t i = 0; i < tmp.size(); i++) {
        View::WriteToView(20, i + 20, tmp[i]);
    }

    View::DrawTextWrapped(20, 3, Language::GetString(L"HELP_7-3_TITLE"), 8, 40);

    if (Utils::ShortcutCompare(InputHandle::Get(), L"b")) {
        goto Pokemon_select_walk_through;
    }
    Utils::PlaySpecialKeySound();
}

Left_side_of_the_board : {
    View::ClearScreen();
    GameScreen gameScreen(7, 2);

    gameScreen.DrawGameScreen();
    gameScreen.DrawToElements(mockGameState);
    View::ClearRect({0, 60, 119, 29});

    View::DrawTextWrapped(63, 3, Language::GetString(L"HELP_8-1_TITLE"), 4, 50);

    for (size_t i = 0; i < 4; i++) {
        gameScreen.boardContainer.DrawToBoardContainerCell(
            i,
            0,
            Constants::PLAYER_ONE.symbol,
            Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR)
        );
        gameScreen.boardContainer.DrawToBoardContainerCell(
            i,
            1,
            Constants::PLAYER_TWO.symbol,
            Theme::GetColor(ThemeColor::PLAYER_TWO_COLOR)
        );
    }

    gameScreen.boardContainer.DrawToBoardContainerCell(
        3,
        1,
        Constants::PLAYER_TWO.symbol,
        Theme::GetColor(ThemeColor::PLAYER_TWO_HIGHLIGHT_COLOR)
    );

    InputHandle::Get();
    Utils::PlaySpecialKeySound();

    View::DrawTextWrapped(63, 8, Language::GetString(L"HELP_8-2_TITLE"), 4, 50);

    for (size_t i = 0; i < 4; i++) {
        gameScreen.boardContainer.DrawToBoardContainerCell(
            i,
            0,
            Constants::PLAYER_ONE.symbol,
            Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR)
        );
        gameScreen.boardContainer.DrawToBoardContainerCell(
            i,
            1,
            Constants::PLAYER_TWO.symbol,
            Theme::GetColor(ThemeColor::PLAYER_TWO_COLOR)
        );
    }

    for (size_t i = 0; i < 5; ++i) {
        gameScreen.boardContainer.DrawToBoardContainerCell(
            i,
            0,
            Constants::PLAYER_ONE.symbol,
            Theme::GetColor(ThemeColor::WIN_HIGHLIGHT_COLOR)
        );
    }

    if (Utils::ShortcutCompare(InputHandle::Get(), L"b")) {
        Utils::PlaySpecialKeySound();
    }

    auto& tmp = Language::GetString(L"HELP_8-3_TITLE");
    View::WriteToView(89 - tmp.length() / 2, 14, tmp);

    auto& tmp2 = Language::GetString(L"HELP_8-4_TITLE");
    View::WriteToView(89 - tmp2.length() / 2, 15, tmp2);

    auto tt = View::WrapText(Language::GetString(L"HELP_8-5_TITLE"), 3, 50);
    for (size_t i = 0; i < tt.size(); i++) {
        View::WriteToView(89 - tt[i].length() / 2, 20 + i, tt[i]);
    }

    Utils::PlaySpecialKeySound();
    if (Utils::ShortcutCompare(InputHandle::Get(), L"b")) {
        goto Right_side_of_the_game_board;
    }
}
    return NavHost.Back();
}
