#include "Logic.h"

#include "Constants.h"

namespace Logic {
    bool CheckLeftDiagonalWin(
        const vector<vector<short>>& boardGameMatrix, const int& rowCur,
        const int& colCur, const int& playerValue
    ) {
        int pointSameValueCount = 1;
        for (int row = rowCur + 1, col = colCur + 1;
             row < boardGameMatrix.size() && col < boardGameMatrix.size();
             ++row, ++col) {
            if (boardGameMatrix[row][col] == playerValue) {
                pointSameValueCount++;
                if (pointSameValueCount == Constants::WIN_VALUE_COUNT) {
                    return 1;
                }
            } else {
                break;
            }
        }

        for (int row = rowCur - 1, col = colCur - 1; row >= 0 && col >= 0;
             --row, --col) {
            if (boardGameMatrix[row][col] == playerValue) {
                pointSameValueCount++;
                if (pointSameValueCount == Constants::WIN_VALUE_COUNT) {
                    return 1;
                }
            } else {
                break;
            }
        }

        return 0;
    }

    bool CheckRightDiagonalWin(
        const vector<vector<short>>& boardGameMatrix, const int& rowCur,
        const int& colCur, const int& playerValue
    ) {
        int pointSameValueCount = 1;
        for (int row = rowCur - 1, col = colCur + 1;
             row >= 0 && col < boardGameMatrix.size(); --row, ++col) {
            if (boardGameMatrix[row][col] == playerValue) {
                pointSameValueCount++;
                if (pointSameValueCount == Constants::WIN_VALUE_COUNT) {
                    return 1;
                }
            } else {
                break;
            }
        }

        for (int row = rowCur + 1, col = colCur - 1;
             row < boardGameMatrix.size() && col >= 0; ++row, --col) {
            if (boardGameMatrix[row][col] == playerValue) {
                pointSameValueCount++;
                if (pointSameValueCount == Constants::WIN_VALUE_COUNT) {
                    return 1;
                }
            } else {
                break;
            }
        }

        return 0;
    }

    bool CheckHorizontalWin(
        const vector<vector<short>>& boardGameMatrix, const int& rowCur,
        const int& colCur, const int& playerValue
    ) {
        int pointSameValueCount = 1;
        for (int col = colCur + 1; col < boardGameMatrix.size(); ++col) {
            if (boardGameMatrix[rowCur][col] == playerValue) {
                pointSameValueCount++;
                if (pointSameValueCount == Constants::WIN_VALUE_COUNT) {
                    return 1;
                }
            } else {
                break;
            }
        }

        for (int col = colCur - 1; col >= 0; --col) {
            if (boardGameMatrix[rowCur][col] == playerValue) {
                pointSameValueCount++;

                if (pointSameValueCount == Constants::WIN_VALUE_COUNT) {
                    return 1;
                }
            } else {
                break;
            }
        }

        return 0;
    }

    bool CheckVerticalWin(
        const vector<vector<short>>& boardGameMatrix, const int& rowCur,
        const int& colCur, const int& playerValue
    ) {
        int pointSameValueCount = 1;
        for (int row = rowCur + 1; row < boardGameMatrix.size(); ++row) {
            if (boardGameMatrix[row][colCur] == playerValue) {
                pointSameValueCount++;
                if (pointSameValueCount == Constants::WIN_VALUE_COUNT) {
                    return 1;
                }
            } else {
                break;
            }
        }

        for (int row = rowCur - 1; row >= 0; --row) {
            if (boardGameMatrix[row][colCur] == playerValue) {
                pointSameValueCount++;
                if (pointSameValueCount == Constants::WIN_VALUE_COUNT) {
                    return 1;
                }
            } else {
                break;
            }
        }

        return 0;
    }

    bool CheckDraw(
        const vector<vector<short>>& boardGameMatrix, const int& moveCount
    ) {
        return (moveCount == boardGameMatrix.size() * boardGameMatrix.size());
    }

    int GetGameState(
        const vector<vector<short>>& boardGameMatrix, const int& moveCount,
        const int& rowCur, const int& colCur, const int& playerValue
    ) {
        if (CheckRightDiagonalWin(
                boardGameMatrix, rowCur, colCur, playerValue
            ) ||
            CheckLeftDiagonalWin(
                boardGameMatrix, rowCur, colCur, playerValue
            ) ||
            CheckHorizontalWin(boardGameMatrix, rowCur, colCur, playerValue) ||
            CheckVerticalWin(boardGameMatrix, rowCur, colCur, playerValue)) {
            return 1;
        }

        if (CheckDraw(boardGameMatrix, moveCount)) {
            return 0;
        }
        return Constants::NULL_VALUE;
    }
}  // namespace Logic
