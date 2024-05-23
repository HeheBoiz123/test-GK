#include <iostream>
using namespace std;

const int N = 3; // Kích thước của ma trận
void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void rotate90CounterClockwise(int matrix[N][N]) {
    // Bước 1: Chuyển vị ma trận
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Bước 2: Đảo ngược từng cột của ma trận đã chuyển vị
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N / 2; i++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[N - 1 - i][j];
            matrix[N - 1 - i][j] = temp;
        }
    }
}
int main() {
    int matrix[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Ma trận ban đầu:" << endl;
    printMatrix(matrix);

    rotate90CounterClockwise(matrix);

    cout << "Ma trận sau khi xoay 90 độ ngược chiều kim đồng hồ:" << endl;
    printMatrix(matrix);

    return 0;
}