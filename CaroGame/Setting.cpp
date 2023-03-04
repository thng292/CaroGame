#include "Setting.h"

short CalcMaxWidth(const auto& strList);
short CalcMenuHeight(short noLine, bool hasTitle = true);

void Setting::SettingScreen(NavigationHost& NavHost) {
	auto langList = Language::DiscoverLanguageFile();
	int langSelect = ([&]() -> int {
		for (size_t i = 0; i < langList.size(); i++)
		{
			if (langList[i].path == Config::GetSetting(L"LanguageFilePath")) {
				return i;
			}
		}
		return 0;
		})();

		int select = 0;
		std::vector<std::wstring> titles = {
			Language::GetString(L"BG_MUSIC_TITLE"),
			Language::GetString(L"SOUND_EFFECT_TITLE"),
			Language::GetMeta(L"[LANG_SELECT]"),
		};
		std::vector<std::wstring> options = {
			Config::GetSetting(L"Music") == L"True"
			? Language::GetString(L"ON_TITLE")
			: Language::GetString(L"OFF_TITLE"),
			Config::GetSetting(L"SoundEffect") == L"True"
			? Language::GetString(L"ON_TITLE")
			: Language::GetString(L"OFF_TITLE"),
			Language::GetMeta(L"[LANGUAGE]")
		};

		while (true)
		{
			short titlesMaxWidth = CalcMaxWidth(titles);
			short optionsMaxWidth = CalcMaxWidth(options);
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
	return titlesMaxWidth + optionsMaxWidth + 1 + 2 * (View::BORDER_WIDTH + View::HPADDING);
}

inline std::pair<short, short> CalcPosCenter(short menuWidth, short menuHeight) {
	return {};
}