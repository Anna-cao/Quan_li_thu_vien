#include "../include/ThuVien.h"
#include <iostream>
#include <string>
using namespace std;

bool ThuVien::themDocGia(DocGia* dg) {
    for (int i = 0; i < soDocGia; ++i) {
        if (danhSachDocGia[i]->getMaDocGia() == dg->getMaDocGia()) {
            cout << "Doc gia da ton tai (ma: " << dg->getMaDocGia() << ")\n";
            delete dg;
            return false;
        }
    }
    if (soDocGia >= Max_docgia) {
        cout << "Danh sach doc gia da day!\n";
        delete dg;
        return false;
    }
    danhSachDocGia[soDocGia++] = dg;
    cout << "Them doc gia: " << dg->getHoTen() << "\n";
    return true;
}

void ThuVien::hienThiDanhSachDocGia() const {
    if (soDocGia == 0) {
        cout << "Chua co doc gia nao!\n";
        return;
    }
    cout << "\n----- DANH SACH DOC GIA -----\n";
    for (int i = 0; i < soDocGia; ++i) {
        cout << "\nDoc gia thu " << i + 1 << ":\n";
        danhSachDocGia[i]->hienThiThongTin();
    }
}

DocGia* ThuVien::timDocGiaTheoMa(const string& ma) const {
    for (int i = 0; i < soDocGia; ++i)
        if (danhSachDocGia[i]->getMaDocGia() == ma)
            return danhSachDocGia[i];
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
bool ThuVien::suaThongTinDocGia(const std::string& maDocGia) {
    DocGia* dg = timDocGiaTheoMa(maDocGia);
    if (!dg) {
        cout << "Khong tim thay doc gia co ma: " << maDocGia << endl;
        return false;
    }
    cout << "Nhap lai thong tin doc gia:\n";
    dg->nhap();
    cout << "Da cap nhat thong tin doc gia!\n";
    return true;
}

bool ThuVien::xoaDocGia(const std::string& maDocGia) {
    for (int i = 0; i < soDocGia; ++i) {
        if (danhSachDocGia[i]->getMaDocGia() == maDocGia) {
            delete danhSachDocGia[i];
            for (int j = i; j < soDocGia - 1; ++j) {
                danhSachDocGia[j] = danhSachDocGia[j + 1];
            }
            soDocGia--;
            cout << "Da xoa doc gia co ma: " << maDocGia << endl;
            return true;
        }
    }
    cout << "Khong tim thay doc gia co ma: " << maDocGia << endl;
    return false;
}