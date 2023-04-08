#include "PokemonWhite.h"

void logo_pokemon_white(int x, int y)
{
    View::Color den = View::Color::BLACK;
    View::Color trang = View::Color::BRIGHT_WHITE;
    View::Color do1 = View::Color::LIGHT_RED;
    View::Color do2 = View::Color::RED;
    View::Color xam1 = View::Color::WHITE;
    View::Color xam2 = View::Color::GRAY;

    View::WriteToView(
        x + 4,
        y + 1,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 5,
        y + 1,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 6,
        y + 1,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 7,
        y + 1,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 22,
        y + 1,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 23,
        y + 1,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 2,
        y + 2,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 3,
        y + 2,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 4,
        y + 2,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 5,
        y + 2,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 6,
        y + 2,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 7 + i,
            y + 2,
            L'\u2580',
            0,
            den,
            View::Color::BLACK,
            View::Color::BLACK,
            trang
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 10 + i,
            y + 2,
            L'\u2580',
            0,
            trang,
            View::Color::BLACK,
            View::Color::BLACK,
            den
        );
    }
    View::WriteToView(
        x + 19,
        y + 2,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 20,
        y + 2,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 21,
        y + 2,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 22,
        y + 2,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 23,
        y + 2,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 1,
        y + 3,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 2,
        y + 3,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 3,
        y + 3,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 4,
        y + 3,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 6,
        y + 3,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 12,
        y + 3,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 18,
        y + 3,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 19,
        y + 3,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 20,
        y + 3,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 21,
        y + 3,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 1,
        y + 4,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 2,
        y + 4,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 3,
        y + 4,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 4,
        y + 4,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 6,
        y + 4,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
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
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 11,
        y + 4,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 12,
        y + 4,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
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
        trang
    );
    View::WriteToView(
        x + 15,
        y + 4,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 16,
        y + 4,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 17,
        y + 4,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 18,
        y + 4,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 19,
        y + 4,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 20,
        y + 4,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 21,
        y + 4,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 1,
        y + 5,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 2,
        y + 5,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 3,
        y + 5,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 4,
        y + 5,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 5,
        y + 5,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 6,
        y + 5,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 7,
        y + 5,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        do1
    );
    View::WriteToView(
        x + 8,
        y + 5,
        L'\u2580',
        0,
        do2,
        View::Color::BLACK,
        View::Color::BLACK,
        do2
    );
    View::WriteToView(
        x + 9,
        y + 5,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 10,
        y + 5,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 11,
        y + 5,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 12,
        y + 5,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 13,
        y + 5,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 15,
        y + 5,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 16,
        y + 5,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 18,
        y + 5,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 19,
        y + 5,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 4,
        y + 6,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 5,
        y + 6,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 6,
        y + 6,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 7,
        y + 6,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 8,
        y + 6,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 9,
        y + 6,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 10,
        y + 6,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 11,
        y + 6,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 12,
        y + 6,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 13,
        y + 6,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
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
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 16,
        y + 6,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 20,
        y + 6,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 5,
        y + 7,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 6,
        y + 7,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 7,
        y + 7,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 9,
        y + 7,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 10,
        y + 7,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 11,
        y + 7,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 12,
        y + 7,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 13,
        y + 7,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 14,
        y + 7,
        L'\u2580',
        0,
        trang,
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
        xam1
    );
    View::WriteToView(
        x + 16,
        y + 7,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 17,
        y + 7,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 20,
        y + 7,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 21,
        y + 7,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 22,
        y + 7,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 5,
        y + 8,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 6,
        y + 8,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 7,
        y + 8,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 8,
        y + 8,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 11,
        y + 8,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 12,
        y + 8,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 13,
        y + 8,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 14,
        y + 8,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 15,
        y + 8,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 17,
        y + 8,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 18,
        y + 8,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 19,
        y + 8,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 20,
        y + 8,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 21,
        y + 8,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 22,
        y + 8,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 5,
        y + 9,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 6,
        y + 9,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 7,
        y + 9,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 8,
        y + 9,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 9,
        y + 9,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 10,
        y + 9,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 11,
        y + 9,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 12,
        y + 9,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 13 + i,
            y + 9,
            L'\u2580',
            0,
            xam1,
            View::Color::BLACK,
            View::Color::BLACK,
            xam1
        );
    }
    View::WriteToView(
        x + 16,
        y + 9,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 18,
        y + 9,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 19,
        y + 9,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 20,
        y + 9,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 21,
        y + 9,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 4,
        y + 10,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 5,
        y + 10,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 6,
        y + 10,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 7,
        y + 10,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 8,
        y + 10,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 10,
        y + 10,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 11,
        y + 10,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 12,
        y + 10,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 14,
        y + 10,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 15,
        y + 10,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 19,
        y + 10,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 20,
        y + 10,
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
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 11,
        y + 11,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 12,
        y + 11,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 13,
        y + 11,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 14,
        y + 11,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
}