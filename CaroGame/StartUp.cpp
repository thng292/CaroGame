#include "StartUp.h"

void StartUp::StartUpScreen(NavigationHost& NavHost) {
	View::Setup();
	if (!Config::LoadUserSetting()) {
		return NavHost.Navigate("FirstTimeLanguageScreen");
	}
	else {
		Language::LoadLanguageFromFile(Config::GetSetting(L"LanguageFilePath"));
		return NavHost.Navigate("MainMenu");
	}
}

void StartUp::FirstTimeLanguageScreen(NavigationHost& NavHost) {
	auto languages = Language::DiscoverLanguageFile();
	static int userSelect = 0;
	std::wstring tmp;
	while (1) {
		View::ClearScreen();
		View::DrawMenuCenter(L"", {
			{std::format(L"{}: < {} >", languages[userSelect].meta[L"[LANG_SELECT]"],languages[userSelect].meta[L"[LANGUAGE]"]), 0},
			}, -1);
		tmp = InputHandle::Get();
		Utils::PlayKeyPressSound();
		if (Utils::keyMeanLeft(tmp)) {
			userSelect = Utils::modCycle(userSelect - 1, languages.size());
		}
		if (Utils::keyMeanRight(tmp)) {
			userSelect = Utils::modCycle(userSelect + 1, languages.size());
		}
		if (tmp == L"\r") {
			Config::SetSetting(L"LanguageFilePath", languages[userSelect].path.generic_wstring());
			Language::LoadLanguageFromFile(languages[userSelect].path);
			return NavHost.Navigate("FirstTimeMusicScreen");
		}
	}
}

void StartUp::FirstTimeMusicScreen(NavigationHost& NavHost) {
	auto title = Language::GetString(L"ENABLE_MUSIC_Q");
	std::vector<View::Option> options = {
		{Language::GetString(L"YES"),	Language::GetString(L"YES_SHORTCUT")[0]},
		{Language::GetString(L"NO"),	Language::GetString(L"NO_SHORTCUT")[0]}
	};
	static int select = 0;
	int num = 2;
	std::wstring tmp;
	while (1)
	{
		View::DrawMenuCenter(title, options, select);
		tmp = InputHandle::Get();
		Utils::PlayKeyPressSound();
		if (Utils::keyMeanDown(tmp)) {
			select = Utils::modCycle(select - 1, num);
		}
		if (Utils::keyMeanUp(tmp)) {
			select = Utils::modCycle(select + 1, num);
		}
		if (tmp == L"\r") {
			Config::SetSetting(L"Music", (select == 1 ? L"On" : L"Off"));
			return;
		}
	}
}
