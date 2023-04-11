#include "GameSelectionView.h"

void GameSelectionView::GameModeVersusView(NavigationHost& NavHost)
{
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::CURRENT_GAME)
        );

    short selectedOption = 0;
    const short MAX_OPTIONS = 2;

    std::vector<short> optionValueList = {
        Constants::GAME_MODE_PVP, Constants::GAME_MODE_PVE};
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

    Common::DrawHintsLess();
    DrawCurrentOptionBox(curGameState, 2);
    View::DrawMenuPrevState menuPrevState;
    auto soundEffect = Config::GetConfig(Config::SoundEffect);

    while (1) {
        View::DrawMenuCenter(menuPrevState, label, options, selectedOption);
        auto tmp = InputHandle::Get();

        if (soundEffect == Config::Value_True) {
            if (tmp == L"\r") {
                Utils::PlaySpecialKeySound();
            } else {
                Utils::PlayKeyPressSound();
            }
        }

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
        if (tmp == L"b") {
            return NavHost.Back();
        }

        if (tmp == L"\r") {
            optionValue = optionValueList[selectedOption];
            navigationValue = navigationValueList[selectedOption];
            break;
        }
    }
    curGameState.gameMode = optionValue;
    NavHost.SetContext(Constants::CURRENT_GAME, curGameState);
    return NavHost.Navigate(navigationValue);
}

void GameSelectionView::PlayerNameView(NavigationHost& NavHost)
{
    View::DrawTextCenterdVertically(
        29 - 2,
        std::format(
            L"Enter: {}, Tab: {}, ESC: {}",
            Language::GetString(L"STRING_INPUT_DONE_LABEL"),
            Language::GetString(L"CHANGE_INPUT_LABEL"),
            Language::GetString(L"NAVIGATE_BACK_KEY_TITLE")
        )
    );

    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::CURRENT_GAME)
        );

    bool maxReached = false;
    const short MAX_LENGTH = 10;
    size_t curLabel = 0;

    InputBox::LabelList labelList;
    InputBox::InputList inputList;

    if (curGameState.gameMode == Constants::GAME_MODE_PVE) {
        labelList = {Language::GetString(L"PLAYER_NAME_LABEL") + L":"};
        inputList = {L"", L"Gura"};
    } else {
        labelList = {
            Language::GetString(L"PLAYER_NAME_ONE_LABEL") + L":",
            Language::GetString(L"PLAYER_NAME_TWO_LABEL") + L":"};
        inputList = {L"", L""};
    }

    DrawCurrentOptionBox(curGameState, 4);

    const short MAX_LABEL = labelList.size();
    bool navBack = false;

    while (curLabel < MAX_LABEL) {
        if (!InputBox::DrawInputBox(
                labelList, curLabel, inputList, maxReached, MAX_LENGTH
            )) {
            return NavHost.Back();
        }
    }
    curGameState.playerNameOne = inputList[0];
    curGameState.playerNameTwo = inputList[1];

    Utils::PlaySpecialKeySound();

    NavHost.SetContext(Constants::CURRENT_GAME, curGameState);
    return NavHost.Navigate("AvatarSelectView");
}

