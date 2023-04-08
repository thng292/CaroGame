#include "LoadScreen.h"

void LoadScreen::LoadSceen(NavigationHost& NavHost)
{
    std::mutex lock;
    auto currentState = LoadScreenState();
    currentState.ReloadAllOptions();

    if (currentState.allOptions.size() == 0) {
        return NavHost.Navigate("EmptyLoad");
    }

    Common::DrawHints();

    auto& soundEffect = Config::GetSetting(Config::SoundEffect);
    auto& title = Language::GetString(L"LOAD_MENU_TITLE");
    auto& leadingText = Language::GetString(L"SEARCH_FIELD_TITLE");

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

        View::Input(
            searchX,
            29 - 5,
            leadingText,
            currentState.searchInput,
            currentState.isSearching,
            currentState.onSearchValueChange(drawMain)
        );

        if (currentState.isSearching) {
            currentState.isSearching = 0;
            continue;
        };

        View::Goto(0, 0);

        tmp = InputHandle::Get();

        if (soundEffect == Config::Value_True) {
            if (tmp == L"\r") {
                Utils::PlaySpecialKeySound();
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
            return NavHost.Navigate("LoadScreen");
        }

        if (tmp == L"\r") {
            auto loaded = currentState.LoadCurrentSelect();
            if (loaded) {
                NavHost.SetContext(Constants::CURRENT_GAME, loaded.value());
                return NavHost.Navigate("GameScreenView");
            } else {
                return NavHost.NavigateStack("LoadFailed");
            }
        }

        if (tmp == L"\t") {
            currentState.isSearching = 1;
        }

    }
}

void LoadScreen::EmptyLoad(NavigationHost& NavHost)
{
    View::DrawMenuPrevState menuPrevState;

    View::DrawMenuCenter(
        menuPrevState,
        L"",
        {
            {Language::GetString(L"EMPTY_SAVE_DESC"), 0},
        },
        1
    );
    InputHandle::Get();
    NavHost.Back();
    return NavHost.Back();
}

void LoadScreen::LoadFailed(NavigationHost& NavHost)
{
    View::DrawMenuPrevState menuPrevState;

    View::DrawMenuCenter(
        menuPrevState,
        L"",
        {
            {Language::GetString(L"LOAD_FAILED_TITLE"), 0}
        },
        0
    );
    InputHandle::Get();
    return NavHost.Back();
}

inline std::optional<GameState> LoadScreen::LoadScreenState::LoadCurrentSelect()
{
    return SaveLoad::Load(
        allOptions[currentPage * Constants::PAGE_SIZE + selected].second
    );
}