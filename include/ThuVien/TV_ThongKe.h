#ifndef THUVIEN_THONGKE_H
#define THUVIEN_THONGKE_H
#include "../include/Date.h"
using namespace std;
class ThuVien {
private:

public:
    void thongKeMuonTra(const Date& ngayHienTai) const;
    void thongKeSachTheoNXB() const;
    void thongKeDoanhThu(const Date& tu, const Date& den) const;
    void thongKeSachBanChay() const;
    double tongTienPhat();
};

#endif