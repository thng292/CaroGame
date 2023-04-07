#include "SaveScreen.h"

void SaveScreen::SaveScreen(NavigationHost& NavHost)
{
    static auto currentState = SaveScreenState();
    currentState.ReloadAllOptions();

    Common::DrawHints();

    auto SaveHandle = [&] {
        currentState.isSearching = 0;
        if (!currentState.searchInput.length()) {
            currentState.searchInput =
                currentState.allOptions[currentState.selected].second.filename();
        }
        bool userChoice = 1;
        if (currentState.CheckOverwrite()) {
            userChoice =
                Common::ConfirmPrompt(Language::GetString(L"OVERWRITE_NOTICE_TITLE"));
        }
        if (!userChoice) {
            return NavHost.Navigate("SaveScreen");
        }
        auto currentGameState = std::any_cast<GameState>(
            NavHost.GetFromContext(Constants::CURRENT_GAME)
        );
        if (currentState.Save(currentGameState)) {
            return NavHost.NavigateStack("SaveSuccess");
        } else {
            return NavHost.NavigateStack("SaveFailed");
        }
    };

    auto& soundEffect = Config::GetSetting(Config::SoundEffect);
    auto& title = Language::GetString(L"SAVE_MENU_TITLE");
    auto& leadingText = Language::GetString(L"NAMING_FIELD_TITLE");

    const short searchX = 59 - (leadingText.length() + 32) / 2;
    std::wstring tmp;
    View::DrawMenuPrevState menuPrevState;

    auto drawMain = [&] {
        return View::DrawMenuCenter(
            menuPrevState, title, currentState.options, currentState.selected
        );
    };

    while (1) {
        drawMain();

        wchar_t inp = View::Input(
            searchX,
            29 - 5,
            leadingText,
            currentState.searchInput,
            currentState.isSearching,
            currentState.onSearchValueChange(drawMain)
        );

        if (inp == L'\r') {
            return SaveHandle();
        }

        if (currentState.isSearching) {
            currentState.isSearching = 0;
            continue;
        };

        View::Goto(0, 0);

        tmp = InputHandle::Get();

        if (soundEffect == Config::Value_True) {
            if (tmp == L"\r") {
                PlaySpecialKeySound();
            } else {
                Utils::PlayKeyPressSound();
            }
        }

        if (Utils::keyMeanDown(tmp)) {
            currentState.NextSelection();
        }

        if (Utils::keyMeanUp(tmp)) {
            currentState.PrevSelection();
        }

        if (Utils::keyMeanLeft(tmp)) {
            currentState.PrevPage();
        }

        if (Utils::keyMeanRight(tmp)) {
            currentState.NextPage();
        }

        if (tmp == L"B" || tmp == L"b") {
            return NavHost.Back();
        }

        if (tmp == L"x" || tmp == L"X") {
            if (Common::ConfirmPrompt(Language::GetString(L"DELETE_NOTICE_TITLE"
                ))) {
                currentState.RemoveCurrentSelect();
            }
            return NavHost.Navigate("SaveScreen");
        }

        if (tmp == L"\r") {
            return SaveHandle();
        }

        if (tmp == L"\t") {
            currentState.isSearching = 1;
        }
    }
}

inline bool SaveScreen::SaveScreenState::Save(const GameState& currentGameState)
{
    if (searchInput.length()) {
        return SaveLoad::Save(currentGameState, searchInput);
    }
    return 0;
}

void SaveScreen::SaveFailed(NavigationHost& NavHost)
{
    View::DrawMenuPrevState menuPrevState;

    View::DrawMenuCenter(
        menuPrevState,
        L"",
        {
            {(Language::GetString(L"SAVE_FAILED_TITLE")), 0}
    },
        0
    );
    InputHandle::Get();
    return NavHost.Back();
}

void SaveScreen::SaveSuccess(NavigationHost& NavHost)
{
    View::DrawMenuPrevState menuPrevState;

    View::DrawMenuCenter(
        menuPrevState,
        L"",
        {
            {(Language::GetString(L"SAVE_SUCCESS_TITLE")), 0}
    },
        0
    );
    InputHandle::Get();
    return NavHost.Back();
}
