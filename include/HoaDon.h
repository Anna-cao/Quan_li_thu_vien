#ifndef HOADON_H
#define HOADON_H

#include <bits/stdc++.h>
#include "Date.h"
#include "Sach.h"
#include "DocGia.h"
using namespace std;

class HoaDon {
protected:
    string maHoaDon;
    string maThe;          
    Date ngMuon;
    Date ngTraThucTe;
    double phiQuaHan, tongPhi, tiencoc;
    string maKH;
    int status;
public:
    HoaDon();
    HoaDon(string maHD, string maT, Date muon, Date tra , double phi , double tong);
    virtual ~HoaDon();

    virtual void DocFile(ifstream &file);
    void tinhPhiQuaHan(const DocGia* dg, const Date& ngayTra);
    virtual void hienThiThongTin() const;

    double getTongPhi() const { return tongPhi; }
    virtual string getMaThe() const { return maThe; }
    virtual Date getNgMuon() const { return ngMuon; }
    string getMaHoaDon() const { return maHoaDon; }
    string getMaKH() const { return maKH; }
    int getStatus() const{return status;}
    double getTienCoc() const { return tiencoc; }
    double getPhiQuaHan() const { return phiQuaHan; }

    Date getNgayMuon() const { return ngMuon; }
    Date getNgayTraThucTe() const { return ngTraThucTe; }

    void setDaTra(const Date& ngayTra);
    static int docFileHoaDon(HoaDon danhSach[], int soLuongToiDa, const std::string& duongDan = "data/hoadon.txt");
    static void ghiFileHoaDon(const HoaDon danhSach[], int soLuong, const std::string& duongDan = "data/hoadon.txt");

};
#endif
