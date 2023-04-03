#pragma once
#include <format>
#include <vector>

#include "AI.h"
#include "Constants.h"
#include "GameAction.h"
#include "GameScreen.h"
#include "GameState.h"
#include "Language.h"
#include "Logic.h"
#include "View.h"

namespace GameScreenAction {
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
        GameAction::Point& curMove,
        GameAction::Point& prevMove,
        Constants::Player& curPlayer,
        Constants::Player& prevPlayer,
        bool& isPlayerOneTurn
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
        const std::wstring value
    );

    void UnhightlightMove(
        GameScreen& gameScreen,
        const GameAction::Point& move,
        const std::wstring value
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
        GameState gameState,
        AI& ai
    );

    void DeleteMoveFromScreen(
        GameScreen& gameScreen, const GameAction::Point& move
    );

}  // namespace GameScreenAction