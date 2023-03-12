#pragma once
#include <algorithm>
#include <format>
#include <ctime>
#include <locale>
#include "View.h"
#include "SaveLoad.h"
#include "InputHandle.h"
#include "Utils.h"
#include "Navigate.h"
#include "Config.h"
#include "Language.h"
#include "Constants.h"

namespace LoadScreen {
	void Load(NavigationHost& NavHost);
}