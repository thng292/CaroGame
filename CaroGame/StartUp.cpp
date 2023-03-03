#include "StartUp.h"
#include "Timer.h"

void StartUp::StartUpScreen(NavigationHost& NavHost) {
	View::Setup();
	int time = 0;
	Timer t([&time]() {
		View::WriteToView(0, 0, std::format(L"{}", time));
		time++;
		});
	t.Start();
	InputHandle::Get();
	t.Stop();
	if (!Config::LoadUserSetting() || !Config::GetSetting(L"LanguageFilePath").length()) {
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
			{std::format(
				L"{}: < {} >",
				languages[userSelect].meta[L"[LANG_SELECT]"],
				languages[userSelect].meta[L"[LANGUAGE]"]),
			0},
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
	auto next = [&]() {
		Config::SetSetting(L"Music", (select == 0 ? L"True" : L"False"));
		return NavHost.Navigate("FirstTimeSoundEffectScreen");
	};
	while (1)
	{
		View::DrawMenuCenter(title, options, select);
		tmp = InputHandle::Get();
		Utils::PlayKeyPressSound();
		if (Utils::keyMeanDown(tmp)) {
			select = Utils::modCycle(select - 1, num);
			continue;
		}
		if (Utils::keyMeanUp(tmp)) {
			select = Utils::modCycle(select + 1, num);
			continue;
		}
		if (tmp == L"\r") {
			return next();
		}
		for (int i = 0; i < options.size(); i++) {
			if (tmp[0] == options[i].underline) {
				select = i;
				return next();
			}
		}
	}
}

void StartUp::FirstTimeSoundEffectScreen(NavigationHost& NavHost) {
	auto title = Language::GetString(L"ENABLE_SOUND_EFFECT_Q");
	std::vector<View::Option> options = {
		{Language::GetString(L"YES"),	Language::GetString(L"YES_SHORTCUT")[0]},
		{Language::GetString(L"NO"),	Language::GetString(L"NO_SHORTCUT")[0]}
	};
	static int select = 0;
	int num = 2;
	std::wstring tmp;
	auto next = [&]() {
		Config::SetSetting(L"SoundEffect", (select == 0 ? L"True" : L"False"));
		Config::SaveUserSetting();
		return NavHost.Navigate("MainMenu");
	};
	while (1)
	{
		View::DrawMenuCenter(title, options, select);
		tmp = InputHandle::Get();
		Utils::PlayKeyPressSound();
		if (Utils::keyMeanDown(tmp)) {
			select = Utils::modCycle(select - 1, num);
			continue;
		}
		if (Utils::keyMeanUp(tmp)) {
			select = Utils::modCycle(select + 1, num);
			continue;
		}
		if (tmp == L"\r") {
			return next();
		}
		for (int i = 0; i < options.size(); i++)
		{
			if (tmp.size()==1 && tmp[0] == options[i].underline) {
				select = i;
				return next();
			}
		}
	}
}