#pragma once
#include <unordered_map>
#include <any>
#include "FileHandle.h"
#include "Constants.h"
namespace Config {

	static std::unordered_map<std::string, std::string> Settings;

	// Return if the setting is previously exist(first time or not)
	bool LoadUserSetting();

	std::string& GetSetting(const std::string& name);

	void SetSetting(const std::string& name, const std::string& data);

	bool SaveUserSetting();
};