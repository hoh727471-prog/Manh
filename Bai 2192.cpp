#include <iostream>
#include <cmath>
using namespace std;

// ================= CÂU 1 =================
class SP1
{
protected:
    float thuc, ao;

public:
    // Ham tao
    SP1()
    {
        thuc = 0;
        ao = 0;
    }

    SP1(float t, float a)
    {
        thuc = t;
        ao = a;
    }

    // Nhap so phuc
    void nhap()
    {
        cout << "Nhap phan thuc: ";
        cin >> thuc;

        cout << "Nhap phan ao: ";
        cin >> ao;
    }

    // In so phuc
    void in()
    {
        if (ao >= 0)
            cout << thuc << " + " << ao << "i";
        else
            cout << thuc << " - " << -ao << "i";
    }

    // Tinh module
    float module()
    {
        return sqrt(thuc * thuc + ao * ao);
    }
};

// ================= CÂU 2 =================
class SP2 : public SP1
{
public:
    // Nạp chồng toán tử =
    SP2& operator=(const SP2& p)
    {
        thuc = p.thuc;
        ao = p.ao;
        return *this;
    }

    // Nạp chồng toán tử >
    // So sánh theo module
    bool operator>(const SP2& p)
    {
        return module() > p.module();
    }
};

// ================= CÂU 3 =================
int main()
{
    SP2 ds[10];
    int n;

    cout << "Nhap so luong so phuc: ";
    cin >> n;

    if (n > 10)
        n = 10;

    // Nhap danh sach
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap so phuc thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    // Sap xep giam dan theo module
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ds[j] > ds[i])
            {
                SP2 tam;
                tam = ds[i];
                ds[i] = ds[j];
                ds[j] = tam;
            }
        }
    }

    // In danh sach
    cout << "\nDanh sach so phuc giam dan theo module:\n";

    for (int i = 0; i < n; i++)
    {
        ds[i].in();
        cout << "   Module = " << ds[i].module() << endl;
    }

    return 0;
}