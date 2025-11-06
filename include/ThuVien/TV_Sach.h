#ifndef THUVIEN_SACH_H
#define THUVIEN_SACH_H
#include "../include/Sach.h"
using namespace std;
class ThuVien {
private:
    Sach danhSach[Max_sach];
    int n;
public:
    void hienThi();
    void themSach();
    void timTheoTen(std::string ten);
    void suaSachTheoMa(std::string ma);
    void xoaSachTheoMa(std::string ma);
};

#endif