
#ifndef THUVIEN_H
#define THUVIEN_H

#include "HoaDon.h"
#include "Date.h"

class ThuVien {
private:
    HoaDon danhSachHoaDon[200];
    int soHoaDon;

public:
    ThuVien();
    ~ThuVien();

    void themHoaDon(const HoaDon& hd);
    void hienThiDanhSachHoaDon() const;
    void tinhTienPhatQuaHan(const std::string& maDocGia, const Date& ngayHienTai);
};

#endif

