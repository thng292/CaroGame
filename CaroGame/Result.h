#pragma once
#include "Avatar.h"
#include "Constants.h"
#include "View.h"
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
void Logo_Result(int k, bool &stop);