#include "../include/HoiVien.h"
#include <iostream>
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
    cout << "=== THONG TIN HOI VIEN ===\n";
    cout << "Ten: " << getHoTen() << endl;
    cout << "Ma so: " << getMaDocGia() << endl;
    cout << "So sach da muon: " << getSoLuotMuon() << endl;
    cout << "Thoi gian muon toi da: " << thoiGianMuonMax << " ngay" << endl;
    cout << "Ti le giam gia: " << (tileGiamGia * 100) << "%" << endl;
    cout << "Ngay dang ky: " << ngayDangKy << endl;
    cout << "Ngay het han: " << ngayHetHan << endl;
    cout << "==========================\n";
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

