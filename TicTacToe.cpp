/*
################################################################################
   
   Tic tac Toe

################################################################################
*/

#include "Board.h"
#include "TicTacBot.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string>

//
// constants and globals
//

//
// function dec
//

int main(){
    Board* board = new Board();

    std::string temp;
    
    board->PrintBoard();

    std::cin>> temp;
    return 0;
}