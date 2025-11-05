#include "../include/HoaDon.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <limits>
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
bool HoaDon::ghiFile(ofstream& out) const {
    if (!out.good()) return false;
    out << maHoaDon << "," << maThe << ","
        << ngMuon.toString() << "," << ngTraThucTe.toString() << ","
        << phiQuaHan << "," << tongPhi << "\n";
    return true;
}

bool HoaDon::docFile(ifstream& in) {
    string line;
    if (!getline(in, line) || line.empty()) return false;
    stringstream ss(line);
    string ngayMuonStr, ngayTraStr, phiStr, tongStr;

    getline(ss, maHoaDon, ',');
    getline(ss, maThe, ',');
    getline(ss, ngayMuonStr, ',');
    getline(ss, ngayTraStr, ',');
    getline(ss, phiStr, ',');
    getline(ss, tongStr, ',');

    ngMuon.fromString(ngayMuonStr);
    ngTraThucTe.fromString(ngayTraStr);
    phiQuaHan = stod(phiStr);
    tongPhi = stod(tongStr);
    return true;
}