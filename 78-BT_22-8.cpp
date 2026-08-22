#include <iostream>
#include <vector>
using namespace std;

// =======================
// LOP NHAN VIEN
// =======================
class NhanVien
{
private:
    string hoTen;
    int tuoi;
    double luong;

public:
    void nhap()
    {
        cout << "Nhap ho ten: ";
        cin.ignore();
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

// =======================
// HAM MAIN
// =======================
int main()
{
    int i;

    // ==================================================
    // CACH 1: DUNG MANG TINH
    // ==================================================

    cout << "\n========== CACH 1: MANG TINH ==========\n";

    NhanVien dsnv1[10];

    // Nhap du lieu cho mang
    for (i = 0; i < 10; i++)
    {
        cout << "\n=== NHAP THONG TIN NHAN VIEN THU "
             << i + 1 << " ===" << endl;

        dsnv1[i].nhap();
    }

    // Xuat du lieu
    cout << "\n========== DANH SACH NHAN VIEN ==========\n";

    for (i = 0; i < 10; i++)
    {
        cout << "\n=== NHAN VIEN THU " << i + 1 << " ===" << endl;
        dsnv1[i].xuat();
    }


    // ==================================================
    // CACH 2: DUNG MANG DONG
    // ==================================================

    cout << "\n\n========== CACH 2: MANG DONG ==========\n";

    NhanVien *dsnv2;

    // Cap phat mang dong 10 phan tu
    dsnv2 = new NhanVien[10];

    // Nhap du lieu
    for (i = 0; i < 10; i++)
    {
        cout << "\n=== NHAP THONG TIN NHAN VIEN THU "
             << i + 1 << " ===" << endl;

        dsnv2[i].nhap();
    }

    // Xuat du lieu
    cout << "\n========== DANH SACH NHAN VIEN ==========\n";

    for (i = 0; i < 10; i++)
    {
        cout << "\n=== NHAN VIEN THU " << i + 1 << " ===" << endl;
        dsnv2[i].xuat();
    }

    // Giai phong bo nho
    delete[] dsnv2;


    // ==================================================
    // CACH 3: DUNG VECTOR
    // ==================================================

    cout << "\n\n========== CACH 3: VECTOR ==========\n";

    vector<NhanVien> ds;

    // Nhap 10 nhan vien
    for (i = 0; i < 10; i++)
    {
        NhanVien nv;

        cout << "\n=== NHAP THONG TIN NHAN VIEN THU "
             << i + 1 << " ===" << endl;

        nv.nhap();

        // Them nhan vien vao vector
        ds.push_back(nv);
    }

    // Xuat danh sach
    cout << "\n========== DANH SACH NHAN VIEN ==========\n";

    for (i = 0; i < ds.size(); i++)
    {
        cout << "\n=== NHAN VIEN THU " << i + 1 << " ===" << endl;
        ds[i].xuat();
    }

    return 0;
}
// 78-H? S? M?nh
