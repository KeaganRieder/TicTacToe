#ifndef TICTACBOT_H
#define TICTACBOT_H

#include "Board.h"
//https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-4-alpha-beta-pruning/
//struct uses to pass a  the cords of the given move
struct Move
{
    int row;
    int col;
};


// Summary
// defining function for used by the tic tac toe bot
// to examine the board and determine various aspects
class TicTacBot
{
private:
    // used to dertime if max or mins turn
    bool isMax;
    char botIcon;

public:
    TicTacBot(char icon);
    ~TicTacBot();

    // function which uses a minimax algorthim. it considers all possible
    // moves given the current state
    int FindBestMove(Board &board);

    // perfoms the max side of the Minimax algorthim
    int DoMaxTurn(Board &board);

    // perfoms the min side of the Minimax algorthim
    int DoMinTurn(Board &board);

    // returns the best possible move for the computer of bot
    Move PerformTurn(Board &board);
};

#endif