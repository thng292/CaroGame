#include "GameScreenAction.h"

void GameScreenAction::UpdateGame(
    GameScreen gameScreen,
    GameAction::Board& board,
    short& moveCount,
    const GameAction::Point& move,
    const Constants::Player& player,
    GameState& gameState,
    bool loadFromSave
)
{
    if (move.row != -1) {
        View::Color color = (player.symbol == Constants::PLAYER_ONE.symbol)
                                ? (View::Color)Constants::PLAYER_ONE_COLOR
                                : (View::Color)Constants::PLAYER_TWO_COLOR;
        GameAction::MakeMove(board, moveCount, move, player.value);
    }

    if (!loadFromSave) {
        if (move.row != -1) gameState.moveList.push_back({move.row, move.col});
        gameScreen.logContainer.DrawToLogContainer(
            gameState.moveList,
            gameState.playerNameOne,
            gameState.playerNameTwo,
            gameState.playerOneFirst
        );
    }
}

void GameScreenAction::UndoMove(
    GameScreen& gameScreen,
    GameAction::Board& gameBoard,
    short& moveCount,
    GameState& curGameState,
    GameAction::Point& latestMove,
    GameAction::Point& previousToLastMove,
    Constants::Player& curPlayer,
    Constants::Player& prevPlayer,
    bool& isPlayerOneTurn
)
{
    GameAction::UndoMove(gameBoard, moveCount, latestMove);
    GameScreenAction::DeleteMoveFromScreen(gameScreen, latestMove);
    curGameState.moveList.pop_back();
    if (curGameState.moveList.size() != 0) {
        latestMove = {
            curGameState.moveList.back().first,
            curGameState.moveList.back().second};
        if (curGameState.moveList.size() != 0) curGameState.moveList.pop_back();
        if (curGameState.moveList.size() != 0)
            previousToLastMove = {
                curGameState.moveList.back().first,
                curGameState.moveList.back().second};
        else {
            previousToLastMove = {-1, -1};
        }

    } else {
        latestMove = {-1, -1};
        previousToLastMove = {-1, -1};
    }

    GameScreenAction::FlipTurn(prevPlayer, curPlayer, isPlayerOneTurn);


    GameScreenAction::UpdateGame(
        gameScreen, gameBoard, moveCount, latestMove, curPlayer, curGameState
    );

    GameScreenAction::HighlightMove(gameScreen, latestMove, prevPlayer.symbol);

}

void GameScreenAction::HighLightCursor(
    GameScreen& gameScreen,
    const GameAction::Board& gameBoard,
    const GameAction::Point& curPos,
    const GameAction::Point& latestMove
)
{
    std::wstring value = L" ";
    View::Color color = View::DEFAULT_TEXT_COLOR;
    if (gameBoard[curPos.row][curPos.col] != 0) {
        if (gameBoard[curPos.row][curPos.col] == Constants::PLAYER_ONE.value) {
            if (curPos.row == latestMove.row && curPos.col == latestMove.col) {
                color = (View::Color)Constants::PLAYER_ONE_HIGHLIGHT;
            } else color = (View::Color)Constants::PLAYER_ONE_COLOR;
            value = Constants::PLAYER_ONE.symbol;
        } else {
            if (curPos.row == latestMove.row && curPos.col == latestMove.col) {
                color = (View::Color)Constants::PLAYER_TWO_HIGHLIGHT;
            } else
                color = (View::Color)Constants::PLAYER_TWO_COLOR;
            value = Constants::PLAYER_TWO.symbol;
        }
            
    }
    gameScreen.boardContainer.DrawToBoardContainerCell(
        curPos.row, curPos.col, value, color, true
    );
}


void GameScreenAction::UnhighlightCursor(
    GameScreen& gameScreen,
    const GameAction::Board& gameBoard,
    const GameAction::Point& prevPos,
    const GameAction::Point& latestMove
)
{
    std::wstring value = L" ";
    View::Color color = View::DEFAULT_TEXT_COLOR;
    if (gameBoard[prevPos.row][prevPos.col] == Constants::PLAYER_ONE.value) {

            if (prevPos.row == latestMove.row && prevPos.col == latestMove.col) {
                color = (View::Color)Constants::PLAYER_ONE_HIGHLIGHT;
            } else
                color = (View::Color)Constants::PLAYER_ONE_COLOR;
        
        
        value = Constants::PLAYER_ONE.symbol;
    } else if (gameBoard[prevPos.row][prevPos.col] == Constants::PLAYER_TWO.value) {

            if (prevPos.row == latestMove.row && prevPos.col == latestMove.col) {
                color = (View::Color)Constants::PLAYER_TWO_HIGHLIGHT;
            } else
                color = (View::Color)Constants::PLAYER_TWO_COLOR;
        
       
        value = Constants::PLAYER_TWO.symbol;
    }
    
    gameScreen.boardContainer.DrawToBoardContainerCell(
        prevPos.row, prevPos.col, value, color, false
    );
}

void GameScreenAction::HightLightWin(
    const GameAction::Point& winMoveOne,
    const GameAction::Point& winMoveTwo,
    const std::wstring& playerValue,
    GameScreen& gameScreen,
    bool unhighlight
)
{
    GameAction::Point leftPoint, rightPoint;
    if (winMoveOne.col < winMoveTwo.col) {
        leftPoint = winMoveOne;
        rightPoint = winMoveTwo;
    } else {
        leftPoint = winMoveTwo;
        rightPoint = winMoveOne;
    }

    short rowAddition = 0,
          colAddition = (leftPoint.col == rightPoint.col) ? 0 : 1;

    if (leftPoint.row < rightPoint.row) {
        rowAddition = 1;
    } else if (leftPoint.row > rightPoint.row) {
        rowAddition = -1;
    }

    short cnt = 0;
    GameAction::Point point = leftPoint;

    View::Color color;
    if (unhighlight) {
        if (playerValue == Constants::PLAYER_ONE.symbol)
            color = (View::Color)Constants::PLAYER_ONE_COLOR;
        else
            color = (View::Color)Constants::PLAYER_TWO_COLOR;
    } else
        color = (View::Color)Constants::WIN_HIGHLIGHT;

    while (cnt < 5) {
        gameScreen.boardContainer.DrawToBoardContainerCell(
            point.row, point.col, playerValue, color
        );
        point.row += rowAddition;
        point.col += colAddition;
        cnt++;
    }
}

