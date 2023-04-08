#pragma once
#include "GameState.h"
#include "Constants.h"

namespace GameAction {
    struct Point {
        short row, col;
    };

    typedef std::vector<std::vector<short>> Board;

    void MakeMove(
        Board& board,
        short& moveCount,
        const Point& move,
        const short& playerValue
    );

    inline bool isValidPoint(short row, short col)
    {
        return !(
            row < 0 || col < 0 || row >= Constants::BOARD_SIZE ||
            col >= Constants::BOARD_SIZE
        );
    }

    void UndoMove(Board& board, short& moveCount, const Point& move);

    std::vector<Point> GetWarningPoints(const Board& board, const Point& move, const short &player);
    
}  // namespace GameAction