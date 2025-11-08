#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    string tenDangNhap;
    string matKhau;
    int vaiTro; 
public:
    User();
    User(string tenDangNhap, string matKhau, int vaiTro);

    string getTenDangNhap() const;
    string getMatKhau() const;
    int getVaiTro() const;
    void doiMatKhau(string mkMoi);
    // IO kiểu mảng cho user (auth)
    static int docFileUser(User danhSach[], int soLuongToiDa, const std::string& duongDan = "data/auth.txt");
    static void ghiFileUser(const User danhSach[], int soLuong, const std::string& duongDan = "data/auth.txt");
};
#endif
