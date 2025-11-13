#ifndef AUTH_H
#define AUTH_H

#include "user.h"
#include <string>
#define Max_User 200
using namespace std;

class Auth {
private:
    User danhSachNguoiDung[Max_User];  
    int soNguoiDung;
    User* nguoiDungHienTai;

    bool kiemTraTrungTen(const string& tenDangNhap) const;
    int timViTriUser(const string& tenDangNhap) const;

public:
    Auth();
    void docFile(const string& filePath = "data/auth.txt");
    bool dangNhap(const string& tenDangNhap, const string& matKhau, int& lanThu);
    bool dangKy(const string& tenDangNhap, const string& matKhau, int vaiTro = 0);
    bool doiMatKhau(const string& mkCu, const string& mkMoi);
    bool xoaTaiKhoan(const string& tenXoa); // Chỉ Admin
    void dangXuat();
    bool daDangNhap() const;
    User* getNguoiDungHienTai();

    User* getDanhSach() { return danhSachNguoiDung; }
    int getSoNguoiDung() const { return soNguoiDung; }
    
    void hienThiTatCaNguoiDung() const;
    void luuFile(const string& filePath = "data/auth.txt") const;
};

#endif