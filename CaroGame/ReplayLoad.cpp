#include "ReplayLoad.h"

void ReplayLoad::ReplayLoad(NavigationHost& NavHost)
{
    auto currentState = ReplayLoadState(Constants::REPLAY_PATH);
    currentState.ReloadAllOptions();

    if (currentState.allOptions.size() == 0) {
        return NavHost.Navigate("EmptyLoad");
    }

    Common::DrawHints();

    auto& soundEffect = Config::GetSetting(Config::SoundEffect);
    auto& title = Language::GetString(L"REPLAY_LOAD_MENU_TITLE");
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
            return NavHost.Navigate("ReplayLoad");
        }

        if (tmp == L"\r") {
            auto loaded = currentState.LoadCurrentSelect();
            if (loaded) {
                NavHost.SetContext(Constants::FINISHED_GAME, loaded.value());
                return NavHost.Navigate("ReplayScreenView");
            } else {
                return NavHost.NavigateStack("LoadFailed");
            }
        }

        if (tmp == L"\t") {
            currentState.isSearching = 1;
        }
    }
}

inline std::optional<GameState> ReplayLoad::ReplayLoadState::LoadCurrentSelect()
{
    return SaveLoad::Load(
        allOptions[currentPage * Constants::PAGE_SIZE + selected].second
    );
}