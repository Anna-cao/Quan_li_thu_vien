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

    string getTenDangNhap();
    string getMatKhau();
    int getVaiTro();
    void doiMatKhau(string mkMoi);
};
#endif
