#include "Setting.h"

short CalcMaxWidth(const auto& strList);
short CalcMenuHeight(short noLine, bool hasTitle = true);
short CalcMenuWidth(short titlesMaxWidth, short optionsMaxWidth);
std::pair<short, short> CalcPosCenter(short menuWidth, short menuHeight);

void Setting::SettingScreen(NavigationHost& NavHost) {
	auto langList = Language::DiscoverLanguageFile();

	int select = 0;
	int langSelect = [&langList]() {
		const auto& tmp = Config::GetSetting(L"LanguageFilePath");
		for (int i = 0; i < langList.size(); i++) 
			if (langList[i].path == tmp) return i;
		return 0;
		}
	();

	std::vector<std::wstring> titles;
	std::vector<std::wstring> options;
	bool musicSetting = Config::GetSetting(L"Music") == L"True";
	bool soundEffectSetting = Config::GetSetting(L"SoundEffect") == L"True";
	{
		const auto controlHint1 = std::format(
			L"A, W, S, D, Arrow Keys: {}",
			Language::GetString(L"NAVIGATION_KEYS_TITLE")
		);
		View::WriteToView(59 - controlHint1.size() / 2, 29 - 4, controlHint1);
		const auto controlHint2 = std::format(
			L"Enter: {} B: {}",
			Language::GetString(L"SELECT_KEY_TITLE"),
			Language::GetString(L"NAVIGATE_BACK_TITLE")
		);
		View::WriteToView(59 - controlHint2.size() / 2, 29 - 3, controlHint2);
	}
	while (true)
	{
		titles = {
			Language::GetMeta(L"[LANG_SELECT]"),
			Language::GetString(L"BG_MUSIC_TITLE"),
			Language::GetString(L"SOUND_EFFECT_TITLE"),
		};
		options = {
			L"< " + langList[langSelect].meta[L"[LANGUAGE]"] + L" >",
			musicSetting
			? Language::GetString(L"ON_TITLE")
			: Language::GetString(L"OFF_TITLE"),
			soundEffectSetting
			? Language::GetString(L"ON_TITLE")
			: Language::GetString(L"OFF_TITLE"),
		};
		short titlesWidth = CalcMaxWidth(titles);
		short menuWidth = CalcMenuWidth(
			titlesWidth,
			CalcMaxWidth(options)
		);
		short menuHeight = CalcMenuHeight(titles.size(), true);
		auto posCenter = CalcPosCenter(menuWidth, menuHeight);
		View::Rect DrawnRect = {
			posCenter.second,
			posCenter.first,
			posCenter.first + menuWidth - 1,
			posCenter.second + menuHeight - 1
		};
		View::DrawRect(DrawnRect);
		posCenter.first += View::BORDER_WIDTH + View::HPADDING;
		posCenter.second += View::BORDER_WIDTH + View::VPADDING;
		View::WriteToView(posCenter.first, posCenter.second, Language::GetString(L"SETTINGS_TITLE"));
		posCenter.second += 2;
		titlesWidth += 2;
		for (size_t i = 0; i < titles.size(); i++)
		{
			View::WriteToView(posCenter.first, posCenter.second + i, titles[i]);
			View::WriteToView(posCenter.first + titlesWidth - 2, posCenter.second + i, L":");
			View::WriteToView(posCenter.first + titlesWidth, posCenter.second + i, options[i], 0, i == select);
		}
		auto tmp = InputHandle::Get();
		Utils::PlayKeyPressSound();
		if (Utils::keyMeanDown(tmp)) {
			select = Utils::modCycle(select + 1, titles.size());
		}
		if (Utils::keyMeanUp(tmp)) {
			select = Utils::modCycle(select - 1, titles.size());
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
			switch (select)
			{
			case 0:
				Config::SetSetting(L"LanguageFilePath", langList[langSelect].path);
				Language::LoadLanguageFromFile(langList[langSelect].path);
				break;
			case 1:
				musicSetting = !musicSetting;
				break;
			case 2:
				soundEffectSetting = !soundEffectSetting;
			default:
				break;
			}
		}
		if (tmp == L" ") {
			Language::LoadLanguageFromFile(langList[langSelect].path);
			Config::SaveUserSetting();
			auto tmp = Language::GetString(L"SAVE_SUCCESSFULLY");
			View::WriteToView(59 - tmp.size() / 2, 2, tmp);
		}
		View::ClearRect(DrawnRect);
	}
}

inline short CalcMaxWidth(const auto& strList) {
	short res = 0;
	for (auto& i : strList)
	{
		res = res < i.size() ? i.size() : res;
	}
	return res;
}


inline short CalcMenuHeight(short noLine, bool hasTitle) {
	return noLine + 2 * (View::BORDER_WIDTH + View::VPADDING) + (hasTitle ? 2 : 0);
}


inline short CalcMenuWidth(short titlesMaxWidth, short optionsMaxWidth) {
	return titlesMaxWidth + optionsMaxWidth + 2 + 2 * (View::BORDER_WIDTH + View::HPADDING);
}

inline std::pair<short, short> CalcPosCenter(short menuWidth, short menuHeight) {
	return { 59 - menuWidth / 2, 14 - menuHeight / 2 };
}