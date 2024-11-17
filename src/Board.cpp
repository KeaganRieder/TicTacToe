#include "Board.h"

Board::Board()
{
    turn = 0;
    playerIcon = ' ';
    botIcon = ' ';

    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
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

bool Board::PlacePlayerIcon(int row, int col)
{
    row -= 1;
    col -= 1;
    bool validRow = row <= BOARD_SIZE && row >= 0;
    bool validCol = col <= BOARD_SIZE && col >= 0;
    // make sure space is unocupied
    if (contents[row][col] == '_' && validCol && validRow)
    {
        contents[row][col] = playerIcon;
        return true;
    }

    return false;
}

void Board::SetBotIcon(char icon)
{
    botIcon = icon;
}
char Board::GetBotIcon()
{
    return botIcon;
}
void Board::PlaceBotIcon(int row, int col)
{
    contents[row][col] = botIcon;   
}

//
// function handling board implementaion
//

bool Board::SpaceEmpty(int row, int col){
    return contents[row][col] == '_';
}

bool Board::SpacesLeft()
{
    int spacesLeft = 0;
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
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

int Board::CheckForVictor(){
    bool playerWin = false;
    bool botWin = false;

    // checking if player or bot one on either colums or rows

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        bool rowWin = contents[i][0] == contents[i][1] && contents[i][1] == contents[i][2];
        bool colWin = contents[0][i] == contents[1][i] && contents[1][i] == contents[2][i];

        bool playerWin = (contents[i][0] == playerIcon && rowWin) || (contents[0][i] == playerIcon && colWin);

        bool botWin = (contents[i][0] == botIcon && rowWin) || (contents[0][i] == botIcon && colWin);

        // return 1 menaing player one on either a col or row
        if (playerWin)
        {
            return PLAYER_WIN;
        }
        // return -1 menaing bot one on either a col or row
        else if (botWin)
        {
            return BOT_WIN;
        }     
    }

    //check on diagonals
    //top left to bot right diagonal
    bool diaOne = contents[0][0] == contents[1][1] && contents[1][1] == contents[2][2];
    //top right to bot left diagonal
    bool diaTwo = contents[2][0] == contents[1][1] && contents[1][1] == contents[0][2];

    playerWin = contents[1][1] == playerIcon && (diaOne || diaTwo);
    botWin = contents[1][1] == botIcon && (diaOne || diaTwo);

    // return 1 menaing player one on either diagonal
    if (playerWin)
    {
        return PLAYER_WIN;
    }
    // return -1 menaing bot one on either diagonal
    else if (botWin)
    {
        return BOT_WIN;
    }  
    //return 0 meaning a tie
    return 0;
}

void Board::PrintBoard()
{
    std::cout << "\n> Here is the board on turn " << turn << " \n\n";
    
    std::cout << "-------------\n";
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        std::cout << "|";
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            std::cout << " " << contents[row][col] << " |";
        }
        std::cout << "\n-------------\n";
    }
}