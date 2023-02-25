#pragma once
#include <vector>

using namespace std;

namespace Game {
	void MakeMove(
		vector<vector<short>>& boardGameMatrix,
		int& moveCount,
		const int& row,
		const int& col,
		const int& playerValue);

	void UndoMove(
		vector<vector<short>>& boardGameMatrix,
		int& moveCount,
		const int& row,
		const int& col);

	void InitBoard(vector<vector<short>>& boardGameMatrix, int& moveCount);
}