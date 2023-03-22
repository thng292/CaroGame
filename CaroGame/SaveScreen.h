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

namespace SaveScreen {

    typedef std::vector<std::pair<std::wstring, std::filesystem::path>>
        OptionList;

    struct SaveScreenState {
        struct SortTemporary {
            size_t foundIndex = 0;
            std::wstring name;
            size_t mapIndex = 0;
        };

        SaveScreenState()
        {
            LoadAllOptions();
            maxPage = allOptions.size() / 10 + bool(allOptions.size() % 10);
            UpdatePage(0);
            selected = -1;
        }

        int selected = 0;
        int currentPage = 0;
        bool isSearching = 0;
        int maxPage;

        OptionList allOptions;
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
        void UpdateSearchInputOnNavigate();
        void Search();
        std::function<void(const std::wstring&)> onSearchValueChange(
            const std::function<void(void)>& callback
        );
        bool Save(const GameState& currentGameState);
        bool CheckOverwrite();
    };

    void SaveSuccess(NavigationHost& NavHost);
    void SaveFailed(NavigationHost& NavHost);
    void SaveScreen(NavigationHost& NavHost);
}  // namespace SaveScreen