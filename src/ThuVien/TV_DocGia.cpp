#include "../include/ThuVien.h"
#include <iostream>
#include <string>
using namespace std;

bool ThuVien::themDocGia(DocGia* dg) {
    if (!dg) return false;
    dg->nhap();  
    for (int i = 0; i < soDocGia; ++i)
        if (danhSachDocGia[i]->getMaDocGia() == dg->getMaDocGia()) {
            cout << "Ma da ton tai!\n";
            delete dg; 
            return false;
        }
    if (soDocGia >= Max_docgia) { cout << "Danh sach day!\n"; delete dg; return false; }
    danhSachDocGia[soDocGia++] = dg;
    cout << "Them thanh cong!\n";
    return true;
}

void ThuVien::hienThiDanhSachDocGia() const {
    if (soDocGia == 0) { cout << "Chua co ai!\n"; return; }
    DocGia::hienThiTieuDe();
    for (int i = 0; i < soDocGia; ++i)
        if (danhSachDocGia[i]->getStatus() == 1)
            danhSachDocGia[i]->hienThiDong();
    cout << string(100, '-') << endl;
}

DocGia* ThuVien::timDocGiaTheoMa(const string& ma) const {
    for (int i = 0; i < soDocGia; ++i)
        if (danhSachDocGia[i]->getMaDocGia() == ma && danhSachDocGia[i]->getStatus() == 1)
            return danhSachDocGia[i];
    return nullptr;
}

void ThuVien::capNhatTheMuonChoDocGia(const string& maDocGia, TheMuon* the) {
    DocGia* dg = timDocGiaTheoMa(maDocGia);
    if (!dg) { cout << "Khong tim thay!\n"; delete the; return; }
    delete dg->getTheMuon();
    dg->setTheMuon(the) ;
    cout << "Da cap nhat the!\n";
}

bool ThuVien::suaThongTinDocGia(const string& maDocGia) {
    DocGia* dg = timDocGiaTheoMa(maDocGia);
    if (!dg) { cout << "Khong tim thay ma: " << maDocGia << endl; return false; }
    cout << "=== SUA THONG TIN ===\n";
    cout << "Hien tai:\n";
    dg->hienThiThongTin();
    dg->nhap(); 

    cout << "Da cap nhat!\n";
    return true;
}

bool ThuVien::xoaDocGia(const string& maDocGia) {
    for (int i = 0; i < soDocGia; ++i)
        if (danhSachDocGia[i]->getMaDocGia() == maDocGia) {
            if (danhSachDocGia[i]->getStatus() == 0) { cout << "Da xoa truoc do!\n"; return false; }
            danhSachDocGia[i]->setStatus(0);
            cout << "Da an doc gia!\n";
            return true;
        }
    cout << "Khong tim thay ma!\n";
    return false;
}