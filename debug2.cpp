#include<iostream>
using namespace std;
int main() {
	char good[81];
	char bad[81];
	strcpy_s(good, "This does not create a null pointer assignment.\n");
	strcpy_s(bad, "This create a null pointer assignment.\n");
	cout << good;
	cout << bad;
	return 0;
}