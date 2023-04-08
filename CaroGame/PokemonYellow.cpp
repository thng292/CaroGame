#include "PokemonYellow.h"

void logo_pokemon_yellow(int x, int y)
{
    View::Color den = View::Color::BLACK;
    View::Color trang = View::Color::BRIGHT_WHITE;
    View::Color vang = View::Color::LIGHT_YELLOW;
    View::Color nau = View::Color::YELLOW;
    View::Color doo = View::Color::LIGHT_RED;
    View::WriteToView(
        x + 5,
        y + 2,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 6,
        y + 2,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 7,
        y + 2,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 16,
        y + 2,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 17,
        y + 2,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 18,
        y + 2,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 4,
        y + 3,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 5,
        y + 3,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 6,
        y + 3,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 7,
        y + 3,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 12 + i,
            y + 3,
            L'\u2580',
            0,
            trang,
            View::Color::BLACK,
            View::Color::BLACK,
            den
        );
    }
    View::WriteToView(
        x + 15,
        y + 3,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 16,
        y + 3,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 17,
        y + 3,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 18,
        y + 3,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 19,
        y + 3,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 3,
        y + 4,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 4,
        y + 4,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 5,
        y + 4,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 6,
        y + 4,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 7,
        y + 4,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 8,
        y + 4,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 9,
        y + 4,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 10,
        y + 4,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 11,
        y + 4,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 12,
        y + 4,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 13,
        y + 4,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 14,
        y + 4,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 15,
        y + 4,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 16,
        y + 4,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 17,
        y + 4,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 18,
        y + 4,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 1,
        y + 5,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 2,
        y + 5,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    for (int i = 0; i < 8; i++) {
        View::WriteToView(
            x + 3 + i,
            y + 5,
            L'\u2580',
            0,
            vang,
            View::Color::BLACK,
            View::Color::BLACK,
            vang
        );
    }
    View::WriteToView(
        x + 11,
        y + 5,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 12,
        y + 5,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 13,
        y + 5,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 14,
        y + 5,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 15,
        y + 5,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 16,
        y + 5,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 17,
        y + 5,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 1,
        y + 6,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 2,
        y + 6,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 3 + i,
            y + 6,
            L'\u2580',
            0,
            vang,
            View::Color::BLACK,
            View::Color::BLACK,
            vang
        );
    }
    View::WriteToView(
        x + 6,
        y + 6,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 7,
        y + 6,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 8 + i,
            y + 6,
            L'\u2580',
            0,
            vang,
            View::Color::BLACK,
            View::Color::BLACK,
            vang
        );
    }
    View::WriteToView(
        x + 12,
        y + 6,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 13,
        y + 6,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 14,
        y + 6,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 15,
        y + 6,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 16,
        y + 6,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 17,
        y + 6,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 2,
        y + 7,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 3,
        y + 7,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 4,
        y + 7,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 5,
        y + 7,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 6,
        y + 7,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 7,
        y + 7,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 8,
        y + 7,
        L'\u2580',
        0,
        doo,
        View::Color::BLACK,
        View::Color::BLACK,
        doo
    );
    View::WriteToView(
        x + 9,
        y + 7,
        L'\u2580',
        0,
        doo,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 10,
        y + 7,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 11,
        y + 7,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 12,
        y + 7,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 13,
        y + 7,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 14,
        y + 7,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 15,
        y + 7,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 4,
        y + 7,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        doo
    );
    View::WriteToView(
        x + 2,
        y + 8,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 3,
        y + 8,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 4,
        y + 8,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    for (int i = 0; i < 5; i++) {
        View::WriteToView(
            x + 5 + i,
            y + 8,
            L'\u2580',
            0,
            nau,
            View::Color::BLACK,
            View::Color::BLACK,
            vang
        );
    }
    View::WriteToView(
        x + 10,
        y + 8,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 11,
        y + 8,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 12,
        y + 8,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 13,
        y + 8,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 14,
        y + 8,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 3,
        y + 9,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 4,
        y + 9,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 5,
        y + 9,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 6 + i,
            y + 9,
            L'\u2580',
            0,
            vang,
            View::Color::BLACK,
            View::Color::BLACK,
            nau
        );
    }
    View::WriteToView(
        x + 9,
        y + 9,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 10,
        y + 9,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 11 + i,
            y + 9,
            L'\u2580',
            0,
            nau,
            View::Color::BLACK,
            View::Color::BLACK,
            nau
        );
    }
    View::WriteToView(
        x + 14,
        y + 9,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    for (int i = 0; i < 5; i++) {
        View::WriteToView(
            x + 3 + i,
            y + 10,
            L'\u2580',
            0,
            den,
            View::Color::BLACK,
            View::Color::BLACK,
            trang
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 8 + i,
            y + 10,
            L'\u2580',
            0,
            nau,
            View::Color::BLACK,
            View::Color::BLACK,
            den
        );
    }
    View::WriteToView(
        x + 11,
        y + 10,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 12,
        y + 10,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 13,
        y + 10,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 9,
        y + 11,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 10,
        y + 11,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 11,
        y + 11,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 12,
        y + 11,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 13,
        y + 11,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
}