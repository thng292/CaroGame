#include "Common.h"

void Common::DrawHints()
{
    View::DrawTextCenterdVertically(
        29 - 3,
        std::format(
            L"A, W, S, D, \u2190\u2191\u2193\u2192 : {}, X: {}",
            Language::GetString(L"NAVIGATION_KEYS_TITLE"),
            Language::GetString(L"DELETE_KEY_TITLE")
        )
    );

    View::DrawTextCenterdVertically(
        29 - 2,
        std::format(
            L"B: {}, Enter: {}, Tab: {}",
            Language::GetString(L"NAVIGATE_BACK_KEY_TITLE"),
            Language::GetString(L"SELECT_KEY_TITLE"),
            Language::GetString(L"SEARCH_KEY_TITLE")
        )
    );
}

void Common::DrawHintsLess()
{
    View::DrawTextCenterdVertically(
        29 - 2,
        std::format(
            L"A, W, S, D, \u2190\u2191\u2193\u2192: {}, Enter: {}, B: {}",
            Language::GetString(L"NAVIGATION_KEYS_TITLE"),
            Language::GetString(L"SELECT_KEY_TITLE"),
            Language::GetString(L"NAVIGATE_BACK_KEY_TITLE")

        )
    );
}

bool Common::ConfirmPrompt(const std::wstring& title)
{
    DrawHintsLess();
    std::vector<View::Option> options = {
        {Language::GetString(L"YES_TITLE"),
         Language::GetString(L"YES_TITLE_SHORTCUT")[0]},
        {Language::GetString(L"NO_TITLE"),
         Language::GetString(L"NO_TITLE_SHORTCUT")[0] }
    };
    int select = 0;
    int num = 2;
    std::wstring tmp;
    View::DrawMenuPrevState menuPrevState;

    while (1) {
        View::DrawMenuCenter(menuPrevState, title, options, select);
        tmp = InputHandle::Get();
        if (Config::GetConfig(Config::SoundEffect) == Config::Value_True) {
            if (tmp == L"\r") {
                Audio::PlayAndForget(Audio::Sound::MenuSelect);
            } else {
                Utils::PlayKeyPressSound();
            }
        }
        if (Utils::keyMeanDown(tmp)) {
            select = Utils::modCycle(select - 1, num);
        }
        if (Utils::keyMeanUp(tmp)) {
            select = Utils::modCycle(select + 1, num);
        }

        if (Utils::ShortcutCompare(
                tmp, Language::GetString(L"YES_TITLE_SHORTCUT")
            )) {
            return 1;
        }

        if (Utils::ShortcutCompare(
                tmp, Language::GetString(L"NO_TITLE_SHORTCUT")
            )) {
            return 0;
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

void Common::SaveLoadScreenViewModel::LoadAllOptions(path dir)
{
    auto availableLoadFiles = SaveLoad::DiscoverSaveFiles(dir);

    std::sort(
        availableLoadFiles.begin(),
        availableLoadFiles.end(),
        [](const FileHandle::FileDetail& a, const FileHandle::FileDetail& b) {
            return a.lastModified > b.lastModified;
        }
    );

    allOptions.clear();
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

    maxPage = allOptions.size() / 10 + bool(allOptions.size() % 10);
}

void Common::SaveLoadScreenViewModel::NextPage()
{
    UpdatePage(Utils::modCycle(currentPage + 1, maxPage));
}

void Common::SaveLoadScreenViewModel::PrevPage()
{
    UpdatePage(Utils::modCycle(currentPage - 1, maxPage));
}

void Common::SaveLoadScreenViewModel::NextSelection()
{
    selected = Utils::modCycle(selected + 1, options.size() - 1);
}

void Common::SaveLoadScreenViewModel::PrevSelection()
{
    selected = Utils::modCycle(selected - 1, options.size() - 1);
}

void Common::SaveLoadScreenViewModel::UpdatePage(int page)
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

bool Common::SaveLoadScreenViewModel::Search()
{
    static auto cmp = [](const SortTemporary& a, const SortTemporary& b) {
        if (a.foundIndex != size_t(-1) && b.foundIndex != size_t(-1)) {
            return a.name > b.name;
        }

        if (a.foundIndex == b.foundIndex) {
            return a.name > b.name;
        }

        return a.foundIndex < b.foundIndex;
    };
    size_t n = allOptions.size();
    std::vector<SortTemporary> tmp;
    tmp.resize(n);

    for (size_t i = 0; i < n; i++) {
        auto ttt = allOptions[i].second.filename().wstring();
        tmp[i] = {ttt.find(searchInput), std::move(ttt), i};
    }

    if (std::is_sorted(tmp.begin(), tmp.end(), cmp)) {
        return 0;
    }

    std::sort(tmp.begin(), tmp.end(), cmp);

    OptionList vtmp;
    vtmp.resize(n);
    for (size_t i = 0; i < n; i++) {
        vtmp[i] = allOptions[tmp[i].mapIndex];
    }
    allOptions = vtmp;
    return 1;
}

std::function<void(const std::wstring&)>
Common::SaveLoadScreenViewModel::onSearchValueChange(
    const std::function<void(void)>& callback
)
{
    return [&](const std::wstring& newInp) {
        if (newInp.length() > 30) {
            return;
        }
        searchInput = newInp;
        if (Search()) {
            UpdatePage(0);
            callback();
        }
    };
}

bool Common::SaveLoadScreenViewModel::RemoveCurrentSelect()
{
    return FileHandle::Delete(
        allOptions[currentPage * Constants::PAGE_SIZE + selected].second
    );
}

bool Common::SaveLoadScreenViewModel::CheckOverwrite()
{
    for (auto& [i, path] : allOptions) {
        if (searchInput == path.filename()) {
            return true;
        }
    }
    return false;
}
