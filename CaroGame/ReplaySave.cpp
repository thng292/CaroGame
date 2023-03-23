#include "ReplaySave.h"

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

static bool OverwritePrompt()
{
    auto& title = Language::GetString(L"OVERWRITE_NOTICE_TITLE");
    std::vector<View::Option> options = {
        {Language::GetString(L"YES_TITLE"),
         Language::GetString(L"YES_SHORTCUT")[0]},
        {Language::GetString(L"NO_TITLE"),
         Language::GetString(L"NO_SHORTCUT")[0] }
    };
    int select = 0;
    int num = 2;
    std::wstring tmp;
    while (1) {
        View::DrawMenuCenter(title, options, select);
        tmp = InputHandle::Get();
        if (Config::GetSetting(Config::SoundEffect) == Config::Value_True) {
            Utils::PlayKeyPressSound();
        }
        if (Utils::keyMeanDown(tmp)) {
            select = Utils::modCycle(select - 1, num);
        }
        if (Utils::keyMeanUp(tmp)) {
            select = Utils::modCycle(select + 1, num);
        }
        if (tmp == L"\r") {
            return !select;
        }
        for (int i = 0; i < options.size(); i++) {
            if (tmp[0] == options[i].underline) {
                select = i;
                return !select;
            }
        }
    }
}

void ReplaySave::ReplaySave(NavigationHost& NavHost)
{
    static auto currentState = ReplaySaveState();

    DrawHints();

    auto SaveHandle = [&] {
        bool userChoice = 1;
        if (currentState.CheckOverwrite()) {
            userChoice = OverwritePrompt();
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

inline void ReplaySave::ReplaySaveState::LoadAllOptions()
{
    auto availableLoadFiles = SaveLoad::DiscoverSaveFiles(Constants::REPLAY_PATH);

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

inline void ReplaySave::ReplaySaveState::NextPage()
{
    UpdatePage(Utils::modCycle(currentPage + 1, maxPage));
    UpdateSearchInputOnNavigate();
}

inline void ReplaySave::ReplaySaveState::PrevPage()
{
    UpdatePage(Utils::modCycle(currentPage - 1, maxPage));
    UpdateSearchInputOnNavigate();
}

inline void ReplaySave::ReplaySaveState::NextSelection()
{
    selected = Utils::modCycle(selected + 1, options.size() - 1);
    UpdateSearchInputOnNavigate();
}

inline void ReplaySave::ReplaySaveState::PrevSelection()
{
    selected = Utils::modCycle(selected - 1, options.size() - 1);
    UpdateSearchInputOnNavigate();
}

void ReplaySave::ReplaySaveState::UpdatePage(int page)
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

void ReplaySave::ReplaySaveState::UpdateSearchInputOnNavigate()
{
    searchInput = allOptions[Constants::PAGE_SIZE * currentPage + selected]
                      .second.filename();
}

inline void ReplaySave::ReplaySaveState::Search()
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
ReplaySave::ReplaySaveState::onSearchValueChange(
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

inline bool ReplaySave::ReplaySaveState::Save(const GameState& currentGameState)
{
    if (searchInput.length()) {
        return SaveLoad::Save(currentGameState, searchInput, Constants::REPLAY_PATH);
    }
    return 0;
}

bool ReplaySave::ReplaySaveState::CheckOverwrite()
{
    for (auto& [i, path] : allOptions) {
        if (searchInput == path.filename()) {
            return true;
        }
    }
    return false;
}
