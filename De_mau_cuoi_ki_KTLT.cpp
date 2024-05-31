#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
struct diemxh
{
    double su, dia, gdcd;
};

struct diemtn
{
    double sinh, ly, hoa;
};
struct d
{
    double toan, van, anh;
    diemxh xh;
    diemtn tn;
};
struct in4
{
    d diem;
    string mssv, tinh;
    int size;
};
string is_sp(string s)
{

    size_t start = s.find_first_not_of(' '); // tim ra vi tri dau tien cua ky tu khong phai la khoang trang
    size_t end = s.find_last_not_of(' ');    // tim ra vi tri cuoi cung cua ky tu khong phai la khoang trang

    if (start == std::string::npos)
    {
        return ""; // Chuỗi chỉ chứa khoảng trắng
    }

    return s.substr(start, end - start + 1);
}
bool rot_tn(in4 *a, int i);
void input(in4 *a)
{
    int count = 0;
    ifstream input("diem_thi_2021.txt");
    if (!input)
    {
        cout << "khong the mo file duoc!" << endl;
        return;
    }
    string c;
    getline(input, c);
    int i = 0;
    while (getline(input, c))
    {
        stringstream ss(c);
        string ms, toan, van, anh, ly, hoa, sinh, su, dia, gdcd, tinh;
        ss >> ms >> toan >> van >> anh >> ly >> hoa >> sinh >> su >> dia >> gdcd;
        getline(ss, tinh);
        a[i].mssv = ms;
        a[i].tinh = is_sp(tinh);
        // diem tu nhien
        a[i].diem.tn.hoa = stof(hoa);
        a[i].diem.tn.sinh = stof(sinh);
        a[i].diem.tn.ly = stof(ly);
        // diem xa hoi
        a[i].diem.xh.dia = stof(dia);
        a[i].diem.xh.gdcd = stof(gdcd);
        a[i].diem.xh.su = stof(su);
        // diem 3 mon bat buoc
        a[i].diem.toan = stof(toan);
        a[i].diem.anh = stof(anh);
        a[i].diem.van = stof(van);
        if (rot_tn(a, i))
        {
            count++;
        }
        i++;
        a[0].size = i;
    }

    input.close();
    cout << "so sinh vien rot tn" << count - 1 << endl;
}
int toan_less(in4 *a)
{
    int count = 0;
    for (int i = 0; i < a[0].size; i++)
    {
        if (a[i].diem.toan == -1.0)
        {
            count++;
        }
    }
    return count;
}
int xahoi_count(in4 *a)
{
    int count = 0;
    for (int i = 0; i < a[0].size; i++)
    {
        if (a[i].diem.xh.dia != -1.0)
        {
            count++;
        }
    }
    return count;
}
double tong_diem(double a, double b, double c)
{
    return a + b + c;
}
int the_chosen_one(in4 *a)
{
    int max = 0;
    int position = 0;
    for (int i = 0; i < a[0].size; i++)
    {
        if (a[i].tinh == "Quang Ninh")
        {
            if (max < tong_diem(a[i].diem.tn.hoa, a[i].diem.tn.ly, a[i].diem.tn.sinh))
            {
                max = tong_diem(a[i].diem.tn.hoa, a[i].diem.tn.ly, a[i].diem.tn.sinh);
                position = i;
            }
        }
        continue;
    }
    return position;
}
double diem_tot_nghiep(double tong, double toan, double van, double anh)
{
    return ((tong / 3.0) + toan + van + anh) / 4.0;
}
bool rot_tn(in4 *a, int i)
{
    if (a[i].diem.toan == -1 || a[i].diem.van == -1 || a[i].diem.anh == -1)
        return true;
    if (a[i].diem.toan < 1 || a[i].diem.van < 1 || a[i].diem.anh < 1)
        return true;
    if (a[i].diem.tn.hoa == -1)
    {
        if (diem_tot_nghiep(tong_diem(a[i].diem.xh.dia, a[i].diem.xh.gdcd, a[i].diem.xh.gdcd), a[i].diem.toan, a[i].diem.van, a[i].diem.anh) < 5.0)
        {
            return true;
        }
    }
    else
    {
        if (diem_tot_nghiep(tong_diem(a[i].diem.tn.sinh, a[i].diem.tn.ly, a[i].diem.tn.hoa), a[i].diem.toan, a[i].diem.van, a[i].diem.anh) < 5.0)
        {
            return true;
        }
    }
    return false;
}
bool tinh(in4 *a, int i)
{
    return a[i].tinh == "Hai Phong" || a[i].tinh == "Vinh" || a[i].tinh == "Nam Dinh" ? true : false;
}
void ghifile(in4 *a)
{
    ofstream output("d_xg_HP_V_ND.txt");
    if (!output.is_open())
    {
        cout << "Khogn the mo file" << endl;
    }
    for (int i = 0; i < a[0].size; i++)
    {
        if (tinh(a, i))
        {
            output << a[i].mssv << " " << a[i].diem.toan << " " << a[i].diem.tn.hoa << " " << a[i].diem.xh.dia << " " << tinh << endl;
        }
    }
    output.close();
}
int main()
{
    in4 *sinhvien = new in4[150];
    input(sinhvien);

    // cout << toan_less(sinhvien)<<endl;
    // cout << xahoi_count(sinhvien);

    cout << sinhvien[the_chosen_one(sinhvien)].mssv << endl;
    ghifile(sinhvien);
    delete[] sinhvien;
    sinhvien = nullptr;
}