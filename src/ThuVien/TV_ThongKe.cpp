#include "../include/ThuVien.h"
#include"../include/Sach.h"
#include"../include/HoaDon.h"

#include <iostream>
#include <string>
using namespace std;
DocGia* ThuVien::timDocGiaTheoMaThe(const string& maThe) const {
    for (int i = 0; i < soDocGia; ++i) {
        if (danhSachDocGia[i]->getTheMuon()->getMaThe() == maThe) {
            return danhSachDocGia[i];
        }
    }
    return nullptr;
}

void ThuVien::thongKeMuonTra(const Date& ngayHienTai) const {
    if (soHoaDon == 0 && soLuongTong == 0) {
        cout << "Khong co du lieu de thong ke!\n";
        return;
    }

    int demDangMuon = 0;
    int demDaTra = 0;
    int demQuaHan = 0;
    double tongDoanhThu = 0.0;
    const int hanMuon = 14;

    for (int i = 0; i < soHoaDon; ++i) {
        HoaDon* hd = new HoaDon(danhSachHoaDon[i]); 

        if (!hd) continue;

        if (hd->getNgayTraThucTe().HopLe()) {
            demDaTra++;
            DocGia* dg = timDocGiaTheoMaThe(hd->getMaThe());
            hd->tinhPhiQuaHan(dg, hd->getNgayTraThucTe());  
            tongDoanhThu += hd->getTongPhi();
        }
        else {
            demDangMuon++;

            Date hetHan = hd->getNgayMuon();
            hetHan.congNgay(hanMuon);
            if (hetHan < ngayHienTai) {
                demQuaHan++;
            }
        }
    }

    int tongSach = 0, tongDangMuonSoLuong = 0, tongCon = 0;
    for (int i = 0; i < soLuongTong; ++i) {
        tongSach += danhSach[i].getSoLuongTong();
        tongDangMuonSoLuong += danhSach[i].getSoLuongDaMuon();
        tongCon += danhSach[i].soSachConLai();
    }

    cout << "\n===== THONG KE THU VIEN =====\n";
    cout << "Ngay thong ke: "; ngayHienTai.Xuat(); cout << "\n";
    cout << "Tong so sach trong thu vien: " << tongSach << "\n";
    cout << "Tong so sach con lai trong kho: " << tongCon << "\n";
    cout << "Tong so sach dang muon: " << tongDangMuonSoLuong << "\n";
    cout << "So hoa don dang muon: " << demDangMuon << "\n";
    cout << "So hoa don da tra: " << demDaTra << "\n";
    cout << "So hoa don qua han: " << demQuaHan << "\n";
    cout << "Tong doanh thu (phi phat): " << fixed << setprecision(0) << tongDoanhThu << " VND\n";
    cout << "================================\n";
}