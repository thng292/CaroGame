#pragma once
#include "GameAction.h"

using namespace std;

namespace Evaluation {

	const short tempBoost = 10;

	short GetComboEval(
		const GameAction::Board& boardGameArray,
		const short& playerValue);
}