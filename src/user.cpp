#include "../include/user.h"

User::User() {}

User::User(string tenDangNhap, string matKhau, int vaiTro) 
{
    this->tenDangNhap = tenDangNhap;
    this->matKhau = matKhau;
    this->vaiTro = vaiTro;
}

string User::getTenDangNhap() {return tenDangNhap;}
string User::getMatKhau(){ return matKhau;}
int User::getVaiTro() {return vaiTro;}
void User::doiMatKhau(string mkMoi) {matKhau = mkMoi;}
