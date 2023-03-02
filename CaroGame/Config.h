#pragma once
#include <unordered_map>
#include <any>
#include "FileHandle.h"
#include "Constants.h"
namespace Config {

	static std::unordered_map<std::wstring, std::wstring> Settings;

	// Return if the setting is previously exist(first time or not)
	bool LoadUserSetting();

	inline std::wstring& GetSetting(const std::wstring& name);

	inline void SetSetting(const std::wstring& name, const std::wstring& data);

	bool SaveUserSetting();
};