void GameSelectionView::AvatarSelectView(NavigationHost& NavHost)
{
    auto currentGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::CURRENT_GAME)
        );

    int selected = 0;
    const int MaxSelect = 8;
    if (currentGameState.gameMode == Constants::GAME_MODE_PVE) {
        currentGameState.playerAvatarTwo = MaxSelect;
    }
    if (NavHost.CheckContext(Constants::TUTORIAL_MODE)) {
        if (bool isTutorial = std::any_cast<bool>(
                NavHost.GetFromContext(Constants::TUTORIAL_MODE)
            );
            !isTutorial) {
            View::DrawTextCenterdVertically(
                2, Language::GetString(L"SELECT_AVATAR_TITLE")
            );
        }
    } else {
        View::DrawTextCenterdVertically(
            2, Language::GetString(L"SELECT_AVATAR_TITLE")
        );
    }

    logo_pokemon_red(3, 3);
    logo_pokemon_blue(33, 3);
    logo_pokemon_green(63, 3);
    logo_pokemon_yellow(93, 3);
    logo_pokemon_pink(3, 15);
    logo_pokemon_gray(33, 15);
    logo_pokemon_white(63, 15);
    logo_pokemon_black(93, 15);

    View::DrawTextCenterdVertically(
        28,
        std::format(
            L"A, W, S, D, Arrow Keys: {}, Enter: {}",
            Language::GetString(L"NAVIGATION_KEYS_TITLE"),
            Language::GetString(L"SELECT_KEY_TITLE")

        )
    );

    View::Rect drawnRect, player1Selection;
    auto& soundEffect = Config::GetConfig(Config::SoundEffect);

    while (currentGameState.playerAvatarOne == -1 ||
           currentGameState.playerAvatarTwo == -1) {
        if (currentGameState.playerAvatarOne != -1) {
            View::DrawBorder(player1Selection, Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR));
        }

        if (selected < 4) {
            drawnRect = {
                3, short(selected * 30), short(selected * 30 + 29), 15};
        } else {
            drawnRect = {
                15,
                short((selected - 4) * 30),
                short((selected - 4) * 30 + 29),
                27};
        }
        View::DrawBorder(
            drawnRect,
            player1Selection.Top ? Theme::GetColor(ThemeColor::PLAYER_TWO_COLOR)
                                 : Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR)
        );
        

        auto tmp = InputHandle::Get();
        if (soundEffect == Config::Value_True) {
            if (tmp == L"\r") {
                Utils::PlaySpecialKeySound();
            } else {
                Utils::PlayKeyPressSound();
            }
        }

        if (tmp == L"b") {
            return NavHost.Back();
        }

        if (Utils::keyMeanLeft(tmp)) {
            selected = Utils::modCycle(selected - 1, MaxSelect);
        }

        if (Utils::keyMeanRight(tmp)) {
            selected = Utils::modCycle(selected + 1, MaxSelect);
        }

        if (Utils::keyMeanDown(tmp)) {
            selected = Utils::modCycle(selected + MaxSelect / 2, MaxSelect);
        }

        if (Utils::keyMeanUp(tmp)) {
            selected = Utils::modCycle(selected - MaxSelect / 2, MaxSelect);
        }
        if (tmp == L"\r") {
            if (currentGameState.playerAvatarOne == -1) {
                currentGameState.playerAvatarOne = selected;
                player1Selection = drawnRect;
            } else {
                currentGameState.playerAvatarTwo = selected;
            }
        }
        View::DrawBorder(
            drawnRect, Theme::GetColor(ThemeColor::CONSOLE_COLOR), Theme::GetColor(ThemeColor::CONSOLE_COLOR)
        );
    }
    NavHost.SetContext(Constants::CURRENT_GAME, currentGameState);
    return NavHost.Navigate("GameScreenView");
}

