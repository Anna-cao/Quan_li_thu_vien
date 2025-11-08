#include "../include/auth.h"
#include <fstream>
#include <iostream>
using namespace std;

Auth::Auth() {
    soNguoiDung = 0;
    nguoiDungHienTai = nullptr;
}

void Auth::docFile(const string &filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "Khong mo duoc file: " << filePath << endl;
        return;
    }

    string ten, mk;
    int role;

    while (file >> ten >> mk >> role && soNguoiDung < Max_User) {
        danhSachNguoiDung[soNguoiDung] = User(ten, mk, role);
        soNguoiDung++;
    }

    file.close();
}

bool Auth::dangNhap(const string &tenDangNhap, const string &matKhau) {
    for (int i = 0; i < soNguoiDung; i++) {
        if (danhSachNguoiDung[i].getTenDangNhap() == tenDangNhap &&
            danhSachNguoiDung[i].getMatKhau() == matKhau) {
            nguoiDungHienTai = &danhSachNguoiDung[i];
            cout << "Dang nhap thanh cong!\n";
            return true;
        }
    }
    cout << "Sai ten dang nhap hoac mat khau!\n";
    return false;
}

void Auth::dangXuat() 
{
    if (nguoiDungHienTai != nullptr) {
        cout << "Da dang xuat!\n";
        nguoiDungHienTai = nullptr;
    } else {
        cout << "Chua co ai dang nhap!\n";
    }
}

bool Auth::daDangNhap() const {
    return nguoiDungHienTai != nullptr;
}
User* Auth::getNguoiDungHienTai() {
    return nguoiDungHienTai;
}

