#include<iostream>
using namespace std;
//đệ quy đuôi
int sodaonguoc(int n, int N)
{
	if (n == 0)
	{
		return N;;
	}
	else
	{
		N = N * 10 + n % 10;
		return sodaonguoc(n / 10, N);
	}

}
//đệ quy phi tuyến
int SOMU(int x, int y)
{
	if (y == 0) {
		return 1;
	}
	if (y % 2 == 0) {
		return SOMU(x, y / 2) * SOMU(x, y / 2);
	}
	else {
		return SOMU(x, y / 2) * SOMU(x, y / 2) * x;
	}
}
//đệ quy nhị phân
void taomang(int a[], int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
	}
}
void xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
int MIN(int array[], int left, int right) {
	if (left == right) {
		return array[left];
	}
	else {
		if (array[left] > array[right]) {
			return MIN(array, left + 1, right);
		}
		else if (array[left] < array[right]) {
			return MIN(array, left, right - 1);
		}
		else {
			return MIN(array, left + 1, right - 1);
		}

	}
}
//đệ quy hỗ tương
int giaithua(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return n * giaithua(n - 1);
	}
}
int tonggiaithua(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return giaithua(n) + tonggiaithua(n - 1);
	}
}
//đệ quy tuyến tính
int tongmang(int a[], int n)
{
	if (n == 1)
	{
		return a[0];
	}
	else
	{
		return a[n - 1] + tongmang(a, n - 1);
	}
}
int main()
{
	int choose;
	cout << "-------MENU-------\n1. de quy duoi\n2. de quy phi tuyen\n3. de quy nhi phan\n4. de quy ho tong\n------------------\n";
	cout << "Nhap lua chon cua ban: "; cin >> choose;
	if (choose == 1)
	{
		int n, N = 0;
		cout << "Nhap n: "; cin >> n;
		cout << sodaonguoc(n, N);
	}
	else if (choose == 2)
	{
		int x, y;
		cout << "Nhap vao so x luy thua y: "; cin >> x >> y;
		cout << SOMU(x, y);
	}
	else if (choose == 3)
	{
		int z;
		int a[50];
		cout << "Nhap so luong phan tu: "; cin >> z;
		int left = 0, right = z - 1;

		taomang(a, z);
		xuatmang(a, z);
		cout << endl;
		cout << MIN(a, left, right);
	}
	return 0;
}