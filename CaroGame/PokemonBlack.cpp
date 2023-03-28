#include "PokemonBlack.h"

void logo_pokemon_black(int x, int y)
{
    View::Color den = View::Color::BLACK;
    View::Color trang = View::Color::BRIGHT_WHITE;
    View::Color vang = View::Color::LIGHT_YELLOW;
    View::Color nau = View::Color::YELLOW;
    View::Color doo = View::Color::LIGHT_RED;
    View::Color xam = View::Color::GRAY;

    View::WriteToView(
        x + 1,
        y + 2,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 2,
        y + 2,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 3,
        y + 2,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 12 + i,
            y + 2,
            L'\u2580',
            0,
            trang,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            den
        );
    }
    View::WriteToView(
        x + 1,
        y + 3,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 2,
        y + 3,
        L'\u2580',
        0,
        vang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        vang
    );
    View::WriteToView(
        x + 3,
        y + 3,
        L'\u2580',
        0,
        vang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 4,
        y + 3,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 5,
        y + 3,
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
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 10,
        y + 3,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        vang
    );
    View::WriteToView(
        x + 11,
        y + 3,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        vang
    );
    View::WriteToView(
        x + 12,
        y + 3,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 13,
        y + 3,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 14,
        y + 3,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 18,
        y + 3,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 19 + i,
            y + 3,
            L'\u2580',
            0,
            den,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            den
        );
    }
    View::WriteToView(
        x + 1,
        y + 4,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 2,
        y + 4,
        L'\u2580',
        0,
        nau,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 3,
        y + 4,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 4,
        y + 4,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 5,
        y + 4,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        vang
    );
    View::WriteToView(
        x + 6,
        y + 4,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        nau
    );
    View::WriteToView(
        x + 7,
        y + 4,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
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
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 10,
        y + 4,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 11,
        y + 4,
        L'\u2580',
        0,
        vang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        nau
    );
    View::WriteToView(
        x + 12,
        y + 4,
        L'\u2580',
        0,
        vang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 13,
        y + 4,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 16,
        y + 4,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 17,
        y + 4,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        nau
    );
    View::WriteToView(
        x + 18,
        y + 4,
        L'\u2580',
        0,
        vang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        vang
    );
    View::WriteToView(
        x + 19,
        y + 4,
        L'\u2580',
        0,
        nau,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        vang
    );
    View::WriteToView(
        x + 20,
        y + 4,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        nau
    );
    View::WriteToView(
        x + 21,
        y + 4,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 2,
        y + 5,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 3,
        y + 5,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 4,
        y + 5,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 5,
        y + 5,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        vang
    );
    View::WriteToView(
        x + 6,
        y + 5,
        L'\u2580',
        0,
        vang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 7,
        y + 5,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 8,
        y + 5,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 9,
        y + 5,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 10,
        y + 5,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 11,
        y + 5,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 13 + i,
            y + 5,
            L'\u2580',
            0,
            trang,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            den
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 16 + i,
            y + 5,
            L'\u2580',
            0,
            den,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            den
        );
    }
    View::WriteToView(
        x + 19,
        y + 5,
        L'\u2580',
        0,
        vang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 20,
        y + 5,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 2,
        y + 6,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 3,
        y + 6,
        L'\u2580',
        0,
        vang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 4,
        y + 6,
        L'\u2580',
        0,
        vang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 5,
        y + 6,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 6,
        y + 6,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 7,
        y + 6,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        doo
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
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    for (int i = 0; i < 7; i++) {
        View::WriteToView(
            x + 10 + i,
            y + 6,
            L'\u2580',
            0,
            den,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            den
        );
    }
    View::WriteToView(
        x + 17,
        y + 6,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 18,
        y + 6,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 2,
        y + 7,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 3,
        y + 7,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 4,
        y + 7,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 5,
        y + 7,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 6,
        y + 7,
        L'\u2580',
        0,
        doo,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 7,
        y + 7,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 8,
        y + 7,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 9,
        y + 7,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    for (int i = 0; i < 5; i++) {
        View::WriteToView(
            x + 10 + i,
            y + 7,
            L'\u2580',
            0,
            den,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            den
        );
    }
    View::WriteToView(
        x + 15,
        y + 7,
        L'\u2580',
        0,
        nau,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        nau
    );
    View::WriteToView(
        x + 16,
        y + 7,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 17,
        y + 7,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 4,
        y + 8,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 5,
        y + 8,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 6,
        y + 8,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 7,
        y + 8,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 8,
        y + 8,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 9,
        y + 8,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 10,
        y + 8,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    for (int i = 0; i < 5; i++) {
        View::WriteToView(
            x + 11 + i,
            y + 8,
            L'\u2580',
            0,
            den,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            den
        );
    }
    View::WriteToView(
        x + 16,
        y + 8,
        L'\u2580',
        0,
        nau,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 17,
        y + 8,
        L'\u2580',
        0,
        den,
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
        x + 5,
        y + 9,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 6,
        y + 9,
        L'\u2580',
        0,
        den,
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
        den
    );
    View::WriteToView(
        x + 8,
        y + 9,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 9,
        y + 9,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 10,
        y + 9,
        L'\u2580',
        0,
        xam,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam
    );
    View::WriteToView(
        x + 11,
        y + 9,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        nau
    );
    View::WriteToView(
        x + 12,
        y + 9,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
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
        trang
    );
    View::WriteToView(
        x + 15,
        y + 9,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 16 + i,
            y + 9,
            L'\u2580',
            0,
            den,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            den
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 4 + i,
            y + 10,
            L'\u2580',
            0,
            den,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            den
        );
    }
    View::WriteToView(
        x + 7,
        y + 10,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 10,
        y + 10,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 11,
        y + 10,
        L'\u2580',
        0,
        nau,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 12,
        y + 10,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 16,
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
        den
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
        x + 10,
        y + 11,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 11,
        y + 11,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 12,
        y + 11,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
}