void GameScreenAction::HighlightMove(
    GameScreen& gameScreen,
    const GameAction::Point& move,
    const std::wstring value
)
{
    if (move.row == -1) return;
    View::Color color = (value == Constants::PLAYER_ONE.symbol)
                            ? (View::Color)Constants::PLAYER_ONE_HIGHLIGHT
                            : (View::Color)Constants::PLAYER_TWO_HIGHLIGHT;
    gameScreen.boardContainer.DrawToBoardContainerCell(
        move.row, move.col, value, color
    );
}

void GameScreenAction::UnhightlightMove(
    GameScreen& gameScreen,
    const GameAction::Point& move,
    const std::wstring value
)
{
    if (move.row == -1) return;
    View::Color color = (value == Constants::PLAYER_ONE.symbol)
                            ? (View::Color)Constants::PLAYER_ONE_COLOR
                            : (View::Color)Constants::PLAYER_TWO_COLOR;
    gameScreen.boardContainer.DrawToBoardContainerCell(
        move.row, move.col, value, color
    );
}

GameAction::Point GameScreenAction::HandleState(
    const GameAction::Board& board,
    const short& moveCount,
    const GameAction::Point& move,
    const Constants::Player& player,
    const bool& isPlayerOneTurn,
    GameState& curGameState,
    short& endGame,
    GameScreen& gameScreen
)
{
    GameAction::Point winPoint;

    short state = Logic::GetGameState(
        board, moveCount, move, player.value, winPoint, true
    );
    switch (state) {
        case Logic::WIN_VALUE:
            if (isPlayerOneTurn) {
                curGameState.playerScoreOne++;
                endGame = Constants::END_GAME_WIN_ONE;
            } else {
                curGameState.playerScoreTwo++;
                endGame = Constants::END_GAME_WIN_TWO;
            }
            HightLightWin(move, winPoint, player.symbol, gameScreen);
            break;
        case Logic::DRAW_VALUE:
            endGame = Constants::END_GAME_DRAW;
            break;
    }
    return winPoint;
}

void GameScreenAction::LoadGameToView(
    GameScreen& gameScreen,
    GameAction::Board& board,
    short& moveCount,
    GameState gameState,
    AI& ai
)
{
    bool isPlayerOne = gameState.playerOneFirst;

    const short moveListSize = gameState.moveList.size();
    Constants::Player player;
    GameAction::Point move;

    for (size_t i = 0; i < moveListSize; ++i) {
        player = (isPlayerOne) ? Constants::PLAYER_ONE : Constants::PLAYER_TWO;
        move = {gameState.moveList[i].first, gameState.moveList[i].second};

        ai.UpdatePrivateValues(move);
        board[move.row][move.col] = player.value;
        UpdateGame(gameScreen, board, moveCount, move, player, gameState, true);
        if (i == moveListSize - 1)
            HighlightMove(gameScreen, move, player.symbol);
        isPlayerOne = !isPlayerOne;
    }
}

void GameScreenAction::DeleteMoveFromScreen(
    GameScreen& gameScreen, const GameAction::Point& move
)
{
    if (move.row == -1) return;
    gameScreen.boardContainer.DrawToBoardContainerCell(
        move.row, move.col, L" "
    );
}

GameAction::Point GameScreenAction::GetHintMove(
    GameAction::Board& board,
    short moveCount,
    bool isPlayerOneTurn,
    AI ai
)
{
    if (isPlayerOneTurn) {
        ai.PLAYER_AI = Constants::PLAYER_ONE.value;
        ai.PLAYER_HUMAN = Constants::PLAYER_TWO.value;
    } else {
          ai.PLAYER_AI = Constants::PLAYER_TWO.value;
        ai.PLAYER_HUMAN = Constants::PLAYER_ONE.value;
    }
    
    if (moveCount == 0) return ai.GetFirstMove();
    return ai.GetBestMove(board, moveCount);

}

void GameScreenAction::DrawMove(
    GameScreen& gameScreen, const GameAction::Point& move, const Constants::Player &player, const View::Color &color
)
{
    gameScreen.boardContainer.DrawToBoardContainerCell(
        move.row, move.col, player.symbol, color
    );
}

void GameScreenAction::FlipTurn(
    Constants::Player& prevPlayer,
    Constants::Player& curPlayer,
    bool& isPlayerOneTurn
)
{
    isPlayerOneTurn = !isPlayerOneTurn;
    prevPlayer = curPlayer;
    curPlayer =
        (isPlayerOneTurn) ? Constants::PLAYER_ONE : Constants::PLAYER_TWO;
}

void GameScreenAction::AIMove(
    GameScreen& gameScreen, GameAction::Board& board, short&moveCount, bool& isAIthinking, AI& ai, GameState& gameState
)
{
    GameAction::Point move = ai.GetBestMove(board, moveCount);
    GameScreenAction::HighlightMove(gameScreen, move, L"X");
    UpdateGame(
        gameScreen, board, moveCount, move, Constants::PLAYER_ONE, gameState
    );
    isAIthinking = false;
}

