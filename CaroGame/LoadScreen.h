#pragma once
#include <algorithm>
#include <ctime>
#include <format>
#include <locale>

#include "Config.h"
#include "Constants.h"
#include "InputHandle.h"
#include "Language.h"
#include "Navigate.h"
#include "SaveLoad.h"
#include "Utils.h"
#include "View.h"

namespace LoadScreen {

    struct SortTemporary {
        size_t foundIndex;
        std::wstring name;
        size_t mapIndex;
    };

    void DrawHints();

    std::vector<std::pair<std::wstring, std::filesystem::path>>
    LoadScreen::LoadAllOptions(
        const std::filesystem::path& dir = Constants::SAVE_PATH
    );

    void LoadPage(
        const auto& allOptions, int& selected, int maxPage,
        std::wstring& pageIndicator, std::vector<View::Option>& options,
        int page
    );

    std::vector<std::pair<std::wstring, std::filesystem::path>> Search(
        const std::vector<std::pair<std::wstring, std::filesystem::path>>&
            allOptions,
        const std::wstring& searchTerm
    );

    void LoadSceen(NavigationHost& NavHost);
}  // namespace LoadScreen