#include "GameAction.h"

#include <fstream>

#include "Constants.h"

namespace GameAction {
    void InitBoard(
        Board& board,
        short& moveCount,
        Point& topLeftPoint,
        Point& bottomRightPoint
    )
    {
        moveCount = 0;
        for (size_t i = 0; i < Constants::BOARD_SIZE; i++) {
            for (size_t j = 0; j < Constants::BOARD_SIZE; j++) {
                board[i][j] = 0;
            }
        }
    }

}  // namespace GameAction