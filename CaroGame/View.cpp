#include "View.h"
#include <stdio.h>

void View::Setup() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME) & ~(WS_HSCROLL) & ~(WS_VSCROLL);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
    system("cls");
    system("color f0");
}

void View::Goto(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void View::DrawText(int x, int y, char* str, bool highlight, char underline) {
    View::Goto(x, y);
    /*if (highlight) {
        WORD currentConsoleAttr;
    }*/
    printf("%s", str);
}
