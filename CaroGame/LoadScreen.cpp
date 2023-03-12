#include "LoadScreen.h"

void EmptyLoad(NavigationHost& NavHost);

void LoadFailed(NavigationHost& NavHost);

void LoadScreen::Load(NavigationHost& NavHost) {
    {
        View::DrawTextCenterdVertically(29 - 3, std::format(
            L"A, W, S, D, Arrow Keys: {}",
            Language::GetString(L"NAVIGATION_KEYS_TITLE")
        ));
        View::DrawTextCenterdVertically(29 - 2, std::format(
            L"B: {}, Enter: {}",
            Language::GetString(L"NAVIGATE_BACK_TITLE"),
            Language::GetString(L"SELECT_KEY_TITLE")
        ));
    }
    auto& soundSetting = Config::GetSetting(Config::SoundEffect);
    auto allOptions = ([]() {
        auto availableLoadFiles = SaveLoad::DiscoverSaveFiles();
        std::sort(availableLoadFiles.begin(), availableLoadFiles.end(),
            [](const FileHandle::FileDetail& a, const FileHandle::FileDetail& b) {
                return a.lastModified > b.lastModified;
            });
        std::wstring tmp;
        std::vector<std::pair<std::wstring, std::filesystem::path>> res;
        for (auto& file : availableLoadFiles)
        {
            res.emplace_back(
                Utils::CatStringSpaceBetween(50,
                    file.filePath.filename(),
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
    int selected = 0;
    int currentPage = 0;
    int maxPage = allOptions.size() / 10 + bool(allOptions.size() % 10);
    std::vector<View::Option> options;
    std::wstring pageIndicator;
    auto loadPage = [&](int page) {
        selected = 0;
        options.clear();
        size_t end = min((page + 1) * Constants::PAGE_SIZE, allOptions.size());
        for (size_t i = page * Constants::PAGE_SIZE; i < end; i++)
        {
            options.emplace_back(allOptions[i].first, 0);
        }
        pageIndicator = std::format(L"{}/{}", page + 1, maxPage);
        options.emplace_back(pageIndicator, 0);
    };
    loadPage(0);
    auto& title = Language::GetString(L"LOAD_MENU_TITLE");
    while (1)
    {
        auto drawnRect = View::DrawMenuCenter(title, options, selected);
        auto tmp = InputHandle::Get();
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
            loadPage(currentPage);
        }
        if (Utils::keyMeanRight(tmp)) {
            currentPage = Utils::modCycle(currentPage + 1, maxPage);
            loadPage(currentPage);
        }
        if (tmp == L"B" || tmp == L"b") {
            return NavHost.Back();
        }
        if (tmp == L"\r") {
            if (options[selected].underline == 0) {
                auto loaded = SaveLoad::Load(
                    allOptions[currentPage * Constants::PAGE_SIZE + selected].second);
                if (loaded) {
                    NavHost.SetContext(Constants::CURRENT_GAME, loaded.value());
                    return NavHost.Navigate("GameScreenView");
                }
                else {
                    return LoadFailed(NavHost);
                }
            }
        }
        View::ClearRect(drawnRect);
    }
}

void EmptyLoad(NavigationHost& NavHost) {
    View::DrawMenuCenter(
        Language::GetString(L"EMPTY_SAVE_TITLE"),
        {
            {Language::GetString(L"EMPTY_SAVE_DESC"), 0} ,
            {Language::GetString(L"NAVIGATE_BACK_TITLE"), Language::GetString(L"NAVIGATE_BACK_SHORTCUT")[0]}
        },
        1);
    InputHandle::Get();
    NavHost.Back();
}

void LoadFailed(NavigationHost& NavHost) {
    View::DrawMenuCenter(Language::GetString(L"LOAD_FAILED_TITLE"), {}, 0);
    InputHandle::Get();
    return NavHost.Back();
}