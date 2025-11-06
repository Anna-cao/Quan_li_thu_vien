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
    virtual string getMaThe(){return maThe; }
    virtual Date getNgMuon(){return ngMuon; }

    Date getNgayMuon() const { return ngMuon; }
    Date getNgayTraThucTe() const { return ngTraThucTe; }

    double getPhiQuaHan() const;
};
#endif
