#pragma once
#include <string>

namespace View {
	//All posible color
	enum class Color : char {
		BLACK = 0,
		BLUE = 1,
		GREEN = 2,
		CYAN = 3,
		RED = 4,
		MAGENTA = 5,
		YELLOW = 6,
		WHITE = 7,
		GRAY = 8,
		LIGHT_BLUE = 9,
		LIGHT_GREEN = 10,
		LIGHT_CYAN = 11,
		LIGHT_RED = 12,
		LIGHT_MAGENTA = 13,
		LIGHT_YELLOW = 14,
		BRIGHT_WHITE = 15
	};

	const Color DEFAULT_TEXT_COLOR = Color::BLACK;
	const Color DEFAULT_HIGHLIGHT_COLOR = Color::BLACK;
	const Color DEFAULT_HIGHLIGHT_TEXT_COLOR = Color::BRIGHT_WHITE;
	const Color DEFAULT_BACKGROUND_COLOR = Color::BRIGHT_WHITE;
	
	// Setup console
	void Setup();

	// Set cursor position
	void Goto(short x, short y);

	// Print string to console
	void Print(
		int x, int y, //Draw position
		std::string str,
		char shortcut = 0, //Character want to underline
		bool highlight = false,
		Color textColor = DEFAULT_TEXT_COLOR,
		Color highlightColor = DEFAULT_HIGHLIGHT_COLOR,
		Color highlightTextColor = DEFAULT_HIGHLIGHT_TEXT_COLOR
	);

	//Print character to console
	void Print(
		int x, int y, //Draw position
		char str,
		bool highlight = false,
		Color textColor = DEFAULT_TEXT_COLOR,
		Color highlightColor = DEFAULT_HIGHLIGHT_COLOR,
		Color highlightTextColor = DEFAULT_HIGHLIGHT_TEXT_COLOR
	);

	// Return underlined string
	std::string Underline(std::string str);

	// Return underlined string
	std::string Underline(char str);
}