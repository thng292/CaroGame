#pragma once
#include <time.h>

#include <chrono>
#include <cwctype>
#include <initializer_list>

#include "Audio.h"
#include "InputHandle.h"
#include "Utils.h"

namespace Utils {
    static Audio::AudioPlayer OnKeyPressSound(Audio::Sound::OnKey);

    template <typename T, typename U = T>
    inline bool keyMatchPattern(
        const T& key, const std::initializer_list<U>& patterns
    ) {
        bool res = 0;
        for (const auto& pattern : patterns) {
            res |= (pattern == key);
        }
        return res;
    }

    inline bool keyMeanUp(const std::wstring& key) {
        return keyMatchPattern(key, {L"W", L"w", L"UP"});
    }

    inline bool keyMeanDown(const std::wstring& key) {
        return keyMatchPattern(key, {L"S", L"s", L"DOWN"});
    }

    inline bool keyMeanLeft(const std::wstring& key) {
        return keyMatchPattern(key, {L"A", L"a", L"LEFT"});
    }

    inline bool keyMeanRight(const std::wstring& key) {
        return keyMatchPattern(key, {L"D", L"d", L"RIGHT"});
    }

    inline auto modCycle(auto current, auto max) {
        current += max;
        return current % max;
    }

    inline void ltrim(auto& str) {
        str.erase(
            str.begin(), std::find_if(
                             str.begin(), str.end(),
                             [](wchar_t ch) { return !std::iswspace(ch); }
                         )
        );
    }

    inline void rtrim(auto& str) {
        str.erase(
            std::find_if(
                str.rbegin(), str.rend(),
                [](wchar_t ch) { return !std::iswspace(ch); }
            ).base(),
            str.end()
        );
    }

    inline void trim(auto& str) {
        ltrim(str);
        rtrim(str);
    }

    inline void PlayKeyPressSound() {
        OnKeyPressSound.Pause();
        OnKeyPressSound.Play();
    }

    template <typename T, typename _Elem>
    inline std::pair<T, T> LineSplitter(const T& line, _Elem delim = L'=') {
        size_t tmp = line.find_first_of(delim);
        return {line.substr(0, tmp), line.substr(tmp + 1)};
    }

    inline tm filesystem_time_to_time_t_local(
        std::filesystem::file_time_type fileTime
    ) {
        auto tmp = std::chrono::system_clock ::to_time_t(
            std::chrono::clock_cast<std::chrono::system_clock>(fileTime)
        );
        tm res;
        localtime_s(&res, &tmp);
        return res;
    }

    std::wstring filesystem_time_to_wstr_local(
        std::filesystem::file_time_type fileTime
    );

    std::wstring CatStringSpaceBetween(
        int width, const std::wstring& str1, const std::wstring& str2
    );
};  // namespace Utils
