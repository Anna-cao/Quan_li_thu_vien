#include "../include/ThuVien.h"
#include <iostream>
using namespace std;

ThuVien::ThuVien() {
    n = 0;
    soDocGia =0;
    soHoaDon =0;
}
ThuVien::ThuVien()
{
    for(int i =0; i<soDocGia; i++)
    {
        delete danhSachDocGia[i];
    }
}
//SACH
void ThuVien::themSach() {
    if (n >= Max_sach) {
        cout << "Thu vien da day, khong the them sach moi!" << endl;
        return;
    }
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
        cout << "\nThong tin cua sach thu " << i + 1 << "la:" << endl;
        danhSach[i].hienThiThongTin();
    }
}
void ThuVien::timTheoTen(string ten) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (danhSach[i].getTenSach() == ten)
        {
            danhSach[i].hienThiThongTin();
            found = true;
        }
    }
    if (found==false) cout << "Khong tim thay sach co ten \"" << ten << "\"" << endl;
}

void ThuVien::suaSachTheoMa(string ma) 
{
    bool found = false;
    for (int i = 0; i < n; i++) 
    {
        if (danhSach[i].getMaSach() == ma) 
        {
            cout << "Nhap lai thong tin sach: " << endl;
            danhSach[i].nhap();
            cout << "Da sua thanh cong!" << endl;
            found = true;
            break;
        }
    }
    if (found==false)
        cout << "Khong tim thay thong tin sach co ma: "<<ma <<endl;
}
void ThuVien::xoaSachTheoMa(string ma) 
{
    bool found = false;
    for (int i = 0; i < n; i++) 
    {
        if (danhSach[i].getMaSach() == ma)
        {
            for (int j = i; j < n - 1; j++) 
            {
                danhSach[j] = danhSach[j + 1];
            }
            n--;
            cout << "Da xoa sach co ma " << ma << endl;
            found = true;
            break;
        }
    }
    if (found==false)
        cout << "Khong tim thay sach co ma: "<<ma<<endl;
}
// DOCGIA
void ThuVien::themDocGia(DocGia* dg) 
{
    if (soDocGia >= Max_docgia) 
    {
        cout << "Danh sach doc gia da day!\n";
        delete dg;
        return;
    }
    danhSachDocGia[soDocGia++] = dg;
    cout << "Them doc gia: " << dg->getHoTen() << "\n";
}
void ThuVien::hienThiDanhSachDocGia() const 
{
    if (soDocGia == 0)
    {
        cout << "Chua co doc gia nao!"<<endl;
        return;
    }
    cout << "\n-----DANH SACH DOC GIA -----\n";
    for (int i = 0; i < soDocGia; ++i) {
        cout << "\nThong tin doc gia thu " << i + 1 << " la\n";
        danhSachDocGia[i]->hienThiThongTin();
    }
}
DocGia* ThuVien::timDocGiaTheoMa(const string& ma) const 
{
    for (int i = 0; i < soDocGia; ++i)
        if (danhSachDocGia[i]->getMaDocGia() == ma) return danhSachDocGia[i];
    return nullptr;
}
void ThuVien::capNhatTheMuonChoDocGia(const string& maDocGia, TheMuon* the) {
    DocGia* dg = timDocGiaTheoMa(maDocGia);
    if (dg) {
        dg->setTheMuon(the);
        cout << "Cap nhat the muon cho doc gia " << maDocGia << "\n";
    } else {
        cout << "Khong tim thay doc gia " << maDocGia << "\n";
        delete the;               
    }
}
//HOA DON
void ThuVien::themHoaDon(const HoaDon& hd) {
    if (soHoaDon >= Max_hoadon) {
        cout << "Danh sach hoa don da day!" << endl;
        return;
    }
    danhSachHoaDon[soHoaDon++] = hd;
    cout << "Them hoa don thanh cong!" << endl;
}

void ThuVien::hienThiDanhSachHoaDon() const {
    if (soHoaDon == 0) {
        cout << "Chua co hoa don nao!" << endl;
        return;
    }
    cout << "\n----- DANH SACH HOA DON -----\n";
    for (int i = 0; i < soHoaDon; ++i) {
        cout << "\n--- Hoa don " << i + 1 << " ---\n";
        danhSachHoaDon[i].hienThiThongTin();
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
