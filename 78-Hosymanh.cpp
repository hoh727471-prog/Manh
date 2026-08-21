#include <iostream>
#include <string>
using namespace std;

class NhanVien
{
private:
    string hoten;
    string manv;
    string ngaysinh;
    string diachi;

public:
    // Phuong thuc nhap
    void Nhap()
    {
        cout << "Nhap ho ten: ";
        getline(cin, hoten);

        cout << "Nhap ma nhan vien: ";
        getline(cin, manv);

        cout << "Nhap ngay sinh: ";
        getline(cin, ngaysinh);

        cout << "Nhap dia chi: ";
        getline(cin, diachi);
    }

    // Phuong thuc xuat
    void Xuat()
    {
        cout << "\n--- Thong tin nhan vien ---" << endl;
        cout << "Ho ten: " << hoten << endl;
        cout << "Ma nhan vien: " << manv << endl;
        cout << "Ngay sinh: " << ngaysinh << endl;
        cout << "Dia chi: " << diachi << endl;
    }
};

int main()
{
    // Khai bao doi tuong Minh thuoc lop NhanVien
    NhanVien Minh;

    // Nhap thong tin cho Minh
    Minh.Nhap();

    // Xuat thong tin cua Minh
    Minh.Xuat();

    return 0;
}