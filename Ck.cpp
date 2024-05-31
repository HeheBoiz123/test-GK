#include <iostream>	
#include <string>	
#include <sstream>
#include <fstream>
using namespace std;
struct Student {
	int SBD;
	double Toan,Van,Anh,Sinh,Ly,Hoa, Su, Dia, GDCD;
	string Tinh;
	int Nhomthi;
	int DiemTN;
	bool KQ = 1;
};
void Readfile(const string& s, Student*& a,int &i) {
	ifstream data;
	data.open(s, ios::in);
	if (data.is_open()) {
		string s;
		getline(data, s);
		while (getline(data, s)) {
			stringstream token(s);
			token >>a[i].SBD>> a[i].Toan >> a[i].Van >> a[i].Anh
				>> a[i].Sinh >> a[i].Ly >> a[i].Hoa
				>> a[i].Su >> a[i].Dia >> a[i].GDCD;
			token >> ws;
			getline(token, a[i].Tinh);
			i++;
		}
	}
	data.close();
}
void InDS(Student*& a, int n) {
	for (int i = 0; i < n; i++) {
		cout <<a[i].SBD<< a[i].Toan << " " << a[i].Van << " " << a[i].Anh << " "
			<< a[i].Sinh << " " << a[i].Ly << " " << a[i].Hoa << " "
			<< a[i].Su << " " << a[i].Dia << " " << a[i].GDCD << " "
			<< a[i].Tinh << endl;
	}
}
int Bothitoan(Student*&a,int number,int list[]) {
	int count=0;
	int j = 0;
	for (int i = 0; i < number; i++) {
		if (a[i].Toan == -1) {
			count++;
			list[j] = i;
			j++;
		}
	}
	return count;
}
void InlistNoMATH(Student*& a, int countlist,int List[]) {
	for (int i = 0; i < countlist; i++) {
		cout <<a[List[i]].SBD<< a[List[i]].Toan << " " << a[List[i]].Van << " " << a[List[i]].Anh << " "
			<< a[List[i]].Sinh << " " << a[List[i]].Ly << " " << a[List[i]].Hoa << " "
			<< a[List[i]].Su << " " << a[List[i]].Dia << " " << a[List[i]].GDCD << " "
			<< a[List[i]].Tinh << endl;
	}
}
void PhanloaiHS(Student*&a,int n,int &TN,int &XH) {
	for (int i = 0; i < n; i++) {
		if (a[i].Sinh == -1 && a[i].Ly == -1 && a[i].Hoa == -1) {
			a[i].Nhomthi = 0;
			XH++;
		}
		if (a[i].Su == -1 && a[i].Dia == -1 && a[i].GDCD == -1) {
			a[i].Nhomthi = 1;
			TN++;
		}
	}
}
void TinhDiemTotNghiep(Student*& a, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i].Nhomthi == 1) {
			a[i].DiemTN = ((a[i].Sinh + a[i].Ly + a[i].Hoa) / 3 + a[i].Toan + a[i].Van + a[i].Anh) / 4;
		}
		if (a[i].Nhomthi == 0) {
			a[i].DiemTN = ((a[i].Su + a[i].Dia + a[i].GDCD) / 3 + a[i].Toan + a[i].Van + a[i].Anh) / 4;
		}
	}
}
int SortMAXbyTinh(Student*&a, int n,const string s) {
	int max = -1;
	int sbd = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].Tinh == s && a[i].DiemTN > max) {
			max = a[i].DiemTN;
			sbd = a[i].SBD;
		}
	}
	return sbd;
}
void inCaNhan(Student*& a, int n, int sbd) {
	for (int i = 0; i < n; i++) {
		if (a[i].SBD == sbd) {
			cout << a[i].SBD << a[i].Toan << " " << a[i].Van << " " << a[i].Anh << " "
				<< a[i].Sinh << " " << a[i].Ly << " " << a[i].Hoa << " "
				<< a[i].Su << " " << a[i].Dia << " " << a[i].GDCD << " "
				<< a[i].Tinh <<" "<<a[i].DiemTN <<endl;
		}
	}
}
void KetQuaTN(Student*& a, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i].Toan < 1 || a[i].Van < 1 || a[i].Anh < 1|| a[i].DiemTN < 5) {
			a[i].KQ = 0;
		}
	}
}
int SortDau(Student*&a,int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].KQ == 1) {
			count++;
		}
	}
	return count;
}
int SortRot(Student*& a, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].KQ == 0) {
			count++;
		}
	}
	return count;
}
void WriteThisinhXH(Student*&a,int n,const string s,const string Tinh) {
	ofstream file;
	file.open(s, ios::app);
	if (file.is_open()) {
		for (int i = 0; i < n; i++) {
			if (a[i].Tinh == Tinh && a[i].Nhomthi == 0) {
				file << a[i].SBD <<" "<< a[i].Toan << " " << a[i].Van << " " << a[i].Anh << " "
					<< a[i].Sinh << " " << a[i].Ly << " " << a[i].Hoa << " "
					<< a[i].Su << " " << a[i].Dia << " " << a[i].GDCD << " "
					<< a[i].DiemTN<<" "<<a[i].Tinh << " " << endl;
			}
		}
	}
	file.close();
}
int main() {
	Student* list = new Student[100];
	int number = 0;
	int listofNoMATH[100];
	Readfile("diem_thi_2021.txt", list, number);
	int TN = 0;
	int XH = 0;
	PhanloaiHS(list, number, TN, XH);
	TinhDiemTotNghiep(list, number);
	while (true) {
		cout << "***************************************************" << endl;
		cout << "Quan ly danh sach thi sinh thi tot nghiep 2021" << endl;
		cout << "1.Thi sinh bo thi mon Toan" << endl;
		cout << "2.So luong thi sinh thi xa hoi" << endl;
		cout << "3.Thi sinh co diem thi tu nhien cao nhat Quang Ninh" << endl;
		cout << "4.So luong thi sinh rot tot nghiep" << endl;
		cout << "5.So luong thi sinh dau tot nghiep" << endl;
		cout << "6.Tim thi sinh dua vao SBD" << endl;
		cout << "7.In danh sach bo thi mon Toan" << endl;
		cout << "8.Ghi thi sinh XH thuoc HP Vinh Nam Dinh vao File" << endl;
		cout << "0.Ket thuc" << endl;
		cout << "***************************************************" << endl;
		cout << "Nhap lua chon cua ban: ";
		int a; cin >> a;
		switch (a) {
		case 0:
		{
			cout << "Cam on ban da xem <3" << endl;
			system("pause");
			exit(0);
			break;
		}
		case 1:
		{
			cout << "So luong thi sinh bo thi mon Toan la: " << Bothitoan(list, number, listofNoMATH) << endl;
			break;
		}
		case 2:
		{
			cout << "So luong thi sinh thi xa hoi la: " << XH << endl;
			break;
		}
		case 3:
		{
			cout << "Thi sinh co diem thi tu nhien cao nhat Quang Ninh co SBD: " << SortMAXbyTinh(list, number, "Quang Ninh") << endl;
			inCaNhan(list, number, SortMAXbyTinh(list, number, "Quang Ninh"));
			cout << endl;
			break;
		}
		case 4:
		{
			cout << "So luong thi sinh rot tot nghiep: " << SortRot << endl;
			break;
		}
		case 5:
		{
			cout << "So luong thi sinh rot tot nghiep: " << SortDau << endl;;
			break;
		}
		case 6:
		{
			cout << "Nhap SBD can tim: ";
			int sbd; cin >> sbd;
			inCaNhan(list, number, sbd);
			cout << endl;
		}
		case 7:
		{
			InlistNoMATH(list, Bothitoan(list, number, listofNoMATH), listofNoMATH);
			cout << endl;
		}
		case 8:
		{
			WriteThisinhXH(list, number, "diem_XH_HP_V_ND.txt", "Hai Phong");
			WriteThisinhXH(list, number, "diem_XH_HP_V_ND.txt", "Vinh");
			WriteThisinhXH(list, number, "diem_XH_HP_V_ND.txt", "Nam Dinh");
			cout << "Da ghi vao file diem_XH_HP_V_ND.txt" << endl;
		}
		}
		while (true) {
			cout << "Nhan 1 de tiep tuc hoac 0 de ket thuc: ";
			int b; cin >> b;
			if (b == 0)
			{
				cout << "Cam on ban da xem <3";
				exit(0);
			}
			if (b == 1)
				break;
			else
				cout << "Khong hop le nhap lai. " << endl;
		}
		system("cls");
	}
	delete[]list;
	return 0;
}