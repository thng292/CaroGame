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
    NavHost.SetContext(Constants::CURRENT_GAME, curGameState);
    return NavHost.Navigate(navigationValue);
}

void GameSelectionView::PlayerNameView(NavigationHost& NavHost)
{
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::CURRENT_GAME)
        );

    bool maxReached = false;
    const short MAX_LENGTH = 10;
    size_t curLabel = 0;

    InputBox::LabelList labelList;
    InputBox::InputList inputList;

    if (curGameState.gameMode == Constants::GAME_MODE_PVE) {
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
        currentGameState.playerAvatarTwo = MaxSelect + 1;
    }

    View::DrawTextCenterdVertically(
        2, Language::GetString(L"SELECT_AVATAR_TITLE")
    );

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

    while (currentGameState.playerAvatarOne == -1 ||
           currentGameState.playerAvatarTwo == -1) {
        auto tmp = InputHandle::Get();
        if (Config::GetSetting(Config::SoundEffect) == Config::Value_True) {
            Utils::PlayKeyPressSound();
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
            } else {
                currentGameState.playerAvatarTwo = selected;
            }
        }
    }
    NavHost.SetContext(Constants::CURRENT_GAME, currentGameState);
    return NavHost.Navigate("GameScreenView");
}

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
    if (selectedOption == 0) {
        NavHost.Navigate(navigationValueList[1]);
    }
    return NavHost.Navigate(navigationValue);
}

void GameSelectionView::ReplaySaveView(NavigationHost& NavHost)
{
    View::WriteToView(20, 20, L"Replay saving view, press any key to continue");
    auto tmp = InputHandle::Get();
    return NavHost.Navigate("PlayAgainView");
}

void GameSelectionView::PlayAgainView(NavigationHost& NavHost)
{
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::CURRENT_GAME)
        );

    short selectedOption = 0;
    const short MAX_OPTIONS = 2;

    std::vector<std::string> navigationValueList = {
        "GameScreenView", "MainMenu"};
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
    if (navigationValue == navigationValueList[0]) {
        curGameState.playerOneFirst = !curGameState.playerOneFirst;
        curGameState.moveList.clear();
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
    NavHost.SetContext(Constants::CURRENT_GAME, curGameState);
    return NavHost.Navigate(navigationValue);
}

void GameSelectionView::PauseMenuView(NavigationHost& NavHost)
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
