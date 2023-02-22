#pragma once
#include <vector>

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
		const bool& isMaximizingPlayer);

	pair<short, short> GetBestMove(
		vector<vector<short>>&boardGameMatrix,
		int &moveCount,
		const int& rowLastMove, 
		bool isMaximizingPlayer, 
		const int& colLastMove);
}
