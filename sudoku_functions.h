#ifndef HEADERFILE_H
#define HEADERFILE_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#endif

using namespace std;

//generates the board
int board_generation(int board[9][9])
{

    //initialize random seed for rand function below
    srand(time(0));

    //nested for loop iterates over all spaces in board...
    for (int i = 0; i < 9; i ++)
    {
        for (int j = 0; j < 9; j++)
        {
            //...and generates a random number for them, between 1 & 9
            board[i][j] = (rand() % 9) + 1;
        }
    }

    return board[9][9];
}

//function to print board to console
void display_board(int board[9][9])
{
    cout << "___________________________" << endl;

    //nested for loop to print board
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << "[" << board[i][j] << "]";

            //if j is equal to 8, end the line
            if (j == 8)
            {
                cout << "\n" << endl;
                cout << "---------------------------\n";
            }
        }
    }

    cout << "___________________________" << endl;
}

//REMOVAL OF INVALID FUNCTIONS

//function to remove all numbers which are invalid by row
void remove_row_invalids(int board[9][9], int control_list[9])
{
    int numlist[9];

    //for loop to create a number list of 1-9 (control list exists as we are gonna need to copy it a few times)
    for (int i = 0; i < 9; i++)
    {
        numlist[i] = control_list[i];
    }

    //nested for loop to parse through all cells
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            //for all indices of the num list
            for (int k = 0; k < 9; k++)
            {
                //if (when) a number of the control list is found to be in cell i, j
                if (board[i][j] == numlist[k])
                {
                    //remove the number in cell i, j from the number list
                    numlist[k] = 0;

                    //break out of k loop / numlist loop
                    break;
                }
                
                //if at the final index of k and still no match has been found
                if (k == 8 && (board[i][j] != numlist[k]))
                {
                    //else if cell at i, j was not found (because i, j is a duplicate number), set its' value to zero
                    board[i][j] = 0;
                }
            }

            //if we are at the last index of the row, and after we have checked cell i, j=8
            if (j == 8)
            {
                //reset the numlist to be equal to the control list for the next row
                for (int k = 0; k < 9; k++)
                {
                    numlist[k] = control_list[k];
                }
            }
        }
    }
}

//function to remove all numbers which are invald by column
void remove_column_invalids(int board[9][9], int control_list[9])
{
    int numlist[9];

    //for loop to create a number list of 1-9 (control list exists as we are gonna need to copy it a few times)
    for (int i = 0; i < 9; i++)
    {
        numlist[i] = control_list[i];
    }

    //nested for loop to parse through all cells
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            //for all indices of the num list
            for (int k = 0; k < 9; k++)
            {
                //if (when) a number of the control list is found to be in cell j, i
                if (board[j][i] == numlist[k])
                {
                    //remove the number in cell j, i from the number list
                    numlist[k] = 0;

                    //break out of k loop / numlist loop
                    break;
                }
                
                //if at the final index of k and still no match has been found
                if (k == 8 && (board[j][i] != numlist[k]))
                {
                    //else if cell at j, i was not found (because j, i is a duplicate number), set its' value to zero
                    board[j][i] = 0;
                }
            }

            //if we are at the last index of the row, and after we have checked cell j=8, i
            if (j == 8)
            {

                //reset the numlist to be equal to the control list for the next row
                for (int k = 0; k < 9; k++)
                {
                    numlist[k] = control_list[k];
                }
            }
        }
    }
}

