#include <iostream>
#include <cmath>
using namespace std;

// =======================
// CÂU 1: LỚP SP1
// =======================
class SP1
{
protected:
    double phanThuc;
    double phanAo;

public:
    // Hàm tạo
    SP1(double thuc = 0, double ao = 0)
    {
        phanThuc = thuc;
        phanAo = ao;
    }

    // Phương thức nhập số phức
    void nhap()
    {
        cout << "Nhap phan thuc: ";
        cin >> phanThuc;

        cout << "Nhap phan ao: ";
        cin >> phanAo;
    }

    // Phương thức in số phức
    void xuat()
    {
        cout << phanThuc;

        if (phanAo >= 0)
            cout << " + " << phanAo << "i";
        else
            cout << " - " << -phanAo << "i";
    }

    // Tính module số phức
    double module()
    {
        return sqrt(phanThuc * phanThuc +
                    phanAo * phanAo);
    }
};


// =======================
// CÂU 2: LỚP SP2 KẾ THỪA SP1
// =======================
class SP2 : public SP1
{
public:
    // Hàm tạo
    SP2(double thuc = 0, double ao = 0)
        : SP1(thuc, ao)
    {
    }

    // Nạp chồng toán tử =
    SP2& operator=(const SP2& x)
    {
        if (this != &x)
        {
            phanThuc = x.phanThuc;
            phanAo = x.phanAo;
        }

        return *this;
    }

    // Nạp chồng toán tử >
    // So sánh theo module
    bool operator>(const SP2& x)
    {
        return module() > x.module();
    }
};


// =======================
// CÂU 3: CHƯƠNG TRÌNH CHÍNH
// =======================
int main()
{
    SP2 ds[10];
    int n;

    // Nhập số lượng phần tử
    do
    {
        cout << "Nhap so luong so phuc (1-10): ";
        cin >> n;
    } while (n < 1 || n > 10);

    // Nhập danh sách
    cout << "\n===== NHAP DANH SACH =====\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nSo phuc thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    // Sắp xếp giảm dần theo module
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ds[j] > ds[i])
            {
                SP2 temp;
                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    // Xuất danh sách sau khi sắp xếp
    cout << "\n===== DANH SACH SAU KHI SAP XEP =====\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nSo phuc thu " << i + 1 << ": ";
        ds[i].xuat();

        cout << "   | Module = "
             << ds[i].module();
    }

    return 0;
}