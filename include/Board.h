#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include <iomanip>

//
// Board const
//
const int BOARD_SIZE = 3;
const int BOT_WIN = 1;
const int PLAYER_WIN = -1;

// Summary
// Board defines the tic tac toe board, allowing
// keeping track of the boards state,
class Board
{
private:
    // contains the content of the board which is
    // represnt as a 3 x 3 matirx of chars
    char contents[BOARD_SIZE][BOARD_SIZE];
    char playerIcon;
    char botIcon;
    int turn;

public:
    // default constructor initializing the board
    Board();

    ~Board();

    void SetPlayerIcon(char icon);
    char GetPlayerIcon();
    // returns true if valid move (empty space) otherwise
    // returns false
    bool PlacePlayerIcon(int row, int col);

    void SetBotIcon(char icon);
    char GetBotIcon();
    // returns true if valid move (empty space) otherwise
    // returns false
    void PlaceBotIcon(int row, int col);

    //
    // functions handling the board
    //
    
    // checks if provided cords on board are empty
    // returns true if contenst[row,col] = '_'
    // returns false otherwise
    bool SpaceEmpty(int row, int col);

    // checks if teher are any space left on the board
    // returns true if there is
    // returns false if not
    bool SpacesLeft();

    // checks if theres been a victor
    // this also acts as evaluate function used by the bot
    // to dertimnine it's move.
    // function returns 0 if no victors present,
    // -1 if player victory and 1 if bots
    int CheckForVictor();

    void IncreaseTurn(){
        turn++;
    }

    // prints out the board and current turn to terminal
    void PrintBoard();

    //
    // operator overloading
    //

    // overloaidng index operator
    char *operator[](int index)
    {
        return contents[index];
    }
};

#endif
