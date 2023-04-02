#include "View.h"
#include "Avatar.h"
#include "cstdlib"
void khung_Among_Us();

void Win(
    int x,
    int y,
    View::Color a1,
    View::Color a2,
    View::Color a3,
    View::Color a4,
    View::Color a5
);

void Lose(
    int x,
    int y,
    View::Color a1,
    View::Color a2,
    View::Color a3,
    View::Color a4,
    View::Color a5
);

void Draw(
    int x,
    int y,
    View::Color a1,
    View::Color a2,
    View::Color a3,
    View::Color a4,
    View::Color a5
);

void Logo_Draw(
    int x,
    int y
);

void Logo_Win(
    int x,
    int y
);

void Logo_Lose(
    int x,
    int y
);
void Logo_Result(int k);