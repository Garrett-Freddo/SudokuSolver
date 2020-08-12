#include <iostream>
#include "sudoku.h"
#include <string>
using namespace std;

int sudokuSolver( int array[9][9], int solved[9][9], int rows, int cols ){

	int  i, j, spacetaker;
	bool valid = false;
	
	 cout << "rows" << ": " << rows << "  " << "cols" << ": " << cols<< endl;
	cout << solved[rows][cols]<< endl;
	
	
	while((!isGiven(array, cols, rows))){
		if(cols < 8){
			cols +=1;
			
		}else if (rows < 8){
			rows +=1;
			cols = 0;

		}else if (rows ==8 && cols ==8){
				return 0;
		}
	}
	while(solved[rows][cols] < 9 && !valid){
		solved[rows][cols]+=1;
		if(validMove(solved, rows, cols)){
				valid = true;
		}else{
			valid = false;}
			
			cout << "rows" << ": " << rows << "  " << "cols" << ": " << cols<< endl;
	cout << solved[rows][cols]<< endl;
			
	}
	if(valid){
		if(cols < 8){
			cols +=1;
		}else if (rows < 8){
			rows +=1;
			cols = 0;
		}else if (rows ==8 && cols ==8){
				return 0;
		}
	}
	else{		
		solved[rows][cols] = 0;
		if(cols > 0){
			cols -= 1;
		}else if (cols == 0){
			rows -=1;
			cols = 8;
		}
		while((!isGiven(array, cols, rows))){
		if(cols > 0){
			cols -=1;
			
		}else if (cols == 0){
			rows -=1;
			cols = 8;

	}
	}
	}
		sudokuSolver(array, solved, rows, cols);
	
	
	
}

bool isGiven(int array[9][9], int cols, int rows){    //Checks to see if it is a user inputted array value

	if (array[rows][cols] == 0)
		return true;
	else
		return false;
}
	
	
bool validMove(int solved[9][9], int rows, int cols){   //Checks to see if the move breaks any rules
	int i, j, spacefiller;
	//Test for rows and columns
	for(i = 0; i < 9; ++i){
		if( !(i == rows)){
			if( solved[i][cols] == solved[rows][cols]){
			return false;}
		}
		if( !( i == cols)){
			if( solved[rows][i] == solved[rows][cols]){
			return false;}
		}
	}
		// Now test for the square (FIX THIS)
		int rowPos = rowFinder(rows);
		int colPos = colFinder(cols);
		int testingNum;
		if(rowPos == 1){
			int switchval = colPos;
			switch (switchval){
				case 1:
					i = 0;
					while( i < 3){
						for( j = 0; j < 3; ++j){
							if(rows + i == rows && cols + j == cols)
								spacefiller = 1;
							else if(solved[rows+i][cols+j] == solved[rows][cols])
								return false;
						}
						i +=1;
					}
					break;
				case 2:
					i=0;
					while( i < 3){
						for( j = -1; j < 2; ++j){
							if(rows + i == rows && cols + j == cols){
							spacefiller = 1;}
							else if(solved[rows+i][cols+j] == solved[rows][cols]){
								cout << rows+i << " " << cols+j << " ";
							return false;}
						}
						i+=1;
					}
					break;
				case 3:
					i=0;
					while( i < 3){
						for( j = -2; j < 1; ++j){
							if(rows + i == rows && cols + j == cols)
								spacefiller = 1;
							else if(solved[rows+i][cols+j] == solved[rows][cols])
								return false;
						}
						i+=1;
					}
					break;
			}
		}
			if(rowPos == 2){
			int switchval = colPos;
			switch (switchval){
				case 1:
					i=-1;
					while( i < 2){
						for( j = 0; j < 3; ++j){
							if(rows + i == rows && cols + j == cols)
								spacefiller = 1;
							else if(solved[rows+i][cols+j] == solved[rows][cols])
								return false;
						}
						i+=1;
					}
					break;
				case 2:
					i=-1;
					while( i < 2){
						for( j = -1; j < 2; ++j){
							if(rows + i == rows && cols + j == cols)
								spacefiller = 1;
							else if(solved[rows+i][cols+j] == solved[rows][cols])
								return false;
						}
						i+=1;
					}
					break;
				case 3:
					i=-1;
					while( i < 2){
						for( j = -2; j < 1; ++j){
							if(rows + i == rows && cols + j == cols)
								spacefiller = 1;
							else if(solved[rows+i][cols+j] == solved[rows][cols])
								return false;
						}
						i+=1;
					}
					break;
			}
			}
			if(rowPos == 3){
			int switchval = colPos;
			switch (switchval){
				case 1:
					i=-2;
					while( i < 1){
						for( j = 0; j < 3; ++j){
							if(rows + i == rows && cols + j == cols)
								spacefiller = 1;
							else if(solved[rows+i][cols+j] == solved[rows][cols])
								return false;
						}
						i+=1;
					}
					break;
				case 2:
					i=-2;
					while( i < 1){
						for( j = -1; j < 2; ++j){
							if(rows + i == rows && cols + j == cols)
								spacefiller = 1;
							else if(solved[rows+i][cols+j] == solved[rows][cols])
								return false;
						}
						i+=1;
					}
					break;
				case 3:
					i=-2;
					while( i < 1){
						for( j = -2; j < 1; ++j){
							if(rows + i == rows && cols + j == cols)
								spacefiller = 1;
							else if(solved[rows+i][cols+j] == solved[rows][cols])
								return false;
						}
						i+=1;
					}
					break;
			}
}
return true;
			}

int colFinder(int cols){
	int switchVal = cols+1;
	switchVal = switchVal % 3;
	
	switch (switchVal){
		case 0:
			return 3 ;
		case 2:
			return 2;
		case 1:
			return 1;
	}
	
}
int rowFinder(int rows){
	int switchVal = rows+1;
	switchVal = switchVal % 3;
	switch (switchVal){
		case 0:
			return 3 ;
		case 2:
			return 2;
		case 1:
			return 1;
	}
}