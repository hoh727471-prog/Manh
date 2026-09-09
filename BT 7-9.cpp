#include <iostream>
using namespace std;

class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
   
    PhanSo() {
        tuSo = 0;
        mauSo = 1;
    }


    PhanSo(int tu, int mau) {
        tuSo = tu;
        mauSo = mau;
    }

   
    ~PhanSo() {
    }

   
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tuSo;

        do {
            cout << "Nhap mau so: ";
            cin >> mauSo;
        } while (mauSo == 0);
    }

 
    void xuat() {
        cout << tuSo << "/" << mauSo;
    }

  
    void rutGon() {
        int a = tuSo;
        int b = mauSo;

        if (a < 0) a = -a;
        if (b < 0) b = -b;

        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }

        tuSo = tuSo / a;
        mauSo = mauSo / a;

        if (mauSo < 0) {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }

 
    PhanSo cong(PhanSo p) {
        PhanSo kq;

        kq.tuSo = tuSo * p.mauSo + p.tuSo * mauSo;
        kq.mauSo = mauSo * p.mauSo;

        kq.rutGon();
        return kq;
    }

    
    PhanSo tru(PhanSo p) {
        PhanSo kq;

        kq.tuSo = tuSo * p.mauSo - p.tuSo * mauSo;
        kq.mauSo = mauSo * p.mauSo;

        kq.rutGon();
        return kq;
    }

   
    PhanSo nhan(PhanSo p) {
        PhanSo kq;

        kq.tuSo = tuSo * p.tuSo;
        kq.mauSo = mauSo * p.mauSo;

        kq.rutGon();
        return kq;
    }

   
    PhanSo chia(PhanSo p) {
        PhanSo kq;

        kq.tuSo = tuSo * p.mauSo;
        kq.mauSo = mauSo * p.tuSo;

        kq.rutGon();
        return kq;
    }
};

int main() {
    PhanSo a, b;

    cout << "Nhap phan so thu nhat:\n";
    a.nhap();

    cout << "\nNhap phan so thu hai:\n";
    b.nhap();

 
    a.rutGon();
    b.rutGon();

    cout << "\nPhan so thu nhat: ";
    a.xuat();

    cout << "\nPhan so thu hai: ";
    b.xuat();


    cout << "\n\nTong: ";
    PhanSo tong = a.cong(b);
    tong.xuat();

    // Tru
    cout << "\nHieu: ";
    PhanSo hieu = a.tru(b);
    hieu.xuat();

    // Nhan
    cout << "\nTich: ";
    PhanSo tich = a.nhan(b);
    tich.xuat();

    // Chia
    cout << "\nThuong: ";
    PhanSo thuong = a.chia(b);
    thuong.xuat();

    return 0;
}