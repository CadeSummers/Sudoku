#include <iostream>
#include "sudoku_functions.h"

using namespace std;

//global initialization of board
int board[9][9];

int main ()
{
    cout << "Hello World!" << endl;
    
    board[9][9] = board_generation(board);
    display_board(board);
    

    
    return 0;
}