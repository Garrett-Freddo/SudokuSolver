#include <iostream>
#include "sudoku.h"
#include <string>
using namespace std;


int main(){
	int array[9][9] = { { 2,0,0, 1,0,0, 0,0,0},
						{ 0,0,0, 0,8,0, 5,0,6},
						{ 0,0,0, 0,0,0, 1,0,7},
						
						{ 0,0,0, 3,0,0, 6,9,4},
						{ 7,0,0, 9,0,5, 0,0,8},
						{ 4,2,9, 0,0,1, 0,0,0},
						
						{ 3,0,4, 0,0,0, 0,0,0},
						{ 1,0,6, 0,5,0, 0,0,0},
						{ 0,0,0, 0,0,7, 0,0,1}};
			
	int i, j;
	int solved[9][9]; /*
	array is where the original board will be stored. This way, the original user-entered values
	cannot be changed during the recursion process. A copy of this area will be defined as solved,
	where the actual logic and solving of the puzzle will occur.*/
	for ( i = 0; i < 9; ++i){
		for ( j = 0; j < 9; ++j){
			solved[i][j] = array[i][j];
}
	}
sudokuSolver(array, solved, 0, 0);
for ( i = 0; i < 9; ++i){
		for ( j = 0; j < 9; ++j){
			cout<< solved[i][j]<< "   ";
			;
		}
		cout<<endl;
}
}
