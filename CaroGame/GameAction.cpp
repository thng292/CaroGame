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

    void IteratePoints(
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

    void AddToList(
        std::vector<Point>& warningList, const std::vector<Point> &pointList
    )
    {
        for (size_t i = 0; i < pointList.size(); ++i) {
            warningList.push_back(pointList[i]);
        }
    }

    bool Blocked(
        const Board& board,
        const std::vector<Point>& pointList,
        short rowDirection,
        short colDirection
    )
    {
        short row = pointList[0].row, col = pointList[0].col;
        short index = 1;
        while (index <= 4) {
            row += rowDirection;
            col += colDirection;
        }

    }

    std::vector<Point> GetWarningPoints(
        const Board& board, const Point& move, const short& player
    )
    {
        std::vector<Point> pointList;
        std::vector<Point> warningList;
        for (short rowDirection = -1; rowDirection <= 0; ++rowDirection) {
            for (short colDirection = -1; colDirection <= 0; ++colDirection) {
                if (!(rowDirection == 0 && colDirection == 0)) {
                    pointList.clear();
                    IteratePoints(
                        board,
                        move,
                        player,
                        pointList,
                        rowDirection,
                        colDirection
                    );
                    if (pointList.size() == 3) {
                        AddToList(warningList, pointList);
                    }

                    IteratePoints(
                        board,
                        move,
                        player,
                        pointList,
                        -rowDirection,
                        -colDirection
                    );
                    if (pointList.size() == 3)
                        AddToList(warningList, pointList);
                }
            }
        }
        pointList.clear();
        IteratePoints(board, move, player, pointList, -1, 1);
        if (pointList.size() == 3) AddToList(warningList, pointList);
        IteratePoints(board, move, player, pointList, 1, -1);
        if (pointList.size() == 3) AddToList(warningList, pointList);
        return warningList;
    }

}  // namespace GameAction