#pragma once

#include "BoardContainer.h"
#include "Container.h"
#include "GameState.h"
#include "Label.h"
#include "Pokemon.h"
#include "Gura.h"
#include <unordered_map>


// Class for the game's UI
class GameScreen {
   public:
    BoardContainer boardContainer;
    Container timerContainerOne, timerContainerTwo;
    Container playerContainerOne, playerContainerTwo;
    Container winCountContainerOne, winCountContainerTwo;
    Container playerInfoContainerOne, playerInfoContainerTwo;
    Container logContainer;
    //std::unordered_map<short, std::function<void(short, short)>> avatarMap;
    std::vector<std::function<void(short, short)>> avatarMap = {
        logo_pokemon_red,
        logo_pokemon_blue,
        logo_pokemon_green,
        logo_pokemon_yellow,
        logo_pokemon_pink,
        logo_pokemon_gray,
        logo_pokemon_white,
        logo_pokemon_black,
        logoGura
    };

    GameScreen(short x, short y);
    void DrawGameScreen();
    void DrawToElements(const GameState &gameState, bool isReplay = false);

    

   private:
    void InitElement(
        Container& element,
        short x,
        short y,
        short cell_width,
        short cell_height,
        short x_offset,
        short y_offset
    );
};
