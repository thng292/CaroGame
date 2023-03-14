
#include "MainMenu.h"
void MainMenu::Logo_Win(NavigationHost& NavHost,int x,int y) {

}




void MainMenu::ScreenMainMenu(NavigationHost& NavHost) {
	static short selectedOption = 0;										// User option
	static const short maxOption = 7;										// Number of option
	int x = 33;                                                             // Vi tri bat dau ve 
	int y = 2;                                                              // Vi tri bat dau ve 
	MainMenu::Logo_Win( NavHost,1,1);
	MainMenu::Logo(x, y);
	//MainMenu::AmongUs(5, 12, View::Color::RED, View::Color::LIGHT_CYAN);
	vector<View::Option> options = {
			{Language::GetString(L"NEW_GAME_TITLE"),Language::GetString(L"NEW_GAME_SHORTCUT")[0]},
			{Language::GetString(L"LOAD_TITLE"),Language::GetString(L"LOAD_SHORTCUT")[0]},
			{Language::GetString(L"REPLAY_TITLE"),Language::GetString(L"REPLAY_SHORTCUT")[0]},
			{Language::GetString(L"SETTINGS_TITLE"),Language::GetString(L"SETTINGS_SHORTCUT")[0]},
			{Language::GetString(L"TUTORIAL_TITLE"),Language::GetString(L"TUTORIAL_SHORTCUT")[0]},
			{Language::GetString(L"ABOUT_TITLE"),Language::GetString(L"ABOUT_SHORTCUT")[0]},
			{Language::GetString(L"EXIT_TITLE"),Language::GetString(L"EXIT_SHORTCUT")[0]},
	};
	auto& soundEffect = Config::GetSetting(L"SoundEffect");
	while (1) {																			// Main while loop
		View::DrawMenu(54,12,L"", options, selectedOption);
		auto tmp = InputHandle::Get();										// Get input from user
		if (soundEffect == L"True") {
			Utils::PlayKeyPressSound();
		}
		// Input Handle
		// Normal Navigation
		if (Utils::keyMeanUp(tmp)) {
			selectedOption = Utils::modCycle(selectedOption - 1, options.size());
		}
		if (Utils::keyMeanDown(tmp)) {
			selectedOption = Utils::modCycle(selectedOption + 1, options.size());
		}
		// Shortcut
		if (tmp == Language::GetString(L"NEW_GAME_SHORTCUT")) {
			return NavHost.Navigate("New Game");							// Nho return
		}
		if (tmp == Language::GetString(L"LOAD_SHORTCUT")) {
			return NavHost.Navigate("Load Game");							// Nho return
		}
		if (tmp == Language::GetString(L"REPLAY_SHORTCUT")) {
			return NavHost.Navigate("Replay game");							// Nho return
		}
		if (tmp == Language::GetString(L"SETTINGS_SHORTCUT")) {
			return NavHost.Navigate("Setting");							// Nho return
		}
		if (tmp == Language::GetString(L"TUTORIAL_SHORTCUT")) {
			return NavHost.Navigate("Tutorial");							// Nho return
		}
		if (tmp == Language::GetString(L"ABOUT_SHORTCUT")) {
			return NavHost.Navigate("About");							// Nho return
		}
		if (tmp == Language::GetString(L"EXIT_SHORTCUT")) {
			return NavHost.NavigateStack("ExitView");						// Nho return
		}
		// Handle Select
		if (tmp == L"\r") {
			switch (selectedOption)
			{
			case 0:
				return NavHost.Navigate("New Game");						// Nho return
			case 1:
				return NavHost.Navigate("Load");						// Nho return
			case 2:
				return NavHost.Navigate("Replay");
			case 3:
				return NavHost.Navigate("Setting");
			case 4:
				return NavHost.Navigate("Tutorial");
			case 5:
				return NavHost.Navigate("About");
			case 6:
				return NavHost.NavigateStack("ExitView");					// Nho return
			}
		}
	}
}

