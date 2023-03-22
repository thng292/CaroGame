#include "GameAction.h"

#include <fstream>

#include "Constants.h"

namespace GameAction {
    void MakeMove(
        Board& board,
        short& moveCount,
        const Point& move,
        const short& playerValue
    )
    {
        board[move.row][move.col] = playerValue;
        moveCount++;
    }

    void UndoMove(Board& board, short& moveCount, const Point& move)
    {
        board[move.row][move.col] = 0;
        moveCount--;
    }

    void ResetGameState(GameState& gameState)
    {
        GameState temp;
        gameState = temp;
    }

    void InitBoard(
        Board& board,
        short& moveCount,
        Point& topLeftPoint,
        Point& bottomRightPoint
    )
    {
        moveCount = 0;
        board.resize(Constants::BOARD_SIZE);

        for (short i = 0; i < Constants::BOARD_SIZE; ++i) {
            board[i].resize(Constants::BOARD_SIZE);
        }
    }

}  // namespace GameAction