#include "Logic.h"

#include "Constants.h"

namespace Logic {
    bool CheckLeftDiagonalWin(
        const GameAction::Board& boardGameMatrix,
        const GameAction::Point& move,
        const short& playerValue,
        GameAction::Point& winPoint,
        bool getWinPoint


    )
    {
        short poshortSameValueCount = 1;
        for (short row = move.row + 1, col = move.col + 1;
             row < Constants::BOARD_SIZE && col < Constants::BOARD_SIZE;
             ++row, ++col) {
            if (boardGameMatrix[row][col] == playerValue) {
                poshortSameValueCount++;
                if (poshortSameValueCount == Constants::WIN_VALUE_COUNT) {
                    if (getWinPoint) winPoint = {row, col};
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
                    if (getWinPoint) winPoint = {row, col};

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
        const short& playerValue,
        GameAction::Point& winPoint,
        bool getWinPoint

    )
    {
        short poshortSameValueCount = 1;
        for (short row = move.row - 1, col = move.col + 1;
             row >= 0 && col < Constants::BOARD_SIZE;
             --row, ++col) {
            if (boardGameMatrix[row][col] == playerValue) {
                poshortSameValueCount++;
                if (poshortSameValueCount == Constants::WIN_VALUE_COUNT) {
                    if (getWinPoint) winPoint = {row, col};


                    return 1;
                }
            } else {
                break;
            }
        }

        for (short row = move.row + 1, col = move.col - 1;
             row < Constants::BOARD_SIZE && col >= 0;
             ++row, --col) {
            if (boardGameMatrix[row][col] == playerValue) {
                poshortSameValueCount++;
                if (poshortSameValueCount == Constants::WIN_VALUE_COUNT) {
                    if (getWinPoint) winPoint = {row, col};


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
        const short& playerValue,
        GameAction::Point& winPoint,
        bool getWinPoint
    )
    {
        short poshortSameValueCount = 1;
        for (short col = move.col + 1; col < Constants::BOARD_SIZE; ++col) {
            if (boardGameMatrix[move.row][col] == playerValue) {
                poshortSameValueCount++;
                if (poshortSameValueCount == Constants::WIN_VALUE_COUNT) {
                    if (getWinPoint) winPoint = {move.row, col};

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
                    if (getWinPoint) winPoint = {move.row, col};

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
        const short& playerValue,
        GameAction::Point& winPoint,
        bool getWinPoint

    )
    {
        short poshortSameValueCount = 1;
        for (short row = move.row + 1; row < Constants::BOARD_SIZE; ++row) {
            if (boardGameMatrix[row][move.col] == playerValue) {
                poshortSameValueCount++;
                if (poshortSameValueCount == Constants::WIN_VALUE_COUNT) {
                    if (getWinPoint) winPoint = {row, move.col};

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
                    if (getWinPoint) winPoint = {row, move.col};

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
        return (moveCount == Constants::BOARD_SIZE * Constants::BOARD_SIZE);
    }

    short GetGameState(
        const GameAction::Board& board,
        const short& moveCount,
        const GameAction::Point& move,
        const short& playerValue,
        GameAction::Point& winPoint,
        bool getWinPoint

    )
    {
        if (CheckRightDiagonalWin(board, move, playerValue, winPoint, getWinPoint) ||
            CheckLeftDiagonalWin(board, move, playerValue, winPoint, getWinPoint) ||
            CheckHorizontalWin(board, move, playerValue, winPoint, getWinPoint) ||
            CheckVerticalWin(board, move, playerValue, winPoint, getWinPoint)) {
            return WIN_VALUE;
        }

        if (CheckDraw(board, moveCount)) {
            return DRAW_VALUE;
        }
        return NULL_VALUE;
    }
}  // namespace Logic
