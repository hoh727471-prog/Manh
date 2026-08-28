#include <iostream>
using namespace std;

class MaTran
{
private:
    int soHang;
    int soCot;
    int a[100][100];

public:
    // Hàm tạo mặc định
    MaTran()
    {
        soHang = 0;
        soCot = 0;
    }

    // Hàm tạo có tham số
    MaTran(int hang, int cot)
    {
        soHang = hang;
        soCot = cot;
    }

    // Hàm nhập ma trận
    void Nhap()
    {
        cout << "Nhap so hang: ";
        cin >> soHang;

        cout << "Nhap so cot: ";
        cin >> soCot;

        cout << "Nhap cac phan tu cua ma tran:" << endl;

        for (int i = 0; i < soHang; i++)
        {
            for (int j = 0; j < soCot; j++)
            {
                cout << "a[" << i << "][" << j << "] = ";
                cin >> a[i][j];
            }
        }
    }

    // Hàm xuất ma trận
    void Xuat()
    {
        cout << "Ma tran:" << endl;

        for (int i = 0; i < soHang; i++)
        {
            for (int j = 0; j < soCot; j++)
            {
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Hàm hủy
    ~MaTran()
    {
    }
};

int main()
{
    MaTran mt;

    // Nhập ma trận
    mt.Nhap();

    // Xuất ma trận
    mt.Xuat();

    return 0;
}