#ifndef HOADON_H
#define HOADON_H

#include <bits/stdc++.h>
#include "Date.h"
using namespace std;

class HoaDon {
protected:
    string maHoaDon;
    string maThe;
    Date ngMuon;
    Date ngTraThucTe;
    double phiQuaHan;
    double tongPhi;

public:
    HoaDon();
    HoaDon(string maHD, string maT, Date muon, Date tra, double phi, double tong);
    virtual ~HoaDon();

    virtual void DocFile(ifstream &file);
    virtual void tinhPhiQuaHan();
    virtual void hienThiThongTin() const;

    double getTongPhi() const { return tongPhi; }
};

#endif