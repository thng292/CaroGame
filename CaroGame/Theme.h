#pragma once
#include "View.h"


namespace Theme {
    struct Theme {
        // Menu, hints and normal text
        View::Color TITLE_TEXT_COLOR;
        View::Color TEXT_COLOR;
        View::Color TEXT_HIGHLIGHT_COLOR;

        // Border
        View::Color BORDER_COLOR;
        View::Color BORDER_CORNER_COLOR;

        // Console 
        View::Color CONSOLE_COLOR;

        // Player
        View::Color PLAYER_ONE_COLOR;
        View::Color PLAYER_TWO_COLOR;
        View::Color PLAYER_ONE_HIGHLIGHT_COLOR;
        View::Color PLAYER_TWO_HIGHLIGHT_COLOR;
       
        // Selection screen and end screen values
        View::Color AI_EASY_COLOR;
        View::Color AI_NORMAL_COLOR;
        View::Color AI_HARD_COLOR;

        View::Color TYPE_RUSH_COLOR;
        View::Color TYPE_NORMAL_COLOR;

        View::Color MODE_PVP_COLOR;
        View::Color MODE_PVE_COLOR;

        View::Color TIME_1_COLOR;
        View::Color TIME_5_COLOR;
        View::Color TIME_15_COLOR;

        // Special text
        View::Color WIN_TEXT_COLOR;
        View::Color DRAW_TEXT_COLOR;

    };
}