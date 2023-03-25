#pragma once
#include <vector>
#include <array>

#include "GameState.h"

namespace GameAction {
    struct Point {
        short row, col;
    };

    typedef std::array<std::array<char, Constants::BOARD_SIZE>, Constants::BOARD_SIZE> Board;

    inline void MakeMove(
        Board& board,
        short& moveCount,
        const Point& move,
        const short& playerValue
    )
    {
        board[move.row][move.col] = playerValue;
        moveCount++;
    }

    inline void UndoMove(Board& board, short& moveCount, const Point& move)
    {
        board[move.row][move.col] = 0;
        moveCount--;
    }

    inline void ResetGameState(GameState& gameState)
    {
        gameState = GameState();
    }

    void InitBoard(
        Board& board,
        short& moveCount,
        Point& topLeftCorner,
        Point& bottomRightCorner
    );
    // void InitBoard(vector<vector<short>>& boardGameMatrix, short& moveCount);
}  // namespace GameAction