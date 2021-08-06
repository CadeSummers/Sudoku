#include <iostream>
#include <stdlib.h>

using namespace std;

int board_generation ()
{
    //initialization of 9x9 board
    int board[9][9];

    //initialization of control list (list of valid numbers) we will be making copies of this list and removing any numbers which we cannot use.
    int control_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    //initialization of block (3x3 space in which no digit may be the same) to check for validity
    int val_block[3][3];

    //initialization of line (9 spaces in which no digit may be the same) to check for validity
    int val_line[9];

    //nested for loop iterates over all spaces in board...
    for (int i = 0; i < 9; i ++)
    {
        for (int j = 0; j < 9; j++)
        {
            //...and generates a random number for them
            board[i][j] = (rand() % 9) + 1;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << "[" << board[i][j] << "]";

            //if j is equal to 9, end the line
            if (j == 8)
            {
                cout << "\n" << endl;
                cout << "---------------------------\n";
            }
        }
    }

    return 0;
}

int main()
{
    board_generation();
}