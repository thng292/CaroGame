#include "SaveScreen.h"

static void DrawHints()
{
    View::DrawTextCenterdVertically(
        29 - 3,
        std::format(
            L"A, W, S, D, Arrow Keys: {}",
            Language::GetString(L"NAVIGATION_KEYS_TITLE")
        )
    );

    View::DrawTextCenterdVertically(
        29 - 2,
        std::format(
            L"B: {}, Enter: {}, Tab: {}",
            Language::GetString(L"NAVIGATE_BACK_TITLE"),
            Language::GetString(L"SAVE_TITLE"),
            Language::GetString(L"NAME_INPUT_TITLE")
        )
    );
}

void SaveScreen::SaveScreen(NavigationHost& NavHost)
{
    static auto currentState = SaveScreenState();

    DrawHints();

    auto& soundSetting = Config::GetSetting(Config::SoundEffect);
    auto& title = Language::GetString(L"SAVE_MENU_TITLE");
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
            auto currentGameState = std::any_cast<GameState>(
                NavHost.GetFromContext(Constants::CURRENT_GAME)
            );
            bool saved = currentState.Save(currentGameState);
            if (saved) {
                return SaveSuccess(NavHost);
            } else {
                return SaveFailed(NavHost);
            }
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

        if (tmp == L"\r") {
            auto currentGameState = std::any_cast<GameState>(
                NavHost.GetFromContext(Constants::CURRENT_GAME)
            );
            bool saved = currentState.Save(currentGameState);
            if (saved) {
                return NavHost.NavigateStack("SaveSuccess");
            } else {
                return NavHost.NavigateStack("SaveFailed");
            }
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

inline void SaveScreen::SaveScreenState::LoadAllOptions()
{
    auto availableLoadFiles = SaveLoad::DiscoverSaveFiles();

    std::sort(
        availableLoadFiles.begin(),
        availableLoadFiles.end(),
        [](const FileHandle::FileDetail& a, const FileHandle::FileDetail& b) {
            return a.lastModified > b.lastModified;
        }
    );

    allOptions.reserve(availableLoadFiles.size());

    for (auto& file : availableLoadFiles) {
        allOptions.emplace_back(
            Utils::CatStringSpaceBetween(
                50,
                file.filePath.filename(),
                Utils::filesystem_time_to_wstr_local(file.lastModified)
            ),
            file.filePath
        );
    }
}

inline void SaveScreen::SaveScreenState::NextPage()
{
    UpdatePage(Utils::modCycle(currentPage + 1, maxPage));
    UpdateSearchInputOnNavigate();
}

inline void SaveScreen::SaveScreenState::PrevPage()
{
    UpdatePage(Utils::modCycle(currentPage - 1, maxPage));
    UpdateSearchInputOnNavigate();
}

inline void SaveScreen::SaveScreenState::NextSelection()
{
    selected = Utils::modCycle(selected + 1, options.size() - 1);
    UpdateSearchInputOnNavigate();
}

inline void SaveScreen::SaveScreenState::PrevSelection()
{
    selected = Utils::modCycle(selected - 1, options.size() - 1);
    UpdateSearchInputOnNavigate();
}

void SaveScreen::SaveScreenState::UpdatePage(int page)
{
    currentPage = Utils::modCycle(page, maxPage);

    selected = 0;
    options.clear();

    size_t end = min((page + 1) * Constants::PAGE_SIZE, allOptions.size());
    for (size_t i = page * Constants::PAGE_SIZE; i < end; i++) {
        options.emplace_back(allOptions[i].first, 0);
    }

    pageIndicator = std::format(L"{}/{}", page + 1, maxPage);
    options.emplace_back(pageIndicator, 0);
}

void SaveScreen::SaveScreenState::UpdateSearchInputOnNavigate()
{
    searchInput = allOptions[Constants::PAGE_SIZE * currentPage + selected]
                      .second.filename();
}

inline void SaveScreen::SaveScreenState::Search()
{
    size_t n = allOptions.size();
    std::vector<SortTemporary> tmp;
    tmp.resize(n);

    for (size_t i = 0; i < n; i++) {
        auto ttt = allOptions[i].second.filename().wstring();
        tmp[i] = {ttt.find(searchInput), std::move(ttt), i};
    }

    std::sort(
        tmp.begin(),
        tmp.end(),
        [](const SortTemporary& a, const SortTemporary& b) {
            if (a.foundIndex != size_t(-1) && b.foundIndex != size_t(-1)) {
                return a.name > b.name;
            }

            if (a.foundIndex == b.foundIndex) {
                return a.name > b.name;
            }

            return a.foundIndex < b.foundIndex;
        }
    );

    OptionList vtmp;
    vtmp.resize(n);
    for (size_t i = 0; i < n; i++) {
        vtmp[i] = allOptions[tmp[i].mapIndex];
    }
    allOptions = vtmp;
}

inline std::function<void(const std::wstring&)>
SaveScreen::SaveScreenState::onSearchValueChange(
    const std::function<void(void)>& callback
)
{
    return [&](const std::wstring& newInp) {
        if (newInp.length() > 30) {
            return;
        }
        searchInput = newInp;
        Search();
        UpdatePage(0);
        callback();
    };
}

inline bool SaveScreen::SaveScreenState::Save(const GameState& currentGameState)
{
    if (searchInput.length()) {
        return SaveLoad::Save(currentGameState, searchInput);
    }
    return 0;
}

bool SaveScreen::SaveScreenState::CheckOverwrite()
{
    for (auto& [i, path] : allOptions) {
        if (searchInput == path.filename()) {
            return true;
        }
    }
    return false;
}

void SaveScreen::SaveFailed(NavigationHost& NavHost)
{
    View::DrawMenuCenter(Language::GetString(L"SAVE_FAILED_TITLE"), {}, 0);
    InputHandle::Get();
    return NavHost.Back();
}

void SaveScreen::SaveSuccess(NavigationHost& NavHost)
{
    View::DrawMenuCenter(Language::GetString(L"SAVE_SUCCESS_TITLE"), {}, 0);
    InputHandle::Get();
    return NavHost.Back();
}
