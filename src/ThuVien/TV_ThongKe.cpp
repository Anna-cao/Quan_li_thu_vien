#include "../include/Date.h"
#include "../include/ThuVien/ThuVien.h"
#include <iostream>
#include <string>

using namespace std;
void ThuVien::thongKeSachTheoNXB() const {
    if (soNXB == 0) {
        cout << "Khong co nha xuat ban nao de thong ke!" << endl;
        return;
    }

    cout << "\n===== THONG KE SACH THEO NHA XUAT BAN =====\n";
    for (int i = 0; i < soNXB; ++i) {
        const vector<string>& dsSach = danhSachNXB[i]->getSoSachXB();
        cout << "NXB: " << danhSachNXB[i]->getNXB()
             << " | So luong sach: " << dsSach.size() << endl;
    }
}

void ThuVien::thongKeMuonTra(const Date& ngayHienTai) const {
    if (soHoaDon == 0) {
        cout << "Chua co hoa don nao!\n";
        return;
    }
    int countBorrowed = 0;
    int countReturned = 0;
    int countOverDue = 0;
    const int hanMuon = 14;

    for (int i = 0; i < soHoaDon; i++) {
        const HoaDon& hd = danhSachHoaDon[i];

        if (hd.getNgayTraThucTe().HopLe()) {
            countReturned++;
        } else {
            countBorrowed++;

            Date due = hd.getNgayMuon();
            due.congNgay(hanMuon);

            if (due < ngayHienTai) {
                countOverDue++;
            }
        }
    }
    cout << "\n===== THONG KE MUON/ TRA =====\n";
    cout << "Tong hoa don: " << soHoaDon << "\n";
    cout << "Da tra: " << countReturned << "\n";
    cout << "Dang muon: " << countBorrowed << "\n";
    cout << "Qua han: " << countOverDue << "\n";
    cout << "================================\n";
}
double ThuVien::tongTienPhat() const {
    double tongPhat = 0;
    for (int i = 0; i < soHoaDon; ++i) {
        tongPhat += danhSachHoaDon[i].getPhiQuaHan();
    }
    return tongPhat;
}
void ThuVien::thongKeDoanhThu(const Date& tu, const Date& den) const {
    if (soHoaDonBan == 0) {
        cout << "Chua co hoa don ban nao!\n";
        return;
    }

    double tongDoanhThu = 0;
    for (int i = 0; i < soHoaDonBan; ++i) {
        const HoaDonBan& hdb = danhSachHoaDonBan[i];
        Date ngayBan = hdb.getNgayBan();

        if (ngayBan >= tu && ngayBan <= den) {
            tongDoanhThu += hdb.getTongPhi(); 
        }
    }
    cout << "\n===== THONG KE DOANH THU =====\n";
    cout << "Tu ngay: "; tu.Xuat();
    cout << " -> Den ngay: "; den.Xuat();
    cout << "\nTong doanh thu: " << tongDoanhThu << " VND\n";
    cout << "==============================\n";
}
