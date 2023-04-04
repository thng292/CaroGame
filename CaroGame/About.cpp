#include "About.h"

void About::AboutScreen(NavigationHost& NavHost)
{

    // GURA HERE
    logoGura(59-12, -1);
    logo_pokemon_red(3, 1);
    logo_pokemon_blue(3, 29 - 11 - 2);
    logo_pokemon_green(119 - 25 - 3, 1);
    logo_pokemon_pink(119 - 25 - 3, 29 - 11 - 2);

    View::DrawTextCenterdVertically(
        12, Language::GetString(L"GROUP_TITLE") + L": 11"
    );
    View::DrawTextCenterdVertically(
        13, L"22127401    Nguyễn Quang Thông", View::Color::RED
    );
    View::DrawTextCenterdVertically(
        14, L"22127339    Võ Nhật Phước     ", View::Color::BLUE
    );
    View::DrawTextCenterdVertically(
        15, L"22127463    Nguyễn Anh Vũ     ", View::Color::GREEN
    );
    View::DrawTextCenterdVertically(
        16, L"22127298    Hoàng Trung Nguyên", View::Color::MAGENTA
    );

    View::DrawTextCenterdVertically(
        18, Language::GetString(L"INSTRUCTOR_TITLE") + L": Trương Toàn Thịnh"
    );

    View::DrawTextCenterdVertically(
        20,
        L"Source Code: https://github.com/thng292/CaroGame",
        View::Color::LIGHT_BLUE
    );

    View::DrawTextCenterdVertically(
        27,
        std::format(L"B: {}", Language::GetString(L"NAVIGATE_BACK_KEY_TITLE")),
        View::Color::LIGHT_RED
    );
    while (1) {
        auto tmp = InputHandle::Get();
        if (tmp == L"b" || tmp == L"B") {
            return NavHost.Back();
        }
        if (tmp == L"\r") {
            system(
                "rundll32 url.dll,FileProtocolHandler "
                "https://github.com/thng292/CaroGame"
            );
        }
    }
}
