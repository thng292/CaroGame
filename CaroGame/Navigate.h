#pragma once
#include <Windows.h>
#include <conio.h>

#include <any>
#include <functional>
#include <stack>
#include <string>
#include <unordered_map>

#include "View.h"
#if _DEBUG
#include "InputHandle.h"
#endif

#ifndef ViewFunc
#define ViewFunc std::function<void(NavigationHost&)>
#endif
#ifndef ViewFuncMap
#define ViewFuncMap std::unordered_map<std::string, ViewFunc>
#endif

namespace {
    const int CONSOLE_WIDTH = 120;
    const int CONSOLE_HEIGHT = 30;
    const std::string EXIT = "EXITCODE";
}  // namespace

class NavigationHost {
   private:
    struct Screen {
        std::string name;
        PCHAR_INFO prevScreenBuffer = nullptr;
    };

    Screen _CurrentScreen;
    std::unordered_map<std::string, std::any> Context;
    ViewFuncMap _Links;
    std::stack<Screen> _History;
    void HistoryPop();
    void HistoryPopAllOverlay();

   public:
    NavigationHost() = default;
    NavigationHost(const std::string& Start, const ViewFuncMap& links);
    // delete other constructor
    NavigationHost(const NavigationHost&) = delete;
    NavigationHost& operator=(const NavigationHost&) = delete;
    NavigationHost(NavigationHost&&) = delete;
    NavigationHost& operator=(NavigationHost&&) = delete;

    std::any& GetFromContext(const std::string& name);
    bool CheckContext(const std::string& name);
    void SetContext(const std::string& name, const std::any& data);
    void DeleteContext(const std::string& name);

    void Add(const std::string& path, const ViewFunc& view);
    void NavigateStack(const std::string& path);
    void Navigate(const std::string& path);

    void Back();
    void BackToLastNotOverlay();
    void NavigateExit();
    ~NavigationHost();
};