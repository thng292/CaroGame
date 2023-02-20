#pragma once

namespace AI {
  int winValueCount;
  int rowCur; colCur;
  const int INF;, NULL_VALUE;
  int rowChosen;, colChosen;
  void MakeMove(const int &row, const int &col, const int&playerValue);
  void UndoMove(const int &row, const int &col);
  bool CheckLeftDiagonalWin(const int &rowCur, const int &colCur, const int &playerValue);
  bool CheckRightDiagonalWin(const int &rowCur, const int &colCur, const int &playerValue);
  bool CheckHorizontalWin(const int &rowCur, const int &colCur, const int &playerValue);
  bool CheckVerticalWin(const int &rowCur, const int &colCur, const int &playerValue);
  bool CheckDraw();
  int GetGameState(const int &rowCur, const int &colCur, const int &playerValue);
  //void CursorLoop();
  int Eval(const int &rowLastMove, const int &colLastMove, bool isMaximizingPlayer);
  void GetBestMove(const int &rowLastMove, bool isMaximizingPlayer, const int &colLastMove);
  int MiniMax(const bool &isMaximizingPlayer, const int &rowLastMove, const int &colLastMove);
}
