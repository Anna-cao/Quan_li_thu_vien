#include "../include/ThuVien.h"
#include "../include/DocGiaThuong.h"
#include "../include/HoiVien.h"
#include <iostream>
#include <string>
using namespace std;
bool ThuVien::themDocGia(DocGia* dg) {
    if (!dg) return false;
    if (soDocGia >= Max_docgia) {
        cout << "Danh sach day!\n";
        delete dg;
        return false;
    }
    danhSachDocGia[soDocGia++] = dg;
    cout << "Them thanh cong! Ma: " << dg->getMaDocGia() << endl;
    saveDuLieu();
    return true;
}
void ThuVien::hienThiDanhSachDocGia() const {
    if (soDocGia == 0) {
        cout << "Chua co doc gia nao!\n";
        return;
    }
    DocGia::hienThiTieuDe();
    cout << string(110, '-') << endl;
    for (int i = 0; i < soDocGia; ++i) {
        if (danhSachDocGia[i]->getStatus() == 1) {
            danhSachDocGia[i]->hienThiDong();
        }
    }
    cout << string(110, '-') << endl;
}
DocGia* ThuVien::timDocGiaTheoMa(const string& ma) const {
    for (int i = 0; i < soDocGia; ++i) {
        if (danhSachDocGia[i]->getMaDocGia() == ma &&
            danhSachDocGia[i]->getStatus() == 1) {
            return danhSachDocGia[i];
        }
    }
    return nullptr;
}
void ThuVien::capNhatTheMuonChoDocGia(const string& maDocGia, TheMuon* the) {
    DocGia* dg = timDocGiaTheoMa(maDocGia);
    if (!dg) {
        cout << "Khong tim thay doc gia ma: " << maDocGia << endl;
        delete the;
        return;
    }
    delete dg->getTheMuon();     
    dg->setTheMuon(the);        
    cout << "Da cap nhat the muon cho " << dg->getHoTen() << endl;
    saveDuLieu();
}
bool ThuVien::suaThongTinDocGia(const string& maDocGia) {
    DocGia* dg = timDocGiaTheoMa(maDocGia);
    if (!dg) {
        cout << "Khong tim thay ma: " << maDocGia << endl;
        return false;
    }

    cout << "\n=== THONG TIN HIEN TAI ===\n";
    dg->hienThiThongTin();

    cout << "\n=== NHAP THONG TIN MOI ===\n";
    dg->nhapThongTinChung();  
    saveDuLieu();
    if (dg->getLoaiDocGia() == "Doc Gia Thuong") {
        static_cast<DocGiaThuong*>(dg)->nhapGioiHanMuon();
    }

    cout << "Da cap nhat thong tin!\n";
    saveDuLieu();
    return true;
}
bool ThuVien::xoaDocGia(const string& maDocGia) {
    for (int i = 0; i < soDocGia; ++i) {
        if (danhSachDocGia[i]->getMaDocGia() == maDocGia) {
            if (danhSachDocGia[i]->getStatus() == 0) {
                cout << "Doc gia xoa bi an truoc do!\n";
                return false;
            }
            danhSachDocGia[i]->setStatus(0);
            cout << "Da xoa doc gia: " << danhSachDocGia[i]->getHoTen() << endl;
            saveDuLieu();
            return true;
        }
    }
    cout << "Khong tim thay ma: " << maDocGia << endl;
    return false;
}