#pragma once
#include <initializer_list>
#include <cwctype>
#include "InputHandle.h"
#include "Audio.h"

namespace Utils {
	static Audio::AudioPlayer OnKeyPressSound(Audio::Sound::OnKey);

	void PlayKeyPressSound();

	bool keyMatchPattern(const std::wstring& key, std::initializer_list<std::wstring> patterns);

	bool keyMeanUp(const std::wstring& key);

	bool keyMeanDown(const std::wstring& key);
	
	bool keyMeanLeft(const std::wstring& key);
	
	bool keyMeanRight(const std::wstring& key);

	int modCycle(int current, int max);

	void ltrim(std::string& str);
	
	void ltrim(std::wstring& str);

	void rtrim(std::string& str);

	void rtrim(std::wstring& str);

	void trim(std::string& str);

	void trim(std::wstring& str);
};

