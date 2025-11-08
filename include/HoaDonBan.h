#ifndef HOADONBAN_H
#define HOADONBAN_H

#include "HoaDon.h"
#include "Sach.h"
#include <vector>

class HoaDonBan : public HoaDon {
private:
    vector<Sach> dsSachBan;
    double tongTienBan;

public:
    HoaDonBan();
    HoaDonBan(string maHD);
    Date ngayBan;
    Date getNgayBan() const;
    void setNgayBan(const Date& d);

    void themSach(const Sach &sach, int soLuong);
    void DocFile(ifstream &file) override;
    void tinhPhiQuaHan() override; 
    void hienThiThongTin() const override;

    double getTongTienBan() const;
    int getSoLuongSachBan() const;
    string getMaSachBan(int idx) const;

    static int docFileHoaDonBan(HoaDonBan danhSach[], int soLuongToiDa, const std::string& duongDan = "data/hoadonban.txt");
    static void ghiFileHoaDonBan(const HoaDonBan danhSach[], int soLuong, const std::string& duongDan = "data/hoadonban.txt");
};

#endif
