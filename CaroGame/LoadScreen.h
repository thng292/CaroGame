#pragma once
#include <algorithm>
#include <ctime>
#include <format>
#include <locale>

#include "Config.h"
#include "Constants.h"
#include "InputHandle.h"
#include "Language.h"
#include "Navigate.h"
#include "SaveLoad.h"
#include "Utils.h"
#include "View.h"

namespace LoadScreen {
    void Load(NavigationHost& NavHost);
}