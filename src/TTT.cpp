#include <array>
#include <iostream>
#include <string_view>
#include "TTT.hpp"
#include "win_check_functions.hpp"
#include "macros.hpp"

char TTTSToChar(TicTacToeSquare square)
{
	switch (square) {
	case TTTS_BLANK:
		return ' ';
	case TTTS_O:
		return 'O';
	case TTTS_X:
		return 'X';
	default:
		return ' ';
	}
}

TicTacToeSquare turnSwitch(TicTacToeSquare tile)
{
	return tile == TTTS_O ? TTTS_X : TTTS_O;
}

void boardDisp(std::array<std::array<TicTacToeSquare, numRows>, numCols>& board)
{
	for (const auto& arow : board)   // get each array row
	{
		for (const auto& e : arow) { // get each element of the row
				std::cout << ' ' << TTTSToChar(e) << ' ' << '|';
		}
			std::cout << "\n---+---+---\n";

	}
}

int posReading(int pos)
{
	while (pos < 1 || pos > 9) {
		std::cout << "Position: ";
		std::cin >> pos;
		if (!std::cin) {
			// let's handle the failure
			std::cin.clear(); // put us back in 'normal' operation mode
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
		}
	}

	return pos-1;
}

bool posValidation(int pos, std::array<std::array<TicTacToeSquare, numRows>, numCols>& board)
{
	if (board[pos / 3][pos % 3] == TTTS_BLANK)
		return false;
	else
		return true;
}

void boardWriting(std::array<std::array<TicTacToeSquare, numRows>, numCols>& board, int pos, TicTacToeSquare tile)
{
	board[pos / 3][pos % 3] = tile;
}

bool gameStatus(std::array<std::array<TicTacToeSquare, numRows>, numCols>& board, TicTacToeSquare tile, int pos)
{
	if (check_v(board, tile, pos))
		return false;
	else if (check_h(board, tile, pos))
		return false;
	else if (check_dd(board, tile))
		return false;
	else if (check_ud(board, tile))
		return false;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == TTTS_BLANK) {
				return true;
			}
		}
	}

	std::cout << "Draw" << '\n';
	return false;
}
