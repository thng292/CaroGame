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

    inline void IteratePoints(
        const Board& board,
        const Point& move,
        const short player,
        std::vector<Point>& pointList,
        const short& rowDirection,
        const short& colDirection
    )
    {
        short index = 1, row = move.row, col = move.col;
        while (index <= 4) {
            row += rowDirection;
            col += colDirection;
            index++;
            if (!isValidPoint(row, col)) break;
            if (board[row][col] == 0) continue;
            if (board[row][col] != player) break;
            pointList.push_back({row, col});
            if (pointList.size() == 3) break;
          
        }
    }

    inline void AddToList(
        std::vector<Point>& warningList, const std::vector<Point> &pointList
    )
    {
        for (size_t i = 0; i < pointList.size(); ++i) {
            warningList.push_back(pointList[i]);
        }
    }

    inline bool IsBlocked(
        const std::vector<Point>& pointList,
        const Board& board,
        const short &rowDirection,
        const short &colDirection,
        const Point& firstPoint,
        const Point& secondPoint
    )
    {
        short row = firstPoint.row, col = firstPoint.col;
        while (row != secondPoint.row || col != secondPoint.col) {
            row += rowDirection;
            col += colDirection;
            if (board[row][col] == 0) return false;
        } 
        bool block1 = false, block2 = false;
        row = firstPoint.row + -rowDirection;
        col = firstPoint.col + -colDirection;
        short value = board[firstPoint.row][firstPoint.col];

        if (isValidPoint(row, col)) {
            if (board[row][col] == 0) return false;
            if (board[row][col] == value) return false;
            block1 = true;
        } else {
            block1 = true;
        }

        row = secondPoint.row + rowDirection;
        col = secondPoint.col + colDirection;
        if (isValidPoint(row, col)) {
            if (board[row][col] == 0) return false;
            if (board[row][col] == value) return false;
            block2 = true;
        } else {
            block2 = true;
        }

        return (block1 && block2);
    }

    std::vector<Point> GetWarningPoints(
        const Board& board, const Point& move, const short& player
    )
    {
        std::vector<Point> pointList;
        std::vector<Point> warningList;
        std::vector<std::vector<Point>> directions = {
            {{-1, -1}, {1, 1} },
            {{-1, 0},  {1, 0} },
            {{-1, 1},  {1, -1}},
            {{0, -1},  {0, 1} },
        };
        for (auto& directionPair : directions) {
            pointList.clear();
            bool missing = false;
            Point firstPoint;

            IteratePoints(
                board,
                move,
                player,
                pointList,
                directionPair[0].row,
                directionPair[0].col
            );
            if (pointList.size() == 3) {
                if (!IsBlocked(
                        pointList,
                        board,
                        directionPair[0].row,
                        directionPair[0].col,
                        move,
                        pointList.back()
                    ))
                    AddToList(warningList, pointList);

                pointList.clear();

            } else {
                if (pointList.size() != 0) {
                    firstPoint = pointList.back();
                    missing = true;
                }
            }
            IteratePoints(
                board,
                move,
                player,
                pointList,
                directionPair[1].row,
                directionPair[1].col
            );
            if (pointList.size() == 3) {
                if (!missing) firstPoint = move;
                if (!IsBlocked(
                        pointList,
                        board,
                        directionPair[1].row,
                        directionPair[1].col,
                        firstPoint,
                        pointList.back()
                    ))
                    AddToList(warningList, pointList);
            }

        }
      
        return warningList;
    }

}  // namespace GameAction