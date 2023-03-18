#pragma once
#include <string>
#include <wchar.h>
#include <cwctype>

namespace InputHandle {

	const std::wstring DEL = L"DEL";
	const std::wstring UP = L"UP";
	const std::wstring DOWN = L"DOWN";
	const std::wstring LEFT = L"LEFT";
	const std::wstring RIGHT = L"RIGHT";
	const std::wstring ESC = L"ESC";
	const std::wstring HOME = L"HOME";
	const std::wstring END = L"END";

	std::wstring Filter(wchar_t inp);

	std::wstring Get();

};