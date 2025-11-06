#include "../include/ThuVien.h"
#include <iostream>
#include <string>
using namespace std;

bool ThuVien::themNXB(const string& tenNXB) {
    if (soNXB >= Max_NXB) {
        cout << "Danh sach NXB da day!\n";
        return false;
    }
    if (timNXBTheoTen(tenNXB)) {
        cout << "NXB '" << tenNXB << "' da ton tai!\n";
        return false;
    }
    danhSachNXB[soNXB++] = new NhaXuatBan(tenNXB);
    cout << "Them NXB '" << tenNXB << "' thanh cong!\n";
    return true;
}

void ThuVien::hienThiDanhSachNXB() const {
    if (soNXB == 0) {
        cout << "Chua co NXB nao!\n";
        return;
    }
    cout << "\n===== DANH SACH NHA XUAT BAN =====\n";
    for (int i = 0; i < soNXB; ++i) {
        cout << "\nNXB " << i + 1 << ":\n";
        danhSachNXB[i]->hienThiDSNXB();
    }
}

NhaXuatBan* ThuVien::timNXBTheoTen(const string& tenNXB) const {
    for (int i = 0; i < soNXB; ++i)
        if (danhSachNXB[i]->getNXB() == tenNXB)
            return danhSachNXB[i];
    return nullptr;
}

void ThuVien::themSachVaoNXB(const string& maSach, const string& tenNXB) {
    NhaXuatBan* nxb = timNXBTheoTen(tenNXB);
    if (!nxb) {
        cout << "Khong tim thay NXB '" << tenNXB << "'\n";
        return;
    }
    nxb->ThemSach(maSach);
    cout << "Da them sach " << maSach << " vao NXB " << tenNXB << "\n";
}

void ThuVien::suaNXB(const string& tenCu, const string& tenMoi) {
    NhaXuatBan* nxb = timNXBTheoTen(tenCu);
    if (!nxb) {
        cout << "Khong tim thay NXB '" << tenCu << "'\n";
        return;
    }
    if (timNXBTheoTen(tenMoi)) {
        cout << "Ten moi '" << tenMoi << "' da ton tai!\n";
        return;
    }
    nxb->setNXB(tenMoi);
    cout << "Doi ten NXB thanh cong!\n";
}

void ThuVien::xoaNXB(const string& ten) {
    for (int i = 0; i < soNXB; ++i) {
        if (danhSachNXB[i]->getNXB() == ten) {
            delete danhSachNXB[i];
            for (int j = i; j < soNXB - 1; ++j)
                danhSachNXB[j] = danhSachNXB[j + 1];
            --soNXB;
            cout << "Da xoa NXB '" << ten << "'\n";
            return;
        }
    }
    cout << "Khong tim thay NXB '" << ten << "'\n";
}