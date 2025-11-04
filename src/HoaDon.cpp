#include "HoaDon.h"
#include <iomanip>
using namespace std;

HoaDon::HoaDon() : phiQuaHan(0), tongPhi(0) {}

HoaDon::HoaDon(string maHD, string maT, Date muon, Date tra, double phi, double tong)
    : maHoaDon(maHD), maThe(maT), ngMuon(muon), ngTraThucTe(tra), phiQuaHan(phi), tongPhi(tong) {}

HoaDon::~HoaDon() {}

void HoaDon::DocFile(ifstream &file) {
    getline(file, maHoaDon);
    getline(file, maThe);
    int d1, m1, y1, d2, m2, y2;
    file >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    file >> phiQuaHan >> tongPhi;
    file.ignore();
    ngMuon = Date(d1, m1, y1);
    ngTraThucTe = Date(d2, m2, y2);
}

void HoaDon::tinhPhiQuaHan() {
    int soNgay = ngMuon.TinhSoNgay(ngTraThucTe);
    if (soNgay > 14) {
        phiQuaHan = (soNgay - 14) * 5000;
    } else phiQuaHan = 0;
    tongPhi = phiQuaHan + 10000; 
}

void HoaDon::hienThiThongTin() const {
    cout << left << setw(8) << maHoaDon
         << setw(10) << maThe
         << setw(12); ngMuon.Xuat();
    cout << setw(12); ngTraThucTe.Xuat();
    cout << setw(10) << fixed << setprecision(0) << phiQuaHan
         << setw(10) << tongPhi << endl;
}