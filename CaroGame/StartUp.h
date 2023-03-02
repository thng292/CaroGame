#pragma once
#include "Navigate.h"
#include "Config.h"
#include "View.h"
#include "Language.h"
#include "Format"
#include "InputHandle.h"
#include "Utils.h"


namespace StartUp {

	// StartUpScreen
	void StartUpScreen(NavigationHost& NavHost);

	// FirstTimeLanguageScreen
	void FirstTimeLanguageScreen(NavigationHost& NavHost);

	// FirstTimeMusicScreen
	void FirstTimeMusicScreen(NavigationHost& NavHost);
}