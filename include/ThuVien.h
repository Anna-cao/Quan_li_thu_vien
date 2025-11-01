#ifndef THUVIEN_H
#define THUVIEN_H

#include "Sach.h"
#include <string>
using namespace std;

#define Max_sach 200

class ThuVien {
private:
    Sach danhSach[Max_sach];
    int n;

public:
    ThuVien(); 
    void hienThi();
    void themSach();
    void timTheoTen(string ten);
    void suaSachTheoMa(string ma);
    void xoaSachTheoMa(string ma);
};

#endif