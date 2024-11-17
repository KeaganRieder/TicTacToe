#include "TicTacBot.h"

TicTacBot::TicTacBot(char botIcon, char playerIcon)
{
    this->botIcon = botIcon;
    this->playerIcon = playerIcon;

    // initalize all possible actions
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            std::pair<int, int> move; move.first = row; move.second = col;
            possibleActions.push_back(move);
        }
    }
}
TicTacBot::~TicTacBot()
{
}

int TicTacBot::FindBestMove(Board board, bool isMax, int alpha, int beta)
{
    int bestMove;

    // check for scoure
    int score = board.CheckForVictor();

    // checks to stop recursion
    bool maxWin = score == BOT_WIN;    // bot win
    bool minWin = score == PLAYER_WIN; // player win

    // check if maximizer has one game
    if (maxWin || minWin)
    {
        return score;
    }
    // check if no spaces are left
    else if (!board.SpacesLeft())
    {
        // tie sense no one won
        return 0;
    }

    // if none of the above continue recursion
    // bouncing back and forth between min and max
    if (isMax)
    {
        return DoMaxTurn(board, alpha, beta);
    }

    // do mins turn
    else
    {
        return DoMinTurn(board, alpha, beta);
    }
}

int TicTacBot::DoMaxTurn(Board board, int alpha, int beta)
{
    // do max's turn
    int bestMove = MIN;

    for (auto &&action : possibleActions)
    {
        int row = action.first;
        int col = action.second;
        if (board.SpaceEmpty(row, col))
        {
            // make move
            board[row][col] = 'x';

            int val = FindBestMove(board, false, alpha, beta);
            bestMove = std::max(bestMove, val);
            alpha = std::max(alpha, bestMove);

            // undo move
            board[row][col] = '_';
        }

        // perfom alpha beta pruining
        if (beta <= alpha)
        {
            break;
        }
    }

    return bestMove;
}

int TicTacBot::DoMinTurn(Board board, int alpha, int beta)
{
    int bestMove = MAX;

    for (auto &&action : possibleActions)
    {
        int row = action.first;
        int col = action.second;
        if (board.SpaceEmpty(row, col))
        {
            // make move
            board[row][col] = 'o';

            int val = FindBestMove(board, true, alpha, beta);
            bestMove = std::min(bestMove, val);
            beta = std::min(beta, bestMove);

            // undo move
            board[row][col] = '_';
        }

        // perfom alpha beta pruining
        if (beta <= alpha)
        {
            break;
        }
    }
    return bestMove;
}

std::pair<int, int> TicTacBot::PerformTurn(Board board)
{
    int best;
    std::pair<int, int> move; move.first = -1; move.second = -1;

    if (botIcon == 'o')
    {
        best = -1000;
    }
    else
    {
        best = 1000;
    }

    for (auto &&action : possibleActions)
    {
        int row = action.first;
        int col = action.second;
        // check if space is ocupied
        if (board.SpaceEmpty(row, col))
        {
            // check if bot is player o
            if (botIcon == 'o')
            { 
                // make bots move
                board[row][col] = 'o';

                //sense player 0 run max algorithim first
                //due to it handling placing player x
                int moveValue = FindBestMove(board, true, MIN, MAX);

                // undo
                board[row][col] = '_';

                // if value of curent move is greater then the best value
                // update it
                if (moveValue >= best)
                {
                    best = moveValue;
                    move = action;
                }
            }

            // or player x
            else
            {
                // make bots move
                board[row][col] = 'x';

                //sense player x run min algorithim first
                //due to it handling placing player o
                int moveValue = FindBestMove(board, false, MIN, MAX);

                // undo
                board[row][col] = '_';

                // if value of curent move is less then the best value
                // update it
                if (moveValue <= best)
                {
                    best = moveValue;
                    move = action;
                }
            }
        }
    }

    return move;
}