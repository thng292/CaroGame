#include "Config.h"

inline std::pair<std::wstring, std::wstring> LineSplitter(const std::wstring& line, wchar_t delim = L'=') {
	size_t tmp = line.find_first_of(delim);
	return { line.substr(0, tmp), line.substr(tmp + 1) };
}

void Config::LoadUserSetting() {
	auto fin = FileHandle::OpenInFile(Constants::STR_USERCONFIG_PATH);
	isFirstTime = fin.fail();
	if (!isFirstTime) { //First time
		std::wstring buffer;
		while (!fin.eof())
		{
			fin >> buffer;
			auto tmp = LineSplitter(buffer);
			Settings[tmp.first] = tmp.second;
		}
	}
	fin.close();
}

std::wstring& Config::GetSetting(const std::wstring& name) {
	return Settings[name];
}

bool Config::SaveUserSetting() {
	auto fout = FileHandle::OpenOutFile(Constants::USERCONFIG_PATH);
	if (fout.fail()) {
		return 0;
	}
	for (const auto& [key, val] : Settings) {
		fout << key << '=' << val <<'\n';
	}
	fout.close();
	return 1;
}