//remove block (3x3) invalids
void remove_block_invalids(int board[9][9], int control_list[9])
{
    //initialization of numlist to copy control list
    int numlist[9];

    //for loop to create a number list of 1-9 (control list exists as we are gonna need to copy it a few times)
    for (int i = 0; i < 9; i++)
    {
        numlist[i] = control_list[i];
    }

    // declaration of ints to keep track of the cells we are working with, relevant further down
    int i = 0;
    int j = 0;

    //for each row of 3x3 blocks
    for (int blockrow = 0; blockrow < 3; blockrow++)
    {
        //and each block column index therein (effectivelly each 3x3 block)
        for (int blockcolumn = 0; blockcolumn < 3; blockcolumn++)
        {
            //and for each row within the 3x3 block
            for (int row = 0; row < 3; row++)
            {
                //and for each cell (column index) of the 3 cell row
                for (int cell = 0; cell < 3; cell++)
                {   

                    //THIS is how to index all cells properly in this format----> cout << "Row Index: " << row + (blockrow*3) << " Column Index: " << cell + (blockcolumn*3) << endl;

                    //initialize i and j to be equivalent to cell coordinates
                    i = row + (blockrow*3);
                    j = cell + (blockcolumn*3);

                    //cout << board[i][j] << endl;

                    //for loop to parse through all values of our numlist
                    for (int index = 0; index < 9; index++)
                    {

                        //if we found a match between the number in our block, and the numlist at our index value
                        if (board[i][j] == numlist[index])
                        {
                            //remove that number from the numlist
                            numlist[index] = 0;

                            //TEST
                            //cout << "HERE" << endl;

                            //and break out of this loop
                            break;
                        }

                        //if we are the final index of the list and still no match has been found
                        if (index == 8 && (board[i][j] != numlist[index]))
                        {
                            //remove the invalid index from the board
                            board[i][j] = 0;
                        }

                    }
                }

                //once we have gone through the 3x3 rows and columns of the list, refresh numlist
                if (row == 2)
                {
                    for (int k = 0; k < 9; k++)
                    {
                        numlist[k] = control_list[k];
                    }
                }
            }
        }
    }
}

//function to remove invalid board cells
int remove_invalids(int board[9][9])
{

    //initialization of control list (list of valid numbers) we will be making copies of this list and removing any numbers which we cannot use.
    int control_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    remove_row_invalids(board, control_list);
    remove_column_invalids(board, control_list);
    remove_block_invalids(board, control_list);

    return board[9][9];
}

//SOLVING FUNCTIONS

//validates a row (generally after move, or in backtracking algorithm... which is as of 8/13/21 TODO)
int validate_row(int board[9][9], int control_list[9])
{
    //creation of a list of numbers 1-9
    int numlist[9];

    //for loop copying control list to numlist
    for (int i = 0; i < 9; i++)
    {
        numlist[i] = control_list[i];
    }

    //for all rows (i)
    for (int i = 0; i < 9; i++)
    {
        //and all column indices (cells) of rows (j)
        for (int j = 0; j < 9; j++)
        {
            //check all numbers 1-9 of numlist
            for (int k = 0; k < 9; k++)
            {
                //if (when) a number of the control list is found to be in cell j, i
                if (board[i][j] == numlist[k])
                {
                    //remove the number in cell i, j from the number list
                    numlist[k] = 0;

                    //break out of k loop / numlist loop
                    break;
                }
                
                //if at the final index of k and still no match has been found
                if (k == 8 && (board[i][j] != numlist[k]))
                {
                    //print notice of invalidity
                    cout << "Invalid Move" << endl;

                    //return failure
                    return -1;
                }
            }
        }
    }

    return 0;
}

//validates a column (generally after move, or in backtracking algorithm... which is as of 8/13/21 TODO)
int validate_column(int board[9][9], int control_list[9])
{
    //creation of a list of numbers 1-9
    int numlist[9];

    //for loop copying control list to numlist
    for (int i = 0; i < 9; i++)
    {
        numlist[i] = control_list[i];
    }

    //for all rows (i)
    for (int i = 0; i < 9; i++)
    {
        //and all column indices (cells) of rows (j)
        for (int j = 0; j < 9; j++)
        {
            //check all numbers 1-9 of numlist
            for (int k = 0; k < 9; k++)
            {
                //if (when) a number of the control list is found to be in cell j, i
                if (board[j][i] == numlist[k])
                {
                    //remove the number in cell j, i from the number list
                    numlist[k] = 0;

                    //break out of k loop / numlist loop
                    break;
                }
                
                //if at the final index of k and still no match has been found
                if (k == 8 && (board[j][i] != numlist[k]))
                {
                    //print notice of invalidity
                    cout << "Invalid Move" << endl;

                    //return failure
                    return -1;
                }
            }
        }
    }

    return 0;
}

bool validate(int board[9][9])
{

    //initialization of a control list
    int control_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    //validate_row(board, control_list);
    //validate_column(board);
    //validate_block(board);

    
    return false;
}

