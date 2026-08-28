#include <iostream>
using namespace std;

class MaTran
{
private:
    int soHang;
    int soCot;
    int a[100][100];

public:

    MaTran()
    {
        soHang = 0;
        soCot = 0;
    }


    MaTran(int hang, int cot)
    {
        soHang = hang;
        soCot = cot;
    }


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


    void Xuat()
    {
        for (int i = 0; i < soHang; i++)
        {
            for (int j = 0; j < soCot; j++)
            {
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }
    }


    MaTran Cong(MaTran mt)
    {
        MaTran ketQua;

        ketQua.soHang = soHang;
        ketQua.soCot = soCot;

        for (int i = 0; i < soHang; i++)
        {
            for (int j = 0; j < soCot; j++)
            {
                ketQua.a[i][j] = a[i][j] + mt.a[i][j];
            }
        }

        return ketQua;
    }


    ~MaTran()
    {
    }
};

int main()
{
   
    MaTran A, B, C;

   
    cout << "===== NHAP MA TRAN A =====" << endl;
    A.Nhap();

 
    cout << endl;
    cout << "===== NHAP MA TRAN B =====" << endl;

    B.Nhap();

 


    C = A.Cong(B);


    cout << endl;
    cout << "===== MA TRAN A =====" << endl;
    A.Xuat();


    cout << endl;
    cout << "===== MA TRAN B =====" << endl;
    B.Xuat();

    cout << endl;
    cout << "===== MA TRAN A + B =====" << endl;
    C.Xuat();

    return 0;
}