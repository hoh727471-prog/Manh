#include <iostream>
#include <string>
using namespace std;

// ================= CÂU 1 =================

// Khai báo lớp Người
class Nguoi
{
protected:
    string hoTen;
    int namSinh;

public:
    // Hàm tạo không đối
    Nguoi()
    {
        hoTen = "";
        namSinh = 0;
    }

    // Hàm tạo có đối
    Nguoi(string ht, int ns)
    {
        hoTen = ht;
        namSinh = ns;
    }

    // Phương thức nhập
    void nhap()
    {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);

        cout << "Nhap nam sinh: ";
        cin >> namSinh;
    }

    // Phương thức xuất
    void xuat()
    {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Nam sinh: " << namSinh << endl;
    }
};


// Lớp SinhVien kế thừa từ lớp Nguoi
class SinhVien : public Nguoi
{
private:
    string maSV;
    float diemTB;

public:
    // ================= CÂU 2 =================

    // Hàm tạo không đối
    SinhVien()
    {
        maSV = "";
        diemTB = 0;
    }

    // Hàm tạo có đối
    SinhVien(string ht, int ns, string ma, float diem)
        : Nguoi(ht, ns)
    {
        maSV = ma;
        diemTB = diem;
    }

    // Phương thức nhập
    void nhap()
    {
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);

        cout << "Nhap nam sinh: ";
        cin >> namSinh;

        cin.ignore();
        cout << "Nhap ma sinh vien: ";
        getline(cin, maSV);

        cout << "Nhap diem trung binh: ";
        cin >> diemTB;
    }

    // Phương thức xuất
    void xuat()
    {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Nam sinh: " << namSinh << endl;
        cout << "Ma sinh vien: " << maSV << endl;
        cout << "Diem trung binh: " << diemTB << endl;
    }

    // Hàm lấy điểm trung bình để sắp xếp
    float getDiemTB()
    {
        return diemTB;
    }
};


// ================= MAIN =================

int main()
{
    // Chay thu ham tao co doi
    cout << "===== CHAY THU HAM TAO CO DOI =====" << endl;

    SinhVien sv1("Nguyen Van An", 2005, "SV001", 8.5);

    sv1.xuat();

    // ================= CÂU 3 =================

    int n;
    cout << "\n===== NHAP DANH SACH SINH VIEN =====" << endl;

    cout << "Nhap n: ";
    cin >> n;

    SinhVien *ds = new SinhVien[n];

    // Nhập danh sách
    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Sinh vien thu " << i + 1 << " ---" << endl;
        ds[i].nhap();
    }

    // Sắp xếp giảm dần theo điểm trung bình
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ds[i].getDiemTB() < ds[j].getDiemTB())
            {
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    // In danh sách sau khi sắp xếp
    cout << "\n===== DANH SACH SINH VIEN GIAM DAN THEO DIEM =====" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Sinh vien thu " << i + 1 << " ---" << endl;
        ds[i].xuat();
    }

    delete[] ds;

    return 0;
}