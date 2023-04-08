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
    bool& isPlayerOneTurn,
    ColorMatrix& colorMatrix
)
{
    GameAction::UndoMove(gameBoard, moveCount, latestMove);
    GameScreenAction::DeleteMoveFromScreen(gameScreen, latestMove, colorMatrix);
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
        gameScreen, gameBoard, moveCount, latestMove, prevPlayer, curGameState
    );

    GameScreenAction::HighlightMove(
        gameScreen, latestMove, prevPlayer.symbol, colorMatrix
    );
}

void GameScreenAction::HighLightCursor(
    GameScreen& gameScreen,
    const GameAction::Board& gameBoard,
    const GameAction::Point& curPos,
    const ColorMatrix& colorMatrix,
    std::mutex& lock

)
{
    std::wstring value = L" ";
    if (gameBoard[curPos.row][curPos.col] == Constants::PLAYER_ONE.value)
        value = Constants::PLAYER_ONE.symbol;
    else if (gameBoard[curPos.row][curPos.col] == Constants::PLAYER_TWO.value)
        value = Constants::PLAYER_TWO.symbol;
    View::Color color = colorMatrix[curPos.row][curPos.col];

    lock.lock();
    gameScreen.boardContainer.DrawToBoardContainerCell(
        curPos.row, curPos.col, value, color, true
    );
    lock.unlock();
}

void GameScreenAction::UnhighlightCursor(
    GameScreen& gameScreen,
    const GameAction::Board& gameBoard,
    const GameAction::Point& prevPos,
    const ColorMatrix& colorMatrix,
    std::mutex& lock
)
{
    std::wstring value = L" ";

    if (gameBoard[prevPos.row][prevPos.col] == Constants::PLAYER_ONE.value)
        value = Constants::PLAYER_ONE.symbol;
    else if (gameBoard[prevPos.row][prevPos.col] == Constants::PLAYER_TWO.value)
        value = Constants::PLAYER_TWO.symbol;
    View::Color color = colorMatrix[prevPos.row][prevPos.col];

    lock.lock();
    gameScreen.boardContainer.DrawToBoardContainerCell(
        prevPos.row, prevPos.col, value, color, false
    );
    lock.unlock();
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
    const std::wstring value,
    ColorMatrix& colorMatrix
)
{
    if (move.row == -1) return;
    View::Color color = (value == Constants::PLAYER_ONE.symbol)
                            ? (View::Color)Constants::PLAYER_ONE_HIGHLIGHT
                            : (View::Color)Constants::PLAYER_TWO_HIGHLIGHT;
    colorMatrix[move.row][move.col] = color;
    gameScreen.boardContainer.DrawToBoardContainerCell(
        move.row, move.col, value, color
    );
}

void GameScreenAction::UnhightlightMove(
    GameScreen& gameScreen,
    const GameAction::Point& move,
    const std::wstring value,
    ColorMatrix& colorMatrix
)
{
    if (move.row == -1) return;
    View::Color color = (value == Constants::PLAYER_ONE.symbol)
                            ? (View::Color)Constants::PLAYER_ONE_COLOR
                            : (View::Color)Constants::PLAYER_TWO_COLOR;
    colorMatrix[move.row][move.col] = color;
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
    GameState& gameState,
    AI& ai,
    std::vector<GameAction::Point>& warningPointList,
    ColorMatrix& colorMatrix
)
{
    bool isPlayerOne = gameState.playerOneFirst;

    const short moveListSize = gameState.moveList.size();
    Constants::Player player;
    GameAction::Point move;
    View::Color color;
    for (size_t i = 0; i < moveListSize; ++i) {
        if (isPlayerOne) {
            player = Constants::PLAYER_ONE;
            color = (View::Color)Constants::PLAYER_ONE_COLOR;

        } else {
            player = Constants::PLAYER_TWO;
            color = (View::Color)Constants::PLAYER_TWO_COLOR;
        }
        move = {gameState.moveList[i].first, gameState.moveList[i].second};
        board[move.row][move.col] = player.value;
        colorMatrix[move.row][move.col] = color;

        ai.UpdatePrivateValues(move);
        UpdateGame(gameScreen, board, moveCount, move, player, gameState, true);
        DrawMove(gameScreen, move, player, colorMatrix, color);
        if (i == moveListSize - 1) {
            HighlightWarning(
                gameScreen, board, move, player, warningPointList, colorMatrix
            );
            HighlightMove(gameScreen, move, player.symbol, colorMatrix);
        }
        isPlayerOne = !isPlayerOne;
    }
}

void GameScreenAction::DeleteMoveFromScreen(
    GameScreen& gameScreen,
    const GameAction::Point& move,
    ColorMatrix& colorMatrix

)
{
    if (move.row == -1) return;
    gameScreen.boardContainer.DrawToBoardContainerCell(
        move.row, move.col, L" "
    );
    colorMatrix[move.row][move.col] = View::Color::BLACK;
}

