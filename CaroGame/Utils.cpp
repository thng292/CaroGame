#include "Utils.h"

bool Utils::keyMatchPattern(const std::wstring& key, std::initializer_list<std::wstring> patterns) {
	bool res = 0;
	for (auto& pattern : patterns)
	{
		res |= (pattern == key);
	}
	return res;
}

bool Utils::keyMeanUp(const std::wstring& key) {
	return keyMatchPattern(key, {L"W", L"w", L"UP"});
}

bool Utils::keyMeanDown(const std::wstring& key) {
	return keyMatchPattern(key, { L"S", L"s", L"DOWN" });
}

bool Utils::keyMeanLeft(const std::wstring& key) {
	return keyMatchPattern(key, { L"A", L"a", L"LEFT" });
}

bool Utils::keyMeanRight(const std::wstring& key) {
	return keyMatchPattern(key, { L"D", L"d", L"RIGHT" });
}

int Utils::modCycle(int current, int max) {
	current += max;
	return current % max;
}

void Utils::ltrim(std::string& str) {
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
		return !std::isspace(ch);
		}));
}

void Utils::ltrim(std::wstring& str) {
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](wchar_t ch) {
		return !std::iswspace(ch);
		}));
}

void Utils::rtrim(std::string& str) {
	str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
		return !std::isspace(ch);
		}).base(), str.end());
}

void Utils::rtrim(std::wstring& str) {
	str.erase(std::find_if(str.rbegin(), str.rend(), [](wchar_t ch) {
		return !std::iswspace(ch);
		}).base(), str.end());
}

void Utils::trim(std::string& str) {
	ltrim(str);
	rtrim(str);
}

void Utils::trim(std::wstring& str) {
	ltrim(str);
	rtrim(str);
}

void Utils::PlayKeyPressSound() {
	OnKeyPressSound.Pause();
	OnKeyPressSound.Play();
}