#pragma once
#include <format>
#include <mutex>
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

    void HightLightWin(
        const GameAction::Point& winMoveOne,
        const GameAction::Point& winMoveTwo,
        const std::wstring& playerValue,

        GameScreen& gameScreen

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

    void HandleState(
        const GameAction::Board& board,
        const short& moveCount,
        const GameAction::Point& move,
        const Constants::Player& player,
        const bool& isPlayerOneTurn,
        GameState& curGameState,
        bool& endGame,
        GameScreen& gameScreen

    );

    void LoadGameToView(
        GameScreen& gameScreen,
        GameAction::Board& board,
        short& moveCount,
        GameState gameState,
        AI& ai
    );


    void DeleteMoveFromScreen(GameScreen& gameScreen, const GameAction::Point &move); 

}  // namespace GameView