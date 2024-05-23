
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
void rotate90Clockwise(int matrix[N][N]) {
    // Bước 1: Chuyển vị ma trận
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Bước 2: Đảo ngược từng hàng của ma trận đã chuyển vị
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][N - 1 - j];
            matrix[i][N - 1 - j] = temp;
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

    rotate90Clockwise(matrix);
    cout << "Ma trận sau khi xoay 90 độ:" << endl;
    printMatrix(matrix);
    return 0;
}
