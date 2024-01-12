#pragma once
#include <array>
#include <string_view>
#include "macros.hpp"
// Possible square slots
enum TicTacToeSquare {
  TTTS_BLANK,
  TTTS_O,
  TTTS_X,
};

// Switch between players (turn and tile)
TicTacToeSquare turnSwitch(TicTacToeSquare tile);

// Converting enum to string
char TTTStoChar(TicTacToeSquare square);

// Displays the board progress
void boardDisp(std::array<std::array<TicTacToeSquare, numRows>, numCols>& board);

// Reads the position the player asks
int posReading(int pos);

// Checking if said position is available
bool posValidation(int pos, std::array<std::array<TicTacToeSquare, numRows>, numCols>& board);

// Writes the mark in the desired position
void boardWriting(std::array<std::array<TicTacToeSquare, numRows>, numCols>& board, int pos, TicTacToeSquare tile);

// Groups win-checking functions
bool gameStatus(std::array<std::array<TicTacToeSquare, numRows>, numCols>& board, TicTacToeSquare tile, int pos);
