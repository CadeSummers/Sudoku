#ifndef HEADERFILE_H
#define HEADERFILE_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#endif

using namespace std;

//generates the board
int board_generation(int board[9][9])
{

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

//TODO
//Validates whether or not a line is invalid
int validate_line(int board[9][9])
{
    //initialization of control list (list of valid numbers) we will be making copies of this list and removing any numbers which we cannot use.
    int control_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    //for loops to check all rows

    //for loop to check all columns

    //on invalid return, calls board generation?
    
    return 0;
}

//TODO
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
}

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
int conceal_spaces(int board[9][9])
{
    return 0;
}


//player guesses number
//TODO
int player_guess(int guess_num)
{
    //TODO
    return 0;
}

