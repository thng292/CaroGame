#include "View.h"
#include <iostream>
#include <Windows.h>

void View::Setup() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	DWORD currMode;
	CONSOLE_FONT_INFOEX fontex;


	//Turn off maximize, resize, horizontal and vertical scrolling
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME) & ~(WS_HSCROLL) & ~(WS_VSCROLL);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
	
	
	//Turn off mouse input
	GetConsoleMode(hOut, &currMode);
	SetConsoleMode(hOut, currMode & ~(ENABLE_MOUSE_INPUT) & ~(ENABLE_QUICK_EDIT_MODE));
	
	
	//Set font bold
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 800;
	fontex.dwFontSize.X = 24;
	fontex.dwFontSize.Y = 24;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
	

	//Update console title
	SetConsoleTitle(TEXT("Caro Game"));


	// Change color
	system("cls");
	system("color f0");
}

void View::Goto(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x, y});
}

void View::Print(
	int x, int y, //Draw position
	std::string str,
	char shortcut, //Character want to underline
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
		str = str.substr(0, shortcutIndex) + View::Underline(str[shortcutIndex]) + str.substr(shortcutIndex + 1, str.length() - 1);
	}
	std::cout << str;
}

void View::Print(
	int x, int y, //Draw position
	char str,
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
	std::cout << str;
}

std::string View::Underline(std::string str) {
    return "\033[4m" + str + "\033[24m";
}

std::string View::Underline(char str) {
    return std::string("\033[4m") + str + "\033[24m";
}