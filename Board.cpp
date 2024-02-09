#include "Board.h"

Board::Board()
{
    turn = 0;
    playerIcon = ' ';
    botIcon = ' ';

    for (int row = 0; row < BOARD_ROWS; row++)
    {
        for (int col = 0; col < BOARD_COLS; col++)
        {
            contents[row][col] = '_';
        }
    }
}

Board::~Board(){

}

void Board::SetPlayerIcon(char icon)
{
    playerIcon = icon;
}
char Board::GetPlayerIcon()
{
    return playerIcon;
}

// bool Board::PlacePlayerIcon(int row, int col)
// {

//     // make sure space is unocupied
//     if (contents[row][col] == '_')
//     {
//         contents[row][col] = playerIcon;
//         return true;
//     }

//     return false;
// }
// bool Board::PlacePlayerIcon(Move move)
// {
//     return PlacePlayerIcon(move.row, move.col);
// }

void Board::SetBotIcon(char icon)
{
    botIcon = icon;
}
char Board::GetBotIcon()
{
    return botIcon;
}
// bool Board::PlaceComputerIcon(int row, int col)
// {

//     // make sure space is unocupied
//     if (contents[row][col] == '_')
//     {
//         contents[row][col] = botIcon;
//         return true;
//     }

//     return false;
// }
// bool Board::PlaceComputerIcon(Move move)
// {
//     return PlaceComputerIcon(move.row, move.col);
// }

//
// function handling board implementaion
//

bool Board::SpaceEmpty(int row, int col){
    return contents[row][col] == '_';
}

bool Board::SpacesLeft()
{
    int spacesLeft = 0;
    for (int row = 0; row < BOARD_ROWS; row++)
    {
        for (int col = 0; col < BOARD_COLS; col++)
        {
            if (SpaceEmpty(row,col))
            {
                spacesLeft++;
            }
        }
    }

    // if spaces left is greater then 0 then
    // returns true otherwise return false
    return spacesLeft > 0;
}

int Board::CheckForVictor()
{
    // check rows for player or bot victory
    for (int row = 0; row < BOARD_ROWS; row++)
    {
        if (contents[row][0] == contents[row][1] && contents[row][1] == contents[row][2])
        {
            // player victory
            if (contents[row][0] == playerIcon)
            {
                return 1;
            }
            // bot victory
            else if (contents[row][0] == botIcon)
            {
                return -1;
            }
        }
    }

    // check col for player or bot victory
    for (int col = 0; col < BOARD_COLS; col++)
    {
        if (contents[0][col] == contents[1][col] && contents[1][col] == contents[2][col])
        {
            // player victory
            if (contents[0][col] == playerIcon)
            {
                return 1;
            }
            // bot victory
            else if (contents[0][col] == botIcon)
            {
                return -1;
            }
        }
    }

    // check diagonals
    if (contents[0][0] == contents[1][1] && contents[1][1] == contents[2][2])
    {
        // player victory
        if (contents[0][0] == playerIcon)
        {
            return 1;
        }
        // bot victory
        else if (contents[0][0] == botIcon)
        {
            return -1;
        }
    }
    
    else if (contents[2][0] == contents[1][1] && contents[1][1] == contents[0][2])
    {
        // player victory
        if (contents[2][0] == playerIcon)
        {
            return 1;
        }
        // bot victory
        else if (contents[2][0] == botIcon)
        {
            return -1;
        }
    }
    
    // no one won
    return 0;
}

void Board::PrintBoard()
{

    std::cout << "\n> Here is the board on turn " << turn << " \n\n";

    std::cout << "-------------\n";
    for (int row = 0; row < BOARD_ROWS; row++)
    {
        std::cout << "|";
        for (int col = 0; col < BOARD_COLS; col++)
        {
            std::cout << " " << contents[row][col] << " |";
        }
        std::cout << "\n-------------\n";
    }
}