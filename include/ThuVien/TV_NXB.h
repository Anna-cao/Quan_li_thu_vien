#ifndef THUVIEN_NXB_H
#define THUVIEN_NXB_H
#include "../include/NhaXuatBan.h"
using namespace std;

class ThuVien {
public:
    bool themNXB(const std::string& tenNXB);
    void hienThiDanhSachNXB() const;
    NhaXuatBan* timNXBTheoTen(const std::string& tenNXB) const;
    void themSachVaoNXB(const std::string& maSach, const std::string& tenNXB);
    void suaNXB(const std::string& tenCu, const std::string& tenMoi);
    void xoaNXB(const std::string& ten);
};

#endif