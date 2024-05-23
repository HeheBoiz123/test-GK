#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int _strlen(char* s) {
	char* t;
	t = s;
	while (*s) s++;
	return s - t;
}
int main() {
	cout << "Cau a bai 1\n";
	char* s;
	s = (char*)"Totoro";
	cout << "The string '" << s << "' has length " << _strlen(s) << endl;
	s = (char*)0;
	if (s != nullptr) {
		cout << "The string '" << s << "' has length " << _strlen(s) << endl;
	}
	else {
		cout << "The string is a null pointer\n";
	}
	cout << "\nCau b bai 1\n";
	int* ptr = nullptr;
	int val = 10;
	ptr = &val;
	cout << ptr << endl;
	cout << *ptr << endl;
	cout << "\nCau c bai 1\n";
	int* p1;
	int m = 10;
	p1 = &m;
	int n = *p1;
	cout << n << endl;
	cout << "\nCau d bai 1\n";
	srand(time(NULL));
	int* p = new int[10];
	for (int i = 0; i < 10; i++) {
		*(p + i) = rand() % 20;
	}
	for (int i = 0; i < 10; i++) {
		cout << *(p + i) << " ";
	}
	delete[]p;
	return 0;
}