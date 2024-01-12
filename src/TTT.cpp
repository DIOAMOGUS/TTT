#include <array>
#include <iostream>
#include <string_view>
#include "TTT.hpp"
#include "win_check_functions.hpp"
#include "macros.hpp"

TicTacToeSquare turnSwitch(TicTacToeSquare tile)
{
	return tile == TTTS_O ? TTTS_X : TTTS_O;
}

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

void boardDisp(std::array<std::array<TicTacToeSquare, numRows>, numCols>& board)
{
	for (const auto& arow : board) {   // get each array row
		for (const auto& e : arow)	 // get each element of the row
			std::cout << ' ' << TTTSToChar(e) << ' ' << '|';
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
	// If any line is filled
	if (check_v(board, tile, pos) || check_h(board, tile, pos) || check_dd(board, tile) || check_ud(board, tile)) {
		std::cout << TTTSToChar(tile) << " Won!\n"; // That player won
		return false;
	}
			
	// Draw checking
	for (const auto& arow : board)   // get each array row
		for (const auto& e : arow) // get each element of the row
			if (e == TTTS_BLANK)
				return true;
			
	std::cout << "Draw" << '\n';
	return false;
}
