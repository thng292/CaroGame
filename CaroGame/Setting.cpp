#include "Setting.h"

short CalcMaxWidth(const auto& strList);
short CalcMenuHeight(short noLine, bool hasTitle = true);
short CalcMenuWidth(short titlesMaxWidth, short optionsMaxWidth);
std::pair<short, short> CalcPosCenter(short menuWidth, short menuHeight);

View::Rect DrawSettingMenu(
    const std::vector<std::wstring>& titles,
    const std::vector<std::wstring>& options,
    int select,
    int prevSelect,
    bool updateSelectOnly
)
{
    short titlesWidth = CalcMaxWidth(titles);
    short menuWidth = CalcMenuWidth(titlesWidth, CalcMaxWidth(options));
    short menuHeight = CalcMenuHeight(titles.size(), true) + 2;
    auto posCenter = CalcPosCenter(menuWidth, menuHeight);
    View::Rect DrawnRect = {
        posCenter.second,
        posCenter.first,
        posCenter.first + menuWidth - 1,
        posCenter.second + menuHeight - 1};
    if (!updateSelectOnly) {
        View::DrawRect(DrawnRect);
    }
    posCenter.first += View::BORDER_WIDTH + View::HPADDING;
    posCenter.second += View::BORDER_WIDTH + View::VPADDING;
    if (!updateSelectOnly) {
        View::WriteToView(
            posCenter.first,
            posCenter.second,
            Language::GetString(L"SETTINGS_TITLE"),
            0,
            0,
            Theme::GetColor(ThemeColor::TITLE_TEXT_COLOR)
        );
    }
    posCenter.second += 2;
    titlesWidth += 2;
    for (size_t i = 0; i < titles.size(); i++) {
        if (updateSelectOnly && !(select == i || prevSelect == i)) continue;
        View::WriteToView(posCenter.first, posCenter.second + i, titles[i]);
        View::WriteToView(
            posCenter.first + titlesWidth - 2, posCenter.second + i, L":"
        );
        View::WriteToView(
            posCenter.first + titlesWidth,
            posCenter.second + i,
            options[i],
            0,
            i == select,
            i > 1 ? (options[i] == Language::GetString(L"ON_TITLE")
                         ? Theme::GetColor(ThemeColor::SWITCH_ON)
                         : Theme::GetColor(ThemeColor::SWITCH_OFF))
                  : Theme::GetColor(ThemeColor::TEXT_COLOR)
        );
    }
    View::WriteToView(
        posCenter.first,
        posCenter.second + titles.size() + 1,
        Language::GetString(L"NAVIGATE_BACK_KEY_TITLE"),
        Language::GetString(L"NAVIGATE_BACK_KEY_SHORTCUT")[0],
        select == titles.size()
    );
    return DrawnRect;
}

