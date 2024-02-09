#include "TicTacBot.h"

TicTacBot::TicTacBot(char icon)
{
    isMax = false;
    botIcon = icon;
}
TicTacBot::~TicTacBot()
{
}

int TicTacBot::FindBestMove(Board& board)
{
    // check for scoure
    int score = board.CheckForVictor();

    // if minimizer or maximer has one return their score
    if (score == 1 || score == -1)
    {
        return score;
    }

    // no more moves
    else if (!board.SpacesLeft())
    {
        return 0;
    }

    // maximizers move
    if (isMax)
    {
        return DoMaxTurn(board);
    }

    // minimizers move
    else
    {
        return DoMinTurn(board);
    }
}

int TicTacBot::DoMaxTurn(Board& board)
{
    int bestMove = -10000;

    for (int row = 0; row < BOARD_ROWS; row++)
    {
        for (int col = 0; col < BOARD_COLS; col++)
        {
            if (board.SpaceEmpty(row, col))
            {
                //make move
                board[row][col] = botIcon;

                isMax = !isMax;
                bestMove = std::max(bestMove, FindBestMove(board));

                //undo move 
                board[row][col] = '_';
            }
        }
    }

    return bestMove;
}

int TicTacBot::DoMinTurn(Board& board)
{
    int bestMove = 10000;

    for (int row = 0; row < BOARD_ROWS; row++)
    {
        for (int col = 0; col < BOARD_COLS; col++)
        {
            if (board.SpaceEmpty(row, col))
            {
                //make move
                board[row][col] = botIcon;

                isMax = !isMax;
                bestMove = std::min(bestMove, FindBestMove(board));

                //undo move 
                board[row][col] = '_';
            }
        }
    }

    return bestMove;
}

Move TicTacBot::PerformTurn(Board& board)
{
    int best = -1000;
    Move move;
    move.row = -1;
    move.col = -1;

    //move through the board
    for (int row = 0; row < BOARD_ROWS; row++)
    {
        for (int col = 0; col < BOARD_COLS; col++)
        {
            if (board.SpaceEmpty(row, col))
            {
                //make move
                board[row][col] = botIcon;
                 
                // isMax = false;
                int moveValue = FindBestMove(board);
                std::cout<<"\n move "<<moveValue<<"\n";

                board[row][col] = '_';

                // if value of curent move is greater then the best value
                // update it
                if (moveValue > best)
                {
                    best = moveValue;
                    move.row = row;
                    move.col = col;
                }
                
            }
        }
    }
    return move;
}