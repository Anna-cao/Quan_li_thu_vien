#include "../include/HoiVien.h"
#include <iostream>
#include <iomanip>
using namespace std;
HoiVien::HoiVien(string ten) 
    : DocGia(ten, "HoiVien"), 
      thoiGianMuonMax(30), 
      tileGiamGia(0.1)
{
    stringstream ss;
    Date today = Date::HomNay();
    ss << setw(2) << setfill('0') << today.getNgay() << "/"
       << setw(2) << setfill('0') << today.getThang() << "/"
       << today.getNam();
    ngayDangKy = ss.str();
    ngayHetHan = "";
}
HoiVien::HoiVien(string ten, string maSo, int soSachDaMuon,
                 int thoiGianMuonMax, double tileGiamGia,
                 string ngayDangKy, string ngayHetHan)
    : DocGia(maSo, ten, soSachDaMuon),
      thoiGianMuonMax(thoiGianMuonMax),
      tileGiamGia(tileGiamGia),
      ngayDangKy(ngayDangKy),
      ngayHetHan(ngayHetHan)
{
    theMuon = new TheMuon("HoiVien", ngayLapThe);
}
int HoiVien::getThoiGianMuonMax() const {
    return thoiGianMuonMax;
}
string HoiVien::getNgayDangKy() const {
    return ngayDangKy;
}
void HoiVien::hienThiThongTin() const {
    DocGia::hienThiThongTin();
    cout << " | Max: " << thoiGianMuonMax << " ngay"
         << " | Giam: " << fixed << setprecision(0) << (tileGiamGia * 100) << "%"
         << " | DK: " << ngayDangKy << " | HH: " << ngayHetHan;
}
void HoiVien::ghiFile(ostream& out) const {
    DocGia::ghiFile(out);
    out << thoiGianMuonMax << " " << tileGiamGia << "\n"
        << ngayDangKy << "\n"
        << ngayHetHan << "\n";  
}
void HoiVien::docFile(istream& in) {
    DocGia::docFile(in);
    in >> thoiGianMuonMax >> tileGiamGia;
    in.ignore();
    getline(in, ngayDangKy);
    getline(in, ngayHetHan);
}
