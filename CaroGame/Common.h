#pragma once
#include <algorithm>
#include <chrono>
#include <format>
#include <mutex>
#include <string>

#include "Config.h"
#include "Constants.h"
#include "GameState.h"
#include "Language.h"
#include "SaveLoad.h"
#include "Timer.h"
#include "Utils.h"
#include "View.h"

using std::filesystem::path;

namespace Common {

    typedef std::vector<std::pair<std::wstring, path>> OptionList;

    struct SortTemporary {
        size_t foundIndex = 0;
        std::wstring name;
        size_t mapIndex = 0;
    };

    class SaveLoadScreenViewModel {
       public:
        path allOptionsDir;
        int selected = 0;
        int currentPage = 0;
        bool isSearching = 0;
        int maxPage = 0;

        OptionList allOptions;
        std::vector<View::Option> options;
        std::wstring pageIndicator;
        std::wstring searchInput;

        SaveLoadScreenViewModel(path dir = Constants::SAVE_PATH)
        {
            allOptionsDir = dir;
        }

        void ReloadAllOptions()
        {
            LoadAllOptions(allOptionsDir);
            UpdatePage(currentPage);
        }

        void LoadAllOptions(path dir);
        void NextPage();
        void PrevPage();
        void NextSelection();
        void PrevSelection();
        void UpdatePage(int page);
        bool Search();
        std::function<void(const std::wstring&)> onSearchValueChange(
            const std::function<void(void)>& callback
        );
        bool RemoveCurrentSelect();
        bool CheckOverwrite();
    };

    void DrawHints();
    void DrawHintsLess();
    bool ConfirmPrompt(const std::wstring& title);
}  // namespace Common