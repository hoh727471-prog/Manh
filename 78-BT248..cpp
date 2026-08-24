#include <iostream>
using namespace std;

class NhanVien
{
private:
    string hoTen;
    int tuoi;
    double luong;

public:
    void nhap()
    {
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);

        cout << "Nhap tuoi: ";
        cin >> tuoi;

        cout << "Nhap luong: ";
        cin >> luong;
    }

    void xuat()
    {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Luong: " << luong << endl;
    }
};

int main()
{
    int i;

    // CACH 2: DUNG NEW CAP PHAT MANG DONG

    // Khai bao con tro
    NhanVien *dsnv;

    // Cap phat mang dong gom 10 nhan vien
    dsnv = new NhanVien[10];

    // Nhap du lieu cho mang
    for (i = 0; i < 10; i++)
    {
        cout << "\n=== NHAP THONG TIN NHAN VIEN THU "
             << i + 1 << " ===" << endl;

        dsnv[i].nhap();
    }

    // Xuat du lieu ra man hinh
    cout << "\n\n========== DANH SACH NHAN VIEN ==========" << endl;

    for (i = 0; i < 10; i++)
    {
        cout << "\n=== NHAN VIEN THU " << i + 1 << " ===" << endl;

        dsnv[i].xuat();
    }

    // Giai phong bo nho
    delete[] dsnv;

    return 0;
}