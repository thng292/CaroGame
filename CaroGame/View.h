#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

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

	struct Rect {
		short Top, Left, Right, Bottom;
	};

	struct Option {
		const std::wstring& option;
		const wchar_t underline;
	};

	const Color DEFAULT_TEXT_COLOR = Color::BLACK;
	const Color DEFAULT_HIGHLIGHT_COLOR = Color::BLACK;
	const Color DEFAULT_HIGHLIGHT_TEXT_COLOR = Color::BRIGHT_WHITE;
	const Color DEFAULT_BACKGROUND_COLOR = Color::BRIGHT_WHITE;
	const short HPADDING = 3;
	const short VPADDING = 1;
	const short BORDER_WIDTH = 1;
	const short DEFAULT_SCREEN_ATTRIBUTE = 240;

	// Setup console
	void Setup();

	// Set cursor position
	void Goto(short x, short y);

	// Print string to console
	void WriteToView(
		short x, short y, //Draw position
		const std::wstring& str,
		wchar_t shortcut = 0, //Character want to underline
		bool highlight = false,
		Color textColor = DEFAULT_TEXT_COLOR,
		Color highlightColor = DEFAULT_HIGHLIGHT_COLOR,
		Color highlightTextColor = DEFAULT_HIGHLIGHT_TEXT_COLOR
	);

	//Print character to console
	void WriteToView(
		short x, short y, //Draw position
		wchar_t str,
		bool highlight = false,
		Color textColor = DEFAULT_TEXT_COLOR,
		Color highlightColor = DEFAULT_HIGHLIGHT_COLOR,
		Color highlightTextColor = DEFAULT_HIGHLIGHT_TEXT_COLOR
	);

	// Return underlined string
	inline std::wstring Underline(const std::wstring& str);

	// Return underlined string
	inline std::wstring Underline(wchar_t str);

	void ClearScreen();

	void ClearRect(Rect area);

	void DrawRect(
		const Rect& rect, 
		Color textColor = DEFAULT_TEXT_COLOR,
		Color bgColor = DEFAULT_BACKGROUND_COLOR
	);

	void DrawMenu(
		short x, short y,
		const std::wstring& title,
		const std::vector<Option>& optionsList,
		size_t selected,
		Color textColor = DEFAULT_TEXT_COLOR,
		Color highlightColor = DEFAULT_HIGHLIGHT_COLOR,
		Color highlightTextColor = DEFAULT_HIGHLIGHT_TEXT_COLOR
	);

	void DrawMenuCenter(
		std::wstring title,
		std::vector<Option> optionsList,
		size_t selected,
		Color textColor = DEFAULT_TEXT_COLOR,
		Color highlightColor = DEFAULT_HIGHLIGHT_COLOR,
		Color highlightTextColor = DEFAULT_HIGHLIGHT_TEXT_COLOR
	);

	void DrawTextWrapped(
		short x, short y, 
		const std::wstring& text, 
		short maxRow, short maxWidth, 
		const std::wstring& overflowStr = L"..."
	);
}