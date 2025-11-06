#ifndef NHAXUATBAN_H
#define NHAXUATBAN_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NhaXuatBan {
private:
    string NXB;
    vector<string> SoSachXB;
public:
    NhaXuatBan();
    NhaXuatBan(const string& nxb);
    void ThemSach(const string& maSach);
    string getNXB() const;
    vector<string> getSoSachXB() const;
    void themNXB();
    void hienThiDSNXB() const;
    void setNXB(const string& tenMoi) { NXB = tenMoi; }
};
#endif

