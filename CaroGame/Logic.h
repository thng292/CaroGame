#pragma once

#include "GameAction.h"

namespace Logic {

    const short NULL_VALUE = 0;
    const short WIN_VALUE = 2;
    const short DRAW_VALUE = 1;

    short GetGameState(
        const GameAction::Board& board,
        const short& moveCount,
        const GameAction::Point& move,
        const short& playerValue
    );

    bool CheckDraw(const GameAction::Board& board, const short& moveCount);

    bool CheckVerticalWin(
        const GameAction::Board& board,
        const GameAction::Point& move,
        const short& playerValue
    );

    bool CheckHorizontalWin(
        const GameAction::Board& board,
        const GameAction::Point& move,
        const short& playerValue
    );

    bool CheckLeftDiagonalWin(
        const GameAction::Board& board,
        const GameAction::Point& move,
        const short& playerValue
    );

    bool CheckRightDiagonalWin(
        const GameAction::Board& board,
        const GameAction::Point& move,
        const short& playerValue
    );
}  // namespace Logic