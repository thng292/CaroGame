#include "Gura.h"

void luot(int x, int y)
{
    View::WriteToView(
        x + 1,
        y + 1,
        L'\u2580',
        0,
        View::Color::LIGHT_RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::LIGHT_BLUE
    );
    View::WriteToView(
        x + 3,
        y + 1,
        L'\u2580',
        0,
        View::Color::LIGHT_RED,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::LIGHT_BLUE
    );
    View::WriteToView(
        x + 2,
        y + 2,
        L'\u2580',
        0,
        View::Color::LIGHT_BLUE,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 3,
        y + 2,
        L'\u2580',
        0,
        View::Color::LIGHT_RED,
        View::Color::BLACK,
        View::Color::BLACK
    );
    View::WriteToView(
        x + 2,
        y + 1,
        L'\u2580',
        0,
        View::Color::LIGHT_BLUE,
        View::Color::BLACK,
        View::Color::BLACK,
        View::Color::LIGHT_RED
    );

    View::WriteToView(
        x + 1,
        y + 2,
        L'\u2580',
        0,
        View::Color::LIGHT_RED,
        View::Color::BLACK,
        View::Color::BLACK
    );
}

void xoaluot(int x, int y)
{
    View::WriteToView(
        x + 1,
        y + 1,
        L' '
    );
    View::WriteToView(
        x + 3,
        y + 1,
        L' '
    );
    View::WriteToView(
        x + 2,
        y + 2,
        L' '
    );
    View::WriteToView(
        x + 3,
        y + 2,
        L' '
    );
    View::WriteToView(
        x + 2,
        y + 1,
        L' '
    );

    View::WriteToView(
        x + 1,
        y + 2,
        L' '
    );
}