void Setting::SettingScreen(NavigationHost& NavHost)
{
    auto langList = Language::DiscoverLanguageFile();
    auto themeList = Theme::DiscoverThemeFiles();
    themeList.insert(themeList.begin(), {L"Default"});

    auto& currentLanguagePath = Config::GetConfig(Config::LanguageFilePath);
    auto& currentThemePath = Config::GetConfig(Config::ThemeFilePath);
    auto musicSetting = Config::GetConfig(Config::BGMusic);
    auto soundEffectSetting = Config::GetConfig(Config::SoundEffect);
    auto undoSetting = Config::GetConfig(Config::UndoOption);
    auto hintSetting = Config::GetConfig(Config::Hint);
    auto fourWarningSetting = Config::GetConfig(Config::FourWarning);

    int prevSelect = 0;
    int select = 0;
    int langSelect = std::find_if(
                         langList.begin(),
                         langList.end(),
                         [&currentLanguagePath](const auto& lang) {
                             return lang.path == currentLanguagePath;
                         }
                     ) -
                     langList.begin();
    int themeSelect = 0;
    if (currentThemePath.length()) {
        themeSelect = std::find_if(
                          themeList.begin(),
                          themeList.end(),
                          [&currentThemePath](const auto& theme) {
                              return theme.filePath == currentThemePath;
                          }
                      ) -
                      themeList.begin();
    }
    std::vector<std::wstring> titles = {
        Language::GetMeta(L"[LANG_SELECT]"),
        Language::GetString(L"THEME_SELECT_TITLE"),
        Language::GetString(L"BG_MUSIC_TITLE"),
        Language::GetString(L"SOUND_EFFECT_TITLE"),
        Language::GetString(L"UNDO_OPTION_TITLE"),
        Language::GetString(L"HINT_OPTION_TITLE"),
        Language::GetString(L"FOUR_WARNING_TITLE"),
    };

    std::vector<std::wstring> options = {
        L"< " + langList[langSelect].meta[L"[LANGUAGE]"] + L" >",
        L"< " + themeList[themeSelect].filePath.filename().wstring() + L" >",
        musicSetting == Config::Value_True ? Language::GetString(L"ON_TITLE")
                                           : Language::GetString(L"OFF_TITLE"),
        soundEffectSetting == Config::Value_True
            ? Language::GetString(L"ON_TITLE")
            : Language::GetString(L"OFF_TITLE"),
        undoSetting == Config::Value_True ? Language::GetString(L"ON_TITLE")
                                          : Language::GetString(L"OFF_TITLE"),
        hintSetting == Config::Value_True ? Language::GetString(L"ON_TITLE")
                                          : Language::GetString(L"OFF_TITLE"),
        fourWarningSetting == Config::Value_True
            ? Language::GetString(L"ON_TITLE")
            : Language::GetString(L"OFF_TITLE"),
    };

    auto musicCheck = [&musicSetting, &NavHost]() {
        if (Config::GetConfig(Config::BGMusic) == Config::Value_True) {
            if (!NavHost.CheckContext(Constants::CURRENT_BGM)) {
                return;
            }
            auto currentBGM = std::any_cast<Audio::Sound>(
                NavHost.GetFromContext(Constants::CURRENT_BGM)
            );
            if (BackgroundAudioService::GetCurrentSong() != currentBGM) {
                BackgroundAudioService::ChangeSong(currentBGM);
            }
            BackgroundAudioService::Play(false, true);
        } else {
            BackgroundAudioService::Stop();
        }
    };
    musicCheck();
    auto onExit = Utils::ON_SCOPE_EXIT(musicCheck);

    DrawHints();
    View::Rect DrawnRect;
    bool updateSelection = 0;

    while (true) {
        DrawnRect = DrawSettingMenu(
            titles, options, select, prevSelect, updateSelection
        );
        updateSelection = 0;
        auto tmp = InputHandle::Get();
        if (soundEffectSetting == Config::Value_True) {
            if (tmp == L"\r") {
                Utils::PlaySpecialKeySound();
            } else {
                Utils::PlayKeyPressSound();
            }
        }
        if (tmp == Language::GetString(L"NAVIGATE_BACK_KEY_SHORTCUT")) {
            return NavHost.Back();
        }
        if (Utils::keyMeanDown(tmp)) {
            prevSelect = select;
            select = Utils::modCycle(select + 1, titles.size() + 1);
            updateSelection = 1;
        }
        if (Utils::keyMeanUp(tmp)) {
            prevSelect = select;
            select = Utils::modCycle(select - 1, titles.size() + 1);
            updateSelection = 1;
        }
        if (select == 0) {
            if (Utils::keyMeanLeft(tmp)) {
                langSelect = Utils::modCycle(langSelect - 1, langList.size());
            }
            if (Utils::keyMeanRight(tmp)) {
                langSelect = Utils::modCycle(langSelect + 1, langList.size());
            }
            options[0] =
                L"< " + langList[langSelect].meta[L"[LANGUAGE]"] + L" >";
        }
        if (select == 1) {
            if (Utils::keyMeanLeft(tmp)) {
                themeSelect =
                    Utils::modCycle(themeSelect - 1, themeList.size());
            }
            if (Utils::keyMeanRight(tmp)) {
                themeSelect =
                    Utils::modCycle(themeSelect + 1, themeList.size());
            }
            options[1] = L"< " +
                         themeList[themeSelect].filePath.filename().wstring() +
                         L" >";
        }
        if (tmp == L"\r") {
            switch (select) {
                case 2:
                    musicSetting =
                        (musicSetting == Config::Value_True
                             ? Config::Value_False
                             : Config::Value_True);
                    options[2] = musicSetting == Config::Value_True
                                     ? Language::GetString(L"ON_TITLE")
                                     : Language::GetString(L"OFF_TITLE");
                    break;
                case 3:
                    soundEffectSetting =
                        (soundEffectSetting == Config::Value_True
                             ? Config::Value_False
                             : Config::Value_True);
                    options[3] = soundEffectSetting == Config::Value_True
                                     ? Language::GetString(L"ON_TITLE")
                                     : Language::GetString(L"OFF_TITLE");
                    break;
                case 4:
                    undoSetting =
                        (undoSetting == Config::Value_True
                             ? Config::Value_False
                             : Config::Value_True);
                    options[4] = undoSetting == Config::Value_True
                                     ? Language::GetString(L"ON_TITLE")
                                     : Language::GetString(L"OFF_TITLE");
                    break;
                case 5:
                    hintSetting =
                        (hintSetting == Config::Value_True
                             ? Config::Value_False
                             : Config::Value_True);
                    options[5] = hintSetting == Config::Value_True
                                     ? Language::GetString(L"ON_TITLE")
                                     : Language::GetString(L"OFF_TITLE");
                    break;
                case 6:
                    fourWarningSetting =
                        (fourWarningSetting == Config::Value_True
                             ? Config::Value_False
                             : Config::Value_True);
                    options[6] = fourWarningSetting == Config::Value_True
                                     ? Language::GetString(L"ON_TITLE")
                                     : Language::GetString(L"OFF_TITLE");
                    break;
                case 7:
                    return NavHost.Back();
            }
        }
        if (tmp == L" ") {
            Config::SetConfig(
                Config::ThemeFilePath, themeList[themeSelect].filePath
            );
            Config::SetConfig(L"LanguageFilePath", langList[langSelect].path);
            Config::SetConfig(Config::BGMusic, musicSetting);
            Config::SetConfig(Config::SoundEffect, soundEffectSetting);
            Config::SetConfig(Config::UndoOption, undoSetting);
            Config::SetConfig(Config::Hint, hintSetting);
            Config::SetConfig(Config::FourWarning, fourWarningSetting);

            Language::LoadLanguageFromFile(langList[langSelect].path);
            if (themeSelect) {
                Theme::LoadTheme(themeList[themeSelect].filePath);
            } else {
                Theme::LoadDefaultTheme();
            }

            if (Config::SaveUserSetting()) {
                return NavHost.Navigate("SettingApplied");
            } else {
                return NavHost.Navigate("SettingsAppliedFailed");
            }
        }
        if (tmp == L"B" || tmp == L"b") {
            return NavHost.Back();
        }
        if (!updateSelection) {
            View::ClearRect(DrawnRect);
        }
    }
}

