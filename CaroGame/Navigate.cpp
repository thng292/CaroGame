#include "Navigate.h"

#if _DEBUG
void Draw404(NavigationHost& NavHost)
{
    View::DrawMenuPrevState menuPrevState;

    View::DrawMenuCenter(
        menuPrevState,
        L"404",
        {
            {L"This screen does not exist", 0},
            {L"Press Enter to back",        0},
    },
        0
    );
    while (true) {
        auto tmp = InputHandle::Get();
        if (tmp == L"\r") {
            return NavHost.Back();
        }
    }
}
#endif

NavigationHost::NavigationHost(
    const std::string& Start, const ViewFuncMap& links
)
{
    View::ClearScreen();
    _CurrentScreen = {Start, nullptr};
    _Links = links;
    while (_CurrentScreen.name != EXIT) {
#if _DEBUG
        if (!_Links.contains(_CurrentScreen.name)) {
            Draw404(*this);
        } else {
            _Links[_CurrentScreen.name](*this);
        }
#else
        _Links[_CurrentScreen.name](*this);
#endif
    }
}

std::any& NavigationHost::GetFromContext(const std::string& name)
{
    return Context[name];
}

bool NavigationHost::CheckContext(const std::string& name)
{
    return Context.contains(name);
}

void NavigationHost::SetContext(const std::string& name, const std::any& data)
{
    Context[name] = data;
}

void NavigationHost::DeleteContext(const std::string& name)
{
    Context.erase(name);
}

void NavigationHost::Add(const std::string& path, const ViewFunc& view)
{
    _Links[path] = view;
}

void NavigationHost::HistoryPop()
{
    delete[] _History.top().prevScreenBuffer;
    _History.pop();
}

// No return
void NavigationHost::NavigateStack(const std::string& path)
{
    // Save current screen
    HANDLE StdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    PCHAR_INFO buffer = new CHAR_INFO[CONSOLE_WIDTH * CONSOLE_HEIGHT];
    SMALL_RECT readRegion = {0, 0, 119, 29};
    ReadConsoleOutput(StdHandle, buffer, {120, 30}, {0, 0}, &readRegion);
    _History.push(_CurrentScreen);
    _CurrentScreen = {path, buffer};
}

void NavigationHost::Navigate(const std::string& path)
{
    _History.push(_CurrentScreen);
    HistoryPopAllOverlay();
    _CurrentScreen = {path, nullptr};
    View::ClearScreen();
}

void NavigationHost::Back()
{
    if (_History.empty()) {
        _CurrentScreen = {EXIT, nullptr};
        return;
    }
    View::ClearScreen();
    if (_CurrentScreen.prevScreenBuffer != nullptr) {
        SMALL_RECT tmp = {0, 0, CONSOLE_WIDTH - 1, CONSOLE_HEIGHT - 1};
        WriteConsoleOutput(
            GetStdHandle(STD_OUTPUT_HANDLE),
            _CurrentScreen.prevScreenBuffer,
            {CONSOLE_WIDTH, CONSOLE_HEIGHT},
            {0, 0},
            &tmp
        );
        delete[] _CurrentScreen.prevScreenBuffer;
    }
    _CurrentScreen = _History.top();
    _History.pop();
}

void NavigationHost::BackToLastNotOverlay()
{
    // Pop to last overlay
    while (!_History.empty() && _History.top().prevScreenBuffer != nullptr) {
        _CurrentScreen = _History.top();
        HistoryPop();
    }
    Back();
}

void NavigationHost::NavigateExit() { _CurrentScreen.name = EXIT; }

NavigationHost::~NavigationHost()
{
    delete[] _CurrentScreen.prevScreenBuffer;
    while (!_History.empty()) {
        HistoryPop();
    }
}

void NavigationHost::HistoryPopAllOverlay()
{
    while (!_History.empty() && _History.top().prevScreenBuffer != nullptr) {
        HistoryPop();
    }
}