void GameSelectionView::DrawCurrentOptionBox(
    const GameState& gameState, short selected
)
{
    const short WIDTH = 95, HEIGHT = 2;
    const short X_PIVOT = Label::GetCenterX(0, 120, WIDTH), Y_PIVOT = 5;
    View::Rect rect = {Y_PIVOT, X_PIVOT, X_PIVOT + WIDTH, Y_PIVOT + HEIGHT};
    View::DrawRect(rect);

    const std::wstring GAME_TYPE_LABEL =
        Language::GetString(L"CUR_GAME_TYPE") + L":";
    const std::wstring GAME_MODE_LABEL =
        Language::GetString(L"CUR_GAME_MODE") + L":";
    const std::wstring GAME_TIME_LABEL =
        Language::GetString(L"CUR_TIME") + L":";
    const std::wstring AI_DIFFICULTY_LABEL =
        Language::GetString(L"CUR_DIFFICULTY") + L":";

    std::wstring GAME_TYPE_VALUE;
    std::wstring GAME_TIME_VALUE;
    std::wstring GAME_MODE_VALUE;
    std::wstring AI_DIFFICULTY_VALUE;

    View::Color titleColor = Theme::GetColor(ThemeColor::TITLE_TEXT_COLOR);
    View::Color valueColor = Theme::GetColor(ThemeColor::TEXT_COLOR);
    View::Color aiColor = Theme::GetColor(ThemeColor::TEXT_COLOR);

    if (selected > 0) {
        GAME_TYPE_VALUE = (gameState.gameType == Constants::GAME_TYPE_NORMAL)
                              ? Language::GetString(L"OPTION_TYPE_NORMAL")
                              : Language::GetString(L"OPTION_TYPE_RUSH");
    }
    if (selected > 1) {
        if (gameState.gameType == Constants::GAME_TYPE_RUSH) {
            switch (gameState.gameTime) {
                case 60 * 1:
                    GAME_TIME_VALUE = Language::GetString(L"OPTION_1");
                    break;
                case 60 * 5:
                    GAME_TIME_VALUE = Language::GetString(L"OPTION_5");
                    break;
                case 60 * 15:
                    GAME_TIME_VALUE = Language::GetString(L"OPTION_15");
                    break;
            }
        } else {
            GAME_TIME_VALUE = L"\u221e";
        }
    }
    if (selected > 2) {
        GAME_MODE_VALUE = (gameState.gameMode == Constants::GAME_MODE_PVP)
                              ? Language::GetString(L"OPTION_MODE_PVP")
                              : Language::GetString(L"OPTION_MODE_PVE");
    }
    if (selected > 3) {
        if (gameState.gameMode == Constants::GAME_MODE_PVE) {
            switch (gameState.aiDifficulty) {
                case AI::AI_DIFFICULTY_EASY:
                    AI_DIFFICULTY_VALUE =
                        Language::GetString(L"OPTION_AI_EASY");
                    aiColor = Theme::GetColor(ThemeColor::AI_EASY_COLOR);
                    break;
                case AI::AI_DIFFICULTY_NORMAL:
                    AI_DIFFICULTY_VALUE =
                        Language::GetString(L"OPTION_AI_NORMAL");
                    aiColor = Theme::GetColor(ThemeColor::AI_NORMAL_COLOR);
                    break;
                case AI::AI_DIFFICULTY_HARD:
                    AI_DIFFICULTY_VALUE =
                        Language::GetString(L"OPTION_AI_HARD");
                    aiColor = Theme::GetColor(ThemeColor::AI_HARD_COLOR);
                    break;
            }
        } else {
            AI_DIFFICULTY_VALUE = Language::GetString(L"OPTION_NULL");
        }
    }

    const std::array<std::wstring, 4> LABEL_LIST = {
        GAME_TYPE_LABEL, GAME_TIME_LABEL, GAME_MODE_LABEL, AI_DIFFICULTY_LABEL};

    const std::array<std::wstring, 4> VALUE_LIST = {
        GAME_TYPE_VALUE, GAME_TIME_VALUE, GAME_MODE_VALUE, AI_DIFFICULTY_VALUE};

    short labelListLength = 0, space = 10;
    for (size_t i = 0; i < LABEL_LIST.size(); ++i) {
        labelListLength += LABEL_LIST[i].size() + space + 2;
    }
    short x = Label::GetCenterX(X_PIVOT, WIDTH, labelListLength),
          y = Y_PIVOT + 1;

    for (size_t i = 0; i < LABEL_LIST.size(); ++i) {
        View::WriteToView(x, y, LABEL_LIST[i], (wchar_t)0U, i == selected, titleColor);
        x += LABEL_LIST[i].size() + 2;

        if (i != 3)
            View::WriteToView(
                x, y, VALUE_LIST[i], (wchar_t)0U, false, valueColor
            );
        else
            View::WriteToView(x, y, VALUE_LIST[i], (wchar_t)0U, false, aiColor);
        x += space;
    }
}

