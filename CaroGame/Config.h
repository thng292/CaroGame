#pragma once
#include <unordered_map>
#include <any>
#include "FileHandle.h"
#include "Constants.h"
namespace Config {

	std::unordered_map<std::wstring, std::wstring> Settings;
	bool isFirstTime = 0;

	// Return if the setting is previously exist(first time or not)
	void LoadUserSetting();

	inline std::wstring& GetSetting(const std::wstring& name);

	bool SaveUserSetting();
};