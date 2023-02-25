#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <math.h>


#include "AI.h"
#include "Constants.h"
#include "Logic.h"
#include "Evaluation.h"
#include "Ui.h"
using namespace std;


namespace AI {
	int Eval(
		const vector<vector<short>>& boardGameMatrix,
		const int& moveCount,
		const int& rowLastMove,
		const int& colLastMove,
		bool isMaximizingPlayer) {

		int playerValue = (!isMaximizingPlayer) ? Constants::PLAYER_AI : Constants::PLAYER_HUMAN;
		int totalEval = 0;
		totalEval += Evaluation::GetComboEval(boardGameMatrix, playerValue);
		totalEval += Evaluation::GetGameStateEval(boardGameMatrix, moveCount, rowLastMove, colLastMove, playerValue);
		//totalEval += Evaluation::GetNodeValueEval(boardGameMatrix, playerValue);
		//return Logic::GetGameState(boardGameMatrix, moveCount, rowLastMove, colLastMove, playerValue);
		return (!isMaximizingPlayer) ? totalEval : -totalEval;
	}
	pair<short, short> GetBestMove(
		vector<vector<short>>& boardGameMatrix,
		int& moveCount,
		int alpha,
		int beta,
		const int& depth) {

		int valBest = -Constants::INF;
		pair<short, short>moveBest;
		for (int row = 0;row < boardGameMatrix.size();++row) {
			for (int col = 0;col < boardGameMatrix.size();++col) {
				if (boardGameMatrix[row][col] == 0) {
					Game::MakeMove(boardGameMatrix, moveCount, row, col, Constants::PLAYER_AI);

					int valCur = MiniMax(boardGameMatrix, moveCount, row, col, alpha, beta, false, depth - 1);
					if (valCur > valBest) {
						valBest = valCur;
						moveBest.first = row;
						moveBest.second = col;
					}

					Game::UndoMove(boardGameMatrix, moveCount, row, col);

					alpha = (valCur > alpha) ? valCur : alpha;
					if (beta < alpha) break;

				}
			}
		}
		return moveBest;
	}

	int MiniMax(
		vector<vector<short>>& boardGameMatrix,
		int& moveCount,
		const int& rowLastMove,
		const int& colLastMove,
		int alpha,
		int beta,
		const bool& isMaximizingPlayer,
		const int& depth) {


		const int rowLowerLimit = (rowLastMove - Constants::LOOKUP_RANGE >= 0) ? rowLastMove - Constants::LOOKUP_RANGE : 0;
		const int rowUpperLimit = (rowLastMove + Constants::LOOKUP_RANGE <= Constants::BOARD_SIZE) ? rowLastMove + Constants::LOOKUP_RANGE : Constants::BOARD_SIZE;
		const int colLowerLimit = (colLastMove - Constants::LOOKUP_RANGE >= 0) ? colLastMove - Constants::LOOKUP_RANGE : 0;
		const int colUpperLimit = (colLastMove + Constants::LOOKUP_RANGE <= Constants::BOARD_SIZE ) ? colLastMove + Constants::LOOKUP_RANGE : Constants::BOARD_SIZE;


		const int playerValue = (!isMaximizingPlayer) ? Constants::PLAYER_AI : Constants::PLAYER_HUMAN;

		//UI::PlacePoints(boardGameMatrix, 10, 10);
		//UI::GotoXY(30, 10);
		//cout << evalValue << " " << rowLastMove << " " << colLastMove << " " << !isMaximizingPlayer;
		//char c = _getch();
		//
		if (depth == 0 || Logic::GetGameState(boardGameMatrix, moveCount, rowLastMove, colLastMove, playerValue) != Constants::NULL_VALUE) {
			const int evalValue = Eval(boardGameMatrix, moveCount, rowLastMove, colLastMove, isMaximizingPlayer);
			return evalValue;
		}

		if (isMaximizingPlayer) {
			int valBest = -Constants::INF;
			for (int row = rowLowerLimit;row < rowUpperLimit;++row) {
				for (int col = colLowerLimit;col < colUpperLimit;++col) {
					if (boardGameMatrix[row][col] == 0) {
						Game::MakeMove(boardGameMatrix, moveCount, row, col, Constants::PLAYER_AI);
						int valCur = MiniMax(boardGameMatrix, moveCount, row, col, alpha, beta, false, depth - 1);
						valBest = (valCur > valBest) ? valCur : valBest;
						Game::UndoMove(boardGameMatrix, moveCount, row, col);

						alpha = (valCur > alpha) ? valCur : alpha;
						if (beta < alpha) break;
					}
				}
			}
			return valBest;
		}
		else {
			int valBest = Constants::INF;
			for (int row = 0;row < boardGameMatrix.size();++row) {
				for (int col = 0;col < boardGameMatrix.size();++col) {
					if (boardGameMatrix[row][col] == 0) {
						Game::MakeMove(boardGameMatrix, moveCount, row, col, Constants::PLAYER_HUMAN);
						int valCur = MiniMax(boardGameMatrix, moveCount, row, col, alpha, beta, true, depth - 1);
						valBest = (valCur < valBest) ? valCur : valBest;
						Game::UndoMove(boardGameMatrix, moveCount, row, col);

						beta = (valCur < beta) ? valCur : beta;
						if (beta < alpha) break;
					}
				}
			}
			return valBest;
		}
	}

}