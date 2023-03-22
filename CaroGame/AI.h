#pragma once

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
    GameAction::Point _topLeftPoint = {100, 100},
                      _bottomRightPoint = {-100, -100};
    Hash hash;
    int cnt = 0;
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
        const GameAction::Point bottomRightPoint
    );

    GameAction::Point GetBestMove(GameAction::Board& board, short& moveCount);

    inline void UpdatePrivateValues(GameAction::Point point)
    {
        if (point.row < _topLeftPoint.row) _topLeftPoint.row = point.row;
        if (point.col < _topLeftPoint.col) _topLeftPoint.col = point.col;

        if (point.row > _bottomRightPoint.row)
            _bottomRightPoint.row = point.row;
        if (point.col > _bottomRightPoint.col)
            _bottomRightPoint.col = point.col;
        cnt = 0;
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
                _depth = 4;
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

   private:
    const short INF = 25000;
    const short MAX_SCORE = 10000;
    const short FIRST_LOOKUP_RANGE = 1;
    short _depth = 4;
    const short PLAYER_HUMAN = Constants::PLAYER_ONE.value,
                PLAYER_AI = Constants::PLAYER_TWO.value;
};

inline GameAction::Point NewBottomRightPoint(
    const GameAction::Point& bottomRightPoint, const GameAction::Point& point
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
