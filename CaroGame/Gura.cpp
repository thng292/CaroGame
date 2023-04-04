#include "Gura.h"

void logoGura(int x, int y) {
    View::Color xanh1 = View::Color::CYAN;
    View::Color xanh2 = View ::Color::LIGHT_BLUE;
    View::Color xanh3 = View::Color::BLUE;
    View::Color den = View::Color::BLACK;
    View::Color trang = View::Color::BRIGHT_WHITE;
    View::Color vang = View::Color::LIGHT_YELLOW;
    View::Color nau = View::Color::YELLOW;
    View::Color xam1 = View::Color::WHITE;
    View::Color xam2 = View::Color::GRAY;
    View::Color la = View::Color::GREEN;
    View::Color hong = View::Color::LIGHT_MAGENTA;

    View::WriteToView(
        x + 8,
        y + 1,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 9,
        y + 1,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    for (int i = 0; i < 5; i++) {
        View::WriteToView(
            x + 10 + i,
            y + 1,
            L'\u2580',
            0,
            den,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            xanh3
        );
    }
    View::WriteToView(
        x + 15,
        y + 1,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 16,
        y + 1,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 5,
        y + 2,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 6,
        y + 2,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    x++;
    View::WriteToView(
        x + 6,
        y + 2,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    
    for (int i = 0; i < 6; i++) {
        View::WriteToView(
            x + 7 + i,
            y + 2,
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
        y + 2,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    for (int i = 0; i < 2; i++) {
        View::WriteToView(
            x + 14 + i,
            y + 2,
            L'\u2580',
            0,
            xanh3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            xanh3
        );
    }
    View::WriteToView(
        x + 16,
        y + 2,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 17,
        y + 2,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 18,
        y + 2,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    x--;
    View::WriteToView(
        x + 4,
        y + 3,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 5,
        y + 3,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 6,
        y + 3,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 7,
        y + 3,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 8,
        y + 3,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam1
    );
    View::WriteToView(
        x + 9,
        y + 3,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam2
    );
    View::WriteToView(
        x + 10,
        y + 3,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam2
    );
    View::WriteToView(
        x + 11,
        y + 3,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    View::WriteToView(
        x + 12,
        y + 3,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    for (int i = 0; i < 7; i++) {
        View::WriteToView(
            x + 13 + i,
            y + 3,
            L'\u2580',
            0,
            xanh3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            xanh3
        );
    }
    View::WriteToView(
        x + 20,
        y + 3,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 3,
        y + 4,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 4,
        y + 4,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 5,
        y + 4,
        L'\u2580',
        0,
       trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam1
    );
    View::WriteToView(
        x + 6,
        y + 4,
        L'\u2580',
        0,
        xam1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam1
    );
    View::WriteToView(
        x + 7,
        y + 4,
        L'\u2580',
        0,
        xam1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam2
    );
    for (int i = 0; i < 5; i++) {
        View::WriteToView(
            x + 8 + i,
            y + 4,
            L'\u2580',
            0,
            xam2,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            xam2
        );
    }
    View::WriteToView(
        x + 13,
        y + 4,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam2
    );
    View::WriteToView(
        x + 14,
        y + 4,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        trang
    );
    for (int i = 0; i < 6; i++) {
        View::WriteToView(
            x + 15 + i,
            y + 4,
            L'\u2580',
            0,
            xanh3,
            View::DEFAULT_HIGHLIGHT_COLOR,
            View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
            xanh3
        );
    }
    View::WriteToView(
        x + 21,
        y + 4,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 22,
        y + 4,
        L'\u2580',
        0,
        trang,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        den
    );
    View::WriteToView(
        x + 1,
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
        y + 5,
        L'\u2580',
        0,
        den,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 3,
        y + 5,
        L'\u2580',
        0,
        xanh3,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xanh3
    );
    View::WriteToView(
        x + 4,
        y + 5,
        L'\u2580',
        0,
        xam1,
        View::DEFAULT_HIGHLIGHT_COLOR,
        View::DEFAULT_HIGHLIGHT_TEXT_COLOR,
        xam1
    );
    








}