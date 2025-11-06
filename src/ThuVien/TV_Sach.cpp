#include "../include/ThuVien.h"
#include <iostream>
#include <string>
using namespace std;

void ThuVien::themSach() {
    if (n >= Max_sach) {
        cout << "Thu vien da day, khong the them sach moi!\n";
        return;
    }
    cin.ignore();
    Sach s;
    s.nhap();
    danhSach[n++] = s;
    cout << "Da them sach thanh cong!\n";
}

void ThuVien::hienThi() {
    if (n == 0) {
        cout << "Thu vien trong!\n";
        return;
    }
    cout << "\n----- DANH SACH SACH TRONG THU VIEN -----\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nSach thu " << i + 1 << ":\n";
        danhSach[i].hienThiThongTin();
    }
}

void ThuVien::timTheoTen(const string& ten) {
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (danhSach[i].getTenSach() == ten) {
            danhSach[i].hienThiThongTin();
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay sach co ten \"" << ten << "\"\n";
}

void ThuVien::suaSachTheoMa(const string& ma) {
    for (int i = 0; i < n; ++i) {
        if (danhSach[i].getMaSach() == ma) {
            cout << "Nhap lai thong tin sach:\n";
            danhSach[i].nhap();
            cout << "Da sua thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay sach ma " << ma << "\n";
}

void ThuVien::xoaSachTheoMa(const string& ma) {
    for (int i = 0; i < n; ++i) {
        if (danhSach[i].getMaSach() == ma) {
            for (int j = i; j < n - 1; ++j) danhSach[j] = danhSach[j + 1];
            --n;
            cout << "Da xoa sach ma " << ma << "\n";
            return;
        }
    }
    cout << "Khong tim thay sach ma " << ma << "\n";
}