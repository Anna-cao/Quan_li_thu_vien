#ifndef HOADON_H
#define HOADON_H

#include <bits/stdc++.h>
#include "Date.h"
#include "Sach.h"
using namespace std;

class HoaDon {
protected:
    string maHoaDon;
    string maThe;          
    Date ngMuon;
    Date ngTraThucTe;
    double phiQuaHan;
    double tongPhi;
    string maKH;
public:
    HoaDon();
    HoaDon(string maHD, string maT, Date muon, Date tra, double phi, double tong);
    virtual ~HoaDon();

    virtual void DocFile(ifstream &file);
    virtual void tinhPhiQuaHan();
    virtual void hienThiThongTin() const;

    double getTongPhi() const { return tongPhi; }
    virtual string getMaThe() const { return maThe; }
    virtual Date getNgMuon() const { return ngMuon; }

    string getMaHoaDon() const { return maHoaDon; }
    string getMaKH() const { return maKH; }

    Date getNgayMuon() const { return ngMuon; }
    Date getNgayTraThucTe() const { return ngTraThucTe; }

    double getPhiQuaHan() const;
    static int docFileHoaDon(HoaDon danhSach[], int soLuongToiDa, const std::string& duongDan = "data/hoadon.txt");
    static void ghiFileHoaDon(const HoaDon danhSach[], int soLuong, const std::string& duongDan = "data/hoadon.txt");
};
#endif
