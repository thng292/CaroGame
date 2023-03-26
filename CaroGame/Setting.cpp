#include "Setting.h"

short CalcMaxWidth(const auto& strList);
short CalcMenuHeight(short noLine, bool hasTitle = true);
short CalcMenuWidth(short titlesMaxWidth, short optionsMaxWidth);
std::pair<short, short> CalcPosCenter(short menuWidth, short menuHeight);

void Setting::SettingScreen(NavigationHost& NavHost)
{
    auto langList = Language::DiscoverLanguageFile();

    int select = 0;
    int langSelect = [&langList]() {
        const auto& tmp = Config::GetSetting(L"LanguageFilePath");
        for (int i = 0; i < langList.size(); i++)
            if (langList[i].path == tmp) return i;
        return 0;
    }();

    std::vector<std::wstring> titles;
    std::vector<std::wstring> options;
    auto& musicSetting = Config::GetSetting(Config::BGMusic);
    auto& soundEffectSetting = Config::GetSetting(Config::SoundEffect);
    auto& undoSetting = Config::GetSetting(Config::UndoOption);
    if (musicSetting == Config::Value_True) {
        BackgroundAudioService::getInstance()->getPlayer().Play();
    } else {
        BackgroundAudioService::getInstance()->getPlayer().Stop();
    }
    {
        const auto controlHint1 = std::format(
            L"A, W, S, D, Arrow Keys: {}, Space: {}",
            Language::GetString(L"NAVIGATION_KEYS_TITLE"),
            Language::GetString(L"APPLY_KEY_TITLE")
        );

        const auto controlHint2 = std::format(
            L"Enter: {}, B: {}",
            Language::GetString(L"SELECT_KEY_TITLE"),
            Language::GetString(L"NAVIGATE_BACK_TITLE")
        );

        View::WriteToView(59 - controlHint1.size() / 2, 29 - 4, controlHint1);
        View::WriteToView(59 - controlHint2.size() / 2, 29 - 3, controlHint2);
    }
    while (true) {
        titles = {
            Language::GetMeta(L"[LANG_SELECT]"),
            Language::GetString(L"BG_MUSIC_TITLE"),
            Language::GetString(L"SOUND_EFFECT_TITLE"),
            Language::GetString(L"UNDO_OPTION_TITLE"),
        };
        options = {
            L"< " + langList[langSelect].meta[L"[LANGUAGE]"] + L" >",
            musicSetting == Config::Value_True
                ? Language::GetString(L"ON_TITLE")
                : Language::GetString(L"OFF_TITLE"),
            soundEffectSetting == Config::Value_True
                ? Language::GetString(L"ON_TITLE")
                : Language::GetString(L"OFF_TITLE"),
            undoSetting == Config::Value_True
                ? Language::GetString(L"ON_TITLE")
                : Language::GetString(L"OFF_TITLE"),
        };
        short titlesWidth = CalcMaxWidth(titles);
        short menuWidth = CalcMenuWidth(titlesWidth, CalcMaxWidth(options));
        short menuHeight = CalcMenuHeight(titles.size(), true) + 2;
        auto posCenter = CalcPosCenter(menuWidth, menuHeight);
        View::Rect DrawnRect = {
            posCenter.second,
            posCenter.first,
            posCenter.first + menuWidth - 1,
            posCenter.second + menuHeight - 1};
        View::DrawRect(DrawnRect);
        posCenter.first += View::BORDER_WIDTH + View::HPADDING;
        posCenter.second += View::BORDER_WIDTH + View::VPADDING;
        View::WriteToView(
            posCenter.first,
            posCenter.second,
            Language::GetString(L"SETTINGS_TITLE")
        );
        posCenter.second += 2;
        titlesWidth += 2;
        for (size_t i = 0; i < titles.size(); i++) {
            View::WriteToView(posCenter.first, posCenter.second + i, titles[i]);
            View::WriteToView(
                posCenter.first + titlesWidth - 2, posCenter.second + i, L":"
            );
            View::WriteToView(
                posCenter.first + titlesWidth,
                posCenter.second + i,
                options[i],
                0,
                i == select
            );
        }
        View::WriteToView(
            posCenter.first,
            posCenter.second + titles.size() + 1,
            Language::GetString(L"NAVIGATE_BACK_TITLE"),
            Language::GetString(L"NAVIGATE_BACK_SHORTCUT")[0],
            select == titles.size()
        );
        auto tmp = InputHandle::Get();
        if (soundEffectSetting == Config::Value_True) {
            Utils::PlayKeyPressSound();
        }
        if (tmp == Language::GetString(L"NAVIGATE_BACK_SHORTCUT")) {
            return NavHost.Back();
        }
        if (Utils::keyMeanDown(tmp)) {
            select = Utils::modCycle(select + 1, titles.size() + 1);
        }
        if (Utils::keyMeanUp(tmp)) {
            select = Utils::modCycle(select - 1, titles.size() + 1);
        }
        if (select == 0) {
            if (Utils::keyMeanLeft(tmp)) {
                langSelect = Utils::modCycle(langSelect - 1, langList.size());
            }
            if (Utils::keyMeanRight(tmp)) {
                langSelect = Utils::modCycle(langSelect + 1, langList.size());
            }
        }
        if (tmp == L"\r") {
            switch (select) {
                case 0:
                    Config::SetSetting(
                        L"LanguageFilePath", langList[langSelect].path
                    );
                    Language::LoadLanguageFromFile(langList[langSelect].path);
                    break;
                case 1:
                    musicSetting =
                        (musicSetting == Config::Value_True
                             ? Config::Value_False
                             : Config::Value_True);
                    break;
                case 2:
                    soundEffectSetting =
                        (soundEffectSetting == Config::Value_True
                             ? Config::Value_False
                             : Config::Value_True);
                    break;
                case 3:
                    undoSetting =
                        (undoSetting == Config::Value_True
                             ? Config::Value_False
                             : Config::Value_True);
                    break;
                case 4:
                    return NavHost.Back();
            }
        }
        if (tmp == L" ") {
            Language::LoadLanguageFromFile(langList[langSelect].path);
            Config::SaveUserSetting();
            auto tmp = Language::GetString(L"APPLY_SUCCESSFULLY");
            View::WriteToView(59 - tmp.size() / 2, 2, tmp);
            return NavHost.Navigate("Settings");
        }
        if (tmp == L"B" || tmp == L"b") {
            return NavHost.Back();
        }
        View::ClearRect(DrawnRect);
    }
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