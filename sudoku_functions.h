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

//FUNCTIONS FOR THE REMOVAL OF INVALID NUMBERS

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

                    //initialize i and j to be equivalent to cell coordinates
                    i = row + (blockrow*3);
                    j = cell + (blockcolumn*3);

                    //for loop to parse through all values of our numlist
                    for (int index = 0; index < 9; index++)
                    {

                        //if we found a match between the number in our block, and the numlist at our index value
                        if (board[i][j] == numlist[index])
                        {
                            //remove that number from the numlist
                            numlist[index] = 0;

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

//PLAYER SOLVING FUNCTIONS (functions for the actual game, as opposed to board generation)

//TODO
//remove "Invalid Move" cout statements on final iteration
//? change validate functions' subfunctions to return bools rather than ints?

///////////////////////

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
                    //print notice of invalidity and location 
                    cout << "Invalid Row" << endl;
                    cout << "i: " << i << " j: " << j << endl;

                    //return failure
                    //return -1;
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
                    //print notice of invalidity and location
                    cout << "Invalid Column" << endl;
                    cout << "i: " << i << " j: " << j << endl;

                    //return failure
                    //return -1;
                }
            }
        }
    }

    //if we reach the end of this program, return success
    return 0;
}

//validate block (3x3)
//BUGS? If any validation bugs exist, check here for errors. Shouldn't be, but functionality in this piece was copied over from invalidate_blocks, and so prepare for anything missed.
int validate_block(int board[9][9], int control_list[9])
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

                    //initialize i and j to be equivalent to cell coordinates
                    i = row + (blockrow*3);
                    j = cell + (blockcolumn*3);

                    //for loop to parse through all values of our numlist
                    for (int index = 0; index < 9; index++)
                    {

                        //if we found a match between the number in our block, and the numlist at our index value
                        if (board[i][j] == numlist[index])
                        {
                            //remove that number from the numlist
                            numlist[index] = 0;

                            //and break out of this loop
                            break;
                        }

                        //if we are the final index of the list and still no match has been found
                        if (index == 8 && (board[i][j] != numlist[index]))
                        {
                            //print invalidity and location
                            cout << "Invalid Block" << endl;
                            cout << "i: " << i << " j: " << j << endl;
                            
                            //return failure
                            //return -1;
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

    //if we reach the end of this program, return success
    return 0;
}

//cleans the board from an invalid board, to a valid one
//TODO Fix  clean / validate
int clean(int board[9][9])
{
    //print statement
    cout << "cleaning..." << endl;

    //initialization of numlist to copy control list
    int numlist[9];

    //initialization of a control list
    int control_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    //for loop to create a number list of 1-9 (control list exists as we are gonna need to copy it a few times)
    for (int i = 0; i < 9; i++)
    {
        numlist[i] = control_list[i];
    }

    //initialize random seend
    srand(time(0));

    //for all rows
    for (int i = 0; i < 9; i++)
    {
        //and for all colum indices therein
        for (int j = 0; j < 9; j++)
        {
            //if the cell is filled
            if (board[i][j] != 0)
            {
                //run a 1/3 chance to remove the number (just remove enough nums until the board is viable)
                if (rand() % 2 == 0)
                {
                    board[i][j] = 0;
                }

            }
        }
    }

    //return the "cleaned" board
    return board[9][9];
}

//validates a board
bool validate(int board[9][9])
{

    //initialization of a control list
    int control_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    //initialization of int to hold the sum of validate_row. It will either be zero, -1, -2, or -3, as it sums the value of failed returns.
    int zero_or_fail = 0;

    //add the return values of validate row, validate column and validate block to zero or fail
    zero_or_fail += validate_row(board, control_list);
    zero_or_fail += validate_column(board, control_list);
    zero_or_fail += validate_block(board, control_list);

    //TODO fix the validate function
    //everything below here will not run--- the validate_row, column, and block functions will only return zero so the if statement always happens
    //validate needs to remove all invalids, and then we need to backtrack and attempt to solve (which will work once in a fucking blue moon, and then clean the board until its a valid board)

    //if all three validate columns returned 0
    if (zero_or_fail == 0)
    {
        //return true, indicating program success
        return true;
    }
    
    //else return failure
    /*cout << "Failed. Value exceeded 0. Value: " << zero_or_fail << endl;
    return false;*/

    //if invalid, clean the board
    board[9][9] = clean(board);

    //and then recursively call board validation
    validate(board);

    //return false
    return false;
}


//BACKTRACKING function(s)

//TODO create a condition in backtrack where program recognizes that no possible valid number exists, and terminates the program as a result


//Algorithm:
//for all cells of the board
//  if a board cell is empty, generate a number for it
//      and ensure it is valid
//      if it's valid, 
//          continue
//      else
//         go back to the last certain index
//          and generate a different a new number for it
//      if you reach a point at which there are no valid options and you have exhausted all possibilities
//          return failure
//      if you have solved the board completely, and...
//          if the board is valid
//              return success
//

//////////////////

//TODO backtracking needs to be re-structured into a tree-like format, per standard backtracking algorithm implementations

//solves board by backtracking (used to take randomly generated possible sudoku board and check validity)
//takes as arguments the board, and the indexes we are working with
int backtrack(int board[9][9], int i, int j)
{
    //initialization of a numlist of valid sudoku numbers
    int numlist[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    //initialization of an int to store the last index we were certain about
    int last_certain_index;

    //for each row
    for (int i = 0; i < 9; i++)
    {
        //and for each column index
        for (int j = 0; j < 9; j++)
        {
            //and for each number of numlist
            for (int k = 0; k < 9; k++/*no step because we are manually stepping when we find a valid number*/)
            {
                //if the board at i, j is empty
                if (board[i][j] == 0)
                {
                    //set the board at i, j to be equal to the k index of numlist
                    board[i][j] = numlist[k];



                }
            }
        }
    }

    //return success
    return 0;
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
    //keep char list of coordinates, defines a list f values. When user types in "A", "A", program will traverse list, and find "A" as 0 index both times, and adjust block 0, 0 accordingly.
    char coordinate_list[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};


    //TODO changes a number on the board to the guessed number
    
    //the validates the number
    //validate(board)
    return 0;
}

