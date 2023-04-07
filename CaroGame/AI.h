#pragma once

#include <random>
#include <queue>
#include <functional>

#include "Constants.h"
#include "Evaluation.h"
#include "GameAction.h"
#include "Hash.h"
#include "Logic.h"



class AI {
   public:
    const static short AI_DIFFICULTY_EASY = 1, AI_DIFFICULTY_NORMAL = 2,
                       AI_DIFFICULTY_HARD = 3;
    
    short PLAYER_HUMAN = Constants::PLAYER_ONE.value,
          PLAYER_AI = Constants::PLAYER_TWO.value;

    static struct PointEval {
        GameAction::Point move;
        short eval;
    };

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
        const short& depth
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
    }

    inline void RevertPrivateValues() { 
        _topLeftPoint = _prevPointList.back().first;
        _bottomRightPoint = _prevPointList.back().second;
        _prevPointList.pop_back();
    }

    inline void SetDifficulty(const short& difficulty)
    {
        switch (difficulty) {
            case AI_DIFFICULTY_EASY:
                _range = 6;
                _DEPTH = 2;
                break;
            case AI_DIFFICULTY_NORMAL:
                _range = Constants::BOARD_SIZE;
                _DEPTH = 2;
                break;
            case AI_DIFFICULTY_HARD:
                _range = Constants::BOARD_SIZE;
                _DEPTH = 3;
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

    inline bool isValidPoint(short row, short col)
    {
        return !(
            row < 0 || col < 0 || row >= Constants::BOARD_SIZE ||
            col >= Constants::BOARD_SIZE
        );
    }

    bool IsGoodMove(
        const GameAction::Board& board,
        const GameAction::Point& move,
        const short& playerValue
    )
    {
        for (short row = move.row - 1; row <= move.row + 1; ++row) {
            for (short col = move.col - 1; col <= move.col + 1; ++col) {
                if (isValidPoint(row, col)) {
                    if (board[row][col] != 0) return 1;
                }
            }
        }

        return 0;
    }

    class Compare {
       public:
        bool operator()(PointEval a, PointEval b) { return a.eval < b.eval; }
    };
    
    typedef std::priority_queue<PointEval, std::vector<PointEval>, Compare> MoveQueue;

     MoveQueue GetMoveList(short rowLowerLimit, short rowUpperLimit, short colLowerLimit, short colUpperLimit, short moveCount, GameAction::Board&board){
        short searchSize = (rowUpperLimit - rowLowerLimit + 1) *
                           (colUpperLimit - colLowerLimit + 1);

        short moveListSize = searchSize - moveCount;
        std::vector<GameAction::Point> moveList;
        moveList.resize(moveListSize);
        short right = 0, left = moveListSize - 1;

        MoveQueue moveQueue;

        for (short row = rowLowerLimit; row <= rowUpperLimit; ++row) {
            for (short col = colLowerLimit; col <= colUpperLimit; ++col)  {
                GameAction::MakeMove(board, moveCount, {row, col}, PLAYER_AI);
                moveQueue.push({
                    {row, col},
                    Eval(board, moveCount, {row, col},
                    true)
                });

               
                GameAction::UndoMove(board, moveCount, {row, col});

            }
        }
        return moveQueue;
    };

   private:
    const short INF = 30000;
    const short MAX_SCORE = 10000;
    const short FIRST_LOOKUP_RANGE = 1;
    short _DEPTH = 2;
    
    short _range;
    GameAction::Point _topLeftPoint = {100, 100},
                      _bottomRightPoint = {-100, -100};
    std::vector<std::pair<GameAction::Point, GameAction::Point>> _prevPointList;
};
