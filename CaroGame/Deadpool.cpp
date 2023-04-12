#include "Deadpool.h"
void Logo_Deadpool(int x, int y)
{
   
    View::Color theme = Theme::GetColor(ThemeColor::CONSOLE_COLOR);   
    
    for (int i = 0; i < 6; i++) {
        View::WriteToView(
            x + 12 + i,
            y + 1,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 10 + i,
            y + 1,
            L'\u2580',
            0,
            View::Color::BRIGHT_WHITE,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 18 + i,
            y + 1,
            L'\u2580',
            0,
            View::Color::BRIGHT_WHITE,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 8,
        y + 2,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 21,
        y + 2,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 9,
        y + 2,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 20,
        y + 2,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    for (int i = 0; i < 10; i++) {
        View::WriteToView(
            x + 10 + i,
            y + 2,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 7,
        y + 3,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 22,
        y + 3,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 8,
        y + 3,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 21,
        y + 3,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 9 + i,
            y + 3,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    for (int i = 0; i < 5; i++) {
        View::WriteToView(
            x + 16 + i,
            y + 3,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 13 + i,
            y + 3,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 8,
        y + 4,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 5; i++) {
        View::WriteToView(
            x + 12 + i,
            y + 4,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 21 + i,
            y + 4,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 11,
        y + 4,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 17,
        y + 4,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 20,
        y + 4,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 8 + i,
            y + 4,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 18 + i,
            y + 4,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 7,
        y + 4,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 5,
            L'\u2580',
            0,
            View::Color::BRIGHT_WHITE,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 7,
        y + 5,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 8 + i,
            y + 5,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 11 + i,
            y + 5,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 13 + i,
            y + 5,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            theme
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 15 + i,
            y + 5,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 18,
        y + 5,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 19,
        y + 5,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 20 + i,
            y + 5,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 1,
        y + 6,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 2,
        y + 6,
        L'\u2580',
        0,
        View::Color::YELLOW,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::YELLOW
    );
    View::WriteToView(
        x + 3,
        y + 6,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::YELLOW
    );
    View::WriteToView(
        x + 4,
        y + 6,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 8,
        y + 6,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 9 + i,
            y + 6,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 11 + i,
            y + 6,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 16,
        y + 6,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 17,
        y + 6,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 18,
        y + 6,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 19,
        y + 6,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 20,
        y + 6,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 22,
        y + 6,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 2,
        y + 7,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 3,
        y + 7,
        L'\u2580',
        0,
        View::Color::YELLOW,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 4,
        y + 7,
        L'\u2580',
        0,
        View::Color::YELLOW,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::YELLOW
    );
    View::WriteToView(
        x + 5,
        y + 7,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::YELLOW
    );
    View::WriteToView(
        x + 6,
        y + 7,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );

    View::WriteToView(
        x + 9,
        y + 7,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 10,
        y + 7,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 11,
        y + 7,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 12,
        y + 7,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    for (int i = 0; i < 5; i++) {
        View::WriteToView(
            x + 13 + i,
            y + 7,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 18,
        y + 7,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 19,
        y + 7,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 20 + i,
            y + 7,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 23,
        y + 7,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 24,
        y + 7,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::YELLOW
    );
    View::WriteToView(
        x + 25,
        y + 7,
        L'\u2580',
        0,
        View::Color::YELLOW,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::YELLOW
    );
    View::WriteToView(
        x + 26,
        y + 7,
        L'\u2580',
        0,
        View::Color::YELLOW,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 27,
        y + 7,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 25,
        y + 6,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 26,
        y + 6,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::YELLOW
    );
    View::WriteToView(
        x + 27,
        y + 6,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 4,
        y + 8,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 5,
        y + 8,
        L'\u2580',
        0,
        View::Color::YELLOW,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 6,
        y + 8,
        L'\u2580',
        0,
        View::Color::YELLOW,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::YELLOW
    );
    View::WriteToView(
        x + 7,
        y + 8,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 8,
        y + 8,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 9 + i,
            y + 8,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 12 + i,
            y + 8,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 14 + i,
            y + 8,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 17 + i,
            y + 8,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 19,
        y + 8,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 20,
        y + 8,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 21,
        y + 8,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 22,
        y + 8,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::YELLOW
    );
    View::WriteToView(
        x + 23,
        y + 8,
        L'\u2580',
        0,
        View::Color::YELLOW,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::YELLOW
    );
    View::WriteToView(
        x + 24,
        y + 8,
        L'\u2580',
        0,
        View::Color::YELLOW,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 25,
        y + 8,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 5,
        y + 9,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 6; i++) {
        View::WriteToView(
            x + 6 + i,
            y + 9,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 12,
        y + 9,
        L'\u2580',
        0,
        View::Color::GRAY,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 13,
        y + 9,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 14 + i,
            y + 9,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 18 + i,
            y + 9,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 21 + i,
            y + 9,
            L'\u2580',
            0,
            View::Color::YELLOW,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 23,
        y + 9,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 5 + i,
            y + 10,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 8,
        y + 10,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::GRAY
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 9 + i,
            y + 10,
            L'\u2580',
            0,
            View::Color::GRAY,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::GRAY
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 11 + i,
            y + 10,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 14,
        y + 10,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 15 + i,
            y + 10,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 19,
        y + 10,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 20,
        y + 10,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 21 + i,
            y + 10,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::GRAY
        );
    }
    View::WriteToView(
        x + 23,
        y + 10,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 4,
        y + 11,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 5,
        y + 11,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 6,
        y + 11,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 7,
        y + 11,
        L'\u2580',
        0,
        View::Color::GRAY,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 8,
        y + 11,
        L'\u2580',
        0,
        View::Color::GRAY,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 9,
        y + 11,
        L'\u2580',
        0,
        View::Color::GRAY,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 10,
        y + 11,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 11,
        y + 11,
        L'\u2580',
        0,
        View::Color::GRAY,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 12,
        y + 11,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 13,
        y + 11,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 14 + i,
            y + 11,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 16,
        y + 11,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 17 + i,
            y + 11,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 19,
        y + 11,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 20,
        y + 11,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 21,
        y + 11,
        L'\u2580',
        0,
        View::Color::GRAY,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 22,
        y + 11,
        L'\u2580',
        0,
        View::Color::GRAY,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 23,
        y + 11,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 24,
        y + 11,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 3,
        y + 12,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 4,
        y + 12,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 5 + i,
            y + 12,
            L'\u2580',
            0,
            View::Color::GRAY,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::GRAY
        );
    }
    View::WriteToView(
        x + 8,
        y + 12,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 10,
        y + 12,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 11,
        y + 12,
        L'\u2580',
        0,
        View::Color::GRAY,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 12 + i,
            y + 12,
            L'\u2580',
            0,
            View::Color::GRAY,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::GRAY
        );
    }
    View::WriteToView(
        x + 14,
        y + 12,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 15,
        y + 12,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 16 + i,
            y + 12,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 18,
        y + 12,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 19 + i,
            y + 12,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 21,
        y + 12,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 22 + i,
            y + 12,
            L'\u2580',
            0,
            View::Color::GRAY,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::GRAY
        );
    }
    View::WriteToView(
        x + 24,
        y + 12,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 25,
        y + 12,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 3,
        y + 13,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 4 + i,
            y + 13,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 6,
        y + 13,
        L'\u2580',
        0,
        View::Color::GRAY,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 7,
        y + 13,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 12,
        y + 13,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 13 + i,
            y + 13,
            L'\u2580',
            0,
            View::Color::GRAY,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::GRAY
        );
    }
    View::WriteToView(
        x + 15,
        y + 13,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 16,
        y + 13,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::YELLOW
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 17 + i,
            y + 13,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::YELLOW
        );
    }
    View::WriteToView(
        x + 19,
        y + 13,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 20,
        y + 13,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 21,
        y + 13,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 22 + i,
            y + 13,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::GRAY
        );
    }
    View::WriteToView(
        x + 24,
        y + 13,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 25,
        y + 13,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 3,
        y + 14,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 4 + i,
            y + 14,
            L'\u2580',
            0,
            View::Color::GRAY,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 7,
        y + 14,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 8,
        y + 14,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 12,
        y + 14,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 13,
        y + 14,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 14 + i,
            y + 14,
            L'\u2580',
            0,
            View::Color::YELLOW,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::YELLOW
        );
    }
    View::WriteToView(
        x + 16,
        y + 14,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 18,
        y + 14,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 17,
        y + 14,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 19 + i,
            y + 14,
            L'\u2580',
            0,
            View::Color::YELLOW,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::YELLOW
        );
    }
    View::WriteToView(
        x + 21,
        y + 14,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 22,
        y + 14,
        L'\u2580',
        0,
        View::Color::GRAY,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 23 + i,
            y + 14,
            L'\u2580',
            0,
            View::Color::GRAY,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 25,
        y + 14,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 6; i++) {
        View::WriteToView(
            x + 3 + i,
            y + 15,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }

    View::WriteToView(
        x + 9,
        y + 15,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 11,
        y + 15,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 12,
        y + 15,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 13 + i,
            y + 15,
            L'\u2580',
            0,
            View::Color::GRAY,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::GRAY
        );
    }
    View::WriteToView(
        x + 15,
        y + 15,
        L'\u2580',
        0,
        View::Color::GRAY,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 16 + i,
            y + 15,
            L'\u2580',
            0,
            View::Color::YELLOW,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 19,
        y + 15,
        L'\u2580',
        0,
        View::Color::GRAY,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 20,
        y + 15,
        L'\u2580',
        0,
        View::Color::GRAY,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::GRAY
    );
    View::WriteToView(
        x + 21,
        y + 15,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::GRAY
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 22 + i,
            y + 15,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }

    View::WriteToView(
        x + 24,
        y + 15,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 25,
        y + 15,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 4,
        y + 16,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 5 + i,
            y + 16,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 8 + i,
            y + 16,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BRIGHT_WHITE
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 10 + i,
            y + 16,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 12 + i,
            y + 16,
            L'\u2580',
            0,
            View::Color::GRAY,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::GRAY
        );
    }
    View::WriteToView(
        x + 14,
        y + 16,
        L'\u2580',
        0,
        View::Color::GRAY,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 15,
        y + 16,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 16,
        y + 16,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 17,
        y + 16,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 18,
        y + 16,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 19,
        y + 16,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 20 + i,
            y + 16,
            L'\u2580',
            0,
            View::Color::GRAY,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 22 + i,
            y + 16,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 9 + i,
            y + 17,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 11 + i,
            y + 17,
            L'\u2580',
            0,
            View::Color::GRAY,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::GRAY
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 13 + i,
            y + 17,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 16,
        y + 17,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 17,
        y + 17,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 18 + i,
            y + 17,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 22,
        y + 17,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 8,
        y + 18,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 9,
        y + 18,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 10,
        y + 18,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 11 + i,
            y + 18,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 15 + i,
            y + 18,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 17 + i,
            y + 18,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 21,
        y + 18,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 22,
        y + 18,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 8,
        y + 19,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 9,
        y + 19,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 10,
        y + 19,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 11,
        y + 19,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 12,
        y + 19,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 13,
        y + 19,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 14,
        y + 19,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 16,
        y + 19,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 17,
        y + 19,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 18,
        y + 19,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 19,
        y + 19,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 20,
        y + 19,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 21,
        y + 19,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 17 + i,
            y + 20,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 20,
        y + 20,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 16,
        y + 20,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 7,
        y + 20,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 8,
        y + 20,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 9 + i,
            y + 20,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 12,
        y + 20,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 13,
        y + 20,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 7,
        y + 21,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 8 + i,
            y + 21,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::GRAY
        );
    }
    View::WriteToView(
        x + 11,
        y + 21,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 12,
        y + 21,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 16,
        y + 21,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 17 + i,
            y + 21,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::GRAY
        );
    }
    View::WriteToView(
        x + 21,
        y + 21,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 5,
        y + 22,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 6 + i,
            y + 22,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 9 + i,
            y + 22,
            L'\u2580',
            0,
            View::Color::GRAY,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::GRAY
        );
    }
    View::WriteToView(
        x + 11,
        y + 22,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 16 + i,
            y + 22,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 19 + i,
            y + 22,
            L'\u2580',
            0,
            View::Color::GRAY,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::GRAY
        );
    }
    View::WriteToView(
        x + 18,
        y + 22,
        L'\u2580',
        0,
        View::Color::GRAY,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 21,
        y + 22,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 22,
        y + 22,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 5,
        y + 23,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 6 + i,
            y + 23,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 9,
        y + 23,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 10,
        y + 23,
        L'\u2580',
        0,
        View::Color::GRAY,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 11,
        y + 23,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 16,
        y + 23,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 17 + i,
            y + 23,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 19,
        y + 23,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 20 + i,
            y + 23,
            L'\u2580',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::RED
        );
    }
    View::WriteToView(
        x + 23,
        y + 23,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::RED
    );
    View::WriteToView(
        x + 24,
        y + 23,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    for (int i = 0; i < 7; i++) {
        View::WriteToView(
            x + 5 + i,
            y + 24,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BRIGHT_WHITE
        );
    }
    for (int i = 0; i < 7; i++) {
        View::WriteToView(
            x + 18 + i,
            y + 24,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BRIGHT_WHITE
        );
    }
    View::WriteToView(
        x + 24,
        y + 23,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    
    View::WriteToView(
        x + 10,
        y + 1,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 11,
        y + 1,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 18,
        y + 1,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 19,
        y + 1,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 8,
        y + 2,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 21,
        y + 2,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 7,
        y + 3,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 22,
        y + 3,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 1,
        y + 5,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 2,
        y + 5,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 4,
        y + 6,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    y--;
    View::WriteToView(
        x + 25,
        y + 7,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 6,
        y + 8,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 23,
        y + 8,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 8,
        y + 9,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 21,
        y + 9,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 5,
        y + 10,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x +23,
        y +11
        ,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x +24,
        y +12
        ,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
   
    View::WriteToView(
        x +3,
        y +13
        ,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x +25,
        y +13
        ,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    y++;
    View::WriteToView(
        x +8,
        y +14
        ,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x +12,
        y +14
        ,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x +9,
        y +15
        ,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x +8,
        y +18
        ,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x +7,
        y +20
        ,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x +5,
        y +22
        ,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x +22,
        y +22
        ,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 24,
        y + 23,
        L'\u2580',
        0,
        theme,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 20,
        y + 6,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 2,
        y + 7,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 9,
        y + 7,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 27,
        y + 7,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 4,
        y + 8,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 20,
        y + 8,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 25,
        y + 8,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 23,
        y + 9,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 10,
        y + 12,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 4,
        y + 16,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 8,
        y + 16,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 9,
        y + 16,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 22,
        y + 18,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 14,
        y + 19,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 21,
        y + 19,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    x = x - 2;
    View::WriteToView(
        x + 15,
        y + 20,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 14,
        y + 21,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    View::WriteToView(
        x + 18,
        y + 23,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        theme
    );
    x = x + 2;
    for (int i = 0; i < 7; i++) {
        View::WriteToView(
            x + 5+i,
            y + 24,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            theme
        );
    }
    for (int i = 0; i < 7; i++) {
        View::WriteToView(
            x + 18 + i,
            y + 24,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            theme
        );
    }

}