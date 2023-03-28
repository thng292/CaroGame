#include "PokemonGreen.h"

void logo_pokemon_green(int x, int y)
{
    View::Color xanh1 = View::Color::LIGHT_GREEN;
    View::Color xanh2 = View ::Color::GREEN;
    View::Color xanh3 = View::Color::LIGHT_CYAN;
    View::Color den = View::Color::BLACK;
    View::Color trang = View::Color::BRIGHT_WHITE;
    View::Color hong1 = View::Color::LIGHT_MAGENTA;
    View::Color hong2 = View::Color::MAGENTA;
    View::Color doo1 = View::Color::LIGHT_RED;
    View::Color doo2 = View::Color::RED;

    View::WriteToView(
        x + 10,
        y + 2,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 11,
        y + 2,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        doo2
    );
    View::WriteToView(
        x + 12,
        y + 2,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        hong1
    );
    View::WriteToView(
        x + 13,
        y + 2,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        hong1
    );
    View::WriteToView(
        x + 14,
        y + 2,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 9,
        y + 3,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 10,
        y + 3,
        L'\u2580',
        0,
        hong2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        hong1
    );
    View::WriteToView(
        x + 11,
        y + 3,
        L'\u2580',
        0,
        hong1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        hong2
    );
    View::WriteToView(
        x + 12,
        y + 3,
        L'\u2580',
        0,
        doo2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        doo2
    );
    View::WriteToView(
        x + 13,
        y + 3,
        L'\u2580',
        0,
        hong1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        hong1
    );
    View::WriteToView(
        x + 14,
        y + 3,
        L'\u2580',
        0,
        hong1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        hong1
    );
    View::WriteToView(
        x + 15,
        y + 3,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 16 + i,
            y + 3,
            L'\u2580',
            0,
            trang,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            den
        );
    }
    View::WriteToView(
        x + 4,
        y + 4,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 6,
        y + 4,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 7,
        y + 4,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 8,
        y + 4,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 9,
        y + 4,
        L'\u2580',
        0,
        hong2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        hong2
    );
    View::WriteToView(
        x + 10,
        y + 4,
        L'\u2580',
        0,
        hong1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        hong2
    );
    View::WriteToView(
        x + 11,
        y + 4,
        L'\u2580',
        0,
        doo2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        doo2
    );
    View::WriteToView(
        x + 12,
        y + 4,
        L'\u2580',
        0,
        hong1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        hong2
    );
    View::WriteToView(
        x + 13,
        y + 4,
        L'\u2580',
        0,
        hong1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        hong2
    );
    View::WriteToView(
        x + 14,
        y + 4,
        L'\u2580',
        0,
        hong2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        hong2
    );
    View::WriteToView(
        x + 15,
        y + 4,
        L'\u2580',
        0,
        hong2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        hong2
    );
    View::WriteToView(
        x + 16,
        y + 4,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 17,
        y + 4,
        L'\u2580',
        0,
        xanh1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 18,
        y + 4,
        L'\u2580',
        0,
        xanh1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 19,
        y + 4,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 3,
        y + 5,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 4,
        y + 5,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 5,
        y + 5,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 6,
        y + 5,
        L'\u2580',
        0,
        xanh1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 7,
        y + 5,
        L'\u2580',
        0,
        xanh1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 8,
        y + 5,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh1
    );
    View::WriteToView(
        x + 9,
        y + 5,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh1
    );
    View::WriteToView(
        x + 10,
        y + 5,
        L'\u2580',
        0,
        hong2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 11,
        y + 5,
        L'\u2580',
        0,
        doo2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        hong2
    );
    View::WriteToView(
        x + 12,
        y + 5,
        L'\u2580',
        0,
        hong2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        hong2
    );
    View::WriteToView(
        x + 13,
        y + 5,
        L'\u2580',
        0,
        hong2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 14,
        y + 5,
        L'\u2580',
        0,
        hong2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 15,
        y + 5,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 16,
        y + 5,
        L'\u2580',
        0,
        xanh1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 17,
        y + 5,
        L'\u2580',
        0,
        xanh1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 18,
        y + 5,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh1
    );
    View::WriteToView(
        x + 19,
        y + 5,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh1
    );
    View::WriteToView(
        x + 20,
        y + 5,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 2,
        y + 6,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 3,
        y + 6,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 4,
        y + 6,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 5,
        y + 6,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 6,
        y + 6,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 7,
        y + 6,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 8,
        y + 6,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 9,
        y + 6,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 10,
        y + 6,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 11,
        y + 6,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 12,
        y + 6,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 13,
        y + 6,
        L'\u2580',
        0,
        xanh1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 14,
        y + 6,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh1
    );
    View::WriteToView(
        x + 15,
        y + 6,
        L'\u2580',
        0,
        xanh1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh1
    );
    View::WriteToView(
        x + 16,
        y + 6,
        L'\u2580',
        0,
        xanh1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 17,
        y + 6,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh1
    );
    View::WriteToView(
        x + 18,
        y + 6,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh1
    );
    View::WriteToView(
        x + 19,
        y + 6,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 20,
        y + 6,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh1
    );
    View::WriteToView(
        x + 21,
        y + 6,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 1,
        y + 7,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 2,
        y + 7,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        doo1
    );
    View::WriteToView(
        x + 3,
        y + 7,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 4,
        y + 7,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 5,
        y + 7,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 6,
        y + 7,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 7,
        y + 7,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 8,
        y + 7,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 9,
        y + 7,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 10 + i,
            y + 7,
            L'\u2580',
            0,
            xanh3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            xanh3
        );
    }
    View::WriteToView(
        x + 13,
        y + 7,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 14,
        y + 7,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 15,
        y + 7,
        L'\u2580',
        0,
        xanh1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 16,
        y + 7,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 17,
        y + 7,
        L'\u2580',
        0,
        xanh1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 18,
        y + 7,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 19,
        y + 7,
        L'\u2580',
        0,
        xanh1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh1
    );
    View::WriteToView(
        x + 20,
        y + 7,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh1
    );
    View::WriteToView(
        x + 21,
        y + 7,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 1,
        y + 8,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 2,
        y + 8,
        L'\u2580',
        0,
        doo1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 3 + i,
            y + 8,
            L'\u2580',
            0,
            xanh3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            xanh3
        );
    }
    View::WriteToView(
        x + 6,
        y + 8,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 7,
        y + 8,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 8,
        y + 8,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 9,
        y + 8,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 10,
        y + 8,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 11,
        y + 8,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 12,
        y + 8,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 13,
        y + 8,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 14,
        y + 8,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 15,
        y + 8,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 16,
        y + 8,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 17,
        y + 8,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 18,
        y + 8,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 19,
        y + 8,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 20,
        y + 8,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 21,
        y + 8,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 2,
        y + 9,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 3,
        y + 9,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 4,
        y + 9,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 5,
        y + 9,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 6,
        y + 9,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 7,
        y + 9,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        doo1
    );
    View::WriteToView(
        x + 8,
        y + 9,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        doo1
    );
    View::WriteToView(
        x + 10,
        y + 9,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 11,
        y + 9,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 12,
        y + 9,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 13,
        y + 9,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 14,
        y + 9,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 15,
        y + 9,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 16,
        y + 9,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 17,
        y + 9,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 18,
        y + 9,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    View::WriteToView(
        x + 19,
        y + 9,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 20,
        y + 9,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 3,
        y + 10,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 4,
        y + 10,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 5 + i,
            y + 10,
            L'\u2580',
            0,
            xanh2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            den
        );
    }
    View::WriteToView(
        x + 8,
        y + 10,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 9,
        y + 10,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 10,
        y + 10,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 11,
        y + 10,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh2
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 12 + i,
            y + 10,
            L'\u2580',
            0,
            xanh2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            xanh2
        );
    }
    View::WriteToView(
        x + 15,
        y + 10,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 17,
        y + 10,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 18,
        y + 10,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 19,
        y + 10,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 7,
        y + 11,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 8,
        y + 11,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 10,
        y + 11,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 11,
        y + 11,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 12,
        y + 11,
        L'\u2580',
        0,
        xanh2,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 13,
        y + 11,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 14,
        y + 11,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
}