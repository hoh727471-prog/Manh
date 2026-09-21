#include <iostream>
using namespace std;

// ================= CÂU 1 =================
class PS1
{
protected:
    int tu, mau;

public:
    void nhap()
    {
        cout << "Nhap tu so: ";
        cin >> tu;

        do
        {
            cout << "Nhap mau so (khac 0): ";
            cin >> mau;
        } while (mau == 0);
    }

    void in()
    {
        if (mau == 1)
            cout << tu;
        else
            cout << tu << "/" << mau;
    }

    void toiGian()
    {
        int a = tu;
        int b = mau;

        if (a < 0) a = -a;
        if (b < 0) b = -b;

        while (b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }

        tu = tu / a;
        mau = mau / a;

        // Đưa dấu âm lên tử
        if (mau < 0)
        {
            tu = -tu;
            mau = -mau;
        }
    }
};

// ================= CÂU 2 =================
class PS2 : public PS1
{
public:
    // Nạp chồng toán tử =
    PS2& operator=(const PS2& p)
    {
        tu = p.tu;
        mau = p.mau;
        return *this;
    }

    // Nạp chồng toán tử >
    bool operator>(const PS2& p)
    {
        return tu * p.mau > p.tu * mau;
    }
};

// ================= CÂU 3 =================
int main()
{
    PS2 ds[10];
    int n;

    cout << "Nhap so luong phan so: ";
    cin >> n;

    if (n > 10)
        n = 10;

    // Nhap danh sach
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phan so thu " << i + 1 << ":\n";
        ds[i].nhap();
        ds[i].toiGian();
    }

    // Sap xep giam dan
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ds[j] > ds[i])
            {
                PS2 tam;
                tam = ds[i];
                ds[i] = ds[j];
                ds[j] = tam;
            }
        }
    }

    // In danh sach sau khi sap xep
    cout << "\nDanh sach phan so giam dan:\n";

    for (int i = 0; i < n; i++)
    {
        ds[i].in();
        cout << "  ";
    }

    return 0;
}