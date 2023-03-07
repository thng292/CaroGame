#pragma once
#include <unordered_map>
#include <any>
#include "FileHandle.h"
#include "Constants.h"
namespace Config {

	const std::wstring SoundEffect = L"SoundEffect";
	const std::wstring BGMusic = L"Music";
	const std::wstring UndoOption = L"UndoOption";

	const std::wstring Value_True = L"True";
	const std::wstring Value_False = L"False";

	static std::unordered_map<std::wstring, std::wstring> Settings;

	// Return if the setting is previously exist(first time or not)
	bool LoadUserSetting();

	std::wstring& GetSetting(const std::wstring& name);

	void SetSetting(const std::wstring& name, const std::wstring& data);

	bool SaveUserSetting();
};