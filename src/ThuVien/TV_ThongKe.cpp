#include "../include/Date.h"
#include "../include/ThuVien.h"
#include "../include/HoaDon.h"
#include "../include/DocGia.h"

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
DocGia* ThuVien::timDocGiaTheoMaThe(const string& maThe) const {
    for (int i = 0; i < soDocGia; ++i) {
        if (danhSachDocGia[i].getTheMuon() == maThe) {
            return &danhSachDocGia[i];
        }
    }
    return nullptr;
}
void ThuVien::thongKeMuonTra(const Date& ngayHienTai) const {
    if (soHoaDon == 0 && soLuongTong == 0) {
        cout << "Khong co du lieu de thong ke (khong co hoa don va khong co sach)!\n";
        return;
    }

    int demDangMuon = 0;   
    int demDaTra = 0;      
    int demQuaHan = 0;     
    double tongDoanhThu = 0.0; 
    const int hanMuon = 14;    
    Date ngayTra;
    for (int i = 0; i < soHoaDon; ++i) {
        const HoaDon& hd = danhSachHoaDon[i];
        DocGia*dg;
        if (hd.getNgayTraThucTe().HopLe()) {
            demDaTra++;
            double x= hd.tinhPhiQuaHan(dg, ngayTra);
        } else {
            demDangMuon++;
            Date hetHan = hd.getNgayMuon();
            hetHan.congNgay(hanMuon);
            if (hetHan < ngayHienTai) demQuaHan++;
        }
    }

    int tongSach = 0;
    int tongDangMuonSoLuong = 0; 
    int tongCon = 0;             

    for (int i = 0; i < soLuongTong; ++i) {
        tongSach += danhSach[i].getSoLuongTong();
        tongDangMuonSoLuong += danhSach[i].getSoLuongDaMuon();
        tongCon += danhSach[i].soSachConLai();
    }

    cout << "\n===== THONG KE THU VIEN =====\n";
    cout << "Ngay thong ke: "; ngayHienTai.Xuat(); cout << "\n";
    cout << "Tong so sach trong thu vien: " << tongSach << "\n";
    cout << "Tong so sach con lai trong kho: " << tongCon << "\n";
    cout << "Tong so sach dang muon (theo so luong): " << tongDangMuonSoLuong << "\n";
    cout << "So hoa don dang muon: " << demDangMuon << "\n";
    cout << "So hoa don da tra: " << demDaTra << "\n";
    cout << "So hoa don qua han: " << demQuaHan << "\n";
    cout << "Tong doanh thu (phi phat tu cac hoa don da tra): " << fixed << setprecision(0) << tongDoanhThu << " VND\n";
    cout << "================================\n";
}
