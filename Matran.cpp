#include <iostream>
using namespace std;
void swap (int &a, int &b){
    int temp= a;
    a=b;
    b=temp;
}
// Hàm hoán đổi các hàng của mảng
void swapRow(int arr[][3], int size) {
    for (int i = 0; i < size / 2; ++i) {
        for (int j = 0; j < size; ++j) {
            swap(arr[i][j], arr[size-1-i][j]);
        }
    }
}

// Hàm hoán đổi các cột của mảng
void swapCol(int arr[][3], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size / 2; ++j) {
            swap(arr[i][j],arr[i][size -1 -j]);
        }
    }
}

// Hàm xoay mảng ngược chiều kim đồng hồ
void xoay_mang(int arr[][3], int size) {
    for (int i = 0; i < size / 2; ++i) {
        for (int j = i; j < size - i - 1; ++j) {
            int temp = arr[i][j];
            arr[i][j] = arr[size - 1 - j][i];
            arr[size - 1 - j][i] = arr[size - 1 - i][size - 1 - j];
            arr[size - 1 - i][size - 1 - j] = arr[j][size - 1 - i];
            arr[j][size - 1 - i] = temp;
        }
    }
}
// Hàm in mảng
void xuat_mang(int arr[][3], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Hoán đổi các hàng
    swapRow(arr, 3);
    /*cout << "Mang sau khi doi:\n";
    xuat_mang(arr, 3);*/
    // Hoán đổi các cột
    swapCol(arr, 3);
    /*cout << "Mang sau khi doi:\n";
    xuat_mang(arr, 3);*/
    // Xoay mảng ngược chiều kim đồng hồ
    xoay_mang(arr, 3);

    // In mảng mới
    cout << "Mang sau khi doi:\n";
    xuat_mang(arr, 3);

    return 0;
}