void MainMenu::AmongUs(int x, int y, View::Color mat, View::Color mau) {
	View::WriteToView(x + 1, y + 2, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 1, y + 3, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 5, y + 2, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 5, y + 3, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 8, y + 2, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 8, y + 3, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 10, y + 2, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 10, y + 3, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 8, y + 4, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 8, y + 5, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 2, y + 4, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 2, y + 5, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 7, y + 1, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 5, y + 5, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 6, y + 2, L'\u2580', 0,
		mau,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		mau
	);
	View::WriteToView(x + 6, y + 3, L'\u2580', 0,
		mau,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		mau
	);
	View::WriteToView(x + 3, y + 4, L'\u2580', 0,
		mau,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		mau
	);
	View::WriteToView(x + 6, y + 4, L'\u2580', 0,
		mau,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		mau
	);
	View::WriteToView(x + 7, y + 2, L'\u2580', 0,
		mau,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		mau
	);
	View::WriteToView(x + 7, y + 3, L'\u2580', 0,
		mau,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		mau
	);
	View::WriteToView(x + 7, y + 4, L'\u2580', 0,
		mau,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		mau
	);
	View::WriteToView(x + 9, y + 3, L'\u2580', 0,
		mau,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		mau
	);
	View::WriteToView(x + 2, y + 1, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 8, y + 1, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 2, y + 2, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 3, y + 2, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 9, y + 4, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 10, y + 4, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	for (int i = 0; i < 4; i++) {
		View::WriteToView(x + 3 + i, y + 1, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			mau
		);
	}
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 2 + i, y + 3, L'\u2580', 0,
			mat,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 4 + i, y + 4, L'\u2580', 0,
			mau,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 3 + i, y + 5, L'\u2580', 0,
			mau,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 6 + i, y + 5, L'\u2580', 0,
			mau,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 9, y + 2, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		mau
	);
	View::WriteToView(x + 4, y + 2, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		mat
	);
}
void MainMenu::Logo(int x, int y) {                                         // function paint logo
	for (int i = 1; i <= 6; i++) {
		View::WriteToView(x + 3 + i, y + 1, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 3; i++) {
		View::WriteToView(x + 1 + i, y + 2, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 3; i++) {
		View::WriteToView(x + 1 + i, y + 3, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 3; i++) {
		View::WriteToView(x + 1 + i, y + 4, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 3; i++) {
		View::WriteToView(x + 1 + i, y + 5, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 6; i++) {
		View::WriteToView(x + 3 + i, y + 6, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 3; i++) {
		View::WriteToView(x + 8 + i, y + 2, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 3; i++) {
		View::WriteToView(x + 8 + i, y + 5, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 4; i++) {
		View::WriteToView(x + 18 + i, y + 1, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 2; i++) {
		View::WriteToView(x + 16 + i, y + 2, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 2; i++) {
		View::WriteToView(x + 22 + i, y + 2, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int k = 0; k <= 3; k++) {
		for (int i = 1; i <= 3; i++) {
			View::WriteToView(x + 15 + i, y + 3 + k, L'\u2588', 0,
				View::Color::BLACK,
				View::DEFAULT_HIGHLIGHT_COLOR,
				View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
				View::Color::BLACK
			);
		}
		for (int i = 1; i <= 3; i++) {
			View::WriteToView(x + 22 + i, y + 3 + k, L'\u2588', 0,
				View::Color::BLACK,
				View::DEFAULT_HIGHLIGHT_COLOR,
				View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
				View::Color::BLACK
			);
		}
	}
	for (int i = 1; i <= 4; i++) {
		View::WriteToView(x + 18 + i, y + 4, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int k = 0; k <= 5; k++) {
		for (int i = 1; i <= 3; i++) {
			View::WriteToView(x + 29 + i, y + 1 + k, L'\u2588', 0,
				View::Color::BLACK,
				View::DEFAULT_HIGHLIGHT_COLOR,
				View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
				View::Color::BLACK
			);
		}
	}
	for (int i = 1; i <= 5; i++) {
		View::WriteToView(x + 32 + i, y + 1, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 5; i++) {
		View::WriteToView(x + 32 + i, y + 4, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 3; i++) {
		View::WriteToView(x + 36 + i, y + 2, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 3; i++) {
		View::WriteToView(x + 36 + i, y + 3, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 3; i++) {
		View::WriteToView(x + 36 + i, y + 6, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 3; i++) {
		View::WriteToView(x + 35 + i, y + 5, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 6; i++) {
		View::WriteToView(x + 45 + i, y + 1, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 1; i <= 6; i++) {
		View::WriteToView(x + 45 + i, y + 6, L'\u2588', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int k = 0; k <= 3; k++) {
		for (int i = 1; i <= 3; i++) {
			View::WriteToView(x + 43 + i, y + 2 + k, L'\u2588', 0,
				View::Color::BLACK,
				View::DEFAULT_HIGHLIGHT_COLOR,
				View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
				View::Color::BLACK
			);
		}
	}
	for (int k = 0; k <= 3; k++) {
		for (int i = 1; i <= 3; i++) {
			View::WriteToView(x + 50 + i, y + 2 + k, L'\u2588', 0,
				View::Color::BLACK,
				View::DEFAULT_HIGHLIGHT_COLOR,
				View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
				View::Color::BLACK
			);
		}
	}
	for (int k = 0; k <= 3; k++) {
		View::WriteToView(x + 1, y + 2 + k, L'\u2588', 0,
			View::Color::LIGHT_CYAN,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	for (int k = 0; k <= 3; k++) {
		View::WriteToView(x + 15, y + 3 + k, L'\u2588', 0,
			View::Color::LIGHT_CYAN,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	for (int k = 0; k <= 3; k++) {
		if (k == 1) {
			continue;
		}
		View::WriteToView(x + 22, y + 3 + k, L'\u2588', 0,
			View::Color::LIGHT_CYAN,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	for (int k = 0; k <= 5; k++) {
		View::WriteToView(x + 29, y + 1 + k, L'\u2588', 0,
			View::Color::LIGHT_CYAN,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	for (int k = 0; k <= 3; k++) {
		View::WriteToView(x + 43, y + 2 + k, L'\u2588', 0,
			View::Color::LIGHT_CYAN,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	for (int k = 0; k <= 1; k++) {
		View::WriteToView(x + 50, y + 3 + k, L'\u2588', 0,
			View::Color::LIGHT_CYAN,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	View::WriteToView(x + 36, y + 6, L'\u2588', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	for (int k = 0; k <= 1; k++) {
		View::WriteToView(x + 5, y + 3 + k, L'\u2588', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	View::WriteToView(x + 12, y + 2, L'\u2588', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 12, y + 5, L'\u2588', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	for (int k = 0; k <= 3; k++) {
		if (k == 1) {
			continue;
		}
		View::WriteToView(x + 19, y + 3 + k, L'\u2588', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	for (int k = 0; k <= 3; k++) {
		View::WriteToView(x + 26, y + 3 + k, L'\u2588', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	for (int k = 0; k <= 4; k++) {
		if (k == 2) {
			continue;
		}
		View::WriteToView(x + 33, y + 2 + k, L'\u2588', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	for (int k = 0; k <= 4; k++) {
		if (k == 2 || k == 3) {
			continue;
		}
		View::WriteToView(x + 40, y + 2 + k, L'\u2588', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	for (int k = 0; k <= 1; k++) {
		View::WriteToView(x + 47, y + 3 + k, L'\u2588', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	for (int k = 0; k <= 3; k++) {
		View::WriteToView(x + 54, y + 2 + k, L'\u2588', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	View::WriteToView(x + 2, y + 1, L'\u2584', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 15, y + 2, L'\u2584', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 17, y + 1, L'\u2584', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 35, y + 3, L'\u2584', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 44, y + 1, L'\u2584', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 49, y + 5, L'\u2584', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 3, y + 1, L'\u2580', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 16, y + 2, L'\u2580', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 18, y + 1, L'\u2580', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 36, y + 3, L'\u2580', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 45, y + 1, L'\u2580', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 50, y + 5, L'\u2580', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 8, y + 5, L'\u2580', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 2, y + 6, L'\u2580', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 7, y + 2, L'\u2580', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 21, y + 2, L'\u2580', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 35, y + 2, L'\u2580', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 34, y + 5, L'\u2580', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 44, y + 6, L'\u2580', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 7, y + 5, L'\u2584', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 49, y + 2, L'\u2580', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 3, y + 6, L'\u2584', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 8, y + 2, L'\u2584', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 22, y + 2, L'\u2584', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 35, y + 5, L'\u2584', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 36, y + 2, L'\u2584', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 45, y + 6, L'\u2584', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 50, y + 2, L'\u2584', 0,
		View::Color::LIGHT_CYAN,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 5, y + 2, L'\u2584', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 10, y + 6, L'\u2584', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 19, y + 2, L'\u2584', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 38, y + 4, L'\u2584', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 47, y + 2, L'\u2584', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 52, y + 6, L'\u2584', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 39, y + 5, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 47, y + 5, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 52, y + 1, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 5, y + 5, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 10, y + 1, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 23, y + 1, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 25, y + 2, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 38, y + 1, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 6, y + 5, L'\u2584', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 11, y + 1, L'\u2584', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 24, y + 1, L'\u2584', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 26, y + 2, L'\u2584', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 39, y + 1, L'\u2584', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 40, y + 5, L'\u2584', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 48, y + 5, L'\u2584', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 53, y + 1, L'\u2584', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 6, y + 2, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 11, y + 6, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 20, y + 2, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 39, y + 4, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 48, y + 2, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 53, y + 6, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
}