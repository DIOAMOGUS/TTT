#include <array>
#include "TTT.hpp"
#include "win_check_functions.hpp"
#include "macros.hpp"

bool check_v(std::array<std::array<TicTacToeSquare, numRows>, numCols>& board, TicTacToeSquare tile, int pos)
{
	for (int i = 0; i < 3; i++) {
		if (board[i][pos % 3] != tile) {
			return false;
		}
	}

	return true;
}

bool check_h(std::array<std::array<TicTacToeSquare, numRows>, numCols>& board, TicTacToeSquare tile, int pos)
{
	for (int j = 0; j < 3; j++) {
		if (board[pos / 3][j] != tile) {
			return false;
		}
	}

	return true;
}

bool check_dd(std::array<std::array<TicTacToeSquare, numRows>, numCols>& board, TicTacToeSquare tile)
{
	for (int i = 0; i < 3; i++) {
		if (board[i][i] != tile) {
			return false;
		}
	}

	return true;
}

bool check_ud(std::array<std::array<TicTacToeSquare, numRows>, numCols>& board, TicTacToeSquare tile)
{
	for (int i = 2; i > -1; i--) {
		if (board[i][-(i - 2)] != tile) {
			return false;
		}
	}

	return true;
}
