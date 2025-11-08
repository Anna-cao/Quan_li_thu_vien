#ifndef HOIVIEN_H
#define HOIVIEN_H

#include "DocGia.h"
#include <string>
#include<iostream>
using namespace std;

class HoiVien: public DocGia
{
private:
    int thoiGianMuonMax;
    double tileGiamGia;
    string ngayDangKy;
    string ngayHetHan;

public:
    HoiVien();
    HoiVien(string ten, string maSo, int soSachDaMuon, 
            int thoiGianMuonMax, double tileGiamGia, 
            string ngayDangKy, string ngayHetHan);
    
    int getThoiGianMuonMax() const;
    void setThoiGianMuonMax(int thoiGian);
    double getTileGiamGia() const;
    void setTileGiamGia(double tile);
    string getNgayDangKy() const;
    void setNgayDangKy(string ngay);
    string getNgayHetHan() const;
    void setNgayHetHan(string ngay);
    void hienThiThongTin() const override;
};

#endif