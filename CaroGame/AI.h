#pragma once

#include <functional>
#include <queue>
#include <random>

#include "Constants.h"
#include "Evaluation.h"
#include "GameAction.h"
#include "Hash.h"
#include "Logic.h"

class AI {
   public:
    const static short AI_DIFFICULTY_EASY = 1, AI_DIFFICULTY_NORMAL = 2,
                       AI_DIFFICULTY_HARD = 3;

    int cnt = 0;

    short PLAYER_HUMAN = Constants::PLAYER_ONE.value,
          PLAYER_AI = Constants::PLAYER_TWO.value;

    struct PointEval {
        GameAction::Point move;
        short eval;
    };

    inline GameAction::Point NewBottomRightPoint(
        const GameAction::Point& bottomRightPoint,
        const GameAction::Point& point
    )
    {
        GameAction::Point newPoint = bottomRightPoint;
        if (point.row > bottomRightPoint.row) newPoint.row = point.row;
        if (point.col > bottomRightPoint.col) newPoint.col = point.col;
        return newPoint;
    }

    inline GameAction::Point NewTopLeftPoint(
        const GameAction::Point& topLeftPoint, const GameAction::Point& point
    )
    {
        GameAction::Point newPoint = topLeftPoint;
        if (point.row < topLeftPoint.row) newPoint.row = point.row;
        if (point.col < topLeftPoint.col) newPoint.col = point.col;
        return newPoint;
    }

    short Eval(
        const GameAction::Board& board,
        const short& moveCount,
        const GameAction::Point& lastMove,
        bool isMaximizingPlayer
    );

    short MiniMax(
        GameAction::Board& board,
        short& moveCount,
        const GameAction::Point& lastMove,
        short alpha,
        short beta,
        const bool& isMaximizingPlayer,
        const short& depth,
        const GameAction::Point topLeftPoint,
        const GameAction::Point bottomRightPoint,
        Hash& hash
    );

    GameAction::Point GetBestMove(GameAction::Board& board, short& moveCount);

    inline void UpdatePrivateValues(GameAction::Point point)
    {
        _prevPointList.push_back({_topLeftPoint, _bottomRightPoint});
        if (point.row < _topLeftPoint.row) _topLeftPoint.row = point.row;
        if (point.col < _topLeftPoint.col) _topLeftPoint.col = point.col;

        if (point.row > _bottomRightPoint.row)
            _bottomRightPoint.row = point.row;
        if (point.col > _bottomRightPoint.col)
            _bottomRightPoint.col = point.col;
        cnt = 0;
    }

    inline void RevertPrivateValues()
    {
        _topLeftPoint = _prevPointList.back().first;
        _bottomRightPoint = _prevPointList.back().second;
        _prevPointList.pop_back();
    }

    inline void SetDifficulty(const short& difficulty)
    {
        switch (difficulty) {
            case AI_DIFFICULTY_EASY:
                _depth = 1;
                break;
            case AI_DIFFICULTY_NORMAL:
                _depth = 2;
                break;
            case AI_DIFFICULTY_HARD:
                _depth = 3;
                break;
        }
    }

    inline GameAction::Point GetFirstMove()
    {
        srand(time(NULL));
        short row = Constants::BOARD_SIZE / 2 - 2 + (rand() % 3);
        short col = Constants::BOARD_SIZE / 2 - 2 + (rand() % 3);
        return {row, col};
    }

    class Compare {
       public:
        inline bool operator()(PointEval below, PointEval above)
        {
            if (below.eval < above.eval) return true;
            return false;
        }
    };

    short IteratePoints(
        const GameAction::Board& board,
        const GameAction::Point& move,
        short rowDirection,
        short colDirection,
        bool isPositivePoint,
        short value
    )
    {
        short row = move.row, col = move.col, index = 1;
        short point = 1, nodeCount = 1;
        while (index < 5) {
            row += rowDirection;
            col += colDirection;
            if (GameAction::isValidPoint(row, col)) {
                if (board[row][col] == 0 && isPositivePoint == true) {
                    point++;
                } else if (isPositivePoint && board[row][col] == value) {
                    point += nodeCount * 2;
                    nodeCount++;
                } else if (!isPositivePoint && board[row][col] != value && board[row][col] != 0) {
                    point += nodeCount * 2;
                    nodeCount++;
                }

                else
                    break;
            } else
                break;

            ++index;
        }
        return point;
    }

    short GetNodePoint(
        const GameAction::Board& board,
        const GameAction::Point& move,
        short value
    )
    {
        int point = 0;
        for (short rowDirection = -1; rowDirection <= 1; ++rowDirection) {
            for (short colDirection = -1; colDirection <= 1; ++colDirection) {
                if (!(rowDirection == 0 && colDirection == 0)) {
                    point +=
                        IteratePoints(
                            board, move, rowDirection, colDirection, true, value
                        ) +
                        IteratePoints(
                            board,
                            move,
                            rowDirection,
                            colDirection,
                            false,
                            value
                        );
                }
            }
        }
        return point;
    }

    typedef std::priority_queue<PointEval, std::vector<PointEval>, Compare>
        MoveQueue;

    MoveQueue GetMoveList(
        short rowLowerLimit,
        short rowUpperLimit,
        short colLowerLimit,
        short colUpperLimit,
        short moveCount,
        GameAction::Board& board,
        bool isMaximizingPlayer
    )
    {
        MoveQueue moveQueue;
        short player = (isMaximizingPlayer) ? PLAYER_AI : PLAYER_HUMAN;

        for (short row = rowLowerLimit; row <= rowUpperLimit; ++row) {
            for (short col = colLowerLimit; col <= colUpperLimit; ++col) {
                if (board[row][col] == 0) {
                    GameAction::MakeMove(board, moveCount, {row, col}, player);
                    moveQueue.push({
                        {row, col},
                        GetNodePoint(board, {row, col},
                        player)
                    });

                    GameAction::UndoMove(board, moveCount, {row, col});
                }
            }
        }
        return moveQueue;
    };

   private:
    const short INF = 30000;
    const short MAX_SCORE = 10000;
    short _depth = 2;

    const short _RANGE = 1;
    GameAction::Point _topLeftPoint = {100, 100},
                      _bottomRightPoint = {-100, -100};
    std::vector<std::pair<GameAction::Point, GameAction::Point>> _prevPointList;
};