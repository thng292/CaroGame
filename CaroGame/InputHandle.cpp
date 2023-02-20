#include "InputHandle.h"

std::wstring InputHandle::Get() {
	wchar_t inp = _getwch();
	if (inp == 0 || inp == 0xE0) {
		wchar_t tmp = _getwch();
		switch (tmp)
		{
		case 72:
			return L"UP";
		case 75:
			return L"LEFT";
		case 77:
			return L"RIGHT";
		case 80:
			return L"DOWN";
		}
	}
	if (inp == L'\x1b') {
		return L"ESC";
	}
	if (inp > 127 || inp < 8) {
		return L"";
	}
	return std::wstring(1, inp);
}
