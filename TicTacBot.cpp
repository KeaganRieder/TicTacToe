#include "TicTacBot.h"

TicTacBot::TicTacBot(char botIcon, char playerIcon)
{
    this->botIcon = botIcon;
    this->playerIcon = playerIcon;
}
TicTacBot::~TicTacBot()
{
}

int TicTacBot::FindBestMove(Board board, int depth, int alpha, int beta)
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
    // chekc if no spaces are left
    else if (!board.SpacesLeft())
    {
        // tie sense no one won
        return 0;
    }

    // if none of the above contunie recursion
    // bouncing back and forth between min and max

    if (isMax)
    {
       return DoMaxTurn(board, depth, alpha, beta);
    }

    // do mins turn
    else
    {
       return DoMinTurn(board, depth, alpha, beta);
    }
}

int TicTacBot::DoMaxTurn(Board board, int depth, int alpha, int beta)
{
    // do max's turn
    int bestMove = MIN;

    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            
            if (board.SpaceEmpty(row, col))
            {
                // make move
                board[row][col] = botIcon;

                isMax = !isMax;
                int val = FindBestMove(board, depth + 1, alpha, beta);
                bestMove = std::max(bestMove, val);
                alpha = std::max(alpha, bestMove);

                // undo move
                board[row][col] = '_';
            }

            //perfom alpha beta pruining
            if (beta <= alpha)
            {
                break;
            }
        }
    }

    return bestMove;
}

int TicTacBot::DoMinTurn(Board board, int depth, int alpha, int beta)
{
    int bestMove = MAX;

    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if (board.SpaceEmpty(row, col))
            {
                // make move
                board[row][col] = playerIcon;

                isMax = !isMax;
                int val = FindBestMove(board, depth + 1, alpha, beta);
                bestMove = std::min(bestMove, val);
                beta = std::min(beta, bestMove);
                // undo move
                board[row][col] = '_';
            }

            //perfom alpha beta pruining
            if (beta <= alpha)
            {
                break;
            }
        }
    }

    return bestMove;
}

std::pair<int, int> TicTacBot::PerformTurn(Board board)
{
    int best = -1000;
    std::pair<int, int> move;
    move.first = -1;
    move.second = -1;

    // move through the board
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            // check if space is ocupied
            if (board.SpaceEmpty(row, col))
            {
                // make bots move
                board[row][col] = botIcon;

                isMax = false;
                int moveValue = FindBestMove(board, 0, MIN, MAX);

                // undo
                board[row][col] = '_';

                // if value of curent move is greater then the best value
                // update it
                if (moveValue > best)
                {
                    best = moveValue;
                    move.first = row;
                    move.second = col;
                }
            }
        }
    }
    std::cout << "\n<<< the optimal move is: " << move.first << ", " << move.second << " >>>\n";
    return move;
}