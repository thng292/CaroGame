#pragma once
#include <format>
#include <numeric>

#include "BackgroundAudioService.h"
#include "Config.h"
#include "Language.h"
#include "Navigate.h"
#include "View.h"

namespace Setting {
    void SettingScreen(NavigationHost& NavHost);

    void ApplySuccess(NavigationHost& NavHost);

    void ApplyFailed(NavigationHost& NavHost);
};
