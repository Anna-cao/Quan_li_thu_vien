#include "../include/HoaDonBan.h"
#include "../include/ThuVien/ThuVien.h"
#include <iostream>
#include <string>
using namespace std;
void ThuVien::themHoaDonBan(const HoaDonBan& hdb) {
    if (soHoaDonBan >= Max_hoadonban) {
        cout << "Danh sach hoa don ban da day!" << endl;
        return;
    }
    danhSachHoaDonBan[soHoaDonBan++] = hdb;
    cout << "Them hoa don ban thanh cong!" << endl;
}
void ThuVien::hienThiDanhSachHoaDonBan() const {
    if (soHoaDonBan == 0) {
        cout << "Chua co hoa don ban nao!" << endl;
        return;
    }
    cout << "\n----- DANH SACH HOA DON BAN -----\n";
    for (int i = 0; i < soHoaDonBan; ++i) {
        cout << "\n--- Hoa don ban " << i + 1 << " ---\n";
        danhSachHoaDonBan[i].hienThiThongTin();
    }
}

void ThuVien::tinhTienPhatQuaHan(const string& maDocGia, const Date& ngayHienTai) {
    DocGia* dg = timDocGiaTheoMa(maDocGia);
    if (!dg) {
        cout << "Khong tim thay doc gia!" << endl;
        return;
    }
    double tongPhat = 0.0;
    const double phatMoiNgay = 1000.0;
    for (int i = 0; i < soHoaDon; ++i) {
        if (danhSachHoaDon[i].getMaThe() == dg->getTheMuon()->getMaThe()) {
            Date ngTraDuKien = danhSachHoaDon[i].getNgMuon();
            ngTraDuKien.congNgay(14);

            if (ngayHienTai > ngTraDuKien) {
                int ngayQuaHan = ngayHienTai - ngTraDuKien;
                tongPhat += ngayQuaHan * phatMoiNgay;
            }
        }
    }
    cout << "Tong tien phat qua han cho doc gia " << maDocGia << ": " << tongPhat << " VND" << endl;
}