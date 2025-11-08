#include "../include/Date.h"
#include "../include/ThuVien.h"
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

void ThuVien::thongKeSachBanChay(int soLuongHienThi) const {
    if (soHoaDonBan == 0) {
        cout << "Chua co hoa don ban nao de thong ke!\n";
        return;
    }

    int viTriSach[Max_sach];     
    int soLuongBan[Max_sach];    

    for (int i = 0; i < n; i++) {
        viTriSach[i] = i;
        soLuongBan[i] = danhSach[i].getSoLuongDaMuon();
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (soLuongBan[j] < soLuongBan[j + 1]) {
                int temp = soLuongBan[j];
                soLuongBan[j] = soLuongBan[j + 1];
                soLuongBan[j + 1] = temp;

                temp = viTriSach[j];
                viTriSach[j] = viTriSach[j + 1];
                viTriSach[j + 1] = temp;
            }
        }
    }

    if (soLuongHienThi > n) soLuongHienThi = n;

    cout << "\n===== THONG KE " << soLuongHienThi << " SACH BAN CHAY NHAT =====\n";
    int daDem = 0;
    for (int i = 0; i < n && daDem < soLuongHienThi; i++) {
        if (soLuongBan[i] > 0) {
            cout << daDem + 1 << ". Sach: " << danhSach[viTriSach[i]].getTenSach() 
                 << " | So luong ban: " << soLuongBan[i] << endl;
            daDem++;
        }
    }

    if (daDem == 0) {
        cout << "Khong co sach nao da ban!\n";
    }
    cout << "=====================================\n";
}