void GameSelectionView::AreYouSureView(NavigationHost& NavHost) {
    std::string nextView =
        std::any_cast<std::string>(NavHost.GetFromContext(Constants::NEXT_VIEW));

    bool isSaved =
        std::any_cast<bool>(NavHost.GetFromContext(Constants::IS_SAVED)
        );

    if (isSaved) return NavHost.Navigate(nextView);

    short selectedOption = 0;
    const short MAX_OPTIONS = 3;

    std::wstring label = Language::GetString(L"ARE_YOU_SURE");
    std::vector<View::Option> options = {
        {Language::GetString(L"YES_TITLE"),
         Language::GetString(L"YES_TITLE")[0]},
        {Language::GetString(L"OPTION_NO"),
         Language::GetString(L"OPTION_NO")[0]},
        {Language::GetString(L"NAVIGATE_BACK_KEY_TITLE"),
         Language::GetString(L"NAVIGATE_BACK_KEY_SHORTCUT")[0]}
    };

    Common::DrawHintsLess();
    View::DrawMenuPrevState menuPrevState;
    auto& soundEffect = Config::GetConfig(Config::SoundEffect);

    while (1) {
        View::DrawMenuCenter(menuPrevState, label, options, selectedOption);
        auto tmp = InputHandle::Get();
        if (soundEffect == Config::Value_True) {
            if (tmp == L"\r") {
                Utils::PlaySpecialKeySound();
            } else {
                Utils::PlayKeyPressSound();
            }
        }
        if (Utils::keyMeanUp(tmp)) {
            selectedOption = (selectedOption - 1 + MAX_OPTIONS) % MAX_OPTIONS;
        }
        if (Utils::keyMeanDown(tmp)) {
            selectedOption = (selectedOption + 1) % MAX_OPTIONS;
        }
        if (tmp == L"1") {
            return NavHost.Navigate("SaveScreen");
        }
        if (tmp == L"2") {
            return NavHost.Navigate(nextView);
        }
        if (tmp == L"3") {
            return NavHost.Back();
        }
        if (tmp == L"b") {
            return NavHost.Back();
        }

        if (tmp == L"\r") {
            switch (selectedOption) {
                case 0:
                    return NavHost.Navigate("SaveScreen");
                case 1:
                    return NavHost.Navigate(nextView);
                case 2:
                    return NavHost.Back();
            }
        }
    }
}

// First view when choosing game options
void GameSelectionView::GameModeTypeView(NavigationHost& NavHost)
{
    GameState curGameState;
    short selectedOption = 0;
    const short MAX_OPTIONS = 2;

    std::string navigateValue;
    short optionValue;
    std::vector<short> optionValueList = {
        Constants::GAME_TYPE_RUSH, Constants::GAME_TYPE_NORMAL};
    std::vector<std::string> navigationValueList = {
        "RushTimeView", "GameModeVersusView"};

    std::wstring label = Language::GetString(L"LABEL_GAME_TYPE");
    std::vector<View::Option> options = {
        {Language::GetString(L"OPTION_TYPE_RUSH"),
         Language::GetString(L"OPTION_TYPE_RUSH")[0]  },
        {Language::GetString(L"OPTION_TYPE_NORMAL"),
         Language::GetString(L"OPTION_TYPE_NORMAL")[0]}
    };

    Common::DrawHintsLess();
    DrawCurrentOptionBox(curGameState, 0);
    View::DrawMenuPrevState menuPrevState;
    auto& soundEffect = Config::GetConfig(Config::SoundEffect);

    while (1) {
        View::DrawMenuCenter(menuPrevState, label, options, selectedOption);

        auto tmp = InputHandle::Get();
        if (soundEffect == Config::Value_True) {
            if (tmp == L"\r") {
                Utils::PlaySpecialKeySound();
            } else {
                Utils::PlayKeyPressSound();
            }
        }
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
        if (tmp == L"b") {
            return NavHost.Navigate("MainMenu");
        }

        if (tmp == L"\r") {
            optionValue = optionValueList[selectedOption];
            navigateValue = navigationValueList[selectedOption];
            break;
        }
    }

    curGameState.gameType = optionValue;
    NavHost.SetContext(Constants::CURRENT_GAME, curGameState);
    return NavHost.Navigate(navigateValue);
}

