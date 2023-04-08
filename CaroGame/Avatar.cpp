#include "Avatar.h"

void Logo_AmongUs(int x, int y, View::Color mat, View::Color mau)
{
    View::WriteToView(
        x + 1,
        y + 2,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 1,
        y + 3,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 5,
        y + 2,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 5,
        y + 3,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 8,
        y + 2,
        L'\u2580',
        0,
        View::Color::BLACK,
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
        View::Color::BLACK
    );
    View::WriteToView(
        x + 10,
        y + 2,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 10,
        y + 3,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
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
    View::WriteToView(
        x + 8,
        y + 5,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 2,
        y + 4,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 2,
        y + 5,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 7,
        y + 1,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 5,
        y + 5,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 6,
        y + 2,
        L'\u2580',
        0,
        mau,
        View::Color::BLACK,
        View::Color::BLACK,
        mau
    );
    View::WriteToView(
        x + 6,
        y + 3,
        L'\u2580',
        0,
        mau,
        View::Color::BLACK,
        View::Color::BLACK,
        mau
    );
    View::WriteToView(
        x + 3,
        y + 4,
        L'\u2580',
        0,
        mau,
        View::Color::BLACK,
        View::Color::BLACK,
        mau
    );
    View::WriteToView(
        x + 6,
        y + 4,
        L'\u2580',
        0,
        mau,
        View::Color::BLACK,
        View::Color::BLACK,
        mau
    );
    View::WriteToView(
        x + 7,
        y + 2,
        L'\u2580',
        0,
        mau,
        View::Color::BLACK,
        View::Color::BLACK,
        mau
    );
    View::WriteToView(
        x + 7,
        y + 3,
        L'\u2580',
        0,
        mau,
        View::Color::BLACK,
        View::Color::BLACK,
        mau
    );
    View::WriteToView(
        x + 7,
        y + 4,
        L'\u2580',
        0,
        mau,
        View::Color::BLACK,
        View::Color::BLACK,
        mau
    );
    View::WriteToView(
        x + 9,
        y + 3,
        L'\u2580',
        0,
        mau,
        View::Color::BLACK,
        View::Color::BLACK,
        mau
    );
    View::WriteToView(
        x + 2,
        y + 1,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 8,
        y + 1,
        L'\u2580',
        0,
        View::Color::BRIGHT_WHITE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 2,
        y + 2,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 3,
        y + 2,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 9,
        y + 4,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    View::WriteToView(
        x + 10,
        y + 4,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BRIGHT_WHITE
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 3 + i,
            y + 1,
            L'\u2580',
            0,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK,
            mau
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 2 + i,
            y + 3,
            L'\u2580',
            0,
            mat,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 4 + i,
            y + 4,
            L'\u2580',
            0,
            mau,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 3 + i,
            y + 5,
            L'\u2580',
            0,
            mau,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 6 + i,
            y + 5,
            L'\u2580',
            0,
            mau,
            View::Color::BLACK,
            View::Color::BLACK,
            View::Color::BLACK
        );
    }
    View::WriteToView(
        x + 9,
        y + 2,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        mau
    );
    View::WriteToView(
        x + 4,
        y + 2,
        L'\u2580',
        0,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::BLACK,
        mat
    );
}