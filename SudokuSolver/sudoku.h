
#ifndef SUDOKU_H
#define SUDOKU_H
int sudokuSolver( int array[9][9], int solved[9][9], int rows, int cols); // large function calling on others. Main algorithim code
bool isGiven(int array[9][9], int cols, int rows);    //Checks to see if it is a user inputted array value
bool validMove(int solved[9][9], int rows, int cols);   //Checks to see if the move breaks any rules
int colFinder(int cols); // Finds where in the square it is
int rowFinder(int rows); // Finds where in the square it is
#endif 
