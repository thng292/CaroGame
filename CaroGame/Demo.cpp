#include "InputHandle.h"
#include "Language.h"
#include "Navigate.h"
#include "View.h"

void ExitView(NavigationHost& NavHost)
{
    static short selectedOption = 1;   // User option
    static const short maxOption = 2;  // Number of option
    View::DrawMenuPrevState menuPrevState;
    while (1) {                        // Main while loop
        View::DrawMenuCenter(
            menuPrevState,
            L"Are you sure? ",
            {
                {L"YES",   L'Y'},
                {L"NO :(", L'N'},
        },
            selectedOption
        );
        auto tmp = InputHandle::Get();  // Get input from user
        // Input Handle
        // Normal Navigation
        if (tmp == L"w" || tmp == L"W") {
            selectedOption =
                (selectedOption - 1 + maxOption) % maxOption;  // Cycle effect
        }
        if (tmp == L"s" || tmp == L"S") {
            selectedOption = (selectedOption + 1) % maxOption;  // Cycle effect
        }
        // Shortcut
        if (tmp == L"Y") {
            return NavHost.NavigateExit();  // Nho return
        }
        if (tmp == L"N") {
            return NavHost.Back();  // Nho return
        }
        // Handle Select
        if (tmp == L"\r") {
            switch (selectedOption) {
                case 0:
                    return NavHost.NavigateExit();  // Nho return
                case 1:
                    return NavHost.Back();  // Nho return
            }
        }
    }
}

// DEMO PURPOSE ONLY
void TestView1(NavigationHost& NavHost)
{
    static short selectedOption = 0;   // User option
    static const short maxOption = 3;  // Number of option
    View::DrawTextWrapped(
        0,
        1,
        L"This is a very very long long text. This is a very very long long "
        L"text. This is a very very long long text.",
        3,
        30
    );
    NavHost.SetContext("TestContextValue", L"this is the context value");
    View::DrawMenuPrevState menuPrevState;

    while (1) {  // Main while loop
        View::DrawMenuCenter(
            menuPrevState,
            L"",
            {
                {L"TestView2", L'2'},
                {L"TestView3", L'3'},
                {L"Exit",      L'E'},
        },
            selectedOption
        );
        auto tmp = InputHandle::Get();  // Get input from user
        // Input Handle
        // Normal Navigation
        if (tmp == L"w" || tmp == L"W") {
            selectedOption =
                (selectedOption - 1 + maxOption) % maxOption;  // Cycle effect
        }
        if (tmp == L"s" || tmp == L"S") {
            selectedOption = (selectedOption + 1) % maxOption;  // Cycle effect
        }
        // Shortcut
        if (tmp == L"2") {
            return NavHost.Navigate("TestView2");  // Nho return
        }
        if (tmp == L"3") {
            return NavHost.Navigate("TestView3");  // Nho return
        }
        if (tmp == L"e" || tmp == L"E") {
            return NavHost.NavigateStack("ExitView");  // Nho return
        }
        // Handle Select
        if (tmp == L"\r") {
            switch (selectedOption) {
                case 0:
                    return NavHost.Navigate("TestView2");  // Nho return
                case 1:
                    return NavHost.Navigate("TestView3");  // Nho return
                case 2:
                    return NavHost.NavigateStack("ExitView");  // Nho return
            }
        }
    }
}

// DEMO PURPOSE ONLY
void TestView2(NavigationHost& NavHost)
{
    View::WriteToView(
        20,
        20,
        std::any_cast<const wchar_t*>(NavHost.GetFromContext("TestContextValue")
        ),
        0,
        true
    );
    View::WriteToView(20, 21, L"Enter to go back", 0, true);
    auto tmp = InputHandle::Get();
    /*if (tmp == L"\r") {
            return NavHost.Navigate("TestView3");
    }*/
    if (tmp == L"\r") {
        return NavHost.Back();
    }
}

// DEMO PURPOSE ONLY
void TestView3(NavigationHost& NavHost)
{
    View::WriteToView(20, 22, L"Test view 3", 0, true);
    View::WriteToView(20, 21, L"Enter to go back", 0, true);
    auto tmp = InputHandle::Get();
    if (tmp == L"\r") {
        return NavHost.Back();
    }
}

int Demo()
{
    NavigationHost NavHost(
        "TestView1",  // Initialize Navigation Host. "TestView1 is the first
                      // view to be shown
        {
            {"TestView1", TestView1}, // Register TestView1
            {"TestView2", TestView2}, // Register TestView2
            {"TestView3", TestView3}, // Register TestView3
            {"ExitView",  ExitView }  // Register ExitView
    }
    );
    return 0;
}