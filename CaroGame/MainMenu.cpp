#include "MainMenu.h"

void MainMenu::ScreenMainMenu(NavigationHost& NavHost)
{
    NavHost.SetContext(Constants::CURRENT_BGM, Audio::Sound::MenuBGM);
    if (Config::GetConfig(Config::BGMusic) == Config::Value_True) {
        if (BackgroundAudioService::GetCurrentSong() != Audio::Sound::MenuBGM) {
            BackgroundAudioService::ChangeSong(Audio::Sound::MenuBGM);
            BackgroundAudioService::Play(true, true);
        }
    }

    static short selectedOption = 0;   // User option
    static const short maxOption = 7;  // Number of option
                                       // Vi tri bat dau ve
    Common::DrawHintsLess();
    Caro(32, 1);
    Logo_Deadpool(3, 5);
    Logo_Captain(79 + 4, 5);
    View::WriteToView(119 - Constants::version.size(), 0, Constants::version);

    std::vector<std::wstring> shortcuts = {
        Language::GetString(L"NEW_GAME_SHORTCUT"),
        Language::GetString(L"LOAD_SHORTCUT"),
        Language::GetString(L"REPLAY_SHORTCUT"),
        Language::GetString(L"SETTINGS_SHORTCUT"),
        Language::GetString(L"TUTORIAL_SHORTCUT"),
        Language::GetString(L"ABOUT_SHORTCUT"),
        Language::GetString(L"EXIT_SHORTCUT")

    };

    std::vector<View::Option> options = {
        {Language::GetString(L"NEW_GAME_TITLE"), shortcuts[0][0]},
        {Language::GetString(L"LOAD_TITLE"),     shortcuts[1][0]},
        {Language::GetString(L"REPLAY_TITLE"),   shortcuts[2][0]},
        {Language::GetString(L"SETTINGS_TITLE"), shortcuts[3][0]},
        {Language::GetString(L"TUTORIAL_TITLE"), shortcuts[4][0]},
        {Language::GetString(L"ABOUT_TITLE"),    shortcuts[5][0]},
        {Language::GetString(L"EXIT_TITLE"),     shortcuts[6][0]},
    };
    auto& soundEffect = Config::GetConfig(L"SoundEffect");
    View::DrawMenuPrevState menuPrevState;

    while (1) {  // Main while loop
        View::DrawMenu(menuPrevState, 50, 13, L"", options, selectedOption);
        auto tmp = InputHandle::Get();  // Get input from user
        if (soundEffect == Config::Value_True) {
            if (tmp == L"\r") {
                Utils::PlaySpecialKeySound();
            } else {
                Utils::PlayKeyPressSound();
            }
        }
        // Input Handle
        // Normal Navigation
        if (Utils::keyMeanUp(tmp)) {
            selectedOption =
                Utils::modCycle(selectedOption - 1, options.size());
        }
        if (Utils::keyMeanDown(tmp)) {
            selectedOption =
                Utils::modCycle(selectedOption + 1, options.size());
        }

        // TODO ???????????????????
        // Shortcut
        if (Utils::ShortcutCompare(tmp, shortcuts[0])) {
            return NavHost.Navigate("GameModeTypeView");  // Nho return
        }
        if (Utils::ShortcutCompare(tmp, shortcuts[1])) {
            return NavHost.Navigate("LoadScreen");  // Nho return
        }
        if (Utils::ShortcutCompare(tmp, shortcuts[2])) {
            return NavHost.Navigate("ReplayLoad");  // Nho return
        }
        if (Utils::ShortcutCompare(tmp, shortcuts[3])) {
            return NavHost.Navigate("Setting");  // Nho return
        }
        if (Utils::ShortcutCompare(tmp, shortcuts[4])) {
            return NavHost.Navigate("Tutorial");  // Nho return
        }
        if (Utils::ShortcutCompare(tmp, shortcuts[5])) {
            return NavHost.Navigate("About");  // Nho return
        }
        if (Utils::ShortcutCompare(tmp, shortcuts[6])) {
            return NavHost.NavigateStack("ExitScreen");  // Nho return
        }
        // Handle Select
        if (tmp == L"\r") {
            switch (selectedOption) {
                case 0:
                    return NavHost.Navigate("GameModeTypeView");  // Nho return
                case 1:
                    return NavHost.Navigate("LoadScreen");  // Nho return
                case 2:
                    return NavHost.Navigate("ReplayLoad");
                case 3:
                    return NavHost.Navigate("Setting");
                case 4:
                    return NavHost.Navigate("Tutorial");
                case 5:
                    return NavHost.Navigate("About");
                case 6:
                    return NavHost.NavigateStack("ExitScreen");  // Nho return
            }
        }
    }
}
