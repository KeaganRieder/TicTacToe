#ifndef TICTACBOT_H
#define TICTACBOT_H

#include "Board.h"
// #include "map>
#include <vector>

const int MAX = 1000;
const int MIN = -1000;

//https://medium.com/chat-gpt-now-writes-all-my-articles/advanced-ai-alpha-beta-pruning-in-python-through-tic-tac-toe-70bb0b15db05#:~:text=In%20summary%2C%20alpha%2Dbeta%20pruning,with%20challenging%20and%20rewarding%20experiences.

// Summary
// defining function for used by the tic tac toe bot
// to examine the board and determine various aspects
class TicTacBot
{
private:
    // used to dertime if max or mins turn
    bool isMax;
    char botIcon;
    char playerIcon;

    //all posible actions. action are represnted as a pair in which
    // the first element is the rows, well the second represnted 
    // the col
    std::vector<std::pair<int,int>> possibleActions;

public:
    TicTacBot(char botIcon, char playerIcon);
    ~TicTacBot();

    // function which uses a minimax algorthim. it considers all possible
    // moves given the current state
    int FindBestMove(Board board, int depth, int alpha, int beta);

    // tries to guess where the Bots will place there token based
    // the most optimal move given the current board
    int DoMaxTurn(Board board, int depth, int alpha, int beta);

    // tries to guess where the player will place there token based
    // the most optimal move given the current board
    int DoMinTurn(Board board, int depth, int alpha, int beta);

    // returns the best possible move for the computer of bot
    // move is represnt as a pair in which first = row
    // second = col
    std::pair<int,int> PerformTurn(Board board);
};

#endif