void GameSelectionView::AIDifficultyView(NavigationHost& NavHost)
{
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::CURRENT_GAME)
        );

    short selectedOption = 0;
    const short MAX_OPTIONS = 3;

    std::vector<short> optionValueList = {
        AI::AI_DIFFICULTY_EASY,
        AI::AI_DIFFICULTY_NORMAL,
        AI::AI_DIFFICULTY_HARD};
    short optionValue;
    std::string navigationValue = "PlayerNameView";
    DrawCurrentOptionBox(curGameState, 3);

    std::wstring label = Language::GetString(L"LABEL_AI_DIFFICULTY");
    std::vector<View::Option> options = {
        {Language::GetString(L"OPTION_AI_EASY"),
         Language::GetString(L"OPTION_AI_EASY")[0]  },
        {Language::GetString(L"OPTION_AI_NORMAL"),
         Language::GetString(L"OPTION_AI_NORMAL")[0]},
        {Language::GetString(L"OPTION_AI_HARD"),
         Language::GetString(L"OPTION_AI_HARD")[0]  }
    };

    Common::DrawHintsLess();
    View::DrawMenuPrevState menuPrevState;
    auto& soundEffect = Config::GetConfig(Config::SoundEffect);

    while (1) {
        View::DrawMenuCenter(menuPrevState, label, options, selectedOption);

        auto tmp = InputHandle::Get();
        if (soundEffect == Config::Value_True) {
            if (tmp == L"\r") {
                Utils::PlaySpecialKeySound();
            } else {
                Utils::PlayKeyPressSound();
            }
        }
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
        if (tmp == L"b") {
            return NavHost.Back();
        }

        if (tmp == L"\r") {
            optionValue = optionValueList[selectedOption];
            break;
        }
    }
    curGameState.aiDifficulty = optionValue;
    NavHost.SetContext(Constants::CURRENT_GAME, curGameState);
    return NavHost.Navigate(navigationValue);
}

void GameSelectionView::ReplayMenuView(NavigationHost& NavHost)
{
    short selectedOption = 0;
    const short MAX_OPTIONS = 2;

    std::wstring label = Language::GetString(L"LABEL_SAVE_REPLAY");
    std::vector<std::string> navigationValueList = {
        "ReplaySave", "PlayAgainView"};
    std::string navigationValue;

    std::vector<View::Option> options = {
        {Language::GetString(L"YES_TITLE"),
         Language::GetString(L"YES_TITLE")[0]},
        {Language::GetString(L"NO_TITLE"),
         Language::GetString(L"NO_TITLE")[0] }
    };

    Common::DrawHintsLess();
    View::DrawMenuPrevState menuPrevState;
    auto& soundEffect = Config::GetConfig(Config::SoundEffect);

    while (1) {
        View::DrawMenuCenter(menuPrevState, label, options, selectedOption);
        auto tmp = InputHandle::Get();
        if (soundEffect == Config::Value_True) {
            if (tmp == L"\r") {
                Utils::PlaySpecialKeySound();
            } else {
                Utils::PlayKeyPressSound();
            }
        }
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
    if (selectedOption == 0) {
        NavHost.Navigate(navigationValueList[1]);
    }
    return NavHost.Navigate(navigationValue);
}

void GameSelectionView::PlayAgainView(NavigationHost& NavHost)
{
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::FINISHED_GAME
        ));

    short selectedOption = 0;
    const short MAX_OPTIONS = 2;

    std::vector<std::string> navigationValueList = {
        "GameScreenView", "MainMenu"};
    std::string navigationValue;

    std::wstring label = Language::GetString(L"LABEL_PLAY_AGAIN");
    std::vector<View::Option> options = {
        {Language::GetString(L"YES_TITLE"),
         Language::GetString(L"YES_TITLE")[0]},
        {Language::GetString(L"OPTION_NO"),
         Language::GetString(L"OPTION_NO")[0]}
    };

    Common::DrawHintsLess();
    View::DrawMenuPrevState menuPrevState;
    auto& soundEffect = Config::GetConfig(Config::SoundEffect);

    while (1) {
        View::DrawMenuCenter(menuPrevState, label, options, selectedOption);
        auto tmp = InputHandle::Get();
        if (soundEffect == Config::Value_True) {
            if (tmp == L"\r") {
                Utils::PlaySpecialKeySound();
            } else {
                Utils::PlayKeyPressSound();
            }
        }
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
        if (tmp == L"b") {
            return NavHost.Back();
        }

        if (tmp == L"\r") {
            navigationValue = navigationValueList[selectedOption];
            break;
        }
    }
    if (navigationValue == navigationValueList[0]) {
        curGameState.playerOneFirst = !curGameState.playerOneFirst;
        curGameState.moveList.clear();
        curGameState.playerTimeOne = curGameState.playerTimeTwo =
            curGameState.gameTime;
    }
    NavHost.SetContext(Constants::CURRENT_GAME, curGameState);
    return NavHost.Navigate(navigationValue);
}

