#include <array>
#include <iostream>
#include "TTT.hpp"
#include "macros.hpp"

#ifdef DEBUG
void* operator new(size_t size)
{
    std::cout << "Allocating "<< size << " bytes\n";
    return malloc(size);
}

void operator delete(void* ptr, size_t size)
{
    std::cout << "Freeing " << size << " bytes\n";
    free(ptr);
}
#endif

int main()
{
    bool status = true;
    
    std::array<std::array<TicTacToeSquare, numRows>, numCols> board{};
    TicTacToeSquare tile = TTTS_X;
    int pos{};
    while(status)
    {
        do
        {
            boardDisp(board);
            pos = -1;
            pos = posReading(pos);
        }
        while(posValidation(pos, board));

        boardWriting(board, pos, tile);

        std::cout << '\n';

        status = gameStatus(board, tile, pos);

        tile = turnSwitch(tile);
    }

    boardDisp(board);
}