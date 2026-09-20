#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class Môn học
class MonHoc {
protected:
    string tenMonHoc;
    float diemCC; // Điểm chuyên cần
    float diemKT; // Điểm kiểm tra
    float diemDT; // Điểm thi

public:
    MonHoc() {
        tenMonHoc = "";
        diemCC = 0;
        diemKT = 0;
        diemDT = 0;
    }
};

// Class Sinh viên kế thừa từ Class Môn học
class SinhVien : public MonHoc {
private:
    string hoTen;
    string lop;
    string maSV;

public:
    SinhVien() : MonHoc() {
        hoTen = "";
        lop = "";
        maSV = "";
    }

    // Câu 2: Phương thức nhập thông tin sinh viên
    void nhap() {
        cin.ignore();
        cout << "Nhap ho ten sinh vien: ";
        getline(cin, hoTen);
        cout << "Nhap ma sinh vien: ";
        getline(cin, maSV);
        cout << "Nhap lop: ";
        getline(cin, lop);
        cout << "Nhap ten mon hoc: ";
        getline(cin, tenMonHoc);
        cout << "Nhap diem chuyên can (CC): ";
        cin >> diemCC;
        cout << "Nhap diem kiem tra (KT): ";
        cin >> diemKT;
        cout << "Nhap diem thi (DT): ";
        cin >> diemDT;
    }

    // Câu 2: Phương thức tính điểm học phần
    // Công thức tính điểm hp thông thường: 10% CC + 30% KT + 60% DT
    float tinhDiemHocPhan() const {
        return diemCC * 0.1f + diemKT * 0.3f + diemDT * 0.6f;
    }

    // Kiểm tra sinh viên có bị cấm thi hay không (ĐIỂM CC < 5 HOẶC ĐIỂM KT == 0)
    bool isCamThi() const {
        return (diemCC < 5 || diemKT == 0);
    }

    // Câu 2: Phương thức xuất thông tin sinh viên
    void xuat() const {
        cout << "MSV: " << maSV 
             << " | Ho ten: " << hoTen 
             << " | Lop: " << lop 
             << " | Mon hoc: " << tenMonHoc 
             << " | Điểm CC: " << diemCC 
             << " | Điểm KT: " << diemKT 
             << " | Điểm DT: " << diemDT 
             << " | Điểm Học Phần: " << tinhDiemHocPhan() << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    vector<SinhVien> dsSV(n);

    // Nhập danh sách sinh viên
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thông tin sinh vien thu " << i + 1 << " ---" << endl;
        dsSV[i].nhap();
    }

    // Câu 3: In ra màn hình thông tin các sinh viên bị cấm thi
    cout << "\n================ DANH SÁCH SINH VIÊN BỊ CẤM THI ================" << endl;
    bool coCamThi = false;
    for (int i = 0; i < n; i++) {
        if (dsSV[i].isCamThi()) {
            dsSV[i].xuat();
            coCamThi = true;
        }
    }

    if (!coCamThi) {
        cout << "Khong co sinh vien nao bi cam thi." << endl;
    }

    return 0;
}