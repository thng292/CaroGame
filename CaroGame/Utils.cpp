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

void Utils::PlayKeyPressSound() {
	OnKeyPressSound.Pause();
	OnKeyPressSound.Play();
}