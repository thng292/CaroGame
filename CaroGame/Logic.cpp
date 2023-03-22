#include "Logic.h"

#include "Constants.h"

namespace Logic {
    bool CheckLeftDiagonalWin(
        const GameAction::Board& boardGameMatrix,
        const GameAction::Point& move,
        const short& playerValue
    )
    {
        short poshortSameValueCount = 1;
        for (short row = move.row + 1, col = move.col + 1;
             row < boardGameMatrix.size() && col < boardGameMatrix.size();
             ++row, ++col) {
            if (boardGameMatrix[row][col] == playerValue) {
                poshortSameValueCount++;
                if (poshortSameValueCount == Constants::WIN_VALUE_COUNT) {
                    return 1;
                }
            } else {
                break;
            }
        }

        for (short row = move.row - 1, col = move.col - 1; row >= 0 && col >= 0;
             --row, --col) {
            if (boardGameMatrix[row][col] == playerValue) {
                poshortSameValueCount++;
                if (poshortSameValueCount == Constants::WIN_VALUE_COUNT) {
                    return 1;
                }
            } else {
                break;
            }
        }

        return 0;
    }

    bool CheckRightDiagonalWin(
        const GameAction::Board& boardGameMatrix,
        const GameAction::Point& move,
        const short& playerValue
    )
    {
        short poshortSameValueCount = 1;
        for (short row = move.row - 1, col = move.col + 1;
             row >= 0 && col < boardGameMatrix.size();
             --row, ++col) {
            if (boardGameMatrix[row][col] == playerValue) {
                poshortSameValueCount++;
                if (poshortSameValueCount == Constants::WIN_VALUE_COUNT) {
                    return 1;
                }
            } else {
                break;
            }
        }

        for (short row = move.row + 1, col = move.col - 1;
             row < boardGameMatrix.size() && col >= 0;
             ++row, --col) {
            if (boardGameMatrix[row][col] == playerValue) {
                poshortSameValueCount++;
                if (poshortSameValueCount == Constants::WIN_VALUE_COUNT) {
                    return 1;
                }
            } else {
                break;
            }
        }

        return 0;
    }

    bool CheckHorizontalWin(
        const GameAction::Board& boardGameMatrix,
        const GameAction::Point& move,
        const short& playerValue
    )
    {
        short poshortSameValueCount = 1;
        for (short col = move.col + 1; col < boardGameMatrix.size(); ++col) {
            if (boardGameMatrix[move.row][col] == playerValue) {
                poshortSameValueCount++;
                if (poshortSameValueCount == Constants::WIN_VALUE_COUNT) {
                    return 1;
                }
            } else {
                break;
            }
        }

        for (short col = move.col - 1; col >= 0; --col) {
            if (boardGameMatrix[move.row][col] == playerValue) {
                poshortSameValueCount++;

                if (poshortSameValueCount == Constants::WIN_VALUE_COUNT) {
                    return 1;
                }
            } else {
                break;
            }
        }

        return 0;
    }

    bool CheckVerticalWin(
        const GameAction::Board& boardGameMatrix,
        const GameAction::Point& move,
        const short& playerValue
    )
    {
        short poshortSameValueCount = 1;
        for (short row = move.row + 1; row < boardGameMatrix.size(); ++row) {
            if (boardGameMatrix[row][move.col] == playerValue) {
                poshortSameValueCount++;
                if (poshortSameValueCount == Constants::WIN_VALUE_COUNT) {
                    return 1;
                }
            } else {
                break;
            }
        }

        for (short row = move.row - 1; row >= 0; --row) {
            if (boardGameMatrix[row][move.col] == playerValue) {
                poshortSameValueCount++;
                if (poshortSameValueCount == Constants::WIN_VALUE_COUNT) {
                    return 1;
                }
            } else {
                break;
            }
        }

        return 0;
    }

    bool CheckDraw(
        const GameAction::Board& boardGameMatrix, const short& moveCount
    )
    {
        return (moveCount == boardGameMatrix.size() * boardGameMatrix.size());
    }

    short GetGameState(
        const GameAction::Board& board,
        const short& moveCount,
        const GameAction::Point& move,
        const short& playerValue
    )
    {
        if (CheckRightDiagonalWin(board, move, playerValue) ||
            CheckLeftDiagonalWin(board, move, playerValue) ||
            CheckHorizontalWin(board, move, playerValue) ||
            CheckVerticalWin(board, move, playerValue)) {
            return WIN_VALUE;
        }

        if (CheckDraw(board, moveCount)) {
            return DRAW_VALUE;
        }
        return NULL_VALUE;
    }
}  // namespace Logic