void Setting::DrawHints()
{
    const auto controlHint1 = std::format(
        L"A, W, S, D, Arrow Keys: {}, Space: {}",
        Language::GetString(L"NAVIGATION_KEYS_TITLE"),
        Language::GetString(L"APPLY_KEY_TITLE")
    );

    const auto controlHint2 = std::format(
        L"Enter: {}, B: {}",
        Language::GetString(L"SELECT_KEY_TITLE"),
        Language::GetString(L"NAVIGATE_BACK_KEY_TITLE")
    );

    View::WriteToView(59 - controlHint1.size() / 2, 29 - 4, controlHint1);
    View::WriteToView(59 - controlHint2.size() / 2, 29 - 3, controlHint2);
}

void Setting::ApplySuccess(NavigationHost& NavHost)
{
    View::DrawMenuPrevState menuPrevState;

    View::DrawMenuCenter(
        menuPrevState,
        L"",
        {
            {(Language::GetString(L"APPLY_SUCCESSFULLY")), 0}
    },
        0
    );
    InputHandle::Get();
    return NavHost.Back();
}

void Setting::ApplyFailed(NavigationHost& NavHost)
{
    View::DrawMenuPrevState menuPrevState;

    View::DrawMenuCenter(
        menuPrevState,
        L"",
        {
            {(Language::GetString(L"APPLY_FAILED")), 0}
    },
        0
    );
    InputHandle::Get();
    return NavHost.Back();
}

inline short CalcMaxWidth(const auto& strList)
{
    short res = 0;
    for (auto& i : strList) {
        res = res < i.size() ? i.size() : res;
    }
    return res;
}

inline short CalcMenuHeight(short noLine, bool hasTitle)
{
    return noLine + 2 * (View::BORDER_WIDTH + View::VPADDING) +
           (hasTitle ? 2 : 0);
}

inline short CalcMenuWidth(short titlesMaxWidth, short optionsMaxWidth)
{
    return titlesMaxWidth + optionsMaxWidth + 2 +
           2 * (View::BORDER_WIDTH + View::HPADDING);
}

inline std::pair<short, short> CalcPosCenter(short menuWidth, short menuHeight)
{
    return {59 - menuWidth / 2, 14 - menuHeight / 2};
}