#include <assert.h>

/*
 * Functie ce verifica daca sudoku 9x9 este rezolvat
 * param : sudoku[9][9] matrice 9x9 
 * post: functia returneaza true, daca sudoku e rezolvat corect
 * false, altfel
 * functia prelucreaza o singura data toate elementele
 */
bool sudokuIsSolved(int sudoku[9][9]) {
	bool appearances[3][9][9];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				appearances[i][j][k] = false;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int elem{ sudoku[i][j] - 1 };

			/*Element gresit*/
			if (elem < 0 || elem > 8) {
				return false;
			}

			/*Pe linie*/
			if (appearances[0][i][elem] == true) {
				return false;
			}
			else {
				appearances[0][i][elem] = true;
			}
			/*Pe coloana*/
			if (appearances[1][j][elem] == true) {
				return false;
			}
			else {
				appearances[1][j][elem] = true;
			}
			/*In patrat*/
			int square{ 0 };
			if (i >= 0 && i <= 2 && j >= 3 && j <= 5) {
				square = 1;
			}
			else if (i >= 0 && i <= 2 && j >= 6 && j <= 8) {
				square = 2;
			}
			else if (i >= 3 && i <= 5 && j >= 0 && j <= 2) {
				square = 3;
			}
			else if (i >= 3 && i <= 5 && j >= 3 && j <= 5) {
				square = 4;
			}
			else if (i >= 3 && i <= 5 && j >= 6 && j <= 8) {
				square = 5;
			}
			else if (i >= 6 && i <= 8 && j >= 0 && j <= 2) {
				square = 6;
			}
			else if (i >= 6 && i <= 8 && j >= 3 && j <= 5) {
				square = 7;
			}
			else if (i >= 6 && i <= 8 && j >= 6 && j <= 8) {
				square = 8;
			}
			if (appearances[2][square][elem] == true) {
				return false;
			}
			else {
				appearances[2][square][elem] = true;
			}
		}
	}
	return true;
}

void test() {
	int a[9][9] = { {9,5,7,6,1,3,2,8,4},
					{4,8,3,2,5,7,1,9,6},
					{6,1,2,8,4,9,5,3,7},
					{1,7,8,3,6,4,9,5,2},
					{5,2,4,9,7,1,3,6,8},
					{3,6,9,5,2,8,7,4,1},
					{8,4,5,7,9,2,6,1,3},
					{2,9,1,4,3,6,8,7,5},
					{7,3,6,1,8,5,4,2,9} };
	assert(sudokuIsSolved(a) == true);

	int b[9][9] = { {9,5,7,6,1,3,2,8,4},
					{4,8,3,2,5,7,1,9,6},
					{6,1,2,8,4,9,5,3,7},
					{1,7,8,3,6,4,9,5,2},
					{5,2,4,9,2,1,3,6,8},
					{3,6,9,5,2,8,7,4,1},
					{8,4,5,7,9,2,6,1,3},
					{2,9,1,4,3,6,8,7,5},
					{7,3,6,1,8,5,4,2,9} };
	assert(sudokuIsSolved(b) == false);

	int c[9][9] = { {1,5,2,4,8,9,3,7,6},
					{7,3,9,2,5,6,8,4,1},
					{4,6,8,3,7,1,2,9,5},
					{3,8,7,1,2,4,6,5,9},
					{5,9,1,7,6,3,4,2,8},
					{2,4,6,8,9,5,7,1,3},
					{9,1,4,6,3,7,5,8,2},
					{6,2,5,9,4,8,1,3,7},
					{8,7,3,5,1,2,9,6,4} };
	assert(sudokuIsSolved(c) == true);

	int d[9][9] = { {2,5,1,4,8,9,3,7,6},
					{7,3,9,2,5,6,8,4,1},
					{4,6,8,3,7,1,2,9,5},
					{3,8,7,1,2,4,6,5,9},
					{5,9,1,7,6,3,4,2,8},
					{2,4,6,8,9,5,7,1,3},
					{9,1,4,6,3,7,5,8,2},
					{6,2,5,9,4,8,1,3,7},
					{8,7,3,5,1,2,9,6,4} };
	assert(sudokuIsSolved(d) == false);

	int e[9][9] = { {3,5,2,4,8,9,3,7,6},
					{7,3,9,2,5,6,8,4,1},
					{4,6,8,3,7,1,2,9,5},
					{3,8,7,1,2,4,6,5,9},
					{5,9,1,7,6,3,4,2,8},
					{2,4,6,8,9,5,7,1,3},
					{9,1,4,6,3,7,5,8,2},
					{6,2,5,9,4,8,1,3,7},
					{8,7,3,5,1,2,9,6,4} };
	assert(sudokuIsSolved(e) == false);

	int f[9][9] = { {1,2,3,4,5,6,7,8,9},
					{2,3,4,5,6,7,8,9,1},
					{3,4,5,6,7,8,9,1,2},
					{4,5,6,7,8,9,1,2,3},
					{5,6,7,8,9,1,2,3,4},
					{6,7,8,9,1,2,3,4,5},
					{7,8,9,1,2,3,4,5,6},
					{8,9,1,2,3,4,5,6,7},
					{9,1,2,3,4,5,6,7,8} };
	assert(sudokuIsSolved(f) == false);

	int g[9][9] = { {-3,5,2,4,8,9,3,7,6},
					{7,3,9,2,5,6,8,4,1},
					{4,6,8,3,7,1,2,9,5},
					{3,8,7,1,2,4,6,5,9},
					{5,9,1,7,6,3,4,2,8},
					{2,4,6,8,9,5,7,1,3},
					{9,1,4,6,3,7,5,8,2},
					{6,2,5,9,4,8,1,3,7},
					{8,7,3,5,1,2,9,6,4} };
	assert(sudokuIsSolved(g) == false);
}

int main() {

	test();

	return 0;
}