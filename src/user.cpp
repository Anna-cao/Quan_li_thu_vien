#include "../include/user.h"
#include <fstream>

using namespace std;

User::User() {}

User::User(string tenDangNhap, string matKhau, int vaiTro) 
{
    this->tenDangNhap = tenDangNhap;
    this->matKhau = matKhau;
    this->vaiTro = vaiTro;
}

string User::getTenDangNhap() const {return tenDangNhap;}
string User::getMatKhau() const { return matKhau;}
int User::getVaiTro() const {return vaiTro;}
void User::doiMatKhau(string mkMoi) {matKhau = mkMoi;}

int User::docFileUser(User danhSach[], int soLuongToiDa, const string& duongDan) {
    ifstream in(duongDan);
    if (!in.is_open()) return 0;
    int soLuong = 0;
    string ten, mk;
    int vai;
    while (in >> ten >> mk >> vai) {
        if (soLuong >= soLuongToiDa) break;
        danhSach[soLuong++] = User(ten, mk, vai);
    }
    in.close();
    return soLuong;
}

void User::ghiFileUser(const User danhSach[], int soLuong, const string& duongDan) {
    ofstream out(duongDan);
    if (!out.is_open()) return;
    for (int i = 0; i < soLuong; ++i) {
        out << danhSach[i].getTenDangNhap() << " " << danhSach[i].getMatKhau() << " " << danhSach[i].getVaiTro() << "\n";
    }
    out.close();
}
