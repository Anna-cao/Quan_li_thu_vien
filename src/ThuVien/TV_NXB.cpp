#include "../include/NhaXuatBan.h"
#include "../include/ThuVien/ThuVien.h"
using namespace std;
#include <iostream>
#include <string>

ThuVien::ThuVien() {
    n = 0;
    soDocGia = 0;
    soHoaDon = 0;
    soNXB = 0;
    for (int i = 0; i < Max_NXB; ++i) {
        danhSachNXB[i] = nullptr;
    }
}
ThuVien::~ThuVien() {
    for (int i = 0; i < soDocGia; i++) {
        delete danhSachDocGia[i];
    }
    for (int i = 0; i < soNXB; i++) {
        delete danhSachNXB[i];
    }
}
bool ThuVien::themNXB(const string& tenNXB) {
    if (soNXB >= Max_NXB) {
        cout << "Danh sach nha xuat ban da day!" << endl;
        return false;
    }

    if (timNXBTheoTen(tenNXB) != nullptr) {
        cout << "Nha xuat ban '" << tenNXB << "' da ton tai!" << endl;
        return false;
    }

    danhSachNXB[soNXB++] = new NhaXuatBan(tenNXB);
    cout << "Them nha xuat ban '" << tenNXB << "' thanh cong!" << endl;
    return true;
}
void ThuVien::hienThiDanhSachNXB() const {
    if (soNXB == 0) {
        cout << "Chua co nha xuat ban nao!" << endl;
        return;
    }
    cout << "\n===== DANH SACH NHA XUAT BAN =====\n";
    for (int i = 0; i < soNXB; ++i) {
        cout << "\nNXB thu " << i + 1 << ":\n";
        danhSachNXB[i]->hienThiDSNXB();
    }
}
NhaXuatBan* ThuVien::timNXBTheoTen(const string& tenNXB) const {
    for (int i = 0; i < soNXB; ++i) {
        if (danhSachNXB[i]->getNXB() == tenNXB) {
            return danhSachNXB[i];
        }
    }
    return nullptr;
}
void ThuVien::suaNXB(const string& tenCu, const string& tenMoi) {
    NhaXuatBan* nxb = timNXBTheoTen(tenCu);
    if (!nxb) {
        cout << "Khong tim thay NXB co ten: " << tenCu << endl;
        return;
    }

    if (timNXBTheoTen(tenMoi)) {
        cout << "Ten moi da ton tai, khong the doi!" << endl;
        return;
    }

    NhaXuatBan* nxbMoi = new NhaXuatBan(tenMoi);
    for (const auto& maSach : nxb->getSoSachXB()) {
        nxbMoi->ThemSach(maSach);
    }

    for (int i = 0; i < soNXB; ++i) {
        if (danhSachNXB[i] == nxb) {
            delete danhSachNXB[i];
            danhSachNXB[i] = nxbMoi;
            cout << "Da doi ten NXB thanh cong!\n";
            return;
        }
    }
}
void ThuVien::xoaNXB(const string& ten) {
    for (int i = 0; i < soNXB; ++i) {
        if (danhSachNXB[i]->getNXB() == ten) {
            delete danhSachNXB[i];
            for (int j = i; j < soNXB - 1; ++j) {
                danhSachNXB[j] = danhSachNXB[j + 1];
            }
            soNXB--;
            cout << "Da xoa NXB co ten: " << ten << endl;
            return;
        }
    }
    cout << "Khong tim thay NXB co ten: " << ten << endl;
}