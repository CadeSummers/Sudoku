#include <iostream>
#include <stdlib.h>

using namespace std;

//STEPS / TODO
//conjecture: at a certain point of creating a sudoku board, the creation itself becomes the solving of the board.

/* I believe this will work. Here is linked a working version of this project, though likely not using these steps:
Link: https://www.youtube.com/watch?v=LHCHH5siBCg

1. create a list which is a copy of the control list 
2. generate a random number. This number selects from control list. 
3. replace the selected number from the copy list with another number in the copy list, or zero (and zero can re-roll)
4. for the next cell, select another number from the copy list, and do this for all numbers in the first 3x3 block.
5. after the first block (most likely top left) is finished, take the first 3 indices of the first row and the first column.
6. replace the numbers found in those indices with the adjacent numbers from the control list (such that the list of 9 has only 6 unique numbers available)
7. for the blocks adjacent to the initial block, in the first cell of each, generate a random number from the copy list.
8. continue until a complete row and a complete column is formed.

-- at this point we have generated a sudoku grid whereby one block, one row, and one column have been filled, all with unique and valid numbers --
-- the remaing segments of each row, and each column, are either a line of 6 or a rectangle of 3x2 --
-- as we fill in the board randomly, we have to piece by piece stop focusing random generation, and start "solving" the board based on its' current state. certain numbers MUST be placed in certain places at this point, as creating and solving converge into board gen

9. once more, make a copy of the control list.
10. in the list which remains (6x1), remove all numbers which exist the pre-filled 3 cells of the line this cell is in
11. now, remove all all numbers which exist in the pre-filled cells of the block this cell is in

-- this leaves only a selection of valid numnbers

12. on each selection, remove and replace that number in the list
13. then, after placing each number, look at the 3 numbers which exist in the next block (top 3 of block 3)
14. if a number exists on the next block that exists in the remaining list, replace a random index of the 3 values you placed with that number (this method preserves random board generation, at the expense of undoing a process)

-- we must do the above because if we have 3 numbers remaining, and one of those numbers is a duplicate of one which already exists in the above block, we would have 2 duplicate numbers in the block

15. repeat steps 9-14 on the 2nd column, just as you did for the second row
 
-- at this point, there are four blocks, each with 6 numbers and 3 remaining numbers

16. identify the remaining 3 values for blocks 2 & blocks 4 (0, 1 & 1, 0) NOT the final blocks in the corners
17. randomly generate a value for each index of the remaining block

-- this leaves only the corner blocks with 3 empty values
--in the final block on each corner, the values of the block and the values of the line the empty cells are in are the exact same.

18. generate of the remaining 3 values a random value for each
-- now 5 blocks have been completely filled and 4 blocks are completely empty

19. once again, copy the control list.
20. for the top left cell of the central block (index 3, 3 or 4, 4 starting from index 0 or index 1 respectively ), remove from the list the 3 numbers above it, and the 3 numbers to it's left.
21. from the remaining list, generate a random number
22. then proceed down the row of that cell, headed to the right
23. once more, copy the control list and remove all invalid numbers
24. populate only the central block until only a 2x2 at the bottom right remains.
25. in the central square of the central block, generate a final random number from a list of valid numbers.

-- now we need to solve for the remaining piece of that block to ensure valid numbers. if any character exists in a row or column which eliminates 2 cells, the remaining cell is the only valid column. this can be done by solving or random generation
-- this point is the break even point of the system, whereby we can either randomly generate or solve. At a certain point of random generation of a sudoku board, the creation becomes the solving itself

26. solve for the remaining 3 cells in the central block.
27. By cancelling out impossible numbers of the rows with 3 remaining numbers, solve the remaining sudoku.
28. If need be, brute force the remaining sudoku cells.
29. Finally, generate the board by selecting a random number of cells and random cells and cause them to be reset to blank (0)
30. Play!

*/

int main ()
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

    return 0;
}