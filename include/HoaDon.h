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
    int status;
    static int autoID;
    vector<pair<string, int>> dsSachMuon;

public:
    HoaDon();
    HoaDon(string maHD, string maT, Date muon, Date tra, double phi, double tong);
    virtual ~HoaDon() = default;

    string getMaHoaDon() const { return maHoaDon; }
    string getMaThe() const { return maThe; }
    Date getNgayMuon() const { return ngMuon; }
    Date getNgayTraThucTe() const { return ngTraThucTe; }
    double getPhiQuaHan() const { return phiQuaHan; }
    double getTongPhi() const { return tongPhi; }
    double getTienCoc() const { return tiencoc; }
    int getStatus() const { return status; }
    const vector<pair<string, int>>& getDsSachMuon() const { return dsSachMuon; }

    void setMaThe(const string& ma) { maThe = ma; }
    void setNgayMuon(const Date& d) { ngMuon = d; }
    void setNgayTraThucTe(const Date& d) { ngTraThucTe = d; }
    void setTienCoc(double coc) { tiencoc = coc; }
    void setDsSachMuon(const vector<pair<string, int>>& ds) { dsSachMuon = ds; }
    void taoMaTuDong();
    void capNhatAutoID(int id);
    void setDaTra(const Date& ngayTra);
    void tinhPhiQuaHan(const DocGia* dg, const Date& ngayTra);
    virtual void hienThiThongTin() const;
    virtual void DocFile(ifstream& file);
    static int docFileHoaDon(HoaDon danhSach[], int soLuongToiDa, const string& duongDan = "data/hoadon.txt");
    static void ghiFileHoaDon(const HoaDon danhSach[], int soLuong, const string& duongDan = "data/hoadon.txt");
};

#endif