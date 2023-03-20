#include "LoadScreen.h"

static void EmptyLoad(NavigationHost& NavHost);

static void LoadFailed(NavigationHost& NavHost);

static void DrawHints() {
    View::DrawTextCenterdVertically(
        29 - 3, std::format(
                    L"A, W, S, D, Arrow Keys: {}",
                    Language::GetString(L"NAVIGATION_KEYS_TITLE")
                )
    );
    View::DrawTextCenterdVertically(
        29 - 2, std::format(
                    L"B: {}, Enter: {}, Tab: {}",
                    Language::GetString(L"NAVIGATE_BACK_TITLE"),
                    Language::GetString(L"SELECT_KEY_TITLE"),
                    Language::GetString(L"SEARCH_TITLE")
                )
    );
}

static void LoadPage(
    const auto& allOptions, int& selected, int maxPage,
    std::wstring& pageIndicator, std::vector<View::Option>& options, int page
) {
    selected = 0;
    options.clear();
    size_t end = min((page + 1) * Constants::PAGE_SIZE, allOptions.size());
    for (size_t i = page * Constants::PAGE_SIZE; i < end; i++) {
        options.emplace_back(allOptions[i].first, 0);
    }
    pageIndicator = std::format(L"{}/{}", page + 1, maxPage);
    options.emplace_back(pageIndicator, 0);
}

struct SortTemporary {
    size_t foundIndex;
    std::wstring name;
    size_t mapIndex;
};

std::vector<std::pair<std::wstring, std::filesystem::path>> Search(
    const std::vector<std::pair<std::wstring, std::filesystem::path>>&
        allOptions,
    const std::wstring& searchTerm
) {
    size_t n = allOptions.size();
    std::vector<SortTemporary> tmp;
    tmp.resize(n);
    for (size_t i = 0; i < n; i++) {
        auto ttt = allOptions[i].second.filename().wstring();
        tmp[i] = {ttt.find(searchTerm), std::move(ttt), i};
    }

    std::sort(
        tmp.begin(), tmp.end(),
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
    std::vector<std::pair<std::wstring, std::filesystem::path>> vtmp;
    vtmp.resize(n);
    for (size_t i = 0; i < n; i++) {
        vtmp[i] = allOptions[tmp[i].mapIndex];
    }
    return std::move(vtmp);
}

void LoadScreen::Load(NavigationHost& NavHost) {
    auto allOptions = ([] {
        auto availableLoadFiles = SaveLoad::DiscoverSaveFiles();
        std::sort(
            availableLoadFiles.begin(), availableLoadFiles.end(),
            [](const FileHandle::FileDetail& a, const FileHandle::FileDetail& b
            ) { return a.lastModified > b.lastModified; }
        );
        std::wstring tmp;
        std::vector<std::pair<std::wstring, std::filesystem::path>> res;
        for (auto& file : availableLoadFiles) {
            res.emplace_back(
                Utils::CatStringSpaceBetween(
                    50, file.filePath.filename(),
                    Utils::filesystem_time_to_wstr_local(file.lastModified)
                ),
                file.filePath
            );
        }
        return res;
    })();

    if (allOptions.size() == 0) {
        return EmptyLoad(NavHost);
    }

    DrawHints();

    auto& soundSetting = Config::GetSetting(Config::SoundEffect);
    int selected = 0;
    int currentPage = 0;
    bool isSearching = 0;
    int maxPage = allOptions.size() / 10 + bool(allOptions.size() % 10);
    std::vector<View::Option> options;
    std::wstring pageIndicator;

    LoadPage(allOptions, selected, maxPage, pageIndicator, options, 0);

    auto& title = Language::GetString(L"LOAD_MENU_TITLE");
    auto& leadingText = Language::GetString(L"SEARCH_FIELD_TITLE");
    short searchX = 59 - (leadingText.length() + 32) / 2;
    std::wstring searchInput;
    View::Rect drawnRect;
    std::wstring tmp;

    auto drawMain = [&] {
        return View::DrawMenuCenter(title, options, selected);
    };

    while (1) {
        drawnRect = drawMain();
        if (View::Input(
                searchX, 29 - 5, leadingText, searchInput, isSearching,
                [&](const std::wstring newInp) {
                    searchInput = newInp;
                    allOptions = Search(allOptions, searchInput);
                    currentPage = 0;
                    LoadPage(
                        allOptions, selected, maxPage, pageIndicator, options, 0
                    );
                    View::ClearRect(drawnRect);
                    drawnRect = drawMain();
                }
            )) {
            isSearching = 0;
            continue;
        };
        View::Goto(0, 0);
        isSearching = 0;
        tmp = InputHandle::Get();
        if (soundSetting == Config::Value_True) {
            Utils::PlayKeyPressSound();
        }

        if (Utils::keyMeanDown(tmp)) {
            selected = Utils::modCycle(selected + 1, options.size() - 1);
        }
        if (Utils::keyMeanUp(tmp)) {
            selected = Utils::modCycle(selected - 1, options.size() - 1);
        }
        if (Utils::keyMeanLeft(tmp)) {
            currentPage = Utils::modCycle(currentPage - 1, maxPage);
            LoadPage(
                allOptions, selected, maxPage, pageIndicator, options,
                currentPage
            );
        }
        if (Utils::keyMeanRight(tmp)) {
            currentPage = Utils::modCycle(currentPage + 1, maxPage);
            LoadPage(
                allOptions, selected, maxPage, pageIndicator, options,
                currentPage
            );
        }
        if (tmp == L"B" || tmp == L"b") {
            return NavHost.Back();
        }
        if (tmp == L"\r") {
            if (options[selected].underline == 0) {
                auto loaded = SaveLoad::Load(
                    allOptions[currentPage * Constants::PAGE_SIZE + selected]
                        .second
                );
                if (loaded) {
                    NavHost.SetContext(Constants::CURRENT_GAME, loaded.value());
                    return NavHost.Navigate("GameScreenView");
                } else {
                    return LoadFailed(NavHost);
                }
            }
        }
        if (tmp == L"\t") {
            isSearching = 1;
        }
        View::ClearRect(drawnRect);
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