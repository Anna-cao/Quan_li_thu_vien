#ifndef THEMUON_H
#define THEMUON_H

#include <iostream>
#include <string>

#include <fstream>
#include "Date.h"
using namespace std;

enum LoaiThe {
    THE_THUONG,
    THE_HOI_VIEN
};

class TheMuon {
private:
    static int autoID;
    string maThe;
    string tenDocGia;
    LoaiThe loaiThe;
    double phiDangKy;
    string status;           
    int gioiHanMuon;
    Date ngayLapThe;
    Date hanSuDung;

    static int demThuong;
    static int demHoiVien;

    string taoMaThe(LoaiThe loai);
    void tinhPhiVaGioiHan(); 

public:
    TheMuon();
    TheMuon(string ten, LoaiThe loai);
    TheMuon(string loaiStr, Date ngayLap); 

    string getMaThe() const { return maThe; }
    string getTenDocGia() const { return tenDocGia; }
    LoaiThe getLoaiThe() const { return loaiThe; }
    double getPhiDangKy() const { return phiDangKy; }
    string getStatus() const { return status; }
    int getGioiHanMuon() const { return gioiHanMuon; }
    Date getNgayLapThe() const { return ngayLapThe; }
    Date getHanSuDung() const { return hanSuDung; }

    void setTenDocGia(string ten) { tenDocGia = ten; }
    void setMaThe(string maT) {maThe = maT;}
    void setLoaiThe(LoaiThe loai) { loaiThe = loai; tinhPhiVaGioiHan(); }
    void setStatus(string st) { status = st; }
    void setGioiHanMuon(int g) { gioiHanMuon = g; }
    void setNgayLapThe(const Date& ngay);
    void setHanSuDung(const Date& han) { hanSuDung = han; }

    void nhap();
    void hienThi() const;

    void ghiFile(ostream& out) const;
    void docFile(istream& in);
    static int getDemThuong() { return demThuong; };
    static int getDemHoiVien() { return demHoiVien;};
    static void capNhatAutoID(int id);
};
#endif