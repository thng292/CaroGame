#include "Config.h"

inline std::pair<std::wstring, std::wstring> LineSplitter(const std::wstring& line, wchar_t delim = L'=') {
	size_t tmp = line.find_first_of(delim);
	return { line.substr(0, tmp), line.substr(tmp + 1) };
}

bool Config::LoadUserSetting() {
	auto fin = FileHandle::OpenInFile(Constants::STR_USERCONFIG_PATH);
	if (fin.fail()) {
		return 0;
	}
	Settings.clear();
	std::wstring buffer;
	while (!fin.eof())
	{
		fin >> buffer;
		auto tmp = LineSplitter(buffer);
		Settings[tmp.first] = tmp.second;
	}
	fin.close();
	return 1;
}

std::wstring& Config::GetSetting(const std::wstring& name) {
	return Settings[name];
}

void Config::SetSetting(const std::wstring& name, const std::wstring& data) {
	Settings[name] = data;
}

bool Config::SaveUserSetting() {
	auto fout = FileHandle::OpenOutFile(Constants::USERCONFIG_PATH);
	if (fout.fail()) {
		return 0;
	}
	for (const auto& [key, val] : Settings) {
		fout << key << '=' << val << '\n';
	}
	fout.close();
	return 1;
}
