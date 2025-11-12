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
    int countThuong = 0, countHoiVien = 0;
    for (int i = 0; i < soDocGia; ++i) {
        if (!danhSachDocGia[i] || danhSachDocGia[i]->getStatus() == 0) continue;
        string loai = danhSachDocGia[i]->getLoaiDocGia();
        if (loai == "Doc Gia Thuong" || loai == "DocGiaThuong") countThuong++;
        else if (loai == "HoiVien" || loai == "Hoi Vien") countHoiVien++;
    }
    cout << "\n--- DOC GIA THUONG (" << countThuong << ") ---\n";
    if (countThuong > 0) {
        DocGia::hienThiTieuDe();
        for (int i = 0; i < soDocGia; ++i) {
            DocGia* dg = danhSachDocGia[i];
            if (dg && dg->getStatus() == 1 && 
                (dg->getLoaiDocGia() == "Doc Gia Thuong" || dg->getLoaiDocGia() == "DocGiaThuong")) {
                dg->hienThiDong();
            }
        }
    } else {
        cout << "  (Khong co du lieu)\n";
    }
    cout << "\n--- HOI VIEN (" << countHoiVien << ") ---\n";
    if (countHoiVien > 0) {
        DocGia::hienThiTieuDe();
        for (int i = 0; i < soDocGia; ++i) {
            DocGia* dg = danhSachDocGia[i];
            if (dg && dg->getStatus() == 1 && 
                (dg->getLoaiDocGia() == "HoiVien" || dg->getLoaiDocGia() == "Hoi Vien")) {
                dg->hienThiDong();
            }
        }
    } else {
        cout << "  (Khong co du lieu)\n";
    }
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
DocGia* ThuVien::timDocGiaTheoMaThe(const string& maThe) const {
    for (int i = 0; i < soDocGia; ++i) {
        if (danhSachDocGia[i] && danhSachDocGia[i]->getStatus() == 1) {
            TheMuon* the = danhSachDocGia[i]->getTheMuon();
            if (the && the->getMaThe() == maThe) {
                return danhSachDocGia[i];
            }
        }
    }
    return nullptr;
}
void ThuVien::capNhatTheMuonChoDocGia(const string& maDocGia, TheMuon* the) {
    if (!the) return; 
    DocGia* dg = timDocGiaTheoMa(maDocGia);
    if (!dg) {
        cout << "Khong tim thay doc gia ma: " << maDocGia << endl;
        delete the;
        return;
    }
    TheMuon* oldThe = dg->getTheMuon();
    if (oldThe) {
        delete oldThe;
        dg->setTheMuon(nullptr); 
    }
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