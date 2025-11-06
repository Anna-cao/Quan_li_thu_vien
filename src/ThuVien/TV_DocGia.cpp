#include "../include/DocGia.h"
#include "../include/ThuVien/ThuVien.h"
#include <iostream>
#include <string>
using namespace std;
bool ThuVien::themDocGia(DocGia* dg) {
    for (int i = 0; i < n; i++) {
        if (dg == danhSachDocGia[i]) {
            cout << "Doc gia da ton tai trong danh sach" << endl;
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
        cout << "Chua co doc gia nao!" << endl;
        return;
    }
    cout << "\n-----DANH SACH DOC GIA -----\n";
    for (int i = 0; i < soDocGia; ++i) {
        cout << "\nThong tin doc gia thu " << i + 1 << " la\n";
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