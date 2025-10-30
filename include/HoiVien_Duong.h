#ifndef HOIVIEN_H
#define HOIVIEN_H

#include "DocGia.h"
#include <string>

class HoiVien : public DocGia {
private:
    int thoiGianMuonMax;
    double tileGiamGia;
    std::string ngayDangKy;
    std::string ngayHetHan;

public:
    HoiVien();
    HoiVien(std::string ten, std::string maSo, int soSachDaMuon, 
            int thoiGianMuonMax, double tileGiamGia, 
            std::string ngayDangKy, std::string ngayHetHan);
    
    int getThoiGianMuonMax() const;
    void setThoiGianMuonMax(int thoiGian);
    double getTileGiamGia() const;
    void setTileGiamGia(double tile);
    std::string getNgayDangKy() const;
    void setNgayDangKy(std::string ngay);
    std::string getNgayHetHan() const;
    void setNgayHetHan(std::string ngay);
    
    void hienThiThongTin() const override;
};

#endif