void logoGura(int x, int y) {
    View::Color xanh2 = View::Color::CYAN;
    View::Color xanh1 = View ::Color::LIGHT_BLUE;
    View::Color xanh3 = View::Color::BLUE;
    View::Color den = View::Color::BLACK;
    View::Color trang = View::Color::BRIGHT_WHITE;
    View::Color vang = View::Color::LIGHT_YELLOW;
    View::Color nau = View::Color::YELLOW;
    View::Color xam1 = View::Color::WHITE;
    View::Color xam2 = View::Color::GRAY;
    View::Color la = View::Color::LIGHT_CYAN;
    View::Color hong = View::Color::LIGHT_RED;

    
    View::WriteToView(
        x + 8,
        y + 1,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 9,
        y + 1,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    for (int i = 0; i < 5; i++) {
        View::WriteToView(
            x + 10 + i,
            y + 1,
            L'\u2580',
            0,
            den,
            View::Color::BLACK,
            View::Color::BLACK,
            xanh3
        );
    }
    View::WriteToView(
        x + 15,
        y + 1,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 16,
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
        xanh3
    );
    x++;
    View::WriteToView(
        x + 6,
        y + 2,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    
    for (int i = 0; i < 6; i++) {
        View::WriteToView(
            x + 7 + i,
            y + 2,
            L'\u2580',
            0,
            xanh3,
            View::Color::BLACK,
            View::Color::BLACK,
            xanh3
        );
    }
    View::WriteToView(
        x + 13,
        y + 2,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 14 + i,
            y + 2,
            L'\u2580',
            0,
            xanh3,
            View::Color::BLACK,
            View::Color::BLACK,
            xanh3
        );
    }
    View::WriteToView(
        x + 16,
        y + 2,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    View::WriteToView(
        x + 17,
        y + 2,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
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
    x--;
    View::WriteToView(
        x + 4,
        y + 3,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 5,
        y + 3,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    View::WriteToView(
        x + 6,
        y + 3,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 7,
        y + 3,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 8,
        y + 3,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 9,
        y + 3,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 10,
        y + 3,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 11,
        y + 3,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 12,
        y + 3,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    for (int i = 0; i < 7; i++) {
        View::WriteToView(
            x + 13 + i,
            y + 3,
            L'\u2580',
            0,
            xanh3,
            View::Color::BLACK,
            View::Color::BLACK,
            xanh3
        );
    }
    View::WriteToView(
        x + 20,
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
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 4,
        y + 4,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    View::WriteToView(
        x + 5,
        y + 4,
        L'\u2580',
        0,
       trang,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 6,
        y + 4,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 7,
        y + 4,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    for (int i = 0; i < 5; i++) {
        View::WriteToView(
            x + 8 + i,
            y + 4,
            L'\u2580',
            0,
            xam1,
            View::Color::BLACK,
            View::Color::BLACK,
            xam1
        );
    }
    View::WriteToView(
        x + 13,
        y + 4,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 14,
        y + 4,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    for (int i = 0; i < 6; i++) {
        View::WriteToView(
            x + 15 + i,
            y + 4,
            L'\u2580',
            0,
            xanh3,
            View::Color::BLACK,
            View::Color::BLACK,
            xanh3
        );
    }
    View::WriteToView(
        x + 21,
        y + 4,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    View::WriteToView(
        x + 22,
        y + 4,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        den
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
        xanh3
    );
    View::WriteToView(
        x + 3,
        y + 5,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    View::WriteToView(
        x + 4,
        y + 5,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 5,
        y + 5,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        la
    );
    View::WriteToView(
        x + 6,
        y + 5,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 7,
        y + 5,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 8,
        y + 5,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        la
    );
    for (int i = 0; i < 6; i++) {
        View::WriteToView(
            x + 9 + i,
            y + 5,
            L'\u2580',
            0,
            xam1,
            View::Color::BLACK,
            View::Color::BLACK,
            xam1
        );
    }
    View::WriteToView(
        x + 15,
        y + 5,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    for (int i = 0; i < 7; i++) {
        View::WriteToView(
            x + 16 + i,
            y + 5,
            L'\u2580',
            0,
            xanh3,
            View::Color::BLACK,
            View::Color::BLACK,
            xanh3
        );
    }
    View::WriteToView(
        x + 23,
        y + 5,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 24,
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
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    View::WriteToView(
        x + 2,
        y + 6,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    View::WriteToView(
        x + 3,
        y + 6,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 4,
        y + 6,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh2
    );
    View::WriteToView(
        x + 5,
        y + 6,
        L'\u2580',
        0,
        la,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 6,
        y + 6,
        L'\u2580',
        0,
        xam1,
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
        vang
    );
    View::WriteToView(
        x + 8,
        y + 6,
        L'\u2580',
        0,
        xanh2,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh2
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 9 + i,
            y + 6,
            L'\u2580',
            0,
            xam1,
            View::Color::BLACK,
            View::Color::BLACK,
            xam1
        );
    }
    View::WriteToView(
        x + 12,
        y + 6,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 13,
        y + 6,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        xam2
    );
    View::WriteToView(
        x + 14,
        y + 6,
        L'\u2580',
        0,
        xanh2,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh2
    );
    View::WriteToView(
        x + 15,
        y + 6,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 16,
        y + 6,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 17,
        y + 6,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    for (int i = 0; i < 7; i++) {
        View::WriteToView(
            x + 18 + i,
            y + 6,
            L'\u2580',
            0,
            xanh3,
            View::Color::BLACK,
            View::Color::BLACK,
            xanh3
        );
    }
    View::WriteToView(
        x + 1,
        y + 7,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    View::WriteToView(
        x + 2,
        y + 7,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh1
    );
    View::WriteToView(
        x + 3,
        y + 7,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 4,
        y + 7,
        L'\u2580',
        0,
        xanh2,
        View::Color::BLACK,
        View::Color::BLACK,
        la
    );
    View::WriteToView(
        x + 5,
        y + 7,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 6,
        y + 7,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 7,
        y + 7,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 8,
        y + 7,
        L'\u2580',
        0,
        xanh2,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 9,
        y + 7,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh2
    );
    View::WriteToView(
        x + 10,
        y + 7,
        L'\u2580',
        0,
        xam1,
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
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 13,
        y + 7,
        L'\u2580',
        0,
        xam2,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 14,
        y + 7,
        L'\u2580',
        0,
        la,
        View::Color::BLACK,
        View::Color::BLACK,
        nau
    );
    View::WriteToView(
        x + 15,
        y + 7,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        la
    );
    View::WriteToView(
        x + 16,
        y + 7,
        L'\u2580',
        0,
        xanh2,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 17,
        y + 7,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 18,
        y + 7,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    View::WriteToView(
        x + 19,
        y + 7,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    View::WriteToView(
        x + 20,
        y + 7,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh1
    );
    View::WriteToView(
        x + 21,
        y + 7,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh1
    );
    View::WriteToView(
        x + 22,
        y + 7,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    View::WriteToView(
        x + 23,
        y + 7,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    View::WriteToView(
        x + 24,
        y + 7,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    View::WriteToView(
        x + 1,
        y + 8,
        L'\u2580',
        0,
        xanh2,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 2,
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
        y + 8,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh1
    );
    View::WriteToView(
        x + 4,
        y + 8,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 5,
        y + 8,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 6,
        y + 8,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh2
    );
    View::WriteToView(
        x + 7,
        y + 8,
        L'\u2580',
        0,
        xanh2,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh2
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 8 + i,
            y + 8,
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
        y + 8,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh2
    );
    View::WriteToView(
        x + 13,
        y + 8,
        L'\u2580',
        0,
        xanh2,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh2
    );
    View::WriteToView(
        x + 14,
        y + 8,
        L'\u2580',
        0,
        nau,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 15,
        y + 8,
        L'\u2580',
        0,
        la,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 16,
        y + 8,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 17,
        y + 8,
        L'\u2580',
        0,
        trang,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 18,
        y + 8,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 19,
        y + 8,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 20 + i,
            y + 8,
            L'\u2580',
            0,
            xanh1,
            View::Color::BLACK,
            View::Color::BLACK,
            xanh1
        );
    }
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 23 + i,
            y + 8,
            L'\u2580',
            0,
            xanh3,
            View::Color::BLACK,
            View::Color::BLACK,
            den
        );
    }
    View::WriteToView(
        x + 2,
        y + 9,
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
        xanh1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 4,
        y + 9,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 5,
        y + 9,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        hong
    );
    View::WriteToView(
        x + 14,
        y + 9,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        hong
    );
    View::WriteToView(
        x + 6,
        y + 9,
        L'\u2580',
        0,
        la,
        View::Color::BLACK,
        View::Color::BLACK,
        hong
    );
    View::WriteToView(
        x + 13,
        y + 9,
        L'\u2580',
        0,
        la,
        View::Color::BLACK,
        View::Color::BLACK,
        hong
    );
    View::WriteToView(
        x + 7,
        y + 9,
        L'\u2580',
        0,
        la,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 12,
        y + 9,
        L'\u2580',
        0,
        la,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 8 + i,
            y + 9,
            L'\u2580',
            0,
            vang,
            View::Color::BLACK,
            View::Color::BLACK,
            vang
        );
    }
    View::WriteToView(
        x + 15,
        y + 9,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 16,
        y + 9,
        L'\u2580',
        0,
        xanh2,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh2
    );
    View::WriteToView(
        x + 17,
        y + 9,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 18,
        y + 9,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    View::WriteToView(
        x + 19,
        y + 9,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh1
    );
    View::WriteToView(
        x + 20,
        y + 9,
        L'\u2580',
        0,
        xanh1,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh1
    );
    View::WriteToView(
        x + 21,
        y + 9,
        L'\u2580',
        0,
        xanh1,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh1
    );
    View::WriteToView(
        x + 22,
        y + 9,
        L'\u2580',
        0,
        xanh1,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 23,
        y + 9,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 1,
        y + 10,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 2,
        y + 10,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 3,
        y + 10,
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
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 5,
        y + 10,
        L'\u2580',
        0,
        hong,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh2
    );
    View::WriteToView(
        x + 6,
        y + 10,
        L'\u2580',
        0,
        hong,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 7,
        y + 10,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 8,
        y + 10,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 9,
        y + 10,
        L'\u2580',
        0,
        hong,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 10,
        y + 10,
        L'\u2580',
        0,
        hong,
        View::Color::BLACK,
        View::Color::BLACK,
        hong
    );
    View::WriteToView(
        x + 11,
        y + 10,
        L'\u2580',
        0,
        hong,
        View::Color::BLACK,
        View::Color::BLACK,
        hong
    );
    View::WriteToView(
        x + 12,
        y + 10,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 13,
        y + 10,
        L'\u2580',
        0,
        hong,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 14,
        y + 10,
        L'\u2580',
        0,
        hong,
        View::Color::BLACK,
        View::Color::BLACK,
        vang
    );
    View::WriteToView(
        x + 15,
        y + 10,
        L'\u2580',
        0,
        xanh2,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh2
    );
    View::WriteToView(
        x + 16,
        y + 10,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 17,
        y + 10,
        L'\u2580',
        0,
        vang,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    View::WriteToView(
        x + 18,
        y + 10,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh1
    );
    View::WriteToView(
        x + 19,
        y + 10,
        L'\u2580',
        0,
        xanh1,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh1
    );
    View::WriteToView(
        x + 20,
        y + 10,
        L'\u2580',
        0,
        xanh1,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh1
    );
    View::WriteToView(
        x + 21,
        y + 10,
        L'\u2580',
        0,
        xanh1,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 22,
        y + 10,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 3,
        y + 11,
        L'\u2580',
        0,
        den,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 4,
        y + 11,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 5,
        y + 11,
        L'\u2580',
        0,
        la,
        View::Color::BLACK,
        View::Color::BLACK,
        trang
    );
    View::WriteToView(
        x + 6,
        y + 11,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh2
    );
    for (int i = 0; i < 4; i++) {
        View::WriteToView(
            x + 7 + i,
            y + 11,
            L'\u2580',
            0,
            vang,
            View::Color::BLACK,
            View::Color::BLACK,
            trang
        );
    }
    for (int i = 0; i < 3; i++) {
        View::WriteToView(
            x + 11 + i,
            y + 11,
            L'\u2580',
            0,
            vang,
            View::Color::BLACK,
            View::Color::BLACK,
            xam1
        );
    }
    View::WriteToView(
        x + 14,
        y + 11,
        L'\u2580',
        0,
        la,
        View::Color::BLACK,
        View::Color::BLACK,
        la
    );
    View::WriteToView(
        x + 15,
        y + 11,
        L'\u2580',
        0,
        xam1,
        View::Color::BLACK,
        View::Color::BLACK,
        xam1
    );
    View::WriteToView(
        x + 16,
        y + 11,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        xanh3
    );
    View::WriteToView(
        x + 17,
        y + 11,
        L'\u2580',
        0,
        xanh3,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    View::WriteToView(
        x + 18,
        y + 11,
        L'\u2580',
        0,
        xanh2,
        View::Color::BLACK,
        View::Color::BLACK,
        den
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 19 + i,
            y + 11,
            L'\u2580',
            0,
            den,
            View::Color::BLACK,
            View::Color::BLACK,
            trang
        );
    }
}

