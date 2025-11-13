#include "../include/auth.h"
#include <fstream>
#include <iostream>
using namespace std;

Auth::Auth() {
    soNguoiDung = 0;
    nguoiDungHienTai = nullptr;
}

void Auth::docFile(const string& filePath) {
    soNguoiDung = User::docFileUser(danhSachNguoiDung, Max_User, filePath);
}

bool Auth::kiemTraTrungTen(const string& tenDangNhap) const {
    return timViTriUser(tenDangNhap) != -1;
}

int Auth::timViTriUser(const string& tenDangNhap) const {
    for (int i = 0; i < soNguoiDung; ++i) {
        if (danhSachNguoiDung[i].getTenDangNhap() == tenDangNhap) {
            return i;
        }
    }
    return -1;
}

bool Auth::dangKy(const string& tenDangNhap, const string& matKhau, int vaiTro) {
    if (soNguoiDung >= Max_User) {
        cout << "He thong da day!\n"; return false;
    }
    if (kiemTraTrungTen(tenDangNhap)) {
        cout << "Ten dang nhap da ton tai!\n"; return false;
    }
    if (tenDangNhap.empty() || matKhau.empty()) {
        cout << "Khong duoc de trong!\n"; return false;
    }

    danhSachNguoiDung[soNguoiDung++] = User(tenDangNhap, matKhau, vaiTro);
    luuFile();
    cout << "Dang ky thanh cong!\n";
    return true;
}

bool Auth::dangNhap(const string& tenDangNhap, const string& matKhau, int& lanThu) {
    if (lanThu >= 3) {
        cout << "Ban da nhap sai 3 lan. Thoat chuong trinh!\n";
        return false;
    }

    int pos = timViTriUser(tenDangNhap);
    if (pos != -1 && danhSachNguoiDung[pos].getMatKhau() == matKhau) {
        nguoiDungHienTai = &danhSachNguoiDung[pos];
        cout << "Dang nhap thanh cong!\n";
        lanThu = 0; 
        return true;
    }

    lanThu++;
    cout << "Sai thong tin! Con " << (3 - lanThu) << " lan thu.\n";
    return false;
}

bool Auth::doiMatKhau(const string& mkCu, const string& mkMoi) {
    if (!daDangNhap()) {
        cout << "Chua dang nhap!\n"; return false;
    }
    if (nguoiDungHienTai->getMatKhau() != mkCu) {
        cout << "Mat khau cu sai!\n"; return false;
    }
    if (mkMoi.empty()) {
        cout << "Mat khau moi khong duoc trong!\n"; return false;
    }

    nguoiDungHienTai->doiMatKhau(mkMoi);
    luuFile();
    cout << "Doi mat khau thanh cong!\n";
    return true;
}

bool Auth::xoaTaiKhoan(const string& tenXoa) {
    if (!daDangNhap() || nguoiDungHienTai->getVaiTro() != 2) {
        cout << "Chi Admin moi co quyen xoa!\n"; return false;
    }
    if (nguoiDungHienTai->getTenDangNhap() == tenXoa) {
        cout << "Khong the xoa chinh minh!\n"; return false;
    }

    int pos = timViTriUser(tenXoa);
    if (pos == -1) {
        cout << "Khong tim thay tai khoan!\n"; return false;
    }

    for (int i = pos; i < soNguoiDung - 1; ++i) {
        danhSachNguoiDung[i] = danhSachNguoiDung[i + 1];
    }
    soNguoiDung--;
    luuFile();
    cout << "Xoa tai khoan thanh cong!\n";
    return true;
}

void Auth::luuFile(const string& filePath) const {
    User::ghiFileUser(danhSachNguoiDung, soNguoiDung, filePath);
}

void Auth::dangXuat() {
    if (nguoiDungHienTai) {
        cout << "Da dang xuat!\n";
        nguoiDungHienTai = nullptr;
    }
}

bool Auth::daDangNhap() const { return nguoiDungHienTai != nullptr; }
User* Auth::getNguoiDungHienTai() { return nguoiDungHienTai; }