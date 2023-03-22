#include "Result.h"

void Win(
    int x,
    int y,
    View::Color a1,
    View::Color a2,
    View::Color a3,
    View::Color a4,
    View::Color a5
)
{
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 1,
            L'\u2584',
            0,
            a1,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 11 + i,
            y + 1,
            L'\u2584',
            0,
            a1,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    for (int i = 0; i < 6; i++) {
        View::WriteToView(
            x + 15 + i,
            y + 1,
            L'\u2584',
            0,
            a1,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 23 + i,
            y + 1,
            L'\u2584',
            0,
            a1,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 29 + i,
            y + 1,
            L'\u2584',
            0,
            a1,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 11 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 17 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 23 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 25 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 29 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 11 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 6 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    View::WriteToView(
        x + 5,
        y + 3,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a3
    );
    View::WriteToView(
        x + 8,
        y + 3,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a3
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 17 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 23 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 26 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 29 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    View::WriteToView(
        x + 2,
        y + 4,
        L'\u2580',
        0,
        a4,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 11,
        y + 4,
        L'\u2580',
        0,
        a4,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 4,
        y + 4,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a4
    );
    View::WriteToView(
        x + 9,
        y + 4,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a4
    );
    View::WriteToView(
        x + 3,
        y + 4,
        L'\u2584',
        0,
        a4,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a4
    );
    View::WriteToView(
        x + 10,
        y + 4,
        L'\u2584',
        0,
        a4,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a4
    );
    View::WriteToView(
        x + 5,
        y + 4,
        L'\u2584',
        0,
        a4,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a4
    );
    View::WriteToView(
        x + 8,
        y + 4,
        L'\u2584',
        0,
        a4,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a4
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 6 + i,
            y + 4,
            L'\u2580',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BRIGHT_WHITE
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 17 + i,
            y + 4,
            L'\u2584',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 23 + i,
            y + 4,
            L'\u2584',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 27 + i,
            y + 4,
            L'\u2584',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 29 + i,
            y + 4,
            L'\u2584',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 4 + i,
            y + 5,
            L'\u2584',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 8 + i,
            y + 5,
            L'\u2584',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
    for (int i = 0; i < 6; i++) {
        View::WriteToView(
            x + 15 + i,
            y + 5,
            L'\u2584',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 23 + i,
            y + 5,
            L'\u2584',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 29 + i,
            y + 5,
            L'\u2584',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
}

void Lose(
    int x,
    int y,
    View::Color a1,
    View::Color a2,
    View::Color a3,
    View::Color a4,
    View::Color a5
)
{
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 1,
            L'\u2584',
            0,
            a1,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    View::WriteToView(
        x + 10,
        y + 1,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a1
    );
    View::WriteToView(
        x + 15,
        y + 1,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a1
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 11 + i,
            y + 1,
            L'\u2584',
            0,
            a1,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    View::WriteToView(
        x + 20,
        y + 1,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a1
    );
    View::WriteToView(
        x + 25,
        y + 1,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a1
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 21 + i,
            y + 1,
            L'\u2584',
            0,
            a1,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    for (int i = 0; i < 7; i++) {
        View::WriteToView(
            x + 28 + i,
            y + 1,
            L'\u2584',
            0,
            a1,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    for (int i = 0; i < 6; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 5,
            L'\u2584',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
    View::WriteToView(
        x + 10,
        y + 5,
        L'\u2580',
        0,
        a5,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 15,
        y + 5,
        L'\u2580',
        0,
        a5,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 11 + i,
            y + 5,
            L'\u2584',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
    View::WriteToView(
        x + 19,
        y + 5,
        L'\u2580',
        0,
        a5,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 25,
        y + 5,
        L'\u2580',
        0,
        a5,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    for (int i = 0; i < 5; i++) {
        View::WriteToView(
            x + 20 + i,
            y + 5,
            L'\u2584',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
    for (int i = 0; i < 7; i++) {
        View::WriteToView(
            x + 28 + i,
            y + 5,
            L'\u2584',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 4,
            L'\u2584',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 9 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 9 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 9 + i,
            y + 4,
            L'\u2584',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 15 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 15 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 15 + i,
            y + 4,
            L'\u2584',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 28 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 5; i++) {
        View::WriteToView(
            x + 28 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 28 + i,
            y + 4,
            L'\u2584',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 5 + i,
            y + 4,
            L'\u2580',
            0,
            View::Color::BRIGHT_WHITE,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 19 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 23 + i,
            y + 4,
            L'\u2584',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 21 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    View::WriteToView(
        x + 20,
        y + 3,
        L'\u2580',
        0,
        a3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 24,
        y + 3,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a3
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 19 + i,
            y + 4,
            L'\u2580',
            0,
            View::Color::BRIGHT_WHITE,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 24 + i,
            y + 2,
            L'\u2580',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BRIGHT_WHITE
        );
    }
}

void Draw(
    int x,
    int y,
    View::Color a1,
    View::Color a2,
    View::Color a3,
    View::Color a4,
    View::Color a5
)
{
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 1,
            L'\u2584',
            0,
            a1,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 4,
            L'\u2584',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 1 + i,
            y + 5,
            L'\u2584',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 6 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 6 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 6 + i,
            y + 4,
            L'\u2584',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 10 + i,
            y + 1,
            L'\u2584',
            0,
            a1,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 10 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 10 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 10 + i,
            y + 4,
            L'\u2584',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 10 + i,
            y + 5,
            L'\u2584',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 19 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 19 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 19 + i,
            y + 4,
            L'\u2584',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 19 + i,
            y + 5,
            L'\u2584',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 25 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 25 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 25 + i,
            y + 4,
            L'\u2584',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 25 + i,
            y + 5,
            L'\u2584',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 29 + i,
            y + 1,
            L'\u2584',
            0,
            a1,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 29 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 29 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 37 + i,
            y + 1,
            L'\u2584',
            0,
            a1,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 37 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 37 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 3 + i,
            y + 1,
            L'\u2584',
            0,
            a1,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 6 + i,
            y + 1,
            L'\u2580',
            0,
            View::Color::BRIGHT_WHITE,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 12 + i,
            y + 1,
            L'\u2584',
            0,
            a1,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    for (int i = 0; i < 1; i++) {
        View::WriteToView(
            x + 15 + i,
            y + 1,
            L'\u2580',
            0,
            View::Color::BRIGHT_WHITE,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    View::WriteToView(
        x + 20,
        y + 1,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a1
    );
    View::WriteToView(
        x + 25,
        y + 1,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a1
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 21 + i,
            y + 1,
            L'\u2584',
            0,
            a1,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a1
        );
    }
    View::WriteToView(
        x + 5,
        y + 2,
        L'\u2580',
        0,
        a2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 24,
        y + 2,
        L'\u2580',
        0,
        a2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 21,
        y + 2,
        L'\u2580',
        0,
        a2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 14,
        y + 2,
        L'\u2580',
        0,
        a2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 15 + i,
            y + 2,
            L'\u2584',
            0,
            a2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a2
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 12 + i,
            y + 3,
            L'\u2580',
            0,
            View::Color::BRIGHT_WHITE,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 21 + i,
            y + 3,
            L'\u2580',
            0,
            View::Color::BRIGHT_WHITE,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 14 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 1; i++) {
        View::WriteToView(
            x + 16 + i,
            y + 3,
            L'\u2580',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BRIGHT_WHITE
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 29 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 33 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 37 + i,
            y + 3,
            L'\u2584',
            0,
            a3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a3
        );
    }
    View::WriteToView(
        x + 32,
        y + 3,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a3
    );
    View::WriteToView(
        x + 35,
        y + 3,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a3
    );
    View::WriteToView(
        x + 5,
        y + 4,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a4
    );
    View::WriteToView(
        x + 12,
        y + 4,
        L'\u2580',
        0,
        a4,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 13 + i,
            y + 4,
            L'\u2580',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a4
        );
    }
    View::WriteToView(
        x + 15,
        y + 4,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a4
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 21 + i,
            y + 4,
            L'\u2580',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BRIGHT_WHITE
        );
    }
    View::WriteToView(
        x + 29,
        y + 4,
        L'\u2580',
        0,
        a4,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 38,
        y + 4,
        L'\u2580',
        0,
        a4,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 31,
        y + 4,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a4
    );
    View::WriteToView(
        x + 36,
        y + 4,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a4
    );
    View::WriteToView(
        x + 30,
        y + 4,
        L'\u2580',
        0,
        a4,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a4
    );
    View::WriteToView(
        x + 32,
        y + 4,
        L'\u2580',
        0,
        a4,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a4
    );
    View::WriteToView(
        x + 35,
        y + 4,
        L'\u2580',
        0,
        a4,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a4
    );
    View::WriteToView(
        x + 37,
        y + 4,
        L'\u2580',
        0,
        a4,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        a4
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 33 + i,
            y + 4,
            L'\u2580',
            0,
            a4,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BRIGHT_WHITE
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 3 + i,
            y + 5,
            L'\u2580',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 6 + i,
            y + 5,
            L'\u2580',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            View::Color::BRIGHT_WHITE
        );
    }
    View::WriteToView(
        x + 14,
        y + 5,
        L'\u2580',
        0,
        a5,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 15 + i,
            y + 5,
            L'\u2580',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 31 + i,
            y + 5,
            L'\u2580',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 35 + i,
            y + 5,
            L'\u2580',
            0,
            a5,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            a5
        );
    }
    View::WriteToView(
        x + 30,
        y + 5,
        L'\u2580',
        0,
        a5,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 37,
        y + 5,
        L'\u2580',
        0,
        a5,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        View::Color::BRIGHT_WHITE
    );
}

void Logo_Draw(
    int x,
    int y,
    View::Color a1,
    View::Color a2,
    View::Color a3,
    View::Color a4,
    View::Color a5
)
{
    while (true) {
        Sleep(250);
        Draw(x, y, a1, a2, a3, a4, a5);
        Sleep(250);
        Draw(x, y, a2, a3, a4, a5, a1);
        Sleep(250);
        Draw(x, y, a3, a4, a5, a1, a2);
        Sleep(250);
        Draw(x, y, a4, a5, a1, a2, a3);
        Sleep(250);
        Draw(x, y, a5, a1, a2, a3, a4);
    }
}

void Logo_Win(
    int x,
    int y,
    View::Color a1,
    View::Color a2,
    View::Color a3,
    View::Color a4,
    View::Color a5
)
{
    while (true) {
        Sleep(250);
        Win(x, y, a1, a2, a3, a4, a5);
        Sleep(250);
        Win(x, y, a2, a3, a4, a5, a1);
        Sleep(250);
        Win(x, y, a3, a4, a5, a1, a2);
        Sleep(250);
        Win(x, y, a4, a5, a1, a2, a3);
        Sleep(250);
        Win(x, y, a5, a1, a2, a3, a4);
    }
}

void Logo_Lose(
    int x,
    int y,
    View::Color a1,
    View::Color a2,
    View::Color a3,
    View::Color a4,
    View::Color a5
)
{
    while (true) {
        Sleep(250);
        Lose(x, y, a1, a2, a3, a4, a5);
        Sleep(250);
        Lose(x, y, a2, a3, a4, a5, a1);
        Sleep(250);
        Lose(x, y, a3, a4, a5, a1, a2);
        Sleep(250);
        Lose(x, y, a4, a5, a1, a2, a3);
        Sleep(250);
        Lose(x, y, a5, a1, a2, a3, a4);
    }
}