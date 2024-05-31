#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct film {
	int id;
	string name;
	string namphathanh;
	string theloai;
};
void readfile(const string s, film*& a, int &number){
	ifstream file;
	file.open(s, ios::in);
	if (file.is_open()) {
		string s;
		getline(file, s);
		int i = 0;
		while (i != 26) {
			file >> a[i].id;
			file.ignore(1);
			getline(file, a[i].name, ',');
			getline(file, a[i].theloai);
			i++;
		}
		number = i;
	}
	file.close();
}
void printFile(const string s, film*& a, int number) {
	for (int i = 0; i < number; i++) {
		cout << a[i].id << " " << a[i].name << " "<<a[i].namphathanh<<" " << a[i].theloai << endl;
	}
}
void takeDate(film*& a,int number) {
	for (int i = 0; i < number; i++) {
		a[i].namphathanh = a[i].name.substr(a[i].name.length() - 5, 4);
		a[i].name = a[i].name.erase(a[i].name.length() - 6);
	}
}
int countTheloai(film*& a, int number, string& s) {
	int count = 5;
	for (int i = 0; i < number; i++) {
		string str = a[i].theloai;
		for (int j = 0; j < str.length(); j++) {
			if (j == str.length()-1) {
				string subs2;
				subs2 = str.substr(0, j);
				if (s.find(subs2) != string::npos) {
					continue;
				}
				else {
					s = s + '|' + subs2;
					count++;
				}
			}
			if (str[j] == '|') {
				string subs;
				subs = str.substr(0, j);
				if (s.find(subs) != string::npos) {
					str.erase(0, j + 1);
					j = 0;
				}
				else {
					s = s + '|' + subs;
					count++;
					j = 0;
				}
			}
		}
	}
	return count;
}
int findSciFi(film*&a,int number) {
	int count = 0;
	for (int i = 0; i < number; i++) {
		if (a[i].theloai.find("Sci-Fi") != string::npos) {
			count++;
		}
	}
	return count;
}
int morecategories(film*& a, int number) {
	int count = 0;
	for (int i = 0; i < number; i++) {
		if (a[i].theloai.find("|") != string::npos) {
			count++;
		}
	}
	return count;
}
int main() {
	film* list = new film[26];
	int number = 0;
	readfile("movies.txt", list, number);
	takeDate(list, number);
	//printFile("movies.txt", list, number);
	string s = list[0].theloai;
	//cout << countTheloai(list, number, s) << endl;
	//printFile("movies.txt", list, number);
	cout << endl;
	//cout << "Tat ca cac the loai da co la: " << s << endl;
	cout << findSciFi(list, number)<<endl;
	cout << morecategories(list, number);
	delete[]list;
	list = nullptr;
	return 0;
}