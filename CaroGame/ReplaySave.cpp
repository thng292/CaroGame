#include "ReplaySave.h"

void ReplaySave::ReplaySave(NavigationHost& NavHost)
{
    static auto currentState = ReplaySaveState(Constants::REPLAY_PATH);
    currentState.ReloadAllOptions();

    Common::DrawHints();

    auto SaveHandle = [&] {
        bool userChoice = 1;
        if (currentState.CheckOverwrite()) {
            userChoice =
                Common::ConfirmPrompt(Language::GetString(L"OVERWRITE_NOTICE_TITLE"));
        }
        if (!userChoice) {
            return NavHost.Navigate("ReplaySave");
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

    auto& soundSetting = Config::GetSetting(Config::SoundEffect);
    auto& title = Language::GetString(L"REPLAY_SAVE_MENU_TITLE");
    auto& leadingText = Language::GetString(L"NAMING_FIELD_TITLE");

    const short searchX = 59 - (leadingText.length() + 32) / 2;
    std::wstring tmp;

    auto drawMain = [&] {
        return View::DrawMenuCenter(
            title, currentState.options, currentState.selected
        );
    };

    while (1) {
        currentState.drawnRect = drawMain();

        wchar_t inp = View::Input(
            searchX,
            29 - 5,
            leadingText,
            currentState.searchInput,
            currentState.isSearching,
            currentState.onSearchValueChange([&drawMain] {
                View::ClearRect(currentState.drawnRect);
                currentState.drawnRect = drawMain();
            })
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

        if (soundSetting == Config::Value_True) {
            Utils::PlayKeyPressSound();
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
            return NavHost.Navigate("ReplaySave");
        }

        if (tmp == L"\r") {
            return SaveHandle();
        }

        if (tmp == L"\t") {
            currentState.isSearching = 1;
        }

        View::ClearRect(currentState.drawnRect);
        View::ClearRect(
            {29 - 5,
             searchX,
             searchX + 30 + (short)leadingText.length(),
             29 - 5}
        );
    }
}