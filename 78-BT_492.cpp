#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ================= CÂU 1 =================
// Khai báo lớp SinhVien
class SinhVien
{
private:
    string hoTen;
    int namSinh;
    float diem[4];

public:

    // ================= CÂU 2 =================
    // Phương thức nhập
    void nhap()
    {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);

        cout << "Nhap nam sinh: ";
        cin >> namSinh;

        cout << "Nhap diem 4 mon hoc:\n";

        for (int i = 0; i < 4; i++)
        {
            cout << "Nhap diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    // Phương thức xuất
    void xuat()
    {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Nam sinh: " << namSinh << endl;

        cout << "Diem 4 mon: ";

        for (int i = 0; i < 4; i++)
        {
            cout << diem[i] << " ";
        }

        cout << endl;

        cout << "Diem trung binh: "
             << fixed << setprecision(2)
             << tinhDiemTrungBinh() << endl;
    }

    // Phương thức tính điểm trung bình
    float tinhDiemTrungBinh()
    {
        float tong = 0;

        for (int i = 0; i < 4; i++)
        {
            tong += diem[i];
        }

        return tong / 4;
    }

    // Kiểm tra điều kiện tốt nghiệp
    bool totNghiep()
    {
        // Kiểm tra có môn nào dưới 5 hay không
        for (int i = 0; i < 4; i++)
        {
            if (diem[i] < 5)
            {
                return false;
            }
        }

        // Kiểm tra điểm trung bình
        if (tinhDiemTrungBinh() >= 7)
        {
            return true;
        }

        return false;
    }
};


// ================= CÂU 3 =================
int main()
{
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    SinhVien ds[100];

    // Nhập n sinh viên
    for (int i = 0; i < n; i++)
    {
        cout << "\n========== SINH VIEN THU "
             << i + 1 << " ==========\n";

        ds[i].nhap();
    }

    // Xuất danh sách sinh viên
    cout << "\n\n========== DANH SACH SINH VIEN ==========\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\n----- Sinh vien thu " << i + 1 << " -----\n";
        ds[i].xuat();
    }

    // In sinh viên đủ điều kiện tốt nghiệp
    cout << "\n\n========== SINH VIEN DU DIEU KIEN TOT NGHIEP ==========\n";

    bool coTotNghiep = false;

    for (int i = 0; i < n; i++)
    {
        if (ds[i].totNghiep())
        {
            cout << "\n----- Sinh vien thu " << i + 1 << " -----\n";
            ds[i].xuat();

            coTotNghiep = true;
        }
    }

    if (coTotNghiep == false)
    {
        cout << "Khong co sinh vien nao du dieu kien tot nghiep.\n";
    }

    return 0;
}