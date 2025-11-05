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
public:
    Auth();
    void docFile(const string &filePath);
    bool dangNhap(const string &tenDangNhap, const string &matKhau);
    void dangXuat();
    bool daDangNhap() const;
    User* getNguoiDungHienTai();

    void hienThiTatCaNguoiDung() const;
};

#endif
