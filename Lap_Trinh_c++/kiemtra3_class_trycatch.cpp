#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Định nghĩa lớp SinhVien
class SinhVien {
private:
    string hoTen;
    int maSV;

public:
    // Hàm khởi tạo
    SinhVien(string ten, int ma) {
        hoTen = ten;
        maSV = ma;
    }

    // Phương thức lấy thông tin sinh viên
    void hienThiThongTin() {
        cout << "Ma sinh vien: " << maSV << endl;
        cout << "Ho va ten: " << hoTen << endl;
    }
};

int main() {
    int soLuongSinhVien;
    cout << "Nhap so luong sinh vien: ";
    cin >> soLuongSinhVien;

    vector<SinhVien> danhSachSinhVien;

    // Nhập thông tin cho từng sinh viên
    for (int i = 0; i < soLuongSinhVien; ++i) {
        string ten;
        int ma;
        cout << "Nhap thong tin cho sinh vien thu " << i + 1 << ":" << endl;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, ten);
        cout << "Nhap ma sinh vien: ";
       cin.ignore();
        cin >> ma;
    cin.ignore();
        // Tạo đối tượng sinh viên và thêm vào danh sách
        SinhVien sv(ten, ma);
        danhSachSinhVien.push_back(sv);
    }

    // Hiển thị thông tin của từng sinh viên trong danh sách
    cout << "\nDanh sach sinh vien:\n";
    for (int i = 0; i < soLuongSinhVien; ++i) {
        cout << "\nThong tin cua sinh vien thu " << i + 1 << ":" << endl;
        danhSachSinhVien[i].hienThiThongTin();
    }

    return 0;
}
