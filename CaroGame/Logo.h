#pragma once
#include "Config.h"
#include "InputHandle.h"
#include "Language.h"
#include "Navigate.h"
#include "Utils.h"
#include "View.h"

namespace Logo {
    void Captain(NavigationHost& NavHost, int x, int y);
    void Deadpool(NavigationHost& NavHost, int x, int y);
    void Logo_Draw(
        NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2,
        View::Color a3, View::Color a4, View::Color a5
    );
    void Logo_Win(
        NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2,
        View::Color a3, View::Color a4, View::Color a5
    );
    void Logo_Lose(
        NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2,
        View::Color a3, View::Color a4, View::Color a5
    );
    void Draw(
        NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2,
        View::Color a3, View::Color a4, View::Color a5
    );
    void Lose(
        NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2,
        View::Color a3, View::Color a4, View::Color a5
    );
    void Win(
        NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2,
        View::Color a3, View::Color a4, View::Color a5
    );
    void AmongUs(int x, int y, View::Color mat, View::Color mau);
    void Logo_Caro(int x, int y);

}  // namespace Logo
