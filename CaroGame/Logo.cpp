#include "Logo.h"


void Logo::AmongUs(int x, int y, View::Color mat, View::Color mau) {
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
void Logo::Logo_Caro(int x, int y) {                                         // function paint logo
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

void Logo::Win(NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2, View::Color a3, View::Color a4, View::Color a5) {
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 1 + i, y + 1, L'\u2584', 0,
			a1,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 11 + i, y + 1, L'\u2584', 0,
			a1,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	for (int i = 0; i < 6; i++) {
		View::WriteToView(x + 15 + i, y + 1, L'\u2584', 0,
			a1,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 23 + i, y + 1, L'\u2584', 0,
			a1,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 29 + i, y + 1, L'\u2584', 0,
			a1,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 1 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 11 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 17 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 23 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 25 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 29 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 1 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 11 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 6 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	View::WriteToView(x + 5, y + 3, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a3
	);
	View::WriteToView(x + 8, y + 3, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a3
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 17 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 23 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 26 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 29 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	View::WriteToView(x + 2, y + 4, L'\u2580', 0,
		a4,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 11, y + 4, L'\u2580', 0,
		a4,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 4, y + 4, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a4
	);
	View::WriteToView(x + 9, y + 4, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a4
	);
	View::WriteToView(x + 3, y + 4, L'\u2584', 0,
		a4,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a4
	);
	View::WriteToView(x + 10, y + 4, L'\u2584', 0,
		a4,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a4
	);
	View::WriteToView(x + 5, y + 4, L'\u2584', 0,
		a4,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a4
	);
	View::WriteToView(x + 8, y + 4, L'\u2584', 0,
		a4,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a4
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 6 + i, y + 4, L'\u2580', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 17 + i, y + 4, L'\u2584', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 23 + i, y + 4, L'\u2584', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 27 + i, y + 4, L'\u2584', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 29 + i, y + 4, L'\u2584', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 4 + i, y + 5, L'\u2584', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 8 + i, y + 5, L'\u2584', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
	for (int i = 0; i < 6; i++) {
		View::WriteToView(x + 15 + i, y + 5, L'\u2584', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 23 + i, y + 5, L'\u2584', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 29 + i, y + 5, L'\u2584', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
}
void Logo::Lose(NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2, View::Color a3, View::Color a4, View::Color a5) {
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 1 + i, y + 1, L'\u2584', 0,
			a1,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	View::WriteToView(x + 10, y + 1, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a1
	);
	View::WriteToView(x + 15, y + 1, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a1
	);
	for (int i = 0; i < 4; i++) {
		View::WriteToView(x + 11 + i, y + 1, L'\u2584', 0,
			a1,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	View::WriteToView(x + 20, y + 1, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a1
	);
	View::WriteToView(x + 25, y + 1, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a1
	);
	for (int i = 0; i < 4; i++) {
		View::WriteToView(x + 21 + i, y + 1, L'\u2584', 0,
			a1,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	for (int i = 0; i < 7; i++) {
		View::WriteToView(x + 28 + i, y + 1, L'\u2584', 0,
			a1,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	for (int i = 0; i < 6; i++) {
		View::WriteToView(x + 1 + i, y + 5, L'\u2584', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
	View::WriteToView(x + 10, y + 5, L'\u2580', 0,
		a5,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 15, y + 5, L'\u2580', 0,
		a5,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	for (int i = 0; i < 4; i++) {
		View::WriteToView(x + 11 + i, y + 5, L'\u2584', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
	View::WriteToView(x + 19, y + 5, L'\u2580', 0,
		a5,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 25, y + 5, L'\u2580', 0,
		a5,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	for (int i = 0; i < 5; i++) {
		View::WriteToView(x + 20 + i, y + 5, L'\u2584', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
	for (int i = 0; i < 7; i++) {
		View::WriteToView(x + 28 + i, y + 5, L'\u2584', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 1 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 1 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 1 + i, y + 4, L'\u2584', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 9 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 9 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 9 + i, y + 4, L'\u2584', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 15 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 15 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 15 + i, y + 4, L'\u2584', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 28 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 5; i++) {
		View::WriteToView(x + 28 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 28 + i, y + 4, L'\u2584', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 5 + i, y + 4, L'\u2580', 0,
			View::Color::BRIGHT_WHITE,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 19 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 23 + i, y + 4, L'\u2584', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 21 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	View::WriteToView(x + 20, y + 3, L'\u2580', 0,
		a3,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 24, y + 3, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a3
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 19 + i, y + 4, L'\u2580', 0,
			View::Color::BRIGHT_WHITE,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 24 + i, y + 2, L'\u2580', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
}
void Logo::Draw(NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2, View::Color a3, View::Color a4, View::Color a5) {
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 1 + i, y + 1, L'\u2584', 0,
			a1,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 1 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 1 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 1 + i, y + 4, L'\u2584', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 1 + i, y + 5, L'\u2584', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 6 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 6 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 6 + i, y + 4, L'\u2584', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 10 + i, y + 1, L'\u2584', 0,
			a1,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 10 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 10 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 10 + i, y + 4, L'\u2584', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 10 + i, y + 5, L'\u2584', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 19 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 19 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 19 + i, y + 4, L'\u2584', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 19 + i, y + 5, L'\u2584', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 25 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 25 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 25 + i, y + 4, L'\u2584', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 25 + i, y + 5, L'\u2584', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 29 + i, y + 1, L'\u2584', 0,
			a1,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 29 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 29 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 37 + i, y + 1, L'\u2584', 0,
			a1,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 37 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 37 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 3 + i, y + 1, L'\u2584', 0,
			a1,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 6 + i, y + 1, L'\u2580', 0,
			View::Color::BRIGHT_WHITE,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 12 + i, y + 1, L'\u2584', 0,
			a1,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	for (int i = 0; i < 1; i++) {
		View::WriteToView(x + 15 + i, y + 1, L'\u2580', 0,
			View::Color::BRIGHT_WHITE,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	View::WriteToView(x + 20, y + 1, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a1
	);
	View::WriteToView(x + 25, y + 1, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a1
	);
	for (int i = 0; i < 4; i++) {
		View::WriteToView(x + 21 + i, y + 1, L'\u2584', 0,
			a1,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a1
		);
	}
	View::WriteToView(x + 5, y + 2, L'\u2580', 0,
		a2,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 24, y + 2, L'\u2580', 0,
		a2,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 21, y + 2, L'\u2580', 0,
		a2,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 14, y + 2, L'\u2580', 0,
		a2,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 15 + i, y + 2, L'\u2584', 0,
			a2,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a2
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 12 + i, y + 3, L'\u2580', 0,
			View::Color::BRIGHT_WHITE,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 4; i++) {
		View::WriteToView(x + 21 + i, y + 3, L'\u2580', 0,
			View::Color::BRIGHT_WHITE,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 14 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 1; i++) {
		View::WriteToView(x + 16 + i, y + 3, L'\u2580', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 29 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 33 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 37 + i, y + 3, L'\u2584', 0,
			a3,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a3
		);
	}
	View::WriteToView(x + 32, y + 3, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a3
	);
	View::WriteToView(x + 35, y + 3, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a3
	);
	View::WriteToView(x + 5, y + 4, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a4
	);
	View::WriteToView(x + 12, y + 4, L'\u2580', 0,
		a4,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 13 + i, y + 4, L'\u2580', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a4
		);
	}
	View::WriteToView(x + 15, y + 4, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a4
	);
	for (int i = 0; i < 4; i++) {
		View::WriteToView(x + 21 + i, y + 4, L'\u2580', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	View::WriteToView(x + 29, y + 4, L'\u2580', 0,
		a4,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 38, y + 4, L'\u2580', 0,
		a4,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 31, y + 4, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a4
	);
	View::WriteToView(x + 36, y + 4, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a4
	);
	View::WriteToView(x + 30, y + 4, L'\u2580', 0,
		a4,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a4
	);
	View::WriteToView(x + 32, y + 4, L'\u2580', 0,
		a4,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a4
	);
	View::WriteToView(x + 35, y + 4, L'\u2580', 0,
		a4,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a4
	);
	View::WriteToView(x + 37, y + 4, L'\u2580', 0,
		a4,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		a4
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 33 + i, y + 4, L'\u2580', 0,
			a4,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 3 + i, y + 5, L'\u2580', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 6 + i, y + 5, L'\u2580', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	View::WriteToView(x + 14, y + 5, L'\u2580', 0,
		a5,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 15 + i, y + 5, L'\u2580', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 31 + i, y + 5, L'\u2580', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 35 + i, y + 5, L'\u2580', 0,
			a5,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			a5
		);
	}
	View::WriteToView(x + 30, y + 5, L'\u2580', 0,
		a5,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 37, y + 5, L'\u2580', 0,
		a5,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
}
void Logo::Logo_Draw(NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2, View::Color a3, View::Color a4, View::Color a5) {
	while (true) {
		Sleep(250);
		Logo::Draw(NavHost, x, y, a1, a2, a3, a4, a5);
		Sleep(250);
		Logo::Draw(NavHost, x, y, a2, a3, a4, a5, a1);
		Sleep(250);
		Logo::Draw(NavHost, x, y, a3, a4, a5, a1, a2);
		Sleep(250);
		Logo::Draw(NavHost, x, y, a4, a5, a1, a2, a3);
		Sleep(250);
		Logo::Draw(NavHost, x, y, a5, a1, a2, a3, a4);
	}
}
void Logo::Logo_Win(NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2, View::Color a3, View::Color a4, View::Color a5) {
	while (true) {
		Sleep(250);
		Logo::Win(NavHost, x, y, a1, a2, a3, a4, a5);
		Sleep(250);
		Logo::Win(NavHost, x, y, a2, a3, a4, a5, a1);
		Sleep(250);
		Logo::Win(NavHost, x, y, a3, a4, a5, a1, a2);
		Sleep(250);
		Logo::Win(NavHost, x, y, a4, a5, a1, a2, a3);
		Sleep(250);
		Logo::Win(NavHost, x, y, a5, a1, a2, a3, a4);
	}
}
void Logo::Logo_Lose(NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2, View::Color a3, View::Color a4, View::Color a5) {
	while (true) {
		Sleep(250);
		Logo::Lose(NavHost, x, y, a1, a2, a3, a4, a5);
		Sleep(250);
		Logo::Lose(NavHost, x, y, a2, a3, a4, a5, a1);
		Sleep(250);
		Logo::Lose(NavHost, x, y, a3, a4, a5, a1, a2);
		Sleep(250);
		Logo::Lose(NavHost, x, y, a4, a5, a1, a2, a3);
		Sleep(250);
		Logo::Lose(NavHost, x, y, a5, a1, a2, a3, a4);
	}
}
void Logo::Deadpool(NavigationHost& NavHost, int x, int y) {
	for (int i = 0; i < 6; i++) {
		View::WriteToView(x + 12 + i, y + 1, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 10 + i, y + 1, L'\u2580', 0,
			View::Color::BRIGHT_WHITE,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 18 + i, y + 1, L'\u2580', 0,
			View::Color::BRIGHT_WHITE,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 8, y + 2, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 21, y + 2, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 9, y + 2, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 20, y + 2, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	for (int i = 0; i < 10; i++) {
		View::WriteToView(x + 10+i, y + 2, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 7, y + 3, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 22, y + 3, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 8, y + 3, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 21, y + 3, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	for (int i = 0; i < 4; i++) {
		View::WriteToView(x + 9 + i, y + 3, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	for (int i = 0; i < 5; i++) {
		View::WriteToView(x + 16 + i, y + 3, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 13 + i, y + 3, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 8, y + 4, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 5; i++) {
		View::WriteToView(x + 12 + i, y + 4, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 21 + i, y + 4, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 11, y + 4, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 17, y + 4, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 20, y + 4, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 8 + i, y + 4, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 18 + i, y + 4, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 7, y + 4, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 1 + i, y + 5, L'\u2580', 0,
			View::Color::BRIGHT_WHITE,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 7, y + 5, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 8 + i, y + 5, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 11 + i, y + 5, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 13 + i, y + 5, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 15 + i, y + 5, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 18, y + 5, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 19, y + 5, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 20 + i, y + 5, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 1, y + 6, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 2, y + 6, L'\u2580', 0,
		View::Color::YELLOW,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::YELLOW
	);
	View::WriteToView(x + 3, y + 6, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::YELLOW
	);
	View::WriteToView(x + 4, y + 6, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 8, y + 6, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 9 + i, y + 6, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x +11 + i, y + 6, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 16, y + 6, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 17, y + 6, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 18, y + 6, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 19, y + 6, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 20, y + 6, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 22, y + 6, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 2, y + 7, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 3, y + 7, L'\u2580', 0,
		View::Color::YELLOW,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 4, y + 7, L'\u2580', 0,
		View::Color::YELLOW,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::YELLOW
	);
	View::WriteToView(x + 5, y + 7, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::YELLOW
	);
	View::WriteToView(x + 6, y + 7, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	
	View::WriteToView(x + 9, y + 7, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 10, y + 7, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 11, y + 7, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 12, y + 7, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	for (int i = 0; i < 5; i++) {
		View::WriteToView(x + 13 + i, y + 7, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 18, y + 7, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 19, y + 7, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 20 + i, y + 7, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 23, y + 7, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 24, y + 7, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::YELLOW
	);
	View::WriteToView(x + 25, y + 7, L'\u2580', 0,
		View::Color::YELLOW,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::YELLOW
	);
	View::WriteToView(x + 26, y + 7, L'\u2580', 0,
		View::Color::YELLOW,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 27, y + 7, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 25, y + 6, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 26, y + 6, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::YELLOW
	);
	View::WriteToView(x + 27, y + 6, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 4, y + 8, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 5, y + 8, L'\u2580', 0,
		View::Color::YELLOW,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 6, y + 8, L'\u2580', 0,
		View::Color::YELLOW,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::YELLOW
	);
	View::WriteToView(x + 7, y + 8, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 8, y + 8, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 9+i, y + 8, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x +12+i, y + 8, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 14+i, y + 8, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 17+i, y + 8, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 19, y + 8, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 20, y + 8, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 21, y + 8, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 22, y + 8, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::YELLOW
	);
	View::WriteToView(x + 23, y + 8, L'\u2580', 0,
		View::Color::YELLOW,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::YELLOW
	);
	View::WriteToView(x + 24, y + 8, L'\u2580', 0,
		View::Color::YELLOW,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 25, y + 8, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 5, y + 9, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 6; i++) {
		View::WriteToView(x + 6+i, y + 9, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 12, y + 9, L'\u2580', 0,
		View::Color::GRAY,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 13, y + 9, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	for (int i = 0; i < 4; i++) {
		View::WriteToView(x + 14+i, y + 9, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 18+i, y + 9, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 21+i, y + 9, L'\u2580', 0,
			View::Color::YELLOW,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 23, y + 9, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 5 + i, y + 10, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 8, y + 10, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::GRAY
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 9 + i, y + 10, L'\u2580', 0,
			View::Color::GRAY,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::GRAY
		);
	}
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 11 + i, y + 10, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 14, y + 10, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 4; i++) {
		View::WriteToView(x + 15 + i, y + 10, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 19, y + 10, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 20, y + 10, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 21 + i, y + 10, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::GRAY
		);
	}
	View::WriteToView(x + 23, y + 10, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 4, y + 11, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 5, y + 11, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::GRAY
	);
	View::WriteToView(x + 6, y + 11, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 7, y + 11, L'\u2580', 0,
		View::Color::GRAY,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 8, y + 11, L'\u2580', 0,
		View::Color::GRAY,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 9, y + 11, L'\u2580', 0,
		View::Color::GRAY,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 10, y + 11, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 11, y + 11, L'\u2580', 0,
		View::Color::GRAY,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::GRAY
	);
	View::WriteToView(x + 12, y + 11, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::GRAY
	);
	View::WriteToView(x + 13, y + 11, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 14 + i, y + 11, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 16, y + 11, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 17 + i, y + 11, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 19, y + 11, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 20, y + 11, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 21, y + 11, L'\u2580', 0,
		View::Color::GRAY,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 22, y + 11, L'\u2580', 0,
		View::Color::GRAY,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::GRAY
	);
	View::WriteToView(x + 23, y + 11, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::GRAY
	);
	View::WriteToView(x + 24, y + 11, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 3, y + 12, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 4, y + 12, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 5 + i, y + 12, L'\u2580', 0,
			View::Color::GRAY,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::GRAY
		);
	}
	View::WriteToView(x + 8, y + 12, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 10, y + 12, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 11, y + 12, L'\u2580', 0,
		View::Color::GRAY,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 12 + i, y + 12, L'\u2580', 0,
			View::Color::GRAY,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::GRAY
		);
	}
	View::WriteToView(x + 14, y + 12, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::GRAY
	);
	View::WriteToView(x + 15, y + 12, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 16 + i, y + 12, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 18, y + 12, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 19 + i, y + 12, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 21, y + 12, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 22 + i, y + 12, L'\u2580', 0,
			View::Color::GRAY,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::GRAY
		);
	}
	View::WriteToView(x + 24, y + 12, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::GRAY
	);
	View::WriteToView(x + 25, y + 12, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 3, y + 13, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 4 + i, y + 13, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 6, y + 13, L'\u2580', 0,
		View::Color::GRAY,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 7, y + 13, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 12, y + 13, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 13 + i, y + 13, L'\u2580', 0,
			View::Color::GRAY,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::GRAY
		);
	}
	View::WriteToView(x + 15, y + 13, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 16, y + 13, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::YELLOW
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 17 + i, y + 13, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::YELLOW
		);
	}
	View::WriteToView(x + 19, y + 13, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 20, y + 13, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 21, y + 13, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 22 + i, y + 13, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::GRAY
		);
	}
	View::WriteToView(x + 24, y + 13, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 25, y + 13, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 3, y + 14, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 4 + i, y + 14, L'\u2580', 0,
			View::Color::GRAY,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 7, y + 14, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 8, y + 14, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 12, y + 14, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 13, y + 14, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 14 + i, y + 14, L'\u2580', 0,
			View::Color::YELLOW,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::YELLOW
		);
	}
	View::WriteToView(x + 16, y + 14, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::GRAY
	);
	View::WriteToView(x + 18, y + 14, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::GRAY
	);
	View::WriteToView(x + 17, y + 14, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 19 + i, y + 14, L'\u2580', 0,
			View::Color::YELLOW,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::YELLOW
		);
	}
	View::WriteToView(x + 21, y + 14, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x +22, y + 14, L'\u2580', 0,
		View::Color::GRAY,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 23 + i, y + 14, L'\u2580', 0,
			View::Color::GRAY,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 25, y + 14, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 6; i++) {
		View::WriteToView(x + 3 + i, y + 15, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	
	View::WriteToView(x + 9, y + 15, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 11, y + 15, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 12, y + 15, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 13 + i, y + 15, L'\u2580', 0,
			View::Color::GRAY,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::GRAY
		);
	}
	View::WriteToView(x + 15, y + 15, L'\u2580', 0,
		View::Color::GRAY,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 16 + i, y + 15, L'\u2580', 0,
			View::Color::YELLOW,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 19, y + 15, L'\u2580', 0,
		View::Color::GRAY,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 20, y + 15, L'\u2580', 0,
		View::Color::GRAY,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::GRAY
	);
	View::WriteToView(x + 21, y + 15, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::GRAY
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 22 + i, y + 15, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	
	View::WriteToView(x + 24, y + 15, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 25 ,y + 15, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 4, y + 16, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 5 + i, y + 16, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 8 + i, y + 16, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 10 + i, y + 16, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 12 + i, y + 16, L'\u2580', 0,
			View::Color::GRAY,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::GRAY
		);
	}
	View::WriteToView(x + 14, y + 16, L'\u2580', 0,
		View::Color::GRAY,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 15, y + 16, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 16, y + 16, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 17, y + 16, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 18, y + 16, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 19, y + 16, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 20 + i, y + 16, L'\u2580', 0,
			View::Color::GRAY,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 22 + i, y + 16, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 9 + i, y + 17, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x +11 + i, y + 17, L'\u2580', 0,
			View::Color::GRAY,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::GRAY
		);
	}
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 13 + i, y + 17, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 16, y + 17, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 17, y + 17, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	for (int i = 0; i < 4; i++) {
		View::WriteToView(x + 18 + i, y + 17, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 22, y + 17, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 8, y + 18, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 9, y + 18, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 10, y + 18, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	for (int i = 0; i < 4; i++) {
		View::WriteToView(x + 11 + i, y + 18, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 15 + i, y + 18, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 0; i < 4; i++) {
		View::WriteToView(x + 17 + i, y + 18, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 21, y + 18, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 22, y + 18, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 8, y + 19, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 9, y + 19, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 10, y + 19, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 11, y + 19, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 12, y + 19, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 13, y + 19, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 14, y + 19, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 16, y + 19, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 17, y + 19, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 18, y + 19, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 19, y + 19, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 20, y + 19, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 21, y + 19, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 17 + i, y + 20, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 20, y + 20, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 16, y + 20, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 7, y + 20, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 8, y + 20, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 9 + i, y + 20, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 12, y + 20, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 13, y + 20, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 7, y + 21, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 8 + i, y + 21, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::GRAY
		);
	}
	View::WriteToView(x + 11, y + 21, L'\u2580', 0,
		View::Color::RED,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x +12, y + 21, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	View::WriteToView(x + 16, y + 21, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 4; i++) {
		View::WriteToView(x + 17 + i, y + 21, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::GRAY
		);
	}
	View::WriteToView(x + 21, y + 21, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 5, y + 22, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 6 + i, y + 22, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 9 + i, y + 22, L'\u2580', 0,
			View::Color::GRAY,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::GRAY
		);
	}
	View::WriteToView(x + 11, y + 22, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 16 + i, y + 22, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 19 + i, y + 22, L'\u2580', 0,
			View::Color::GRAY,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::GRAY
		);
	}
	View::WriteToView(x + 18, y + 22, L'\u2580', 0,
		View::Color::GRAY,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 21, y + 22, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 22, y + 22, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 5, y + 23, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 6 + i, y + 23, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 9, y + 23, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 10, y + 23, L'\u2580', 0,
		View::Color::GRAY,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 11, y + 23, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	View::WriteToView(x + 16, y + 23, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BRIGHT_WHITE
	);
	for (int i = 0; i < 2; i++) {
		View::WriteToView(x + 17+i, y + 23, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BLACK
		);
	}
	View::WriteToView(x + 19, y + 23, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	for (int i = 0; i < 3; i++) {
		View::WriteToView(x + 20+i, y + 23, L'\u2580', 0,
			View::Color::RED,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::RED
		);
	}
	View::WriteToView(x + 23, y + 23, L'\u2580', 0,
		View::Color::BLACK,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::RED
	);
	View::WriteToView(x + 24, y + 23, L'\u2580', 0,
		View::Color::BRIGHT_WHITE,
		View::DEFAULT_HIGHLIGHT_COLOR,
		View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
		View::Color::BLACK
	);
	for (int i = 0; i < 7; i++) {
		View::WriteToView(x + 5 + i, y + 24, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
	for (int i = 0; i < 7; i++) {
		View::WriteToView(x + 18 + i, y + 24, L'\u2580', 0,
			View::Color::BLACK,
			View::DEFAULT_HIGHLIGHT_COLOR,
			View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
			View::Color::BRIGHT_WHITE
		);
	}
}
