#pragma once
#include "Config.h"
#include "Format"
#include "InputHandle.h"
#include "Language.h"
#include "Navigate.h"
#include "Utils.h"
#include "View.h"

namespace StartUp {

    // StartUpScreen
    void StartUpScreen(NavigationHost& NavHost);

    // FirstTimeLanguageScreen
    void FirstTimeLanguageScreen(NavigationHost& NavHost);

    // FirstTimeMusicScreen
    void FirstTimeMusicScreen(NavigationHost& NavHost);

    // FirstTimeSoundEffectScreen
    void FirstTimeSoundEffectScreen(NavigationHost& NavHost);
}  // namespace StartUp