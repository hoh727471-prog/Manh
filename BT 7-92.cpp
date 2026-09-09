#include <iostream>
#include <numeric>
using namespace std;

class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
    // Ham tao khong doi
    PhanSo() {
        tuSo = 0;
        mauSo = 1;
    }

    // Ham tao co doi
    PhanSo(int tu, int mau) {
        tuSo = tu;
        mauSo = (mau == 0) ? 1 : mau;
    }

    // Ham huy
    ~PhanSo() {}

    // Nap chong toan tu nhap
    friend istream& operator>>(istream& in, PhanSo& ps) {
        cout << "Nhap tu so: ";
        in >> ps.tuSo;

        do {
            cout << "Nhap mau so (khac 0): ";
            in >> ps.mauSo;
        } while (ps.mauSo == 0);

        return in;
    }

    // Nap chong toan tu xuat
    friend ostream& operator<<(ostream& out, const PhanSo& ps) {
        if (ps.mauSo == 1)
            out << ps.tuSo;
        else if (ps.tuSo == 0)
            out << 0;
        else
            out << ps.tuSo << "/" << ps.mauSo;

        return out;
    }

    // Rut gon phan so
    void rutGon() {
        int ucln = gcd(abs(tuSo), abs(mauSo));

        if (ucln != 0) {
            tuSo /= ucln;
            mauSo /= ucln;
        }

        if (mauSo < 0) {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }

    // Toan tu +
    PhanSo operator+(const PhanSo& ps) const {
        PhanSo kq(
            tuSo * ps.mauSo + ps.tuSo * mauSo,
            mauSo * ps.mauSo
        );
        kq.rutGon();
        return kq;
    }

    // Toan tu -
    PhanSo operator-(const PhanSo& ps) const {
        PhanSo kq(
            tuSo * ps.mauSo - ps.tuSo * mauSo,
            mauSo * ps.mauSo
        );
        kq.rutGon();
        return kq;
    }

    // Toan tu *
    PhanSo operator*(const PhanSo& ps) const {
        PhanSo kq(
            tuSo * ps.tuSo,
            mauSo * ps.mauSo
        );
        kq.rutGon();
        return kq;
    }

    // Toan tu /
    PhanSo operator/(const PhanSo& ps) const {
        PhanSo kq(
            tuSo * ps.mauSo,
            mauSo * ps.tuSo
        );
        kq.rutGon();
        return kq;
    }
};

int main() {
    PhanSo ps1, ps2;

    cout << "===== NHAP PHAN SO THU NHAT =====" << endl;
    cin >> ps1;

    cout << "\n===== NHAP PHAN SO THU HAI =====" << endl;
    cin >> ps2;

    ps1.rutGon();
    ps2.rutGon();

    cout << "\nPhan so thu nhat: " << ps1 << endl;
    cout << "Phan so thu hai: " << ps2 << endl;

    cout << "\n===== KET QUA =====" << endl;
    cout << ps1 << " + " << ps2 << " = " << ps1 + ps2 << endl;
    cout << ps1 << " - " << ps2 << " = " << ps1 - ps2 << endl;
    cout << ps1 << " * " << ps2 << " = " << ps1 * ps2 << endl;

    cout << ps1 << " / " << ps2 << " = " << ps1 / ps2 << endl;

    return 0;
}
