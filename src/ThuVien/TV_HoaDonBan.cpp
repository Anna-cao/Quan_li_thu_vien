#include "../include/ThuVien.h"
#include <iostream>
using namespace std;

void ThuVien::themHoaDonBan(const HoaDonBan& hdb) {
    if (soHoaDonBan >= Max_hoadonban) {
        cout << "Danh sach hoa don ban da day!\n";
        return;
    }
    danhSachHoaDonBan[soHoaDonBan++] = hdb;
    cout << "Them hoa don ban thanh cong!\n";
}

void ThuVien::hienThiDanhSachHoaDonBan() const {
    if (soHoaDonBan == 0) {
        cout << "Chua co hoa don ban nao!\n";
        return;
    }
    cout << "\n----- DANH SACH HOA DON BAN -----\n";
    for (int i = 0; i < soHoaDonBan; ++i) {
        cout << "\n--- Hoa don ban " << i + 1 << " ---\n";
        danhSachHoaDonBan[i].hienThiThongTin();
    }
}