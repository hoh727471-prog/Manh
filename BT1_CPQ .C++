#include <iostream>
#include <string>
using namespace std;

struct NhanVien {
    string maNV;
    string tenNV;
    float luongCoBan;
    float heSo;
};

int main() {
    int n;

    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore();

    NhanVien ds[n];

    // Nhap thong tin n nhan vien
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin nhan vien " << i + 1 << ":\n";

        cout << "Ma nhan vien: ";
        getline(cin, ds[i].maNV);

        cout << "Ten nhan vien: ";
        getline(cin, ds[i].tenNV);

        cout << "Luong co ban: ";
        cin >> ds[i].luongCoBan;

        cout << "He so: ";
        cin >> ds[i].heSo;

        cin.ignore();
    }

    // Xuat thong tin
    cout << "\n========== DANH SACH NHAN VIEN ==========\n";

    for (int i = 0; i < n; i++) {
        cout << "\nNhan vien " << i + 1 << ":\n";
        cout << "Ma NV        : " << ds[i].maNV << endl;
        cout << "Ten NV       : " << ds[i].tenNV << endl;
        cout << "Luong co ban : " << ds[i].luongCoBan << endl;
        cout << "He so        : " << ds[i].heSo << endl;
    }

    return 0;
}
