# Makefile for  missionaries and cannibals problem solver program 

# programs and their associated classes
PROGRAM_NAME = TICTACTOE

CLASS = Board
CLASS2 = TicTacBot
MAIN = TicTacToe

#compiler info
CC=g++
CC_VERSION= -std=c++11
CC_FLAGS= $(CC_VERSION) -Wall

#files for Projects
# OBJS = $(CLASS).0 $(CLASS2).0 $(MAIN).0 $(PROGRAM_NAME).0

# Default goal
.DEFAULT_GOAL := all

all: $(PROGRAM_NAME) 

$(PROGRAM_NAME): $(CLASS).o $(CLASS2).o $(MAIN).o 
	$(CC) $(CFLAGS) -o $(PROGRAM_NAME) $(CLASS).o $(CLASS2).o $(MAIN).o

# making class 1
$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CC) $(CFLAGS) -c $(CLASS).cpp

# making class 2
$(CLASS2).o: $(CLASS2).cpp $(CLASS2).h
	$(CC) $(CFLAGS) -c $(CLASS2).cpp

# making main
$(MAIN).o: $(MAIN).cpp $(CLASS).h  $(CLASS2).h
	$(CC) $(CFLAGS) -c $(MAIN).cpp

#clean targets  
clean:
	$(RM) -f $(PROGRAM_NAME) $(CLASS).o $(CLASS2).o $(MAIN).o

clean-all: clean
	rm -rf ${PROGRAM_NAME} 
