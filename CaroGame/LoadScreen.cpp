#include "LoadScreen.h"

static void EmptyLoad(NavigationHost& NavHost);

static void LoadFailed(NavigationHost& NavHost);

void LoadScreen::LoadSceen(NavigationHost& NavHost) {
    auto currentState = LoadScreenState();

    if (currentState.allOptions.size() == 0) {
        return EmptyLoad(NavHost);
    }

    DrawHints();

    auto& soundSetting = Config::GetSetting(Config::SoundEffect);
    auto& title = Language::GetString(L"LOAD_MENU_TITLE");
    auto& leadingText = Language::GetString(L"SEARCH_FIELD_TITLE");

    const short searchX = 59 - (leadingText.length() + 32) / 2;
    std::wstring tmp;

    auto drawMain = [&] {
        return View::DrawMenuCenter(
            title, currentState.options, currentState.selected
        );
    };

    while (1) {
        currentState.drawnRect = drawMain();

        wchar_t exitKeyPressed = View::Input(
            searchX,
            29 - 5,
            leadingText,
            currentState.searchInput,
            currentState.isSearching,
            currentState.onSearchValueChange([&currentState, &drawMain] {
                View::ClearRect(currentState.drawnRect);
                currentState.drawnRect = drawMain();
            })
        );

        if (exitKeyPressed) {
            currentState.isSearching = 0;
            continue;
        };

        View::Goto(0, 0);
        currentState.isSearching = 0;

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

        if (tmp == L"\r" &&
            currentState.options[currentState.selected].underline == 0) {
            
            auto loaded = currentState.LoadCurrentSelect();
            if (loaded) {
                NavHost.SetContext(Constants::CURRENT_GAME, loaded.value());
                return NavHost.Navigate("GameScreenView");
            } else {
                return LoadFailed(NavHost);
            }
        }

        if (tmp == L"\t") {
            currentState.isSearching = 1;
        }

        View::ClearRect(currentState.drawnRect);
    }
}

static void EmptyLoad(NavigationHost& NavHost) {
    View::DrawMenuCenter(
        Language::GetString(L"EMPTY_SAVE_TITLE"),
        {
            {Language::GetString(L"EMPTY_SAVE_DESC"),     0   },
            {Language::GetString(L"NAVIGATE_BACK_TITLE"),
             Language::GetString(L"NAVIGATE_BACK_SHORTCUT")[0]}
    },
        1
    );
    InputHandle::Get();
    NavHost.Back();
}

static void LoadFailed(NavigationHost& NavHost) {
    View::DrawMenuCenter(Language::GetString(L"LOAD_FAILED_TITLE"), {}, 0);
    InputHandle::Get();
    return NavHost.Back();
}

void LoadScreen::DrawHints() {
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
            Language::GetString(L"SELECT_KEY_TITLE"),
            Language::GetString(L"SEARCH_TITLE")
        )
    );
}

inline void LoadScreen::LoadScreenState::LoadAllOptions() {
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

inline void LoadScreen::LoadScreenState::NextPage() {
    UpdatePage(Utils::modCycle(currentPage + 1, maxPage));
}

inline void LoadScreen::LoadScreenState::PrevPage() {
    UpdatePage(Utils::modCycle(currentPage - 1, maxPage));
}

inline void LoadScreen::LoadScreenState::NextSelection() {
    selected = Utils::modCycle(selected + 1, options.size() - 1);
}

inline void LoadScreen::LoadScreenState::PrevSelection() {
    selected = Utils::modCycle(selected - 1, options.size() - 1);
}

void LoadScreen::LoadScreenState::UpdatePage(int page) {
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

inline void LoadScreen::LoadScreenState::Search() {
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
LoadScreen::LoadScreenState::onSearchValueChange(
    const std::function<void(void)>& callback
) {
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

inline std::optional<GameState> LoadScreen::LoadScreenState::LoadCurrentSelect(
) {
    return SaveLoad::Load(
        allOptions[currentPage * Constants::PAGE_SIZE + selected].second
    );
}
