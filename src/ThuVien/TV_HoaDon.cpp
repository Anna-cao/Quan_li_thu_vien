#include "../include/ThuVien.h"
#include <iostream>
using namespace std;

void ThuVien::themHoaDon(const HoaDon& hd) {
    if (soHoaDon >= Max_hoadon) {
        cout << "Danh sach hoa don da day!\n";
        return;
    }
    danhSachHoaDon[soHoaDon++] = hd;
    cout << "Them hoa don thanh cong!\n";
}

void ThuVien::hienThiDanhSachHoaDon() const {
    if (soHoaDon == 0) {
        cout << "Chua co hoa don nao!\n";
        return;
    }
    cout << "\n----- DANH SACH HOA DON MUON -----\n";
    for (int i = 0; i < soHoaDon; ++i) {
        cout << "\n--- Hoa don " << i + 1 << " ---\n";
        danhSachHoaDon[i].hienThiThongTin();
    }
}

void ThuVien::tinhTienPhatQuaHan(const string& maDocGia, const Date& ngayHienTai) {
    DocGia* dg = timDocGiaTheoMa(maDocGia);
    if (!dg) {
        cout << "Khong tim thay doc gia!\n";
        return;
    }
    double tongPhat = 0.0;
    const double phatMoiNgay = 1000.0;

    for (int i = 0; i < soHoaDon; ++i) {
        if (danhSachHoaDon[i].getMaThe() == dg->getTheMuon()->getMaThe()) {
            Date duKien = danhSachHoaDon[i].getNgMuon();
            duKien.congNgay(14);
            if (ngayHienTai > duKien) {
                int quaHan = ngayHienTai - duKien;
                tongPhat += quaHan * phatMoiNgay;
            }
        }
    }
    cout << "Tong tien phat qua han cho doc gia " << maDocGia
         << ": " << tongPhat << " VND\n";
}