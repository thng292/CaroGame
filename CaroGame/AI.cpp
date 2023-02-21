//int moveCount = 0;
//int winValueCount = 3;
//int rowCur = 0, colCur = 0;
//
//const int INF = 1000, NULL_VALUE = -5;
//int rowChosen = -1, colChosen = -1;
//
//void MakeMove(const int &row, const int &col, const int&playerValue) {
//	boardPointArray[row][col].value = playerValue;
//	moveCount++;
//}
//
//void UndoMove(const int &row, const int &col) {
//	boardPointArray[row][col].value = 0;
//	moveCount--;
//}
//
//
//bool CheckLeftDiagonalWin(const int &rowCur, const int &colCur, const int &playerValue) {
//	int pointSameValueCount = 1;
//	for (int row = rowCur + 1, col = colCur + 1;row < boardSize && col < boardSize; ++row, ++col) {
//		if (boardPointArray[row][col].value == playerValue) {
//			pointSameValueCount++;
//			if (pointSameValueCount == winValueCount) {
//				return 1;
//			}
//		}
//		else {
//			break;
//		}
//	}
//
//	
//
//	for (int row = rowCur - 1, col = colCur - 1;row >= 0 && col >= 0; --row, --col) {
//		if (boardPointArray[row][col].value == playerValue) {
//			pointSameValueCount++;
//			if (pointSameValueCount == winValueCount) {
//				return 1;
//			}
//		}
//		else {
//			break;
//		}
//
//	}
//	
//	return 0;
//
//}
//
//bool CheckRightDiagonalWin(const int &rowCur, const int &colCur, const int &playerValue) {
//	int pointSameValueCount = 1;
//	for (int row = rowCur - 1, col = colCur + 1;row >= 0 && col < boardSize; --row, ++col) {
//		if (boardPointArray[row][col].value == playerValue) {
//			pointSameValueCount++;
//			if (pointSameValueCount == winValueCount) {
//				return 1;
//			}
//		}
//		else {
//			break;
//		}
//	}
//
//	
//
//	
//
//	for (int row = rowCur + 1, col = colCur - 1;row < boardSize && col >= 0; ++row, --col) {
//		if (boardPointArray[row][col].value == playerValue) {
//			pointSameValueCount++;
//			if (pointSameValueCount == winValueCount) {
//				return 1;
//			}
//		}
//		else {
//			break;
//		}
//
//	}
//	
//	return 0;
//
//}
//
//bool CheckHorizontalWin(const int &rowCur, const int &colCur, const int &playerValue) {
//	int pointSameValueCount = 1;
//	for (int col = colCur + 1;col < boardSize;++col) {
//		if (boardPointArray[rowCur][col].value == playerValue) {
//			pointSameValueCount++;
//			if (pointSameValueCount == winValueCount) {
//				return 1;
//			}
//		}
//		else {
//			break;
//		} 
//	}
//
//	for (int col = colCur - 1;col >= 0;--col) {
//		if (boardPointArray[rowCur][col].value == playerValue) {
//			pointSameValueCount++;
//
//			if (pointSameValueCount == winValueCount) {
//				return 1;
//			}
//		}
//		else {
//			break;
//		} 
//	}
//
//	return 0;
//
//}
//
//bool CheckVerticalWin(const int &rowCur, const int &colCur, const int &playerValue) {
//	int pointSameValueCount = 1;
//	for (int row = rowCur + 1;row < boardSize;++row) {
//		if (boardPointArray[row][colCur].value == playerValue) {
//			pointSameValueCount++;
//			if (pointSameValueCount == winValueCount) {
//				return 1;
//			}
//		}
//		else {
//			break;
//		} 
//	}
//
//	for (int row = rowCur - 1;row >= 0;--row) {
//		if (boardPointArray[row][colCur].value == playerValue) {
//			pointSameValueCount++;
//			if (pointSameValueCount == winValueCount) {
//				return 1;
//			}
//		}
//		else {
//			break;
//		} 
//	}
//
//	return 0;
//
//}
//
//bool CheckDraw() {
//	return (moveCount == boardSize * boardSize);
//}
//
//int GetGameState(const int &rowCur, const int &colCur, const int &playerValue) {
//	if (CheckRightDiagonalWin(rowCur, colCur, playerValue) 
//		|| CheckLeftDiagonalWin(rowCur, colCur, playerValue)
//		|| CheckHorizontalWin(rowCur, colCur, playerValue) 
//		|| CheckVerticalWin(rowCur, colCur, playerValue)) {
//		return (playerValue == playerHuman)? -1:1;
//	}
//
//	if (CheckDraw()) {
//		return 0;
//	}
//	return NULL_VALUE;
//}
//
//int Eval(const int &rowLastMove, const int &colLastMove, bool isMaximizingPlayer) {
//	int playerValue = (!isMaximizingPlayer)? playerAI:playerHuman;
//	return GetGameState(rowLastMove, colLastMove, playerValue);
//}
//
//void GetBestMove(const int &rowLastMove, bool isMaximizingPlayer, const int &colLastMove) {
//	int valBest = -INF; 
//	for (int row = 0;row < boardSize;++row) {
//		for (int col = 0;col < boardSize;++col) {
//			if (boardPointArray[row][col].value == 0) {
//				MakeMove(row, col, playerAI);
//
//				int valCur = MiniMax(false, row, col);
//				if (valCur > valBest) {
//					valBest = valCur;
//					rowChosen = row;
//					colChosen = col;
//				}
//					
//				UndoMove(row, col);
//			}
//		}
//	}
//}
//
//int MiniMax(const bool &isMaximizingPlayer, const int &rowLastMove, const int &colLastMove) {
//	const int evalValue = Eval(rowLastMove, colLastMove, isMaximizingPlayer);
//	// PlacePoints(20, 20);
//	// cout << "   Eval: " << evalValue << "|" << "x: " << rowLastMove << "y: " << colLastMove;
//	// char c = getch();
//	if (evalValue != NULL_VALUE) {
//		return evalValue;
//	}
//
//	if (isMaximizingPlayer) {
//		int valBest = -INF; 
//
//		for (int row = 0;row < boardSize;++row) {
//			for (int col = 0;col < boardSize;++col) {
//				if (boardPointArray[row][col].value == 0) {
//					MakeMove(row, col, playerAI);
//
//					int valCur = MiniMax(false, row, col);
//					valBest = (valCur > valBest)? valCur:valBest;
//
//					
//										
//					UndoMove(row, col);
//				}
//			}
//		}
//
//		return valBest;
//	}		
//	else {
//		int valBest = INF; 
//		for (int row = 0;row < boardSize;++row) {
//			for (int col = 0;col < boardSize;++col) {
//				if (boardPointArray[row][col].value == 0) {
//					MakeMove(row, col, playerHuman);
//
//					int valCur = MiniMax(true, row, col);
//					valBest = (valCur < valBest)? valCur:valBest;
//					
//					UndoMove(row, col);
//
//				}
//			}
//		}
//		return valBest;
//	}
//
//}
