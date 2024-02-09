/*
################################################################################

   Tic tac Toe

################################################################################
*/

#include "Board.h"
#include "TicTacBot.h"
#include <iostream>
#include <string>

//
// constants and globals
//

bool playerTurn = true;

//
// function decleration
//

// allows the player to choose either x or o which
// ever isn't chosen is assigned to bot
void SelectToken(Board *board);

// outputs result of game
void PrintGameResults(Board *board);

// game loop determining who plays
void Play(Board *board, TicTacBot *bot);

//prints results of game
void PrintGameResults(Board& board);

//
// main program loop
//
int main()
{
    Board *board = new Board();
    TicTacBot *bot = nullptr;

    std::cout << "<<< Welcome to Tic Tac Toe >>> \n";

    SelectToken(board);
    bot = new TicTacBot(board->GetBotIcon());

    while (true)
    {
        Play(board, bot);

        // no spaces left meaning games done
        if (!board->SpacesLeft())
        {
            break;
        }
        else if (board->CheckForVictor() != 0)
        {
            break;
        }
    }
    PrintGameResults(*board);

    delete board;
    delete bot;

    std::string temp;
    std::cin >> temp;
    return 0;
}

//
// function implementaion
//
void SelectToken(Board *board)
{

    char token;

    std::cout << "\nPlease select if your 'x' or 'o' \n> ";

    // making sure inputs valid
    while (true)
    {
        std::cin >> token;
        if (token == 'x' || token == 'X')
        {
            board->SetPlayerIcon('X');
            board->SetBotIcon('O');
            break;
        }
        else if (token == 'o' || token == 'O')
        {
            board->SetPlayerIcon('O');
            board->SetBotIcon('X');
            break;
        }
        else
        {
            std::cout << "\n" << token
                      << " Isn't valid please input valid choices: 'x' or 'o' \n > ";
        }
    }
}

void Play(Board *board, TicTacBot *bot)
{
    int row = -1;
    int col = -1;
    Move botMove;
    board->PrintBoard();

    if (playerTurn)
    {
        std::cout << "\n<<< Players Turn >>> \n";
        std::cout << "\n> What is your move? \n> ";

        //
        while (true)
        {
            std::cin >> row >> col;

            // move is valid
            if (board->PlacePlayerIcon(row, col))
            {
                break;
            }
            std::cout << "\nPlease select valid move \n> ";
        }
    }
    else
    {
        std::cout << "\n<<< Bots Turn >>> \n";
        botMove = bot->PerformTurn(*board);
        board->PlaceBotIcon(botMove.row,botMove.col);
    }

    // increase turn
    board->IncreaseTurn();
    playerTurn = !playerTurn;
}

void PrintGameResults(Board& board)
{
    int victorVal = board.CheckForVictor();
    std::cout << "\n<<< Games result are >>> \n";

    board.PrintBoard();

    std::cout << "\n> The victor is ";

    if (victorVal == 1)
    {
        std::cout << "The Player \n";
    }
    else if (victorVal == -1)
    {
        std::cout << "Tic Tac Bot \n";
    }
    else
    {
        std::cout << "No One \n";
    }
}