#pragma once
#pragma once
#include "Constants.h"
#include "GameAction.h"
#include "Hash.h"


class AI {
   public:
    const static short AI_DIFFICULTY_EASY = 1, AI_DIFFICULTY_NORMAL = 2,
                       AI_DIFFICULTY_HARD = 3;
    GameAction::Point _topLeftPoint = {100, 100},
                      _bottomRightPoint = {-100, -100};
    Hash hash;
    int cnt = 0;
    short Eval(
        const GameAction::Board& board, const short& moveCount,
        const GameAction::Point& lastMove, bool isMaximizingPlayer
    );

    short MiniMax(
        GameAction::Board& board, short& moveCount,
        const GameAction::Point& lastMove, short alpha, short beta,
        const bool& isMaximizingPlayer, const short& depth,
        const GameAction::Point topLeftPoint,
        const GameAction::Point bottomRightPoint
    );

    GameAction::Point GetBestMove(GameAction::Board& board, short& moveCount);

    void UpdatePrivateValues(GameAction::Point point);

    void SetDifficulty(const short& difficulty);

    GameAction::Point GetFirstMove();

   private:
    const short INF = 25000;
    const short MAX_SCORE = 10000;
    const short FIRST_LOOKUP_RANGE = 1;
    short _depth = 4;
    const short PLAYER_HUMAN = Constants::PLAYER_ONE.value,
                PLAYER_AI = Constants::PLAYER_TWO.value;
};