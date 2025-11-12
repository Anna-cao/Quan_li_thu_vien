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
void ThuVien::capNhatHoaDonDaTra(const string& maHD, const Date& ngayTra) {
    for (int i = 0; i < soHoaDon; ++i) {
        if (danhSachHoaDon[i].getMaHoaDon() == maHD) {
            danhSachHoaDon[i].setDaTra(ngayTra);
            DocGia* dg = timDocGiaTheoMaThe(danhSachHoaDon[i].getMaThe());  
            danhSachHoaDon[i].tinhPhiQuaHan(dg, ngayTra);
            for (const auto& p : danhSachHoaDon[i].getDsSachMuon()) {
                Sach* s = timSachTheoMa(p.first);
                if (s) {
                    for (int j = 0; j < p.second; ++j) {  
                        s->traSach();
                    }
                }
            }
            cout << "Cap nhat hoa don da tra thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay hoa don!\n";
}
void ThuVien::tinhTienPhatQuaHan(const string& maDocGia, const Date& ngayHienTai) {
    DocGia* dg = timDocGiaTheoMa(maDocGia);
    if (!dg || !dg->getTheMuon()) {
        cout << "Khong tim thay doc gia hoac chua co the!\n";
        return;
    }
    double tongPhat = 0.0;
    double phiMotTuan = (dg->getLoaiDocGia() == "HoiVien") ? 5000.0 : 10000.0;
    for (int i = 0; i < soHoaDon; ++i) {
        HoaDon& hd = danhSachHoaDon[i];
        if (hd.getMaThe() != dg->getTheMuon()->getMaThe() || hd.getStatus() != 0) continue;
        Date duKien = hd.getNgayMuon();
        duKien.congNgay(14);
        if (!(ngayHienTai > duKien)) continue;  
        int soNgayQuaHan = ngayHienTai - duKien;
        if (soNgayQuaHan <= 0) continue;  
        int soTuan = (soNgayQuaHan + 6) / 7;
        tongPhat += soTuan * phiMotTuan;
    }
    cout << "Tong tien phat qua han cho doc gia " << maDocGia
         << " (" << dg->getLoaiDocGia() << "): "
         << fixed << setprecision(0) << tongPhat << " VND\n";
}