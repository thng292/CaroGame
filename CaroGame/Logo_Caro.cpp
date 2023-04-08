#include "Logo_Caro.h"

void Caro(int x, int y)
{  // function paint logo
    for (int i = 1; i <= 6; i++) {
        View::WriteToView(
            x + 3 + i,
            y + 1,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 3; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 2,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 3; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 3,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 3; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 4,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 3; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 5,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 6; i++) {
        View::WriteToView(
            x + 3 + i,
            y + 6,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 3; i++) {
        View::WriteToView(
            x + 8 + i,
            y + 2,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 3; i++) {
        View::WriteToView(
            x + 8 + i,
            y + 5,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 4; i++) {
        View::WriteToView(
            x + 18 + i,
            y + 1,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 2; i++) {
        View::WriteToView(
            x + 16 + i,
            y + 2,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 2; i++) {
        View::WriteToView(
            x + 22 + i,
            y + 2,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int k = 0; k <= 3; k++) {
        for (int i = 1; i <= 3; i++) {
            View::WriteToView(
                x + 15 + i,
                y + 3 + k,
                L'\u2588',
                0,
                View::Color::BLACK,
                View::Color::BLACK,
                View::Color::BLACK,
                View::Color::BLACK
            );
        }
        for (int i = 1; i <= 3; i++) {
            View::WriteToView(
                x + 22 + i,
                y + 3 + k,
                L'\u2588',
                0,
                View::Color::BLACK,
                View::Color::BLACK,
                View::Color::BLACK,
                View::Color::BLACK
            );
        }
    }
    for (int i = 1; i <= 4; i++) {
        View::WriteToView(
            x + 18 + i,
            y + 4,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int k = 0; k <= 5; k++) {
        for (int i = 1; i <= 3; i++) {
            View::WriteToView(
                x + 29 + i,
                y + 1 + k,
                L'\u2588',
                0,
                View::Color::BLACK,
                View::Color::BLACK,
                View::Color::BLACK,
                View::Color::BLACK
            );
        }
    }
    for (int i = 1; i <= 5; i++) {
        View::WriteToView(
            x + 32 + i,
            y + 1,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 5; i++) {
        View::WriteToView(
            x + 32 + i,
            y + 4,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 3; i++) {
        View::WriteToView(
            x + 36 + i,
            y + 2,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 3; i++) {
        View::WriteToView(
            x + 36 + i,
            y + 3,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 3; i++) {
        View::WriteToView(
            x + 36 + i,
            y + 6,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 3; i++) {
        View::WriteToView(
            x + 35 + i,
            y + 5,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 6; i++) {
        View::WriteToView(
            x + 45 + i,
            y + 1,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 1; i <= 6; i++) {
        View::WriteToView(
            x + 45 + i,
            y + 6,
            L'\u2588',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int k = 0; k <= 3; k++) {
        for (int i = 1; i <= 3; i++) {
            View::WriteToView(
                x + 43 + i,
                y + 2 + k,
                L'\u2588',
                0,
                View::Color::BLACK,
                View::Color::BLACK,
                View::Color::BLACK,
                View::Color::BLACK
            );
        }
    }
    for (int k = 0; k <= 3; k++) {
        for (int i = 1; i <= 3; i++) {
            View::WriteToView(
                x + 50 + i,
                y + 2 + k,
                L'\u2588',
                0,
                View::Color::BLACK,
                View::Color::BLACK,
                View::Color::BLACK,
                View::Color::BLACK
            );
        }
    }
    for (int k = 0; k <= 3; k++) {
        View::WriteToView(
            x + 1,
            y + 2 + k,
            L'\u2588',
            0,
            View::Color::LIGHT_CYAN,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BRIGHT_WHITE
        );
    }
    for (int k = 0; k <= 3; k++) {
        View::WriteToView(
            x + 15,
            y + 3 + k,
            L'\u2588',
            0,
            View::Color::LIGHT_CYAN,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BRIGHT_WHITE
        );
    }
    for (int k = 0; k <= 3; k++) {
        if (k == 1) {
            continue;
        }
        View::WriteToView(
            x + 22,
            y + 3 + k,
            L'\u2588',
            0,
            View::Color::LIGHT_CYAN,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BRIGHT_WHITE
        );
    }
    for (int k = 0; k <= 5; k++) {
        View::WriteToView(
            x + 29,
            y + 1 + k,
            L'\u2588',
            0,
            View::Color::LIGHT_CYAN,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BRIGHT_WHITE
        );
    }
    for (int k = 0; k <= 3; k++) {
        View::WriteToView(
            x + 43,
            y + 2 + k,
            L'\u2588',
            0,
            View::Color::LIGHT_CYAN,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BRIGHT_WHITE
        );
    }
    for (int k = 0; k <= 1; k++) {
        View::WriteToView(
            x + 50,
            y + 3 + k,
            L'\u2588',
            0,
            View::Color::LIGHT_CYAN,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BRIGHT_WHITE
        );
    }
    View::WriteToView(
        x + 36,
        y + 6,
        L'\u2588',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    for (int k = 0; k <= 1; k++) {
        View::WriteToView(
            x + 5,
            y + 3 + k,
            L'\u2588',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BRIGHT_WHITE
        );
    }
    View::WriteToView(
        x + 12,
        y + 2,
        L'\u2588',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 12,
        y + 5,
        L'\u2588',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    for (int k = 0; k <= 3; k++) {
        if (k == 1) {
            continue;
        }
        View::WriteToView(
            x + 19,
            y + 3 + k,
            L'\u2588',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BRIGHT_WHITE
        );
    }
    for (int k = 0; k <= 3; k++) {
        View::WriteToView(
            x + 26,
            y + 3 + k,
            L'\u2588',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BRIGHT_WHITE
        );
    }
    for (int k = 0; k <= 4; k++) {
        if (k == 2) {
            continue;
        }
        View::WriteToView(
            x + 33,
            y + 2 + k,
            L'\u2588',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BRIGHT_WHITE
        );
    }
    for (int k = 0; k <= 4; k++) {
        if (k == 2 || k == 3) {
            continue;
        }
        View::WriteToView(
            x + 40,
            y + 2 + k,
            L'\u2588',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BRIGHT_WHITE
        );
    }
    for (int k = 0; k <= 1; k++) {
        View::WriteToView(
            x + 47,
            y + 3 + k,
            L'\u2588',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BRIGHT_WHITE
        );
    }
    for (int k = 0; k <= 3; k++) {
        View::WriteToView(
            x + 54,
            y + 2 + k,
            L'\u2588',
            0,
            View::Color::RED,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BRIGHT_WHITE
        );
    }
    View::WriteToView(
        x + 2,
        y + 1,
        L'\u2584',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 15,
        y + 2,
        L'\u2584',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 17,
        y + 1,
        L'\u2584',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 35,
        y + 3,
        L'\u2584',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 44,
        y + 1,
        L'\u2584',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 49,
        y + 5,
        L'\u2584',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 3,
        y + 1,
        L'\u2580',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 16,
        y + 2,
        L'\u2580',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 18,
        y + 1,
        L'\u2580',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 36,
        y + 3,
        L'\u2580',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 45,
        y + 1,
        L'\u2580',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 50,
        y + 5,
        L'\u2580',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 8,
        y + 5,
        L'\u2580',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 2,
        y + 6,
        L'\u2580',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 7,
        y + 2,
        L'\u2580',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 21,
        y + 2,
        L'\u2580',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 35,
        y + 2,
        L'\u2580',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 34,
        y + 5,
        L'\u2580',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 44,
        y + 6,
        L'\u2580',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 7,
        y + 5,
        L'\u2584',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 49,
        y + 2,
        L'\u2580',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 3,
        y + 6,
        L'\u2584',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 8,
        y + 2,
        L'\u2584',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 22,
        y + 2,
        L'\u2584',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 35,
        y + 5,
        L'\u2584',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 36,
        y + 2,
        L'\u2584',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 45,
        y + 6,
        L'\u2584',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 50,
        y + 2,
        L'\u2584',
        0,
        View::Color::LIGHT_CYAN,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 5,
        y + 2,
        L'\u2584',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 10,
        y + 6,
        L'\u2584',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 19,
        y + 2,
        L'\u2584',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 38,
        y + 4,
        L'\u2584',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 47,
        y + 2,
        L'\u2584',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 52,
        y + 6,
        L'\u2584',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 39,
        y + 5,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 47,
        y + 5,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 52,
        y + 1,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 5,
        y + 5,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 10,
        y + 1,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 23,
        y + 1,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 25,
        y + 2,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 38,
        y + 1,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 6,
        y + 5,
        L'\u2584',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 11,
        y + 1,
        L'\u2584',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 24,
        y + 1,
        L'\u2584',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 26,
        y + 2,
        L'\u2584',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 39,
        y + 1,
        L'\u2584',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 40,
        y + 5,
        L'\u2584',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 48,
        y + 5,
        L'\u2584',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 53,
        y + 1,
        L'\u2584',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 6,
        y + 2,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 11,
        y + 6,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 20,
        y + 2,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 39,
        y + 4,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 48,
        y + 2,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 53,
        y + 6,
        L'\u2580',
        0,
        View::Color::RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
}