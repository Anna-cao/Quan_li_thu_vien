#include "../include/HoaDon.h"
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

double HoaDon::getPhiQuaHan() const {
    return phiQuaHan;
}

int HoaDon::docFileHoaDon(HoaDon danhSach[], int soLuongToiDa, const string& duongDan) {
    ifstream in(duongDan);
    if (!in.is_open()) return 0;
    int soLuong = 0;
    while (!in.eof() && soLuong < soLuongToiDa) {
        HoaDon hd;
        hd.DocFile(in);
        if (hd.getMaHoaDon().size() == 0) break;
        danhSach[soLuong++] = hd;
    }
    in.close();
    return soLuong;
}

void HoaDon::ghiFileHoaDon(const HoaDon danhSach[], int soLuong, const string& duongDan) {
    ofstream out(duongDan);
    if (!out.is_open()) return;
    for (int i = 0; i < soLuong; ++i) {
        const HoaDon &h = danhSach[i];
        out << h.getMaHoaDon() << "\n";
        out << h.getMaThe() << "\n";
        Date d1 = h.getNgayMuon();
        Date d2 = h.getNgayTraThucTe();
        out << d1.getNgay() << " " << d1.getThang() << " " << d1.getNam() << " ";
        out << d2.getNgay() << " " << d2.getThang() << " " << d2.getNam() << "\n";
        out << h.getPhiQuaHan() << " " << h.getTongPhi() << "\n\n";
    }
    out.close();
}