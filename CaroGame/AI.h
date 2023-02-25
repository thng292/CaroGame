#pragma once
#include <vector>
#include "Game.h"
#include "Constants.h"

using namespace std;

namespace AI {
	int Eval(
		const vector<vector<short>> &boardGameMatrix,
		const int &moveCount,
		const int& rowLastMove,
		const int& colLastMove,
		bool isMaximizingPlayer);

	int MiniMax(
		vector<vector<short>>& boardGameMatrix, 
		int &moveCount,
		const int& rowLastMove,
		const int& colLastMove,
		int alpha,
		int beta,
		const bool& isMaximizingPlayer,
		const int& depth);

	pair<short, short> GetBestMove(
		vector<vector<short>>&boardGameMatrix,
		int &moveCount,
		int alpha,
		int beta,
		const int &depth);
}
