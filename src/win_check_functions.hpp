#pragma once
#include <array>
#include "macros.hpp"

// Win checking functions 
// Checks for possible win in said column
bool check_v(std::array<std::array<TicTacToeSquare, numRows>, numCols>& board, TicTacToeSquare tile, int pos);

// Checks for possible win in said line
bool check_h(std::array<std::array<TicTacToeSquare, numRows>, numCols>& board, TicTacToeSquare tile, int pos);

// Checks for possible win in downwards diagonal
bool check_dd(std::array<std::array<TicTacToeSquare, numRows>, numCols>& board, TicTacToeSquare tile);

// Checks for possible win in upwards diagonal
bool check_ud(std::array<std::array<TicTacToeSquare, numRows>, numCols>& board, TicTacToeSquare tile);