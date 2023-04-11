#pragma once
#include <format>

#include "AI.h"
#include "Constants.h"
#include "GameAction.h"
#include "GameScreen.h"
#include "GameState.h"
#include "Language.h"
#include "Logic.h"
#include "View.h"
#include "Theme.h"
#include "Config.h"

namespace GameScreenAction {

    typedef std::vector<std::vector<View::Color>> ColorMatrix;

    void UpdateGame(
        GameScreen gameScreen,
        GameAction::Board& board,
        short& moveCount,
        const GameAction::Point& move,
        const Constants::Player& player,
        GameState& gameState,
        bool loadFromSave = false
    );

    void UndoMove(
        GameScreen& gameScreen,
        GameAction::Board& gameBoard,
        short& moveCount,
        GameState& curGameState,
        GameAction::Point& latestMove,
        GameAction::Point& previousToLastMove,
        Constants::Player& curPlayer,
        Constants::Player& prevPlayer,
        bool& isPlayerOneTurn,
        ColorMatrix& colorMatrix
    );

    void HighLightCursor(
        GameScreen& gameScreen,
        const GameAction::Board& gameBoard,
        const GameAction::Point& curPos,
        const ColorMatrix& colorMatrix,
        std::mutex& lock,
        bool isGhostMode

    );

    void UnhighlightCursor(
        GameScreen& gameScreen,
        const GameAction::Board& gameBoard,
        const GameAction::Point& curPos,
        const ColorMatrix& colorMatrix,
        std::mutex& lock

    );

    void HightLightWin(
        const GameAction::Point& winMoveOne,
        const GameAction::Point& winMoveTwo,
        const std::wstring& playerValue,

        GameScreen& gameScreen,
        bool unhighlight = false
    );

    void HighlightMove(
        GameScreen& gameScreen,
        const GameAction::Point& move,
        const std::wstring value,
        ColorMatrix& colorMatrix
    );

    void UnhightlightMove(
        GameScreen& gameScreen,
        const GameAction::Point& move,
        const std::wstring value,
        ColorMatrix& colorMatrix
    );

    GameAction::Point HandleState(
        const GameAction::Board& board,
        const short& moveCount,
        const GameAction::Point& move,
        const Constants::Player& player,
        const bool& isPlayerOneTurn,
        GameState& curGameState,
        short& endGame,
        GameScreen& gameScreen

    );

    void LoadGameToView(
        GameScreen& gameScreen,
        GameAction::Board& board,
        short& moveCount,
        GameState& gameState,
        AI& ai,
        std::vector<GameAction::Point>& warningPointList,

        ColorMatrix& colorMatrix,
        std::mutex& lock

    );

    void DeleteMoveFromScreen(
        GameScreen& gameScreen,
        const GameAction::Point& move,
        ColorMatrix& colorMatrix
    );

    GameAction::Point GetHintMove(
        GameAction::Board& board, short moveCount, bool isPlayerOneTurn, AI ai
    );

    void DeleteHintMove(
        GameScreen& gameScreen,
        GameAction::Point& move,
        ColorMatrix& colorMatrix,
        std::mutex& lock

    );

    void DrawHintMove(
        GameScreen& gameScreen,
        const GameAction::Point& move,
        const Constants::Player& player,
        ColorMatrix& colorMatrix,
        std::mutex& lock

    );

    void DeleteGhostMoves(
        GameScreen& gameScreen,

        std::vector<GameAction::Point>& moveList,
        bool& isPlayerOneTurn,
        Constants::Player& prevPlayer,
        Constants::Player& curPlayer,
        ColorMatrix& colorMatrix

    );

    void TurnOffGhostMode(
        GameScreen& gameScreen,
        GameAction::Board& currentBoard,
        const GameAction::Board gameBoard,
        std::vector<GameAction::Point>& moveList,
        bool& isGhostMode,
        bool& isPlayerOneTurn,
        Constants::Player& prevPlayer,
        Constants::Player& curPlayer,
        ColorMatrix& colorMatrix,
        std::mutex& lock

    );

    void MakeGhostMove(
        GameScreen& gameScreen,
        GameAction::Board& board,

        std::vector<GameAction::Point>& moveList,
        const GameAction::Point& move,
        bool& isPlayerOneTurn,
        Constants::Player& prevPlayer,
        Constants::Player& curPlayer,
        ColorMatrix& colorMatrix,
        std::mutex& lock

    );

    void HandlePlayerMove(
        GameScreen& gameScreen,
        GameAction::Board& currentBoard,
        GameAction::Board& gameBoard,
        short& moveCount,
        GameAction::Point& prevMove,
        GameAction::Point& curMove,
        const GameAction::Point& move,
        bool& isPlayerOneTurn,
        Constants::Player& prevPlayer,
        Constants::Player& curPlayer,
        AI& myAI,
        GameState& curGameState,
        short& endGame,
        ColorMatrix& colorMatrix,
        std::mutex& lock

    );

    void DrawGhostMove(
        GameScreen& gameScreen,
        const GameAction::Point& move,
        const Constants::Player& player,
        ColorMatrix& colorMatrix
    );

    void DrawMove(
        GameScreen& gameScreen,
        const GameAction::Point& move,
        const Constants::Player& player,
        ColorMatrix& colorMatrix,
        View::Color color
    );

    void FlipTurn(
        Constants::Player& prevPlayer,
        Constants::Player& curPlayer,
        bool& isPlayerOneTurn
    );

    bool HighlightWarning(
        GameScreen& gameScreen,
        const GameAction::Board& board,
        const GameAction::Point& move,
        const Constants::Player& player,
        std::vector<GameAction::Point>& pointList,
        ColorMatrix& colorMatrix,
        std::mutex& lock


    );

    void UnhighlightWarning(
        GameScreen& gameScreen,
        const Constants::Player& player,
        std::vector<GameAction::Point>& pointList,
        ColorMatrix& colorMatrix,
        std::mutex& lock

    );

    void ScrollLogUp(GameScreen& gameScreen, short& goBack, const GameState& gameState, std::mutex& lock);
    void ScrollLogDown(
        GameScreen& gameScreen,
        short& goBack,
        const GameState& gameState,
        std::mutex& lock
    );

}  // namespace GameScreenAction