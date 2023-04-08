#include "Utils.h"

std::wstring Utils::filesystem_time_to_wstr_local(
    std::filesystem::file_time_type fileTime
)
{
    auto tmp = filesystem_time_to_time_t_local(fileTime);
    wchar_t* buff = new wchar_t[80];
    wcsftime(buff, 80, L"%H:%M:%OS %d/%m/%y", &tmp);
    auto res = std::wstring(buff);
    delete[] buff;
    return res;
}

std::wstring Utils::CatStringSpaceBetween(
    int width, const std::wstring& str1, const std::wstring& str2
)
{
    std::wstringstream wss;
    if (str1.length() + str2.length() + 3 <= width) {
        wss << str1;
        wss << std::setw(width - str1.length()) << std::setfill(L'.') << str2;
    } else {
        wss << str1.substr(0, width - 3 - str2.length()) << L"..." << str2;
    }
    return wss.str();
}

std::wstring Utils::SecondToMMSS(short seconds)
{
    short min = seconds / 60;
    short sec = seconds % 60;
    std::wstring minStr =
        (min < 10) ? std::format(L"0{}", min) : std::format(L"{}", min);
    std::wstring secStr =
        (sec < 10) ? std::format(L"0{}", sec) : std::format(L"{}", sec);
    return std::format(L"{}:{}", minStr, secStr);
}
