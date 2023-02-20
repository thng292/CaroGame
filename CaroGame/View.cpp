#include "View.h"
#include <iostream>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>

void View::Setup() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	DWORD currMode;
	CONSOLE_FONT_INFOEX fontex;


	// Turn off maximize, resize, horizontal and vertical scrolling
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME) & ~(WS_HSCROLL) & ~(WS_VSCROLL);
	SetWindowLong(consoleWindow, GWL_STYLE, style);


	// Turn off mouse input
	GetConsoleMode(hOut, &currMode);
	SetConsoleMode(hOut, currMode & ~(ENABLE_MOUSE_INPUT) & ~(ENABLE_QUICK_EDIT_MODE));


	// Set font bold
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	wcscpy_s(fontex.FaceName, L"Consolas");
	fontex.FontWeight = 800;
	fontex.dwFontSize.X = 24;
	fontex.dwFontSize.Y = 24;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);


	// Update console title
	SetConsoleTitle(TEXT("Caro Game"));


	// Change color and clear screen
	ClearScreen();

	// Set IO Unicode
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stdin), _O_WTEXT);
}

void View::Goto(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
}

void View::WriteToView(
	short x, short y, //Draw position
	std::wstring str,
	wchar_t shortcut, //Character want to underline
	bool highlight,
	View::Color textColor,
	View::Color highlightColor,
	View::Color highlightTextColor
) {
	View::Goto(x, y);
	if (highlight) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int(highlightColor) << 4) | int(highlightTextColor));
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int(View::DEFAULT_BACKGROUND_COLOR) << 4) | int(textColor));
	}
	if (shortcut) {
		int shortcutIndex = str.find_first_of(shortcut);
		std::wcout << str.substr(0, shortcutIndex) << View::Underline(str[shortcutIndex]) << str.substr(shortcutIndex + 1, str.length() - 1);
	}
	else {
		std::wcout << str;
	}
}

void View::WriteToView(
	short x, short y, //Draw position
	wchar_t str,
	bool highlight,
	View::Color textColor,
	View::Color highlightColor,
	View::Color highlightTextColor
) {
	View::Goto(x, y);
	if (highlight) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int(highlightColor) << 4) | int(highlightTextColor));
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int(View::DEFAULT_BACKGROUND_COLOR) << 4) | int(textColor));
	}
	std::wcout << str;
}

std::wstring View::Underline(std::wstring str) {
	return L"\033[4m" + std::wstring(str.begin(), str.end()) + L"\033[24m";
}

std::wstring View::Underline(wchar_t str) {
	return	L"\033[4m" + std::wstring(1, str) + L"\033[24m";
}

void View::ClearScreen() {
	DWORD tmp = 0;
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	FillConsoleOutputCharacter(StdOut, L' ', 120 * 30, { 0,0 }, &tmp);
	FillConsoleOutputAttribute(StdOut, 240, 120 * 30, { 0,0 }, &tmp);
}