#include "Captain.h"

void Logo_Captain(int x, int y) {
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 16 + i, y + 1, L'\u2580', 0, View::Color::BRIGHT_WHITE,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 5; i++) {
        View::WriteToView(
            x + 18 + i, y + 1, L'\u2580', 0, View::Color::BLACK,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::CYAN
        );
    }
    View::WriteToView(
        x + 23, y + 1, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 24, y + 1, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 14, y + 2, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 15, y + 2, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    for (int i = 0; i < 7; i++) {
        View::WriteToView(
            x + 16 + i, y + 2, L'\u2580', 0, View::Color::CYAN,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::CYAN
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 23 + i, y + 2, L'\u2580', 0, View::Color::CYAN,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BLUE
        );
    }
    View::WriteToView(
        x + 25, y + 2, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 26, y + 2, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 13, y + 3, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 14, y + 3, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 15, y + 3, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 16, y + 3, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 17 + i, y + 3, L'\u2580', 0, View::Color::CYAN,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::CYAN
        );
    }
    View::WriteToView(
        x + 21, y + 3, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 22, y + 3, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 23 + i, y + 3, L'\u2580', 0, View::Color::CYAN,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BLUE
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 26 + i, y + 3, L'\u2580', 0, View::Color::BLACK,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BLUE
        );
    }
    View::WriteToView(
        x + 28, y + 3, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 13, y + 4, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 14, y + 4, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 15, y + 4, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 16, y + 4, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 17, y + 4, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 18 + i, y + 4, L'\u2580', 0, View::Color::CYAN,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::CYAN
        );
    }
    View::WriteToView(
        x + 20, y + 4, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 21, y + 4, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    for (int i = 0; i < 5; i++) {
        View::WriteToView(
            x + 22 + i, y + 4, L'\u2580', 0, View::Color::BLUE,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BLUE
        );
    }
    View::WriteToView(
        x + 27, y + 4, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 28, y + 4, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 13, y + 5, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 14, y + 5, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 15, y + 5, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 16, y + 5, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 17, y + 5, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 18, y + 5, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 19, y + 5, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 21, y + 5, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 20, y + 5, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 22 + i, y + 5, L'\u2580', 0, View::Color::BLUE,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BLUE
        );
    }
    View::WriteToView(
        x + 25, y + 5, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 26, y + 5, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 27, y + 5, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 13, y + 6, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 14, y + 6, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 15, y + 6, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 16, y + 6, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 17, y + 6, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 18, y + 6, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 19, y + 6, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 20, y + 6, L'\u2580', 0, View::Color::LIGHT_YELLOW,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::LIGHT_YELLOW
    );
    View::WriteToView(
        x + 21, y + 6, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 22 + i, y + 6, L'\u2580', 0, View::Color::BLUE,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 24, y + 6, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::LIGHT_YELLOW
    );
    View::WriteToView(
        x + 25, y + 6, L'\u2580', 0, View::Color::LIGHT_YELLOW,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::LIGHT_YELLOW
    );
    View::WriteToView(
        x + 26, y + 6, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 27, y + 6, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 14, y + 7, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 15, y + 7, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::LIGHT_YELLOW
    );
    View::WriteToView(
        x + 16, y + 7, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 17 + i, y + 7, L'\u2580', 0, View::Color::CYAN,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::CYAN
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 20 + i, y + 7, L'\u2580', 0, View::Color::CYAN,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::LIGHT_YELLOW
        );
    }
    View::WriteToView(
        x + 22, y + 7, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::LIGHT_YELLOW
    );
    View::WriteToView(
        x + 23, y + 7, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 24, y + 7, L'\u2580', 0, View::Color::LIGHT_YELLOW,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 25, y + 7, L'\u2580', 0, View::Color::LIGHT_YELLOW,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 26, y + 7, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 14, y + 8, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 15, y + 8, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 16, y + 8, L'\u2580', 0, View::Color::LIGHT_YELLOW,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 17 + i, y + 8, L'\u2580', 0, View::Color::LIGHT_YELLOW,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::LIGHT_YELLOW
        );
    }
    View::WriteToView(
        x + 21, y + 8, L'\u2580', 0, View::Color::LIGHT_YELLOW,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 22, y + 8, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::LIGHT_YELLOW
    );
    View::WriteToView(
        x + 23, y + 8, L'\u2580', 0, View::Color::LIGHT_YELLOW,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 24, y + 8, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 25, y + 8, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 26, y + 8, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 6 + i, y + 9, L'\u2580', 0, View::Color::BRIGHT_WHITE,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 11, y + 9, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 12, y + 9, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 13, y + 9, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 14, y + 9, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 15, y + 9, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 16, y + 9, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 17, y + 9, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 18 + i, y + 9, L'\u2580', 0, View::Color::RED,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BLUE
        );
    }
    View::WriteToView(
        x + 21, y + 9, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 22, y + 9, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 23, y + 9, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 24, y + 9, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 25, y + 9, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 26, y + 9, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 28, y + 9, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 27, y + 9, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 29, y + 9, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 4, y + 10, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 5, y + 10, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 6, y + 10, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 7, y + 10, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 8, y + 10, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 9, y + 10, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 10, y + 10, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 11, y + 10, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 12, y + 10, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 13, y + 10, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 14, y + 10, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 15, y + 10, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 16, y + 10, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 17, y + 10, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 21, y + 10, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 18, y + 10, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 20, y + 10, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 22, y + 10, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 23, y + 10, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 24, y + 10, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 28, y + 10, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 25, y + 10, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 27, y + 10, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );

    View::WriteToView(
        x + 29, y + 10, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 3, y + 11, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 4, y + 11, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 9, y + 11, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 10, y + 11, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 11, y + 11, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 12, y + 11, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 13, y + 11, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 14, y + 11, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 15, y + 11, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 16, y + 11, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 17, y + 11, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 19, y + 11, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 21, y + 11, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 22 + i, y + 11, L'\u2580', 0, View::Color::BRIGHT_WHITE,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BLUE
        );
    }
    View::WriteToView(
        x + 25, y + 11, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 26 + i, y + 11, L'\u2580', 0, View::Color::BLUE,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::CYAN
        );
    }
    View::WriteToView(
        x + 29, y + 11, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 30, y + 11, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 2, y + 12, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 4, y + 12, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 5 + i, y + 12, L'\u2580', 0, View::Color::RED,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 8, y + 12, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 10, y + 12, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 11, y + 12, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 12, y + 12, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 13, y + 12, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 14, y + 12, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 15, y + 12, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 16, y + 12, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 17 + i, y + 12, L'\u2580', 0, View::Color::CYAN,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::CYAN
        );
    }
    View::WriteToView(
        x + 19, y + 12, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 20 + i, y + 12, L'\u2580', 0, View::Color::CYAN,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::CYAN
        );
    }
    View::WriteToView(
        x + 22, y + 12, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 23, y + 12, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 25, y + 12, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 26, y + 12, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 27, y + 12, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 28, y + 12, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 29, y + 12, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 30, y + 12, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 31, y + 12, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 1, y + 13, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 3, y + 13, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 4, y + 13, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 5, y + 13, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 6, y + 13, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 7, y + 13, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 8, y + 13, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 11, y + 13, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 12, y + 13, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 14, y + 13, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 15, y + 13, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 16, y + 13, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 17, y + 13, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 18, y + 13, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 19, y + 13, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 20, y + 13, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 21, y + 13, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 22, y + 13, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 23, y + 13, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 24, y + 13, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 28, y + 13, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );

    View::WriteToView(
        x + 29, y + 13, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 30, y + 13, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 31, y + 13, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 32, y + 13, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 1, y + 14, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 3, y + 14, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 4, y + 14, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 7, y + 14, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 8, y + 14, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 11, y + 14, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 12, y + 14, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );

    View::WriteToView(
        x + 14, y + 14, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 15 + i, y + 14, L'\u2580', 0, View::Color::RED,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::RED
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 21 + i, y + 14, L'\u2580', 0, View::Color::RED,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 24, y + 14, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 29, y + 14, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 30, y + 14, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 31, y + 14, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 32, y + 14, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 33, y + 14, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 1, y + 15, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 3, y + 15, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 4, y + 15, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 5, y + 15, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 6, y + 15, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 7, y + 15, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 8, y + 15, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 11, y + 15, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 12, y + 15, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 14, y + 15, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 15, y + 15, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 16, y + 15, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 17, y + 15, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 18, y + 15, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 19, y + 15, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 20, y + 15, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 21, y + 15, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 22, y + 15, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 23, y + 15, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 24, y + 15, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 25, y + 15, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 28, y + 15, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 29, y + 15, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 30, y + 15, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 31, y + 15, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 32, y + 15, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 33, y + 15, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 2, y + 16, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 4, y + 16, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 7, y + 16, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 5, y + 16, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 6, y + 16, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 10, y + 16, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 11, y + 16, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 12, y + 16, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 13, y + 16, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 14, y + 16, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 15, y + 16, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 16, y + 16, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 17, y + 16, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 18, y + 16, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 19, y + 16, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 20, y + 16, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 21, y + 16, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 22, y + 16, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 23, y + 16, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 24, y + 16, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 25, y + 16, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 26, y + 16, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 28, y + 16, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 29, y + 16, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 30, y + 16, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 31, y + 16, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 32, y + 16, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 33, y + 16, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 3, y + 17, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 4, y + 17, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 9, y + 17, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 10, y + 17, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 11, y + 17, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 13, y + 17, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 14, y + 17, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 15, y + 17, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 16, y + 17, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 17, y + 17, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 18, y + 17, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 19, y + 17, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 20, y + 17, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 21, y + 17, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 22, y + 17, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 23, y + 17, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 24, y + 17, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 25, y + 17, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 26, y + 17, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 29, y + 17, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 30, y + 17, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 31, y + 17, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 4, y + 18, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 5, y + 18, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 6, y + 18, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 7, y + 18, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 8, y + 18, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 9, y + 18, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 12, y + 18, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 13, y + 18, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 14, y + 18, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 15, y + 18, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 16, y + 18, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 17, y + 18, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 18, y + 18, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 21, y + 18, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 22, y + 18, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 23, y + 18, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 25, y + 18, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 24, y + 18, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 26, y + 18, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 27, y + 18, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 6, y + 19, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 7, y + 19, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 10, y + 19, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 11, y + 19, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 12, y + 19, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 13, y + 19, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 14, y + 19, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 15, y + 19, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 16, y + 19, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 23, y + 19, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 29, y + 19, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 28, y + 19, L'\u2580', 0, View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 27, y + 19, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 26, y + 19, L'\u2580', 0, View::Color::CYAN,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 25, y + 19, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLUE
    );
    View::WriteToView(
        x + 24, y + 19, L'\u2580', 0, View::Color::BLUE,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::CYAN
    );
    View::WriteToView(
        x + 10, y + 20, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 11, y + 20, L'\u2580', 0, View::Color::GRAY,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::GRAY
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 12 + i, y + 20, L'\u2580', 0, View::Color::RED,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 16, y + 20, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 29, y + 20, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 28, y + 20, L'\u2580', 0, View::Color::GRAY,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::GRAY
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 24 + i, y + 20, L'\u2580', 0, View::Color::RED,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 23, y + 20, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 11, y + 21, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 12, y + 21, L'\u2580', 0, View::Color::GRAY,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 13, y + 21, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 14, y + 21, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 15, y + 21, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 28, y + 21, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 27, y + 21, L'\u2580', 0, View::Color::GRAY,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 26, y + 21, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 25, y + 21, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 24, y + 21, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 11, y + 22, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 12, y + 22, L'\u2580', 0, View::Color::GRAY,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 13, y + 22, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 14, y + 22, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 28, y + 22, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 27, y + 22, L'\u2580', 0, View::Color::GRAY,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 26, y + 22, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 25, y + 22, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 10, y + 23, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 11, y + 23, L'\u2580', 0, View::Color::GRAY,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 12, y + 23, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 13, y + 23, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 29, y + 23, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 28, y + 23, L'\u2580', 0, View::Color::GRAY,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 27, y + 23, L'\u2580', 0, View::Color::RED,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::RED
    );
    View::WriteToView(
        x + 26, y + 23, L'\u2580', 0, View::Color::BLACK,
        View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BLACK
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 10 + i, y + 24, L'\u2580', 0, View::Color::BLACK,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BRIGHT_WHITE
        );
    }
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 26 + i, y + 24, L'\u2580', 0, View::Color::BLACK,
            View::DEFAULT_HIGHLIGHT_COLOR, View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BRIGHT_WHITE
        );
    }
};