#pragma once
#include <algorithm>
#include <format>

#include "Config.h"
#include "Constants.h"
#include "InputHandle.h"
#include "Language.h"
#include "Navigate.h"
#include "SaveLoad.h"
#include "Utils.h"
#include "View.h"

namespace ReplayLoad {

    typedef std::vector<std::pair<std::wstring, std::filesystem::path>>
        OptionList;

    struct ReplayLoadState {
        struct SortTemporary {
            size_t foundIndex = 0;
            std::wstring name;
            size_t mapIndex = 0;
        };

        ReplayLoadState()
        {
            LoadAllOptions();
            maxPage = allOptions.size() / 10 + bool(allOptions.size() % 10);
            UpdatePage(0);
        }

        OptionList allOptions;
        int selected = 0;
        int currentPage = 0;
        bool isSearching = 0;
        int maxPage;
        std::vector<View::Option> options;
        std::wstring pageIndicator;
        std::wstring searchInput;
        View::Rect drawnRect;

        void LoadAllOptions();
        void NextPage();
        void PrevPage();
        void NextSelection();
        void PrevSelection();
        void UpdatePage(int page);
        void Search();
        std::function<void(const std::wstring&)> onSearchValueChange(
            const std::function<void(void)>& callback
        );
        std::optional<GameState> LoadCurrentSelect();
    };

    void ReplayLoad(NavigationHost& NavHost);
}  // namespace ReplayLoad