#include "../include/Sach.h"
#include "../include/ThuVien/ThuVien.h"
#include <iostream>
#include <string>

using namespace std;
void ThuVien::themSach() {
    if (n >= Max_sach) {
        cout << "Thu vien da day, khong the them sach moi!" << endl;
        return;
    }
    cin.ignore();
    Sach s;
    s.nhap();
    danhSach[n++] = s;
    cout << "Da them sach thanh cong!" << endl;
}
void ThuVien::hienThi() {
    if (n == 0) {
        cout << "Thu vien trong!" << endl;
        return;
    }
    cout << "\n----- DANH SACH SACH TRONG THU VIEN -----\n";
    for (int i = 0; i < n; i++) {
        cout << "\nThong tin cua sach thu " << i + 1 << " la:" << endl;
        danhSach[i].hienThiThongTin();
    }
}
void ThuVien::timTheoTen(string ten) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (danhSach[i].getTenSach() == ten) {
            danhSach[i].hienThiThongTin();
            found = true;
        }
    }
    if (!found)
        cout << "Khong tim thay sach co ten \"" << ten << "\"" << endl;
}
void ThuVien::suaSachTheoMa(string ma) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (danhSach[i].getMaSach() == ma) {
            cout << "Nhap lai thong tin sach: " << endl;
            danhSach[i].nhap();
            cout << "Da sua thanh cong!" << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Khong tim thay thong tin sach co ma: " << ma << endl;
}
void ThuVien::xoaSachTheoMa(string ma) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (danhSach[i].getMaSach() == ma) {
            for (int j = i; j < n - 1; j++) {
                danhSach[j] = danhSach[j + 1];
            }
            n--;
            cout << "Da xoa sach co ma " << ma << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Khong tim thay sach co ma: " << ma << endl;
}