//Validates whether or not a line is invalid
/*
int validate_line(int board[9][9])
{
    //initialization of control list (list of valid numbers) we will be making copies of this list and removing any numbers which we cannot use.
    int control_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int numlist[9];

    //for loop to create a number list of 1-9 (control list exists as we are gonna need to copy it a few times)
    for (int i = 0; i < 9; i++)
    {
        numlist[i] = control_list[i];
    }

    //nested for loop to parse through all board cells
    //for all rows (i)
    for (int i = 0; i < 9; i++)
    {

        //and for all columns / cell indices of row (j)
        for (int j = 0; j < 9; j++)
        {
            
            //for loop to check each cell against our list of numbers
            for (int k = 0; k < 9; k++)
            {
                //TEST print check on comparison
                //cout << "comparing: " << board[i][j] << " & " << numlist[k] << endl;

                //if (when) there is a match between the number on the board and the list of numbers
                if (board[i][j] == numlist[k])
                {
                    //TEST
                    //cout << "Found " << numlist[k] << "! Index: " << i << j << endl;

                    //remove the number from the numlist... since there can only ever be 1 of each of the 9 digits, if any duplicate arises it will fail this test
                    numlist[k] = 0;

                    //reset the index of j (return the the next)
                    j = 0;
                }
            }

            //initialization of an integer named index to track the numlist
            int index = 0;

            //at the final index value of j (once all indices of the row have been checked)
            if (j == 8)
            {
            
                //run this while loop to ensure that all numbers in numlist are the same (0)
                while (index < 9)
                {
                    //if the number is zero, continue to the next iteration
                    if (numlist[index] == 0)
                    {
                        index++;
                    }
                    //if it's not, the line is invalid
                    else
                    {
                        //TEST print statement of invalid line
                        //cout << "Invalid line found at index " << i << ", " << j << endl;

                        //return the first found invalid number
                        return numlist[index];
                    }
                }
            }


        }
    }

    //for loop to check all columns

    //on invalid return, calls board generation?
    
    return 0;
}*/

//TODO
/*
int validate_block(int val_block[3][3], int *num_list)
{
    //for loop checking the indices of the control list
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            //initialization of index k, to be an index of num_list
            int k = 0;
            while (k < 9)
            {
                //if the index of val_block at index i, j is the same as the num_list number at k, remove it from the num_list.
                if (val_block[i][j] == num_list[k])
                {
                    //remove the element at index k of num_list and replace it with 0 (an invalid number in this context)
                    num_list[k] = 0;

                    //leave the loop
                    break;
                }
                
                //if index k is 8 (final index of list) and no match has been found, the block is invalid and has a duplicate.
                if (k == 8) 
                {
                    cout << "Invalid Block. Try again." << endl;
                    return -1;
                }
                
                //increment to continue
                k++;
            }
            
        }
    }
    
    return 0;
}*/

//TODO validate board
void validate_board(int board[9][9])
{
    //initialization of control list (list of valid numbers) we will be making copies of this list and removing any numbers which we cannot use.
    int control_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    //initialization of block (3x3 space in which no digit may be the same) to check for validity, serves as a buffer
    int val_block[3][3];

    //initialization of line (9 spaces in which no digit may be the same) to check for validity, servers as a buffer
    int val_line[9];

    //declaration of an int variable to hold the location of the val_block & val_line buffers for each increment of checking loop across the board
    int stop = 0;

    //initialization of a number list that is a copy of the control list
    int num_list[9];
    for (int x = 0; x < 9; x++)
    {
        num_list[x] = control_list[x];
    }

    //TODO validates line by checking that each number 1-9 occurs only once


    //validates block by checking that each number 1-9 occurs only once
    for (int x = stop; x < stop + 3; x++)
    {
        for (int y = stop; y < stop + 3; y++)
        {
            //initialize each index of valblock to be equivalent to it's position on the board
            val_block[x][y] = board[x][y];
        }
    }

}

//conceals board spaces from valid board
//TODO
//???? What if i just concealed all duplicates and then solved for that?
int conceal_spaces(int board[9][9])
{
    return 0;
}


//player guesses number
//TODO
int player_guess(int board[9][9], int guess_num)
{
    //TODO
    return 0;
}

