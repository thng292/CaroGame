#include "InputHandle.h"

std::wstring InputHandle::Filter(wchar_t inp)
{
    if (inp == 0 || inp == 0xE0) {
        wchar_t tmp = _getwch();
        switch (tmp) {
            case 71:
                return HOME;
            case 72:
                return UP;
            case 75:
                return LEFT;
            case 77:
                return RIGHT;
            case 79:
                return END;
            case 80:
                return DOWN;
            case 83:
                return DEL;
        }
    }
    if (inp == L'\x1b') {
        return ESC;
    }

    if ((inp > 127 || inp < 8)) {
        return L"";
    }
    return std::wstring(1, inp);
}

std::wstring InputHandle::Get()
{
    wchar_t inp = _getwch();
    return Filter(inp);
}
