#pragma once
#include <initializer_list>
#include <cwctype>
#include "InputHandle.h"
#include "Audio.h"

namespace Utils {
	static Audio::AudioPlayer OnKeyPressSound(Audio::Sound::OnKey);

#include "Utils.h"

	inline bool keyMatchPattern(const std::wstring& key, std::initializer_list<std::wstring> patterns) {
		bool res = 0;
		for (auto& pattern : patterns)
		{
			res |= (pattern == key);
		}
		return res;
	}

	inline bool keyMeanUp(const std::wstring& key) {
		return keyMatchPattern(key, { L"W", L"w", L"UP" });
	}

	inline bool keyMeanDown(const std::wstring& key) {
		return keyMatchPattern(key, { L"S", L"s", L"DOWN" });
	}

	inline bool keyMeanLeft(const std::wstring& key) {
		return keyMatchPattern(key, { L"A", L"a", L"LEFT" });
	}

	inline bool keyMeanRight(const std::wstring& key) {
		return keyMatchPattern(key, { L"D", L"d", L"RIGHT" });
	}

	inline int modCycle(int current, int max) {
		current += max;
		return current % max;
	}

	inline void ltrim(std::string& str) {
		str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
			return !std::isspace(ch);
			}));
	}

	inline void ltrim(std::wstring& str) {
		str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](wchar_t ch) {
			return !std::iswspace(ch);
			}));
	}

	inline void rtrim(std::string& str) {
		str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
			return !std::isspace(ch);
			}).base(), str.end());
	}

	inline void rtrim(std::wstring& str) {
		str.erase(std::find_if(str.rbegin(), str.rend(), [](wchar_t ch) {
			return !std::iswspace(ch);
			}).base(), str.end());
	}

	inline void trim(std::string& str) {
		ltrim(str);
		rtrim(str);
	}

	inline void trim(std::wstring& str) {
		ltrim(str);
		rtrim(str);
	}

	inline void PlayKeyPressSound() {
		OnKeyPressSound.Pause();
		OnKeyPressSound.Play();
	}

	inline std::pair<std::wstring, std::wstring> LineSplitter(const std::wstring& line, wchar_t delim = L'=') {
		size_t tmp = line.find_first_of(delim);
		return { line.substr(0, tmp), line.substr(tmp + 1) };
	}
};

