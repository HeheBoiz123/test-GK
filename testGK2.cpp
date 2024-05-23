#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
const int ROW = 9;
const int COL = 9;
void xuat_Sudoku(int Sudoku[ROW][COL]) {
	for (int row = 0; row < 9; ++row) {
		for (int col = 0; col < 9; ++col) {
			cout << Sudoku[row][col] << " ";
			if ((col + 1) % 3 == 0 && col < 9 - 1) {
				cout << "| ";
			}
		}
		cout << endl;
		if ((row + 1) % 3 == 0 && row < 9 - 1) {
			cout << "------+-------+------" << endl;
		}
	}
}
bool is_possible(int board[ROW][COL], int row, int col, int val) {
	for (int i = 0; i < 9; ++i) {
		if (board[row][i] == val || board[i][col] == val) {
			return false;
		}
	}
	int startRow = 3 * (row / 3);
	int startCol = 3 * (col / 3);
	for (int i = startRow; i < startRow + 3; ++i) {
		for (int j = startCol; j < startCol + 3; ++j) {
			if (board[i][j] == val) {
				return false;
			}
		}
	}
	return true;
}
bool solve(int board[ROW][COL], int row, int col) {
	if (col == 9) {
		if (row == 9 - 1) {
			return true;
		}
		else {
			col = 0;
			row++;
		}
	}
	if (board[row][col] != 0) {
		return solve(board, row, col + 1);
	}
	for (int x = 0; x <= 9; ++x) {
		if (is_possible(board, row, col, x)) {
			board[row][col] = x;
			if (solve(board, row, col + 1)) {
				return true;
			}
			board[row][col] = 0;
		}
	}
	return false;
}
int _strlen(char* s) {
	if (s == nullptr) return 0;
	char* t;
	t = s;
	while (*s) s++;
	return s - t;
}
int main() {
	cout << "BAI 1a:\n";
	char* s;
	s = (char*)"Totoro";
	cout << "The string '"<<s<< "' has length " << _strlen(s) << endl;
	s = (char*)0;
	if (s != nullptr) {
		cout << "The string '" << s << "' has length " << _strlen(s) << endl;
	}
	else {
		cout << "The string is a null pointer\n";
	}
	cout << "\nBAI 1b:\n";
	int* ptr = nullptr;
	int val = 10;
	ptr = &val;
	cout << "Dia chi cua ptr: " << ptr << endl;
	cout << "Gia tri cua ptr: " << *ptr << endl;
	cout << "\nBAI 1c\n";
	int* p1;
	p1 = nullptr;
	int m = 25;
	p1 = &m;
	int n = *p1;
	cout << "Gia tri cua n: " << n << endl;
	cout << "\nBAI 1d\n";
	srand(time(NULL));
	int* p = new int[10];
	for (int i = 0; i < 10; i++) {
		*(p + i) = rand() % 20;
		cout << *(p + i) << " ";
	}
	cout << endl;
	delete[]p;
	cout << "\nBAI 2_SUDOKU\n";
	int Sudoku[9][9] = {
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
	};
	cout << "Sudoku Grid:" << endl;
	xuat_Sudoku(Sudoku);
	bool solved = solve(Sudoku, 0, 0);
	if (solved) {
		cout << "\nSolved Sudoku:" << endl;
		xuat_Sudoku(Sudoku);
	}
	else {
		cout << "\nNo solution exists" << endl;
	}
	return 0;
}