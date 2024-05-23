#include <iostream>
using namespace std;
void swap (int &a, int &b){
    int temp= a;
    a=b;
    b=temp;
}
void xoayMatran(int matran[10][10], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			swap(matran[i][j], matran[j][n-1-i]);
		}
	}
}
void inMatran(int matran[10][10], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matran[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int n, value =1;
	cout << "Nhap kich thuoc cua ma tran vuong: ";
	cin >> n;
	int matrix[10][10];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j]=value++;
		}
	}
	cout << "Ma tran ban dau:\n";
	inMatran(matrix, n);
	cout << "Ma tran xoay: \n";
	xoayMatran(matrix, n);
	inMatran(matrix, n);
	return 0;
}