GameAction::Point GameScreenAction::GetHintMove(
    GameAction::Board& board, short moveCount, bool isPlayerOneTurn, AI ai
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

void GameScreenAction::DeleteHintMove(
    GameScreen& gameScreen,
    GameAction::Point& move,
    ColorMatrix& colorMatrix,
    std::mutex& lock

)
{
    if (move.row != -1) {
        lock.lock();
        GameScreenAction::DeleteMoveFromScreen(gameScreen, move, colorMatrix);
        lock.unlock();
    }
    move = {-1, -1};
}

void GameScreenAction::DrawHintMove(
    GameScreen& gameScreen,
    const GameAction::Point& move,
    const Constants::Player& player,
    ColorMatrix& colorMatrix,
    std::mutex& lock

)
{
    View::Color color = View::Color::YELLOW;
    lock.lock();
    DrawMove(gameScreen, move, player, colorMatrix, color);
    lock.unlock();
}

void GameScreenAction::DeleteGhostMoves(
    GameScreen& gameScreen,
    std::vector<GameAction::Point>& moveList,
    bool& isPlayerOneTurn,
    Constants::Player& prevPlayer,
    Constants::Player& curPlayer,
    ColorMatrix& colorMatrix

)
{
    for (auto& move : moveList) {
        GameScreenAction::DeleteMoveFromScreen(gameScreen, move, colorMatrix);
        FlipTurn(prevPlayer, curPlayer, isPlayerOneTurn);
    }
    moveList.clear();
}

void GameScreenAction::TurnOffGhostMode(
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
)
{
    isGhostMode = false;
    lock.lock();
    DeleteGhostMoves(
        gameScreen,
        moveList,
        isPlayerOneTurn,
        prevPlayer,
        curPlayer,
        colorMatrix
    );
    lock.unlock();
    currentBoard = gameBoard;
}

void GameScreenAction::MakeGhostMove(
    GameScreen& gameScreen,
    GameAction::Board& board,
    std::vector<GameAction::Point>& moveList,
    const GameAction::Point& move,
    bool& isPlayerOneTurn,
    Constants::Player& prevPlayer,
    Constants::Player& curPlayer,
    ColorMatrix& colorMatrix,
    std::mutex& lock
)
{
    board[move.row][move.col] = curPlayer.value;
    moveList.push_back(move);
    lock.lock();
    DrawGhostMove(gameScreen, move, curPlayer, colorMatrix);
    lock.unlock();
    FlipTurn(prevPlayer, curPlayer, isPlayerOneTurn);
}

void GameScreenAction::HandlePlayerMove(
    GameScreen& gameScreen,
    GameAction::Board& currentBoard,
    GameAction::Board& gameBoard,
    short& moveCount,
    GameAction::Point& previousToLastMove,
    GameAction::Point& latestMove,
    const GameAction::Point& move,
    bool& isPlayerOneTurn,
    Constants::Player& prevPlayer,
    Constants::Player& curPlayer,
    AI& myAI,
    GameState& curGameState,
    short& endGame,
    ColorMatrix& colorMatrix,
    std::mutex& lock
)
{
    previousToLastMove = latestMove;
    latestMove = move;

    lock.lock();
    UnhightlightMove(
        gameScreen, previousToLastMove, prevPlayer.symbol, colorMatrix
    );
    lock.unlock();

    lock.lock();
    HighlightMove(gameScreen, latestMove, curPlayer.symbol, colorMatrix);
    lock.unlock();

    lock.lock();
    UpdateGame(
        gameScreen, gameBoard, moveCount, latestMove, curPlayer, curGameState
    );
    lock.unlock();

    lock.lock();
    HandleState(
        gameBoard,
        moveCount,
        latestMove,
        curPlayer,
        isPlayerOneTurn,
        curGameState,
        endGame,
        gameScreen
    );

    lock.unlock();

    myAI.UpdatePrivateValues(latestMove);
    FlipTurn(prevPlayer, curPlayer, isPlayerOneTurn);
    currentBoard = gameBoard;
}

void GameScreenAction::DrawGhostMove(
    GameScreen& gameScreen,
    const GameAction::Point& move,
    const Constants::Player& player,
    ColorMatrix& colorMatrix
)
{
    View::Color color = View::Color::GRAY;
    DrawMove(gameScreen, move, player, colorMatrix, color);
}

void GameScreenAction::DrawMove(
    GameScreen& gameScreen,
    const GameAction::Point& move,
    const Constants::Player& player,
    ColorMatrix& colorMatrix,
    View::Color color
)
{
    colorMatrix[move.row][move.col] = color;
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

void GameScreenAction::HighlightWarning(
    GameScreen& gameScreen,
    const GameAction::Board& board,
    const GameAction::Point& move,
    const Constants::Player& player,
    std::vector<GameAction::Point>& pointList,
    ColorMatrix& colorMatrix
)
{
    pointList = GameAction::GetWarningPoints(board, move, player.value);
    if (pointList.size() != 3) return;
    for (auto& point : pointList) {
        DrawMove(gameScreen, point, player, colorMatrix, View::Color::MAGENTA);
    }
}

void GameScreenAction::UnhighlightWarning(
    GameScreen& gameScreen,
    const Constants::Player& player,
    std::vector<GameAction::Point>& pointList,
    ColorMatrix& colorMatrix
)
{
    if (pointList.size() != 3) return;
    View::Color color = (player.value == Constants::PLAYER_ONE.value)
                            ? (View::Color)Constants::PLAYER_ONE_COLOR
                            : (View::Color)Constants::PLAYER_TWO_COLOR;
    for (auto& point : pointList) {
        DrawMove(gameScreen, point, player, colorMatrix, color);
    }
    pointList.clear();
}
