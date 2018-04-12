#include <stdio.h>
void printTable(int puzzle[9][9]);
_Bool makeTable(int puzzle[9][9]);
_Bool isLegal(int num, int puzzle[9][9], int row, int col);
_Bool tableDone(int puzzle[9][9]);
#define true 1;
#define false 0;
int main() {

	int puzzle[9][9] = {0, 0, 0, 0, 0, 0, 0, 0, 0,
			    0, 0, 0, 0, 0, 3, 0, 8, 5,
			    0, 0, 1, 0, 2, 0, 0, 0, 0,
			    0, 0, 0, 5, 0, 7, 0, 0, 0,
			    0, 0, 4, 0, 0, 0, 1, 0, 0,
			    0, 9, 0, 0, 0, 0, 0, 0, 0,
			    5, 0, 0, 0, 0, 0, 7, 0, 3,
			    0, 0, 2, 0, 1, 0, 0, 0, 0,
			    0, 0, 0, 0, 4, 0, 0, 0, 9};
	printTable(puzzle);
	_Bool succ = makeTable(puzzle);
	if (succ) printf("%s", "\nSuccess! The solution was found!\n");
	printTable(puzzle);

	return 0;
}

_Bool makeTable(int puzzle[9][9]){
//	printTable(puzzle);
	_Bool ret;
        _Bool breakflag = false;
	int row, col;
	for (row = 0; row < 9; row++) {
		for (col = 0; col < 9; col++) {
			if (puzzle[row][col] == 0) {
				breakflag = true;
				break;
			}
		}
		if (breakflag) break;
	}	


	for (int i = 1; i <= 9; i++) {
		if (isLegal(i, puzzle, row, col)) {
			puzzle[row][col] = i;
			if (tableDone(puzzle)) {return true;}
		        else {ret = makeTable(puzzle);}
			if (ret) {return true;}
		}		
	}

	puzzle[row][col] = 0;

	return false;	
}	

_Bool isLegal(int num, int puzzle[9][9], int row, int col){
	int i;
	for (i = 0; i <row; i++) {
		if (num == puzzle[i][col]) return false;
	}
	for (i = row + 1; i < 9; i++) {
		if (num == puzzle[i][col]) return false;
	}	
		
	for (i = 0; i < col; i++) {
		if (num == puzzle[row][i]) return false;
	}
	for (i = col +1; i < 9; i++) {
		if (num == puzzle[row][i]) return false
	}

	int rowbound = row - (row % 3);
	int colbound = col - (col % 3);
	for (i = rowbound; i <= rowbound +2; i++) {
		for (int j = colbound; j <= colbound +2; j++) {
			if (num == puzzle[i][j] && (i != row || j != col)) return false;
		}
	}	

	return true;

}	

_Bool tableDone(int puzzle[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (puzzle[i][j] == 0) return false;
		}
	}
	return true;
}	

void printTable(int puzzle[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (puzzle[i][j] == 0) printf("%s", "  ");
			else printf("%d%s", puzzle[i][j], " ");
			printf("%s", "| ");
		}
		printf("%s", "\n");	
	}	

	printf("%s", "\n------------------\n");
}	
