#pragma once
#include "GameAction.h"

namespace Evaluation {

    const short tempBoost = 10;

    short GetComboEval(
        const GameAction::Board& boardGameArray, const short& playerValue
    );

 
}  // namespace Evaluation