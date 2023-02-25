#pragma once
#include <vector>

using namespace std;

namespace Evaluation {
	int GetComboEval(
		const vector<vector<short>>& boardGameArray,
		const int& playerValue);

	int GetGameStateEval(
		const vector<vector<short>>& boardGameMatrix,
		const int& moveCount,
		const int& rowCur,
		const int& colCur,
		const int& playerValue);

	int GetNodeValueEval(const vector<vector<short>>& boardGameMatrix,
		const int& playerValue);

}