# TicTacToe

## About
Tic tac toe is a game play on a 3 x 3 grid where one player is the O token
and another is X token. the game is won when a player has 3 of there tokens
either across and entire row, colum or diagonal.
 
### Game Overview
the game start with the player choosing their token, which ever token they 
didn't choose is given to the bot [(this determines also decides how the bot functions)](#Min-or-Max-First?). 
following this a coin is flipped in which determines who plays first 

## Program Overview
the program allows for a human player to compete against a bot on aboard.

### Bot
The bot is programed using the Minimax Algorithm, which is a graph based algorithm
that bonce between max value and min value. determining what move to make based on if 
min or max goes [first](#Min-or-Max-First?) in it's search

#### Min or Max First?
Wether Min or Max goes first is decide by which token the bot is assigned:
* botIcon == 'o' then the bot will start with max move
* botIcon == 'x' then the bot will start with min move

## compiling Info
the project is set up to be compile on system with either windows or linux Ubuntu 

 Compiler: g++
  * Version: c++14
  * Style Check: cpplint 1.6.1
  * Static Check: cppcheck 1.90
  * Coverage Check: 
    * gcov (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
    * lcov 1.14
  * Memory Check: valgrind 3.15.0

### class file structure
* All header files for the project are found in <code>include/</code> and named <code>*.h</code>, every class must have a header file.
* All project source files for the project are named <code>*.cpp</code>.