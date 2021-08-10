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
    //cout << validate_line(board) << endl;
    board[9][9] = remove_invalids(board);
    display_board(board);

    
    return 0;
}

//???? Limit to 3 per block, 3 per each row, 3 per each column? In order to generate something that could be a valid sudoku, then solve for it? Or re-gen?
//After testing, a significant portion obeying the above rule lead to valid, albeit brut-forced sudoku boards. We can conceal all invalid numbers from the sudoku board, then solve with backtrack algorithm, then if no solution exists we can cut down until there are 3 valids per row, column & block