void GameSelectionView::RushTimeView(NavigationHost& NavHost)
{
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::CURRENT_GAME)
        );

    short selectedOption = 0;
    const short MAX_OPTIONS = 3;

    std::vector<short> optionValueList = {15 * 60, 5 * 60, 60};
    short optionValue;
    std::string navigationValue = "GameModeVersusView";

    DrawCurrentOptionBox(curGameState, 1);

    std::wstring label = Language::GetString(L"LABEL_RUSH_TIME");
    std::vector<View::Option> options = {
        {Language::GetString(L"OPTION_15"),
         Language::GetString(L"OPTION_15")[0]                                  },
        {Language::GetString(L"OPTION_5"),  Language::GetString(L"OPTION_5")[0]},
        {Language::GetString(L"OPTION_1"),
         Language::GetString(L"OPTION_1")[0]                                   }
    };

    Common::DrawHintsLess();
    View::DrawMenuPrevState menuPrevState;
    auto& soundEffect = Config::GetConfig(Config::SoundEffect);

    while (1) {
        View::DrawMenuCenter(menuPrevState, label, options, selectedOption);
        auto tmp = InputHandle::Get();
        if (soundEffect == Config::Value_True) {
            if (tmp == L"\r") {
                Utils::PlaySpecialKeySound();
            } else {
                Utils::PlayKeyPressSound();
            }
        }
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

        if (tmp == L"b") {
            return NavHost.Back();
        }

        if (tmp == L"\r") {
            optionValue = optionValueList[selectedOption];
            break;
        }
    }
    curGameState.playerTimeOne = curGameState.playerTimeTwo = optionValue;
    curGameState.gameTime = optionValue;
    NavHost.SetContext(Constants::CURRENT_GAME, curGameState);
    return NavHost.Navigate(navigationValue);
}

void GameSelectionView::PauseMenuView(NavigationHost& NavHost)
{
    short selectedOption = 0;
    const short MAX_OPTIONS = 6;

    std::string navigationValue;
    NavHost.SetContext(Constants::NEXT_VIEW, Constants::NULL_VIEW);

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

    Common::DrawHintsLess();
    View::DrawMenuPrevState menuPrevState;
    auto& soundEffect = Config::GetConfig(Config::SoundEffect);

    while (1) {
        View::DrawMenuCenter(menuPrevState, label, options, selectedOption);
        auto tmp = InputHandle::Get();
        if (soundEffect == Config::Value_True) {
            if (tmp == L"\r") {
                Utils::PlaySpecialKeySound();
            } else {
                Utils::PlayKeyPressSound();
            }
        }
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
        if (tmp == L"b" || tmp == L"ESC") {
            return NavHost.Back();
        }

        if (tmp == L"\r") {
            navigationValue = navigationValueList[selectedOption];           
            break;
        }
    }
    if (selectedOption == 5) return NavHost.Back();
    if (navigationValue == "SaveScreen" || navigationValue == "Setting")
        return NavHost.Navigate(navigationValue);
    NavHost.SetContext(Constants::NEXT_VIEW, navigationValue);
    return NavHost.Navigate("AreYouSureView");
}
