#include <iostream>
#include <string>
using namespace std;

// ================= LỚP NGƯỜI =================
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
        cin.ignore();
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


// ================= LỚP SINH VIÊN =================
class SinhVien : public Nguoi
{
private:
    string maSV;
    float diemTB;

public:
    // Hàm tạo không đối
    SinhVien() : Nguoi()
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

        cout << "Nhap ma sinh vien: ";
        cin >> maSV;

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

    // Hàm tìm kiếm theo mã sinh viên
    bool timTheoMa(string ma)
    {
        return maSV == ma;
    }

    // Hàm tìm kiếm theo họ tên
    bool timTheoTen(string ten)
    {
        return hoTen == ten;
    }
};


// ================= HÀM MAIN =================
int main()
{
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    // Cấp phát mảng động
    SinhVien *ds = new SinhVien[n];

    // ================= CÂU 2 =================
    // Nhập danh sách sinh viên
    for (int i = 0; i < n; i++)
    {
        cout << "\n===== NHAP SINH VIEN THU " << i + 1 << " =====" << endl;
        ds[i].nhap();
    }

    // ================= CÂU 3 =================
    string tuKhoa;

    cout << "\n====================================" << endl;
    cout << "Nhap ma sinh vien hoac ho ten can tim: ";
    cin.ignore();
    getline(cin, tuKhoa);

    bool timThay = false;

    for (int i = 0; i < n; i++)
    {
        if (ds[i].timTheoMa(tuKhoa) || ds[i].timTheoTen(tuKhoa))
        {
            cout << "\n===== SINH VIEN TIM THAY =====" << endl;
            ds[i].xuat();

            timThay = true;
        }
    }

    if (timThay == false)
    {
        cout << "\nKhong tim thay sinh vien!" << endl;
    }

    // Giải phóng bộ nhớ
    delete[] ds;

    return 0;
}